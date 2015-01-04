CFLAGS = -Wall -pedantic -std=c99
EXEC = aprox
OBJS = main.o funkcje_trygonometryczne.o punkty.o aproksymator_f_trygonometrycznymi.o
SRCS = main.c funkcje_trygonometryczne.c punkty.c aproksymator_f_trygonometrycznymi.c aproksymator_f_trygonometrycznymi.h punkty.h

$(EXEC): $(OBJS) -lm
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS) -lm

$(OBJS): $(SRCS) -lm 
	$(CC) $(CFLAGS) -c $(SRCS) -lm

debug: $(SRCS)
	$(CC) $(CFLAGS) -g -ggdb -c $(SRCS)
	$(CC) $(CFLAGS) -g -ggdb -o $(EXEC) $(OBJS)

