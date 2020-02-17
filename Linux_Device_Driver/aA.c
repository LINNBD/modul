#include <linux/module.h> 
#include <linux/kernel.h>     
//#include <linux/init.h>
#include <linux/input.h>
#include <linux/timer.h>

MODULE_LICENSE("GPL"); 
MODULE_VERSION("0.1");

struct input_dev ex2_dev;

void ex2_timeout(unsigned long unused/*UNUSED*/)
{
    int x;

    for (x=0;x<4;x++) {
	/* letter a or A */
	input_report_key(&ex2_dev, KEY_A, 1);
	input_sync(&ex2_dev);
	input_report_key(&ex2_dev, KEY_A, 0);
	input_sync(&ex2_dev);
    }
    for (x=0;x<4;x++) {
	/* letter b or B */
	input_report_key(&ex2_dev, KEY_B, 1);
	input_sync(&ex2_dev);
	input_report_key(&ex2_dev, KEY_B, 0);
	input_sync(&ex2_dev);
    }
    
    /* set timer for four seconds */
    mod_timer(&ex2_dev.timer,jiffies+4*HZ );
}

static int __init ex2_init(void)
{

    //make... do initialization ...    

    /* set up a repeating timer */
    init_timer(&ex2_dev.timer);
    ex2_dev.timer.function = ex2_timeout;
    ex2_dev.timer.expires = jiffies + HZ;
    add_timer(&ex2_dev.timer);
    
    return 0;
}

static void __exit ex2_exit(void)
{
    del_timer_sync(&ex2_dev.timer);
    input_unregister_device(&ex2_dev);
}

module_init(ex2_init); 
module_exit(ex2_exit); 