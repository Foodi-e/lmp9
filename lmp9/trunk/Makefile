CC = gcc
CFLAGS = -Wall --pedantic -ggdb

OBJS = src/main.o src/mat_io.o src/gauss.o src/backsubst.o

all: bin/gauss

bin/gauss: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o bin/gauss

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f src/*.o bin/gauss src/a.out src/gauss
