// Fix parser in KDevelop
#define notrace __attribute__((no_instrument_function))

/*
 * "Hello, world!" minimal kernel module
 *
 * http://www.linuxdevcenter.com/pub/a/linux/2007/07/05/devhelloworld-a-simple-introduction-to-device-drivers-under-linux.html?page=2
 */

#include <linux/init.h>
#include <linux/module.h>

static int __init
hello_init(void)
{
	printk("Hello, world!\n");
	return 0;
}

static void __exit
hello_exit(void)
{
	printk("Goodbye, world!\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Kevin Funk <kfunk@kde.org>");
MODULE_DESCRIPTION("\"Hello, world!\" minimal module");
MODULE_VERSION("printk");
