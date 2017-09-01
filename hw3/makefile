hw3 : calculator.o frontend.o stack.o
	gcc -g calculator.o frontend.o stack.o -o hw3
calculator.o : calculator.c calculator.h
	gcc -c -g calculator.c
frontend.o : calculator.h stack.h frontend.c
	gcc -c -g frontend.c
stack.o : stack.c stack.h
	gcc -c -g stack.c
clean : 
	rm *.o hw3
