CC = gcc
CFLAGS = -fopenmp -O2 -Wall
LDFLAGS = -lm

SRC = $(wildcard Exercicio*/*.c)

all:
	@for f in $(SRC); do \
		name=$$(basename $$f .c); \
		echo "Compilando $$f -> $$name"; \
		$(CC) $(CFLAGS) $$f -o $$name $(LDFLAGS); \
	done

clean:
	rm -f $(EXEC) *.exe
