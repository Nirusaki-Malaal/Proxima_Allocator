# Proxima Allocator

A simple pool allocator in C that gets its memory from `mmap` only.

## Features

- Fixed size chunks allocated from one big `mmap` block
- Allocate multiple chunks at once
- Free chunks back to the pool
- View stats (total, used, free chunks)
- Reset the pool without unmapping

## Project Structure

```
.
├── main.c    # Menu front end
├── pool.c    # Allocator implementation
├── pool.h    # Public interface
└── Makefile
```

## Build

```bash
make
```

## Run

```bash
make run
```

Or directly:

```bash
./proxima
```

## Usage

```
What Size of chunks you want and also how many chunks you want ?
32 10
```

Then pick from the menu:

```
  1. Allocate Chunk
  2. Free Chunk
  3. View Stats
  4. Reset Pool
  5. Exit
```

## Clean

```bash
make clean
```

## Notes

- The pool is a bump allocator, so freeing just rewinds the counter
- Memory is released with `munmap` when you exit
