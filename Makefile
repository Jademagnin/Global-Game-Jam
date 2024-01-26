##
## PERSONNAL PROJECT, 2024
## Makefile
## File description:
## Makefile
##

.SILENT:

SHELL   =   /bin/bash

SRC_DIR = engine
SRC = $(wildcard $(SRC_DIR)/*.cpp)

NAME    =   jam

OPROG    =    $(SRC:.cpp=.o)

CFLAGS  =   -g -Wall -Wextra -Wconversion -pedantic -Werror

SFML    =   -lsfml-graphics -lsfml-window -lsfml-system

all: $(NAME)

$(NAME):
    g++ $(CFLAGS) -o $(NAME) $(SRC) $(SFML)
    printf "[%s] — Successfully compiled\n" $(NAME)

clean: