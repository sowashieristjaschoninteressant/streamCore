
INCLUDE_DIR := ./inc
NAME := streamcore
BIN_DIR := ./bin/
FLAGS := -g -std=c++17 -Wall -o $(BIN_DIR)$(NAME) -I $(INCLUDE_DIR)



all: build

testing:
	g++ ./tests/*.cpp -I $(INCLUDE_DIR) -o $(BIN_DIR)/Tests -Wall -g -std=c++11

clean:
	rm $(NAME)

build: 
	g++ src/*.cpp $(FLAGS)