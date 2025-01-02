CC = gcc # specifying compiler
CFLAGS = -Wall -std=c99 # compiler flags 
LDFLAGS = -lraylib -lgdi32 -lwinmm

all: main run

main: main.c
	$(CC) $(CFLAGS) main.c $(LDFLAGS) -o main.exe

run: main.exe
	./main.exe

clean:
	rm main.exe
