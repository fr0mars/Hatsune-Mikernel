
#include <linux/kernel.h>
#include <linux/module.h>

static int __init zuck_init(void) {
    printk(KERN_INFO "Hello, earthlings!\n");
    return 0;
}

static void __exit my_module_exit(void) {
    printk(KERN_INFO "Goodbye, earthlings!\n");
}

module_init(my_module_init);
module_exit(my_module_exit);


MODULE_LICENSE("GPL");

