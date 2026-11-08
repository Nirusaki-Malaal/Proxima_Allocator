# Proxima Allocator
CC       = gcc
CFLAGS   = -Wall -Wextra -std=c11 -O2 -Iinclude
TARGET   = proxima
SRCS     = src/main.c src/pool.c
OBJS     = src/main.o src/pool.o

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

src/main.o: src/main.c include/pool.h
	$(CC) $(CFLAGS) -c src/main.c -o src/main.o

src/pool.o: src/pool.c include/pool.h
	$(CC) $(CFLAGS) -c src/pool.c -o src/pool.o

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(OBJS)
