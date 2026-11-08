# Proxima Allocator
CC      = gcc
CFLAGS  = -Wall -Wextra -std=c11 -O2
TARGET  = proxima
OBJS    = main.o pool.o

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

main.o: main.c pool.h
	$(CC) $(CFLAGS) -c main.c -o main.o

pool.o: pool.c pool.h
	$(CC) $(CFLAGS) -c pool.c -o pool.o

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(OBJS)
