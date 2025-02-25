
obj-m := miku_module.o
KERNELDIR ?= /lib/modules/$(shell uname -r)/build

PWD := $(shell pwd)

modules:
	$(MAKE) -C $(KERNELDIR) M=$(PWD)/src/rootkit $@

clean:
	$(RM) *.o *~ core .depend .*.cmd *.ko *.mod.c \
				*.tmp_versions *.mod *.order *.symvers

.PHONY: modules clean