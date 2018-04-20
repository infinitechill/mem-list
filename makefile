#J. Volmer // April 2018
#A linked list memory management system

all: clean memlistdemo run 

memlistdemo:  memlistdemo.c memlist.c
	gcc memlistdemo.c memlist.c -o memlistdemo

clean:
	rm -f memlistdemo

run:
	./memlistdemo