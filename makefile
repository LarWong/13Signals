all: signalhandler.o
	gcc -o tester signalhandler.o
sighandler.o: signalhandler.c
	gcc -o signalhandler.c
run:
	./tester
clean:
	rm -f tester* *txt *o
