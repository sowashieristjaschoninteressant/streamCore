INCLUDE_DIR := ./inc
NAME := streamcore
BIN_DIR := ./bin/
FLAGS := -g -std=c++17 -Wall -o $(BIN_DIR)$(NAME) -I $(INCLUDE_DIR) -fsanitize=address,undefined

all: build

testing:
	mkdir -p $(BIN_DIR)
	g++ ./tests/*.cpp -I $(INCLUDE_DIR) -o $(BIN_DIR)/Tests -Wall -g -std=c++11

clean:
	rm $(BIN_DIR)$(NAME)

build:
	mkdir -p $(BIN_DIR)
	g++ src/*.cpp $(FLAGS)
