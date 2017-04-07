// use of ioctl in character driver


#include<linux/module.h>
#include<linux/types.h>
#include<linux/fs.h>
#include<linux/device.h>
#include<linux/kdev_t.h>
#include<linux/cdev.h>
#include<linux/kernel.h>
#include<asm/uaccess.h>
#include"ioctl_header.h"

//#define AUTHOR "Niraj Ardeshana"
//#define DESC "ioctl implimentation"

static dev_t first;//g.var first device number(major)
static struct cdev c_dev;//g.var character device structure
static struct class *cl;
static int k_var=5;

static int device_open(struct inode *inode,struct file *file)
{
	printk(KERN_INFO"device file opened\n");
	return 0;
}

static int device_release(struct inode *inode,struct file *file)
{
	printk(KERN_INFO"device file closed\n");
	return 0;
}

static ssize_t device_read(struct file *file,char __user *buf,size_t len,loff_t *off)
{
	printk(KERN_INFO"device file read\n");
	return len;
}

static ssize_t device_write(struct file *file,const char __user *buf,size_t len,loff_t *off)
{
	printk(KERN_INFO"device file written\n");
	return len;
}

long device_ioctl(struct file *filp,unsigned int cmd,unsigned long arg)
{
	
	printk(KERN_INFO"in ioctl function\n");
	
	switch(cmd)
	{
		case TEST_IOCTL_SET_VARIABLE:
			copy_from_user(&k_var,(int*)arg,sizeof(int));
			break;
		case TEST_IOCTL_GET_VARIABLE:
			copy_to_user((int*)arg,&k_var,sizeof(int));
			break;
		default:
			return -EINVAL;
	}

	return 0;
}

static struct file_operations my_fops={
	.open=device_open,
	.release=device_release,
	.read=device_read,
	.write=device_write,
	.unlocked_ioctl=device_ioctl,
	};


static int myinit(void)
{

	printk(KERN_INFO"char device registered\n");

	if(alloc_chrdev_region(&first,0,1,"niraj")<0)//getting major number dynamically
	{
		return -1;
	}

	printk(KERN_INFO"major is:%d\n",MAJOR(first));//to print the major number

	if((cl=class_create(THIS_MODULE,"chardrv"))==NULL)//class create
	{
		unregister_chrdev_region(first,1);
		return -1;
	}

	if(device_create(cl,NULL,first,NULL,"mynull")==NULL)//device create
	{
		class_destroy(cl);
		unregister_chrdev_region(first,1);
		return -1;
	}
	cdev_init(&c_dev,&my_fops);//device initialize

	if(cdev_add(&c_dev,first,1)==-1)//adding device
	{
		device_destroy(cl,first);
		class_destroy(cl);
		unregister_chrdev_region(first,1);
		return -1;
	}

	return 0;

}

void myexit(void)
{
	cdev_del(&c_dev);
	device_destroy(cl,first);
	class_destroy(cl);
	unregister_chrdev_region(first,1);
	printk(KERN_INFO"char device unregistered\n");

}


module_init(myinit);
module_exit(myexit);

//MODULE_AUTHOR(AUTHOR);
//MODULE_DESCRIPTION(DESC);
MODULE_LICENSE("GPL");
