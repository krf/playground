// Fix parser in KDevelop
#define notrace __attribute__((no_instrument_function))

#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/slab.h>
#include <linux/sched.h>

static void write_after_free(void) {
  // provoke write after free
  size_t len = 1024;
  u32 *data = kmalloc(len, GFP_KERNEL);

  kfree(data);
  schedule();
  memset(data, 0x78, len);
}

static int hello_killme_show(struct seq_file *m, void *v) {
  write_after_free();
  return 0;
}

static int hello_killme_open(struct inode *inode, struct  file *file) {
  return single_open(file, hello_killme_show, NULL);
}

static const struct file_operations hello_killme_fops = {
  .owner = THIS_MODULE,
  .open = hello_killme_open,
  .read = seq_read,
  .llseek = seq_lseek,
  .release = single_release,
};

static int __init hello_killme_init(void) {
  proc_create("hello_killme", 0, NULL, &hello_killme_fops);
  return 0;
}

static void __exit hello_killme_exit(void) {
  remove_proc_entry("hello_killme", NULL);
}

module_init(hello_killme_init);
module_exit(hello_killme_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Kevin Funk <kfunk@kde.org>");
MODULE_DESCRIPTION("\"Hello, killme!\" minimal module");
MODULE_VERSION("proc");
