
#include <linux/init.h>

#include <linux/kernel.h>
#include <linux/module.h>

static __init int miku_init(void) 
{
    pr_info("Hello, earthlings!\n");
    return 0;
}

static __exit void miku_exit(void) 
{
    pr_info("Goodbye, earthlings!\n");
}

module_init(miku_init);
module_exit(miku_exit);


MODULE_LICENSE("Beerware");
MODULE_DESCRIPTION("Ca fait rien pour l'instant gros");
MODULE_AUTHOR("Hatsune Miku");

