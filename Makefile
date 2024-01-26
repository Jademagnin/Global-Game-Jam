##
## EPITECH PROJECT, 2024
## PGD_02
## File description:
## Makefile
##

NAME = jam
CC = g++
SRC_DIR = ./src

SRC = $(wildcard $(SRC_DIR)/*.cpp $(SRC_DIR)/*/*.cpp $(SRC_DIR)/*/*/*.cpp \
	$(SRC_DIR)/*/*/*/*.cpp $(SRC_DIR)/*/*/*/*/*.cpp $(SRC_DIR)/*/*/*/*/*/*.cpp)

OBJ	= $(SRC:.cpp=.o)
CFLAGS = -Wall -Wextra -Werror -I ./include -std=c++20\
	-Wno-unused-variable -Wno-unused-parameter -lsfml-graphics -lsfml-window -lsfml-system

all: $(OBJ) $(NAME)
$(NAME):
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

debug:
	$(CC) -o $(NAME) $(SRC) $(CFLAGS) -g

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

cstyle:
	make fclean
	cstyle

.PHONY:
	all clean fclean re cstyle debug
