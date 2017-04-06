#include<linux/module.h>
#include<linux/fs.h>
#include<linux/kernel.h>
#include<linux/miscdevice.h>

int misc_register(struct miscdevice *misc);
int misc_deregister(struct miscdevice *misc);
static int device_open(struct inode *inode,struct file *file);
static int device_release(struct inode *inode,struct file *file);

#define AUTHOR "Niraj Ardeshana"
#define DESC "misc driver"


struct file_operations my_fops={
        .open=device_open,
        .release=device_release};

//just to create difference this line is added
struct miscdevice my_dev;


int misc_regs(void)
{
	int retval;
	my_dev.minor=MISC_DYNAMIC_MINOR;
	my_dev.name="my_misc_dev";
	my_dev.fops=&my_fops;
	retval=misc_register(&my_dev);

	if(retval)
	return retval;
	printk(KERN_INFO"misc device registered\n");
	printk(KERN_INFO"MINOR IS:%d\n",my_dev.minor);
	
	return 0;

}


void misc_unregs(void)
{

	misc_deregister(&my_dev);

}


static int device_open(struct inode *inode,struct file *file)
{


        printk(KERN_INFO"file opened\n");

        return 0;

}

static int device_release(struct inode *inode,struct file *file)
{

        printk(KERN_INFO"file closed\n");
        return 0;

}




module_init(misc_regs);
module_exit(misc_unregs);


MODULE_AUTHOR(AUTHOR);
MODULE_DESCRIPTION(DESC);
