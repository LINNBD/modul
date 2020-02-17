#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/interrupt.h>
#include <asm/io.h>
#include <linux/ioctl.h>

#define KBD_IRQ             1       /* IRQ number for keyboard (i8042) */
#define KBD_DATA_REG        0x60    /* I/O port for keyboard data */
#define KBD_SCANCODE_MASK   0x7f
#define KBD_STATUS_MASK     0x80
#define MY_BASEPORT 0x3F8



static irqreturn_t kbd2_isr(int irq, void *dev_id)
{
     unsigned char value = 0xFF;
     outb(value, MY_BASEPORT);
     printk("%d \n",inb(MY_BASEPORT));

    return IRQ_HANDLED;
}

static int __init kbd2_init(void)
{
    return request_irq(KBD_IRQ, kbd2_isr, IRQF_SHARED, "kbd2", (void *)kbd2_isr);
}

static void __exit kbd2_exit(void)
{
    free_irq(KBD_IRQ, (void *)kbd2_isr);
}

module_init(kbd2_init);
module_exit(kbd2_exit);

MODULE_LICENSE("GPL");
