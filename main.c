#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("lhy");
MODULE_DESCRIPTION("test hook");

int ip_test(struct sk_buff *skb,
			struct net_device *dev,
			struct packet_type *ptype,
			struct net_device *dev2)
{
	return 0;
}

struct packet_type ptype = {
	.type = __constant_htons(ETH_P_ALL);
	.func = ip_test;
};


static int __init myhook_init(void)
{
	dev_add_pack(&ptype);

	return 0;
}

static void __exit myhook_fini(void)
{
	dev_remove_pack(&ptype);

}

module_init(myhook_init);
module_exit(myhook_fini);