# Makefile for signals lab

all: signal1 signal2 timer

signal1: signal1.c
	gcc -Wall -std=c99 -g signal1.c -o signal1

signal2: signal2.c
	gcc -Wall -std=c99 -g signal2.c -o signal2

timer: timer.c
	gcc -Wall -std=c99 -g timer.c -o timer

clean:
	rm -f signal1 signal2 timer
