cmd_/home/hjeon/sfs/kernel/sfs.o := ld -m elf_x86_64  -z max-page-size=0x200000   -r -o /home/hjeon/sfs/kernel/sfs.o /home/hjeon/sfs/kernel/super.o /home/hjeon/sfs/kernel/inode.o /home/hjeon/sfs/kernel/namei.o /home/hjeon/sfs/kernel/dir.o /home/hjeon/sfs/kernel/file.o /home/hjeon/sfs/kernel/bitmap.o /home/hjeon/sfs/kernel/itree.o 
