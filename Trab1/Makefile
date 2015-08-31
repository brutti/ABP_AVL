FLAGS=-Wall
BINEXEC=a.out

All: ${BINEXEC}

${BINEXEC}: arv.o main.c
		gcc main.c arv.o ${FLAGS}

arv.o: arv.c
	gcc -c arv.c ${FLAGS}

clean:
	rm -f *.o ${BINEXEC}
