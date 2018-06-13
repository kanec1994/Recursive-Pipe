all: pipeline
pipeline: recursivePipe.o
	gcc -o pipeline recursivePipe.o
recursivePipe.o: recursivePipe.c
	gcc -o recursivePipe.o -c recursivePipe.c
clean:
	rm -f pipeline *~ *.o
