all: stack
stack: stack2.c stack5.c
	gcc stack2.c stack5.c -o stack
clean: 
	rm stack
