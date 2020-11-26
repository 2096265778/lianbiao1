main:bubble.o sort2.o sort4.o
	gcc -o main bubble.o sort2.o sort4.o
bubble.o:bubble1.c
	gcc -c bubble1.c
sort2.o:sort2.c
	gcc -c sort2.c
sort4.o:sort4.c
	gcc -c sort4.c
clear:
	rm -rf *.o main
