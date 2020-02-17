/** @file example1.c
 *
 * \brief first example of input subsystem driver
 *
 */

#include <linux/input.h>   /* input_dev */
#include <linux/module.h>
/* #include <linux/modversions.h> */
#include <linux/init.h>

/* MODULE_LICENSE( "GPL" ); */

struct input_dev example1_dev;

static int __init example1_init( void )
{
  /* extra safe initialization */
  memset( &example1_dev, 0, sizeof(struct input_dev) );
#if 0
  init_input_dev( &example1_dev );
#endif


  /* set up descriptive labels */
  example1_dev.name = "Example 1 device";
#if 0
  example1_dev.phys = "A/Fake/Path";
  example1_dev.id.bustype = BUS_HOST;
  example1_dev.id.vendor  = 0x0001;
  example1_dev.id.product = 0x0001;  // our first product
  example1_dev.id.version = 0x0101;  // version 1.1
#else
  example1_dev.idbus     = BUS_ISA;
  example1_dev.idvendor  = 0x0001;
  example1_dev.idproduct = 0x0001;  // our first product
  example1_dev.idversion = 0x0101;  // version 1.1
#endif
  
  set_bit( EV_KEY, example1_dev.evbit );
  set_bit( KEY_A,  example1_dev.keybit );
  set_bit( KEY_B,  example1_dev.keybit );
  set_bit( KEY_C,  example1_dev.keybit );

  input_register_device( &example1_dev );
  return 0;
}

static void __exit example1_exit( void )
{
  input_unregister_device( &example1_dev );
}

module_init( example1_init );
module_exit( example1_exit );