#Guilherme Bastos de Oliveira

CFLAGS = -Wall
objects = pgmlib.o args.o

all: pgmnega pgmlimiar pgmmedia pgmmediana

pgmnega: pgmnega.o $(objects)
	gcc pgmnega.o $(objects) -o pgmnega $(CFLAGS)

pgmlimiar: pgmlimiar.o $(objects)
	gcc pgmlimiar.o $(objects) -o pgmlimiar $(CFLAGS)

pgmmedia: pgmmedia.o $(objects)
	gcc pgmmedia.o $(objects) -o pgmmedia $(CFLAGS)

pgmmediana: pgmmediana.o $(objects)
	gcc pgmmediana.o $(objects) -o pgmmediana $(CFLAGS)

pgmnega.o: pgmnega.c
	gcc -c pgmnega.c $(CFLAGS)

pgmlimiar.o: pgmlimiar.c
	gcc -c pgmlimiar.c $(CFLAGS)

pgmmedia.o: pgmmedia.c
	gcc -c pgmmedia.c $(CFLAGS)

pgmmediana.o: pgmmediana.c
	gcc -c pgmmediana.c $(CFLAGS)

pgmlib.o: pgmlib.c pgmlib.h
	gcc -c pgmlib.c $(CFLAGS)

args.o: args.c args.h
	gcc -c args.c $(CFLAGS)

clean:
	-rm -f *.o

purge: clean
	-rm -f pgmmediana pgmmedia pgmlimiar pgmnega
