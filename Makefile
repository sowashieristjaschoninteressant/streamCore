
INCLUDE_DIR := ./inc
NAME := streamcore
FLAGS := -g -std=c++11 -Wall -o $(NAME) -I $(INCLUDE_DIR)

all: build

clean:
	rm $(NAME)

build: 
	g++ src/*.cpp $(FLAGS)