#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x7377b0b2, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x4df3e08b, __VMLINUX_SYMBOL_STR(kmem_cache_destroy) },
	{ 0x7ee44fe1, __VMLINUX_SYMBOL_STR(iget_failed) },
	{ 0x2ecda6f9, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0xd2b09ce5, __VMLINUX_SYMBOL_STR(__kmalloc) },
	{ 0x405c1144, __VMLINUX_SYMBOL_STR(get_seconds) },
	{ 0x6ab17657, __VMLINUX_SYMBOL_STR(drop_nlink) },
	{ 0x112b5304, __VMLINUX_SYMBOL_STR(mark_buffer_dirty_inode) },
	{ 0x55be4626, __VMLINUX_SYMBOL_STR(generic_file_llseek) },
	{ 0xda3e43d1, __VMLINUX_SYMBOL_STR(_raw_spin_unlock) },
	{ 0x5f8fcb20, __VMLINUX_SYMBOL_STR(__mark_inode_dirty) },
	{ 0x754d539c, __VMLINUX_SYMBOL_STR(strlen) },
	{ 0x60a13e90, __VMLINUX_SYMBOL_STR(rcu_barrier) },
	{ 0x1f5902be, __VMLINUX_SYMBOL_STR(from_kuid_munged) },
	{ 0xdb417fbf, __VMLINUX_SYMBOL_STR(block_write_begin) },
	{ 0x7fc8cfe9, __VMLINUX_SYMBOL_STR(pagecache_get_page) },
	{ 0x13bcded1, __VMLINUX_SYMBOL_STR(_raw_read_lock) },
	{ 0xf52b0fdc, __VMLINUX_SYMBOL_STR(__lock_page) },
	{ 0x366fafb3, __VMLINUX_SYMBOL_STR(__lock_buffer) },
	{ 0x44b1d426, __VMLINUX_SYMBOL_STR(__dynamic_pr_debug) },
	{ 0xcf99efa, __VMLINUX_SYMBOL_STR(inc_nlink) },
	{ 0x639b6354, __VMLINUX_SYMBOL_STR(mount_bdev) },
	{ 0x7c30127, __VMLINUX_SYMBOL_STR(generic_read_dir) },
	{ 0xd85c18dc, __VMLINUX_SYMBOL_STR(__getblk_gfp) },
	{ 0x28c30beb, __VMLINUX_SYMBOL_STR(unlock_buffer) },
	{ 0x3698cb55, __VMLINUX_SYMBOL_STR(from_kgid_munged) },
	{ 0x62e63685, __VMLINUX_SYMBOL_STR(make_kgid) },
	{ 0x94e430bb, __VMLINUX_SYMBOL_STR(__insert_inode_hash) },
	{ 0xafc527d1, __VMLINUX_SYMBOL_STR(mpage_readpages) },
	{ 0x7e526bfa, __VMLINUX_SYMBOL_STR(__x86_indirect_thunk_r10) },
	{ 0xfb578fc5, __VMLINUX_SYMBOL_STR(memset) },
	{ 0x940c5d83, __VMLINUX_SYMBOL_STR(mpage_readpage) },
	{ 0xb16bdecb, __VMLINUX_SYMBOL_STR(current_task) },
	{ 0x711ced7b, __VMLINUX_SYMBOL_STR(__bread_gfp) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x250aa434, __VMLINUX_SYMBOL_STR(d_rehash) },
	{ 0x449ad0a7, __VMLINUX_SYMBOL_STR(memcmp) },
	{ 0xd2e7a14, __VMLINUX_SYMBOL_STR(mpage_writepages) },
	{ 0xa1c76e0a, __VMLINUX_SYMBOL_STR(_cond_resched) },
	{ 0x9166fada, __VMLINUX_SYMBOL_STR(strncpy) },
	{ 0x5a921311, __VMLINUX_SYMBOL_STR(strncmp) },
	{ 0x7f8a2fa, __VMLINUX_SYMBOL_STR(kmem_cache_free) },
	{ 0x16305289, __VMLINUX_SYMBOL_STR(warn_slowpath_null) },
	{ 0x36d12eb9, __VMLINUX_SYMBOL_STR(set_nlink) },
	{ 0xac8b25e1, __VMLINUX_SYMBOL_STR(_raw_write_lock) },
	{ 0x6c64116d, __VMLINUX_SYMBOL_STR(page_symlink) },
	{ 0x7de21182, __VMLINUX_SYMBOL_STR(sync_dirty_buffer) },
	{ 0x383f5f8d, __VMLINUX_SYMBOL_STR(truncate_pagecache) },
	{ 0xe5ad3a90, __VMLINUX_SYMBOL_STR(unlock_page) },
	{ 0xceebb331, __VMLINUX_SYMBOL_STR(generic_file_read_iter) },
	{ 0xe3b55400, __VMLINUX_SYMBOL_STR(__brelse) },
	{ 0xf11543ff, __VMLINUX_SYMBOL_STR(find_first_zero_bit) },
	{ 0xc539b68, __VMLINUX_SYMBOL_STR(inode_init_once) },
	{ 0xd9b09bc, __VMLINUX_SYMBOL_STR(page_follow_link_light) },
	{ 0x5a2e8296, __VMLINUX_SYMBOL_STR(invalidate_inode_buffers) },
	{ 0xeb0b2d04, __VMLINUX_SYMBOL_STR(kmem_cache_alloc) },
	{ 0xb18e172f, __VMLINUX_SYMBOL_STR(block_write_full_page) },
	{ 0x91a4c768, __VMLINUX_SYMBOL_STR(bdevname) },
	{ 0x58076bc8, __VMLINUX_SYMBOL_STR(block_write_end) },
	{ 0x57e2f69f, __VMLINUX_SYMBOL_STR(make_kuid) },
	{ 0xdb7305a1, __VMLINUX_SYMBOL_STR(__stack_chk_fail) },
	{ 0x6d9a994d, __VMLINUX_SYMBOL_STR(generic_write_end) },
	{ 0x4eb278cf, __VMLINUX_SYMBOL_STR(unlock_new_inode) },
	{ 0x5139be3, __VMLINUX_SYMBOL_STR(kill_block_super) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
	{ 0x87b393c2, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0xd52bf1ce, __VMLINUX_SYMBOL_STR(_raw_spin_lock) },
	{ 0x35a791bd, __VMLINUX_SYMBOL_STR(kmem_cache_create) },
	{ 0x273b3aba, __VMLINUX_SYMBOL_STR(register_filesystem) },
	{ 0x3f658fe3, __VMLINUX_SYMBOL_STR(generic_file_write_iter) },
	{ 0xf605388b, __VMLINUX_SYMBOL_STR(iput) },
	{ 0x47814688, __VMLINUX_SYMBOL_STR(read_cache_page) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x158b4536, __VMLINUX_SYMBOL_STR(ihold) },
	{ 0x643e0ce5, __VMLINUX_SYMBOL_STR(call_rcu_sched) },
	{ 0x6128b5fc, __VMLINUX_SYMBOL_STR(__printk_ratelimit) },
	{ 0xd6423242, __VMLINUX_SYMBOL_STR(block_truncate_page) },
	{ 0x8228d43, __VMLINUX_SYMBOL_STR(sb_set_blocksize) },
	{ 0x2da64ba9, __VMLINUX_SYMBOL_STR(generic_readlink) },
	{ 0x4d691dc1, __VMLINUX_SYMBOL_STR(put_page) },
	{ 0xaa887c1a, __VMLINUX_SYMBOL_STR(__bforget) },
	{ 0x8cb3b675, __VMLINUX_SYMBOL_STR(d_make_root) },
	{ 0x74c134b9, __VMLINUX_SYMBOL_STR(__sw_hweight32) },
	{ 0xcb185ca3, __VMLINUX_SYMBOL_STR(__blockdev_direct_IO) },
	{ 0x5244493b, __VMLINUX_SYMBOL_STR(__block_write_begin) },
	{ 0x80d29bba, __VMLINUX_SYMBOL_STR(mark_buffer_dirty) },
	{ 0xe47c2dad, __VMLINUX_SYMBOL_STR(unregister_filesystem) },
	{ 0x76e4b917, __VMLINUX_SYMBOL_STR(write_one_page) },
	{ 0xdc643be0, __VMLINUX_SYMBOL_STR(init_special_inode) },
	{ 0xd9d82aca, __VMLINUX_SYMBOL_STR(new_inode) },
	{ 0xe95e12, __VMLINUX_SYMBOL_STR(clear_inode) },
	{ 0x227f10b1, __VMLINUX_SYMBOL_STR(page_put_link) },
	{ 0xde735f30, __VMLINUX_SYMBOL_STR(d_instantiate) },
	{ 0x1fbc06e1, __VMLINUX_SYMBOL_STR(generic_block_bmap) },
	{ 0xf1d15aff, __VMLINUX_SYMBOL_STR(iget_locked) },
	{ 0x73d18610, __VMLINUX_SYMBOL_STR(generic_fillattr) },
	{ 0xbdebbaaf, __VMLINUX_SYMBOL_STR(inode_init_owner) },
	{ 0x18ab13eb, __VMLINUX_SYMBOL_STR(truncate_inode_pages) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "8B5F2439AC25F487A2F9AFF");
