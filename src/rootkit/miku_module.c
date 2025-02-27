#include <linux/fs.h>
#include <linux/kernel.h>
#include <linux/mm.h>
#include <linux/mmzone.h> 
#include <linux/module.h>
#include <linux/sched.h> // task_struct my beloved

static void print_status(void)
{
    char buffer[512];
    int pos = 0;

    struct task_struct *task;
    int process_count = 0;
    for_each_process(task)
    {
        process_count++;
    }
    pos += snprintf(buffer + pos, sizeof(buffer) - pos, "Processes: %d\n",
                    process_count);

    unsigned long total_pages = totalram_pages();
    unsigned long free_pages = global_zone_page_state(NR_FREE_PAGES);
    unsigned long page_size = PAGE_SIZE;
    unsigned long total_ram_kb = (total_pages * page_size) / 1024;
    unsigned long free_ram_kb = (free_pages * page_size) / 1024;

    pos += snprintf(buffer + pos, sizeof(buffer) - pos,
                    "RAM Total: %lu kB\nRAM Free: %lu kB\n", total_ram_kb,
                    free_ram_kb);

    struct file *battery =
        filp_open("/sys/class/power_supply/BAT0/capacity", O_RDONLY, 0);
    if (!IS_ERR(battery))
    {
        char bat_data[16];
        kernel_read(battery, bat_data, sizeof(bat_data) - 1, &battery->f_pos);
        bat_data[sizeof(bat_data) - 1] = '\0';
        pos += snprintf(buffer + pos, sizeof(buffer) - pos, "Battery: %s%%\n",
                        bat_data);
        filp_close(battery, NULL);
    }
    else
    {
        pos += snprintf(buffer + pos, sizeof(buffer) - pos,
                        "Battery: Not available\n");
    }

    printk(KERN_INFO "Status Report:\n%s", buffer);
}

static int __init miku_module_init(void)
{
    printk(KERN_INFO "loaded\n");
    print_status();
    return 0;
}

static void __exit miku_module_exit(void)
{
    printk(KERN_INFO "unloaded\n");
}

module_init(miku_module_init);
module_exit(miku_module_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Hatsune Miku");