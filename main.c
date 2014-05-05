#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("lhy");
MODULE_DESCRIPTION("test hook");

static int __init myhook_init(void)
{
	return 0;
}

static void __exit myhook_fini(void)
{
	
}

module_init(myhook_init);
module_exit(myhook_fini);