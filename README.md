# get_next_line

A C implementation of the 42 `get_next_line` project. The function reads from a file descriptor and returns one line at a time, including the newline character when one is present.

## Features

- Reads files incrementally with the POSIX `read()` system call.
- Returns one line per function call.
- Preserves unread data between calls.
- Handles lines longer than `BUFFER_SIZE`.
- Supports files whose final line does not end with a newline.
- Returns `NULL` at end of file or when an invalid input or allocation error occurs.

## Function API

```c
char *get_next_line(int fd);
```

### Return value

- A newly allocated string containing the next line.
- The returned line includes `\n` when the input contains one.
- `NULL` when there is no more data, `fd` is invalid, `BUFFER_SIZE` is invalid, or an allocation/read error occurs.

The caller owns the returned string and must release it with `free()`:

```c
char *line;

line = get_next_line(fd);
if (line != NULL)
{
    /* Use line. */
    free(line);
}
```

## Configuration

`BUFFER_SIZE` controls how many bytes are read at a time. The current default is `13`, but it can be overridden at compile time:

```bash
cc -D BUFFER_SIZE=42 ...
```

The implementation rejects non-positive values and values greater than or equal to `INT_MAX`.

## Build

This repository currently contains the mandatory implementation and does not include a Makefile or test executable. Compile it together with your own program:

```bash
cc -Wall -Wextra -Werror \
    -D BUFFER_SIZE=13 \
    your_main.c \
    mandatory/get_next_line.c \
    mandatory/get_next_line_utils.c \
    -o reader
```

Run the resulting program with:

```bash
./reader
```

## Example

A minimal caller can read standard input until end of file:

```c
#include "mandatory/get_next_line.h"
#include <stdio.h>

int main(void)
{
    char *line;

    line = get_next_line(0);
    while (line != NULL)
    {
        printf("%s", line);
        free(line);
        line = get_next_line(0);
    }
    return (0);
}
```

Compile it from the repository root:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=13 \
    main.c \
    mandatory/get_next_line.c \
    mandatory/get_next_line_utils.c \
    -o reader
```

For a regular file, open the descriptor before reading and close it after the loop:

```c
int fd = open("input.txt", O_RDONLY);
```

Include `<fcntl.h>` when using `open()`.

## Project Structure

```text
.
├── mandatory/
│   ├── get_next_line.c
│   ├── get_next_line.h
│   └── get_next_line_utils.c
└── README.md
```

## Implementation Notes

The implementation accumulates data until it finds a newline, extracts the next line, and keeps the remaining bytes for the following call. It uses a single static remainder buffer, so the current version is intended for sequential reads from one file descriptor at a time. Multi-descriptor bonus support is not included in this repository.

## Requirements

- A POSIX-compatible environment
- A C compiler such as GCC or Clang
- The `read`, `malloc`, and `free` standard/POSIX interfaces
