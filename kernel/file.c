#include <linux/fs.h>

ssize_t 
sfs_file_write_iter(struct kiocb * iocb, 
		            struct iov_iter * from){
	printk("[sfs_file_write_iter] called\n");
	return generic_file_write_iter;
}

ssize_t
sfs_file_read_iter(struct kiocb * iocb,
		           struct iov_iter * iter){
	printk("[sfs_file_read_iter] called\n");
	return generic_file_read_iter;
}

const struct file_operations sfs_file_ops = {
	.llseek = generic_file_llseek,
	.read_iter = generic_file_read_iter,
	.write_iter = generic_file_write_iter,
	//	.mmap = generic_file_mmap,
	//	.splice_read = generic_file_splice_read,
	//	.splice_write = iter_file_splice_write,
};
