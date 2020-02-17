#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/stat.h>
#include <linux/flex_array.h>



MODULE_LICENSE("GPL");
MODULE_AUTHOR("UX BD");

static int n=10000;
module_param(n,int, S_IRUSR | S_IWUSR);

struct array *flex_array_alloc(int n,
                                    unsigned int 10000,
                                    gfp_t flags);

static int __init hello_5_init(void)
{
int i;	
for (i = 0; i < n; i++)
	{ 
		module_param(myint+i,int, S_IRUSR | S_IWUSR);
	}
	return 0;
for (i = 0; i < (sizeof myint / sizeof (int)); i++)
	{
		printk(KERN_INFO " myint[%d] = %d  \n", i,myint[i]);
	}
	return 0;
}

static void __exit hello_5_exit(void)
{
	printk(KERN_INFO "Goodbye, world \n");
}

module_init(hello_5_init);
module_exit(hello_5_exit);







