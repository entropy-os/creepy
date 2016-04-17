##
## Makefile for creepy in /home/grange_c/creepy/
##
## Made by Benjamin Grange
## Login   <grange_c@epitech.net>
##
## Started on  Fri Apr 15 18:28:26 2016 Benjamin Grange
## Last update Sun Apr 17 18:44:52 2016 Benjamin Grange
##

NAME		:= creepy

CC		:= gcc

SOURCE_DIR	:= ./source/

SRC		:= \
		main.c \

SRCARGUMENTS	:= \
		arguments/arguments_parse_operation.c \
		arguments/arguments_parse.c \
		arguments/arguments_usage.c \
		arguments/arguments_version.c \

SRCUTILS	:= \
		utils/utils_cleanup.c \
		utils/utils_error.c \

SRC		+= $(SRCARGUMENTS) $(SRCUTILS)

CFLAGS		:= -W -Wall -Wextra -Iinclude -g3

SRC		:= $(addprefix $(SOURCE_DIR),$(SRC))

OBJ		:= $(SRC:.c=.o)

RM		:= rm -rf

DEFAULT		:= "\033[00;0m"

GREEN		:= "\033[0;32;1m"

RED		:= "\033[0;31;1m"

CYAN		:= "\033[0;36;1m"


all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $(NAME)
	@echo -e $(CYAN)"Done !"$(DEFAULT)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

%.o: %.c
	@$(CC) -c $< -o $@ $(CFLAGS) && \
		echo -e $(GREEN)"[OK]"$(DEFAULT) $< || \
		echo -e $(RED)"[KO]"$(DEFAULT) $<
