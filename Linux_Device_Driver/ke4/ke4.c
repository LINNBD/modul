#include <linux/input.h>
#include <linux/module.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");

struct input_dev *dev_ip;

void dev_ip_timeout(unsigned long unused/*UNUSED*/)
{
/* letter S or s */
input_report_key(dev_ip, KEY_S, 1);
input_sync(dev_ip);
input_report_key(dev_ip, KEY_S, 0);
input_sync(dev_ip);
/* set timer for five second */
mod_timer(&(dev_ip->timer),jiffies+5*HZ );
}

static int __init ip_init(void)
{
/* initialization */
dev_ip = input_allocate_device();
//memset(&dev_ip, 0, sizeof(struct input_dev));
//init_input_dev(&dev_ip);

/* set up descriptive labels */
dev_ip->name = "Con Device";
/* phys is unique on a running system */
dev_ip->phys = "";
dev_ip->id.bustype = BUS_HOST;
dev_ip->id.vendor = 0xDEAD;
dev_ip->id.product = 0xBEEF;
dev_ip->id.version = 0xFACE;

/* this device has one key S*/
set_bit(EV_KEY, dev_ip->evbit);
set_bit(KEY_S, dev_ip->keybit);

/* and finally register with the input core */
input_register_device(dev_ip);

/* set up a repeating timer */
//init_timers(&dev_ip->timer);
dev_ip->timer.function = dev_ip_timeout;
dev_ip->timer.expires = 0;
add_timer(&dev_ip->timer);

return 0;
}

static void __exit ip_exit(void)
{
input_unregister_device(dev_ip);
}

module_init(ip_init);
module_exit(ip_exit);