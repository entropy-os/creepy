##
## Makefile for creepy in /home/grange_c/creepy/
##
## Made by Benjamin Grange
## Login   <grange_c@epitech.net>
##
## Started on  Fri Apr 15 18:28:26 2016 Benjamin Grange
## Last update Sun Apr 24 03:27:57 2016 Benjamin Grange
##

#
# Paths
#
NAME		:= creepy
SRCDIR		:= ./source/
INCDIR		:= ./include/

#
# Compilation & link options
#
CC		:= cc
CFLAGS		:= -W -Wall -Wextra -pedantic -I $(INCDIR) -std=c99 -g3
LDLIBS		:= -lcurl

#
# Misc
#
RM		:= rm -rf
DEFAULT		:= "\033[00;0m"
GREEN		:= "\033[0;32;1m"
RED		:= "\033[0;31;1m"
CYAN		:= "\033[0;36;1m"

#
# Sources
#
SRC		:= \
		init.c \
		main.c \

SRC_OPERATION	:= \
		operation/list/operation_list.c \
		operation/remove/operation_remove.c \
		operation/sync/operation_sync_refresh.c \
		operation/sync/operation_sync.c \

SRC_ARGUMENTS	:= \
		arguments/arguments_needs_root.c \
		arguments/arguments_parse_operation.c \
		arguments/arguments_parse_sync.c \
		arguments/arguments_parse.c \
		arguments/arguments_usage.c \
		arguments/arguments_version.c \

REPOSITORY	:= \
		repository/repository_main_dir.c \

DOWNLOAD	:= \
		download/download_file.c \

SRC_UTILS	:= \
		utils/utils_cleanup.c \
		utils/utils_error.c \


SRC		+= $(SRC_ARGUMENTS) $(SRC_UTILS) $(SRC_OPERATION)
SRC		+= $(DOWNLOAD) $(REPOSITORY)
SRC		:= $(addprefix $(SRCDIR),$(SRC))
OBJ		:= $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LDLIBS)
	echo -e $(CYAN)"Done !"$(DEFAULT)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

%.o: %.c
	@$(CC) -c $< -o $@ $(CFLAGS) && \
		echo -e $(GREEN)"[OK]"$(DEFAULT) $< || \
		echo -e $(RED)"[KO]"$(DEFAULT) $<

.PHONY:	all clean fclean re

.SILENT: $(NAME) clean fclean
