#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/init.h>

static int num;

//input 
module_param(num,int,S_IRUSR | S_IWUSR);

static int __init showme(void){
    int i ;
    
    for (i=11;i<num;i++){
       printk(KERN_INFO "Looping  %d",i); 
    }
    return 0;
}
	
static void __exit cleanme(void){
    printk(KERN_INFO "Goodbye Nahian\n"); 
}

module_init(showme);
module_exit(cleanme);
