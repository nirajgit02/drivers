#include<linux/init.h>
#include<linux/module.h>
#include<linux/fs.h>
#include<linux/debugfs.h>

#define AUTHOR "Niraj Ardeshana"
#define DESC "create debugfs entry"
#define len 200

struct dentry *dirret,*fileret,*u64int;
char ker_buf[len];
int filevalue;
u64 intvalue;

ssize_t debugfs_read(struct file *file,char *buffer,size_t count,loff_t *offset)
{
	return simple_read_from_buffer(buffer,count,offset,ker_buf,len);
} 

ssize_t debugfs_write(struct file *file,const char *buffer,size_t count,loff_t *offset)
{
	if(count>len)
		return -EINVAL;
	return simple_write_to_buffer(ker_buf,len,offset,buffer,count); 
}

struct file_operations debugfs_fops=
{
	.read=debugfs_read,
	.write=debugfs_write,
};



static int myinit(void)
{
	dirret=debugfs_create_dir("fossil",NULL);//create directory

	fileret=debugfs_create_file("text",0644,dirret,&filevalue,&debugfs_fops);//create_file

	u64int=debugfs_create_u64("number",0644,dirret,&intvalue);//read/write to value
	return 0;

}

void myexit(void)
{
	debugfs_remove_recursive(dirret);//remove files recursively

}
module_init(myinit);
module_exit(myexit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR(AUTHOR);
MODULE_DESCRIPTION(DESC);
