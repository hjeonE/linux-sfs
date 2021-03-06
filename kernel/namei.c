#include <linux/fs.h>
#include "sfs.h"

static int add_nondir(struct dentry *dentry, struct inode *inode)
{
	int err = sfs_add_link(dentry, inode);
	if (!err) {
		d_instantiate(dentry, inode);
		return 0;
	}
	iput(inode);
	return err;	
}

static int sfs_mknod(struct inode *dir, struct dentry *dentry, 
			umode_t mode, dev_t rdev)
{
	int err;
	struct inode *inode;

	if (!new_valid_dev(rdev))
		return -EINVAL;

	inode = sfs_new_inode(dir, mode, &err);
	if (!err && inode) {
		sfs_set_inode(inode, rdev);
		mark_inode_dirty(inode);
		err = add_nondir(dentry, inode);
	}
	return err;
} 

static int sfs_mkdir(struct inode *dir, struct dentry *dentry, umode_t mode)
{
	struct inode *inode;
	int err;

	inode_inc_link_count(dir);

	inode = sfs_new_inode(dir, S_IFDIR | mode, &err);
	if (!inode)
		goto out_dir;
	
	inode_inc_link_count(inode);

	sfs_set_inode(inode, 0);

	err = sfs_make_empty(inode, dir);
	if (err)
		goto out_fail;

	err = sfs_add_link(dentry, inode);
	if (err)
		goto out_fail;

	d_instantiate(dentry, inode);
out:
	return err;

out_fail:
	inode_dec_link_count(inode);
	inode_dec_link_count(inode);
	iput(inode);
out_dir:
	inode_dec_link_count(dir);
	goto out;
}

static struct dentry *sfs_lookup(struct inode *dir, struct dentry *dentry,
			unsigned flags)
{
	struct inode *inode = NULL;
	ino_t ino;

	if (dentry->d_name.len >= SFS_MAX_NAME_LEN)
		return ERR_PTR(-ENAMETOOLONG);

	ino = sfs_inode_by_name(dir, &dentry->d_name);
	if (ino) {
		printk("[DEBUG] sfs_lookup is called, %s , after that d_add()\n", &dentry->d_name.name);
		inode = sfs_iget(dir->i_sb, ino);
		if (IS_ERR(inode)) {
			pr_err("Cannot read inode %lu", (unsigned long)ino);
			return ERR_PTR(PTR_ERR(inode));
		}
		d_add(dentry, inode);
	}
	return NULL;
}

static int sfs_create(struct inode *dir, struct dentry *dentry, 
			umode_t mode, bool excl)
{
	printk("[DEBUG] sfs_create() called\n");
	int err;
	struct inode *inode;

	inode = sfs_new_inode(dir, mode, &err);
	if (!err && inode) {
		sfs_set_inode(inode, 0);
		mark_inode_dirty(inode);
		err = add_nondir(dentry, inode);
	}
	return err;
} 

static int sfs_symlink(struct inode * dir, struct dentry *dentry,
			const char * symname)
{
	int err = -ENAMETOOLONG;
	int i = strlen(symname)+1;
	struct inode * inode;

	if (i > dir->i_sb->s_blocksize)
		goto out;

	inode = sfs_new_inode(dir, S_IFLNK | 0777, &err);
	if (!inode)
		goto out;

	sfs_set_inode(inode, 0);
	err = page_symlink(inode, symname, i);
	if (err)
		goto out_fail;

	err = add_nondir(dentry, inode);
out:
	return err;

out_fail:
	inode_dec_link_count(inode);
	iput(inode);
	goto out;
}

static int sfs_link(struct dentry * old_dentry, struct inode * dir,
			struct dentry *dentry)
{
	struct inode *inode = old_dentry->d_inode;

	inode->i_ctime = CURRENT_TIME_SEC;
	inode_inc_link_count(inode);
	ihold(inode);
	return add_nondir(dentry, inode);
}

static int sfs_unlink(struct inode * dir, struct dentry *dentry)
{
	int err = -ENOENT;
	struct inode * inode = dentry->d_inode;
	struct page * page;
	struct sfs_dir_entry * de;

	de = sfs_find_entry(dentry, &page);
	if (!de)
		goto end_unlink;

	err = sfs_delete_entry(de, page);
	if (err)
		goto end_unlink;

	inode->i_ctime = dir->i_ctime;
	inode_dec_link_count(inode);
end_unlink:
	return err;
}

static int sfs_rmdir(struct inode * dir, struct dentry *dentry)
{
	struct inode * inode = dentry->d_inode;
	int err = -ENOTEMPTY;

	if (sfs_empty_dir(inode)) {
		err = sfs_unlink(dir, dentry);
		if (!err) {
			inode_dec_link_count(dir);
			inode_dec_link_count(inode);
		}
	}
	return err;
}

static int sfs_rename(struct inode * old_dir, struct dentry *old_dentry,
			   struct inode * new_dir, struct dentry *new_dentry)
{
	struct inode * old_inode = old_dentry->d_inode;
	struct inode * new_inode = new_dentry->d_inode;
	struct page * dir_page = NULL;
	struct sfs_dir_entry * dir_de = NULL;
	struct page * old_page;
	struct sfs_dir_entry * old_de;
	int err = -ENOENT;

	old_de = sfs_find_entry(old_dentry, &old_page);
	if (!old_de)
		goto out;

	if (S_ISDIR(old_inode->i_mode)) {
		err = -EIO;
		dir_de = sfs_dotdot(old_inode, &dir_page);
		if (!dir_de)
			goto out_old;
	}

	if (new_inode) {
		struct page * new_page;
		struct sfs_dir_entry * new_de;

		err = -ENOTEMPTY;
		if (dir_de && !sfs_empty_dir(new_inode))
			goto out_dir;

		err = -ENOENT;
		new_de = sfs_find_entry(new_dentry, &new_page);
		if (!new_de)
			goto out_dir;
		sfs_set_link(new_de, new_page, old_inode);
		new_inode->i_ctime = CURRENT_TIME_SEC;
		if (dir_de)
			drop_nlink(new_inode);
		inode_dec_link_count(new_inode);
	} else {
		err = sfs_add_link(new_dentry, old_inode);
		if (err)
			goto out_dir;
		if (dir_de)
			inode_inc_link_count(new_dir);
	}

	sfs_delete_entry(old_de, old_page);
	mark_inode_dirty(old_inode);

	if (dir_de) {
		sfs_set_link(dir_de, dir_page, new_dir);
		inode_dec_link_count(old_dir);
	}
	return 0;

out_dir:
	if (dir_de) {
		kunmap(dir_page);
		page_cache_release(dir_page);
	}
out_old:
	kunmap(old_page);
	page_cache_release(old_page);
out:
	return err;
}

int sfs_getattr(struct vfsmount *mnt, struct dentry *dentry, struct kstat *stat)
{
	struct super_block *sb = dentry->d_sb;

	generic_fillattr(dentry->d_inode, stat);
	stat->blocks = (sb->s_blocksize / 512) * sfs_blocks(stat->size, sb);
	stat->blksize = sb->s_blocksize;
	return 0;
}

const struct inode_operations sfs_file_inode_ops = {
	.getattr		= sfs_getattr,
};

const struct inode_operations sfs_symlink_inode_ops = {
	.readlink		= generic_readlink,
	.follow_link		= page_follow_link_light,
	.put_link		= page_put_link,
	.getattr		= sfs_getattr,
};

const struct inode_operations sfs_dir_inode_ops = {
	.create		= sfs_create,
	.lookup		= sfs_lookup,
	.link		= sfs_link,
	.unlink		= sfs_unlink,
	.symlink	= sfs_symlink,
	.mknod		= sfs_mknod,
	.mkdir		= sfs_mkdir,
	.rmdir		= sfs_rmdir,
	.rename		= sfs_rename,
	.getattr	= sfs_getattr,
};

