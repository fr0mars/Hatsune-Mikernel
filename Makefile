modules:
	$(MAKE) -C src/rootkit

clean:
	$(MAKE) -C src/rootkit clean

.PHONY: modules clean
