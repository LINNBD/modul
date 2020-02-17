#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/stat.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("UX BD");

char *s="uhkjdf";


module_param(s, charp, 0000);


static int __init hello_init(void)
{
        printk(KERN_INFO "%s \n",s);
        return 0;
	
}

/* char *str[4]={"Saifu","v","f","fd"};


static int __init hello_init(void)
{
        int i,j;
        for(i=0;i<4;i++)
        {
        printk(KERN_INFO "%d \n",sizeof(str[i])/sizeof(char));
        }
		return 0;
	
}*/

static void __exit hello_exit(void)
{
	printk(KERN_INFO "Goodbye, world \n");
}

module_init(hello_init);
module_exit(hello_exit);







