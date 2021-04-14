FLAGS = -Wall -g
BIN = bin/prime
CC = gcc

all: build

build: main.c
	$(CC) -o $(BIN) main.c $(FLAGS)

install: build
	cp $(BIN) ~/.local/bin/

test: build
	./$(BIN) 1
	./$(BIN) 100
