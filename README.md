# get_next_line

> Reading a line from a file descriptor, one line at a time. A 42 School project exploring file I/O, static variables, and memory management in C.

## About

**get_next_line** is a function that reads and returns one line at a time from a file descriptor. Whether you're reading from a file, stdin, or any valid fd, this function handles it efficiently—remembering where it left off between calls using static variables.

This project taught me how to work with:
- **File descriptors** and the `read()` system call
- **Static variables** to maintain state between function calls  
- **Dynamic memory allocation** and careful cleanup
- **Buffer management** with variable `BUFFER_SIZE`
- **Edge cases** like EOF, empty files, and huge lines

## What I Learned

### The Challenge
The main challenge was understanding how to **persist data between function calls** without using global variables. Static variables became the key—they live across multiple calls but stay confined to the function scope.

### Buffer Management
Learning to work with different `BUFFER_SIZE` values (from 1 to 10,000,000) taught me how to read efficiently: read just enough to find a newline, stop, save the rest, and continue next time.

### Memory Discipline
Every `malloc()` needs a matching `free()`. With multiple allocations per call and leftover data to manage, tracking memory became critical. Valgrind was my best friend here.

### Bonus: Multiple File Descriptors
The bonus part required handling multiple file descriptors simultaneously—reading from fd 3, then 4, then back to 3, without losing track. An array of static pointers solved this elegantly.
