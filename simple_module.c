/*
 Demonstrates command line argument passing to a module.
 */

#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/stat.h>

MODULE_AUTHOR("Niraj Ardeshana");
MODULE_DESCRIPTION("module_param demo");

static int age = 5;

module_param(age,int,0);

static int __init start_init(void)
{
	printk(KERN_INFO"USE OF module_param\n");
	printk(KERN_INFO"you are %d days old\n",age*365);
	return 0;
}

static void __exit start_exit(void)
{
	printk(KERN_INFO"GOOD BYE\n");
}

module_init(start_init);
module_exit(start_exit);
