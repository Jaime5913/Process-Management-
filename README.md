# Process-Management

## Notes
- The project demonstrates Unix/Linux process management using fork() and exec()
- Each process identifies itself by name and PID in its output
- Exit status values are limited to 0-255 (values ≥ 100 are capped at 100)
- The program showcases parallel computation of different number sequences
- Child processes use exec() to transform into different programs while maintaining the parent-child relationship

## Overview
This project demonstrates process creation and management in C using fork() and exec() system calls. It creates a hierarchy of processes to calculate various number sequences and their sums based on input values from a file. The program showcases inter-process communication, file handling, and parallel computation techniques.

## Files

### Initiator.c
- Serves as the main entry point for the program
- Takes a filename as a command-line argument
- Reads numbers from the file line by line
- For each number, creates two child processes (SpecialNumbers and SequentialNumbers)
- Waits for child processes to complete and reports their exit statuses
- Manages the overall process hierarchy

### SpecialNumbers.c
- Creates two child processes (Prime and Square)
- Passes the input number to each child process
- Waits for child processes to complete and reports their exit statuses

### SequentialNumbers.c
- Creates two child processes (Padovan and Perrin)
- Passes the input number to each child process
- Waits for child processes to complete and reports their exit statuses

### Prime.c
- Calculates the sum of prime numbers up to the input value
- Reports the sum and returns it as exit status (or 100 if sum ≥ 100)

### Square.c
- Calculates the sum of the first n square numbers
- Reports the sum and returns it as exit status (or 100 if sum ≥ 100)

### Padovan.c
- Calculates the sum of the first n numbers in the Padovan sequence
- The Padovan sequence is defined as P(0)=0, P(1)=0, P(2)=1, and P(n)=P(n-2)+P(n-3) for n>2
- Reports the sum and returns it as exit status (or 100 if sum ≥ 100)

### Perrin.c
- Calculates the sum of the first n numbers in the Perrin sequence
- The Perrin sequence is defined as P(0)=3, P(1)=0, P(2)=2, and P(n)=P(n-2)+P(n-3) for n>2
- Reports the sum and returns it as exit status (or 100 if sum ≥ 100)

### Makefile
- Compiles all source files into their respective executables
- Provides targets for building all executables, creating a tarball, and cleaning

## Process Hierarchy
```
Initiator
├── SpecialNumbers
│   ├── Prime
│   └── Square
└── SequentialNumbers
    ├── Padovan
    └── Perrin
```

## How It Works
1. The program reads numbers from an input file specified as a command-line argument
2. For each number in the file:
   - Initiator creates SpecialNumbers and SequentialNumbers processes
   - SpecialNumbers creates Prime and Square processes
   - SequentialNumbers creates Padovan and Perrin processes
   - Each leaf process (Prime, Square, Padovan, Perrin) calculates the sum for its respective sequence
   - Each process returns either the calculated sum or 100 (if sum ≥ 100)
   - Parent processes wait for their children and report their exit statuses

## Usage
```bash
# Compile all executables
make all

# Run with an input file
./Initiator input_file.txt

# Clean up compiled files
make clean

# Create a tarball of the project
make tar
```

## Input File Format
The input file should contain numbers, one per line. Each number will be processed by all the calculation modules.

