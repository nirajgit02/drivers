obj-m += my_debugfs.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
load:
	insmod my_debugfs.ko
unload:
	rmmod my_debugfs
