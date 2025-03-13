CC = gcc

default: all
all: Initiator SpecialNumbers SequentialNumbers Prime Square Padovan Perrin
 

.c.o: 
	$(CC) -o  Initiator.c SpecialNumbers.c SequentialNumbers.c Prime.c Square.c Padovan.c Perrin.c




$(out_exe): $(files)
	$(CC) -o $(out_exe) $(files)

tar:
	tar -cvzf Jaime-Munoz-HW2.tar *.c *.txt Makefile

clean:
	rm -f *.o
