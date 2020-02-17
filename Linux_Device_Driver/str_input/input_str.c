#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/kernel.h>
#include <linux/stat.h>
MODULE_LICENSE("Dual BSD/GPL");

static char *mystring = "this is my char string";
module_param(mystring, charp, S_IRUGO | S_IWUSR); 

static int __init params_init(void)
{
  printk("   My char string(mystring): %s\n", mystring);
  return 0;
}


static void __exit params_exit(void)
{
   printk("Driver is unloaded\n");
}



module_init(params_init);
module_exit(params_exit);
