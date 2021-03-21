FLAGS = -Wall
BIN = bin/prime
CC = gcc
all: run

build: main.c
	$(CC) -o $(BIN) main.c $(FLAGS)

install: build
	cp $(BIN) ~/.local/bin/

run: build
	./$(BIN) 1
	./$(BIN) 2
	./$(BIN) 3
	./$(BIN) 4
	./$(BIN) 5
	./$(BIN) 100
