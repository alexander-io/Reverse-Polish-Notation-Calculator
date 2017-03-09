all: stack.o main.c
	###########################################
	### Compiling Reverse Polish Calculator ###
	###########################################
	########### remove object files ###########
	make clean

	############# compile stack.c #############
	make stack.o

	############# compile rpn.c #############
	make rpn.o

	############### compile all ###############
	gcc -Wall -o calculator main.c stack.o rpn.o
	####### issue $ ./calculator to run #######

stack.o:
	gcc -Wall -c stack.c

rpn.o:
	gcc -Wall -c rpn.c
clean:
	rm -f *.o calculator
