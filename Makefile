CC=gcc
CFLAGS= -Wall

all: equations.o observer.o ODE_Solver.c
	$(CC) $(CFLAGS) ODE_Solver.c -o ODE_Solver *.o

equations.o: equations.c
	$(CC) $(CFLAGS) -c equations.c

observer.o: observer.c equations.o
	$(CC) $(CFLAGS) -c observer.c

clean:
	rm *.o ODE_Solver
