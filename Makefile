##
## Makefile for creepy in /home/grange_c/creepy/
##
## Made by Benjamin Grange
## Login   <grange_c@epitech.net>
##
## Started on  Fri Apr 15 18:28:26 2016 Benjamin Grange
## Last update Sun Apr 17 22:25:43 2016 Benjamin Grange
##

NAME		:= creepy

CC		:= gcc

SOURCE_DIR	:= ./source/

SRC		:= \
		main.c \

SRC_OPERATION	:= \
		operation/list/operation_list.c \
		operation/remove/operation_remove.c \
		operation/sync/operation_sync.c \

SRC_ARGUMENTS	:= \
		arguments/arguments_needs_root.c \
		arguments/arguments_parse_operation.c \
		arguments/arguments_parse.c \
		arguments/arguments_usage.c \
		arguments/arguments_version.c \

SRC_UTILS	:= \
		utils/utils_cleanup.c \
		utils/utils_error.c \


SRC		+= $(SRC_ARGUMENTS) $(SRC_UTILS) $(SRC_OPERATION)

SRC		:= $(addprefix $(SOURCE_DIR),$(SRC))

OBJ		:= $(SRC:.c=.o)

CFLAGS		:= -W -Wall -Wextra -Iinclude -std=c99 -g3

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
