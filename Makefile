EXEC=bones
SRC = game.cpp
CC = clang++

$(EXEC): game.cpp
	$(CC) $(SRC) -o $(EXEC)
