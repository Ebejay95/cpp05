# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/25 09:18:57 by jeberle           #+#    #+#              #
#    Updated: 2024/11/26 13:29:02 by jeberle          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------------------------------------------------------------------------#
#--------------                       PRINT                       -------------#
#------------------------------------------------------------------------------#

BLACK := \033[90m
RED := \033[31m
G := \033[32m
Y := \033[33m
B := \033[34m
M := \033[35m
CYAN := \033[36m
X := \033[0m

SUCCESS := \n\
\n\
███████  ███████  ███████   █████    ███████\n\
█        █     █  █     █  █    ██   █      \n\
█        ███████  ███████  █  █  █   ██████ \n\
█        █        █        ██    █         █\n\
███████  █        █         █████    ██████ \n\
\n\
Form up, maggots!\n\
\n\

#------------------------------------------------------------------------------#
#--------------                      GENERAL                      -------------#
#------------------------------------------------------------------------------#

NAME=form_up_maggots

#------------------------------------------------------------------------------#
#--------------                       FLAGS                       -------------#
#------------------------------------------------------------------------------#

CC=c++
CFLAGS=-Wall -Wextra -Werror -Wshadow -std=c++98
LDFLAGS=

ifeq ($(DEBUG), 1)
	CFLAGS += -fsanitize=address -g
endif

DEPFLAGS=-MMD -MP

#------------------------------------------------------------------------------#
#--------------                        DIR                        -------------#
#------------------------------------------------------------------------------#

OBJ_DIR := ./obj
DEP_DIR := $(OBJ_DIR)/.deps
INC_DIRS := .
SRC_DIRS := .

vpath %.cpp $(SRC_DIRS)
vpath %.h $(INC_DIRS)
vpath %.d $(DEP_DIR)

#------------------------------------------------------------------------------#
#--------------                        SRC                        -------------#
#------------------------------------------------------------------------------#

SRCS=	main.cpp \
		Bureaucrat.cpp \
		Form.cpp

#------------------------------------------------------------------------------#
#--------------                      OBJECTS                      -------------#
#------------------------------------------------------------------------------#

OBJECTS := $(addprefix $(OBJ_DIR)/, $(SRCS:%.cpp=%.o))

#------------------------------------------------------------------------------#
#--------------                      COMPILE                      -------------#
#------------------------------------------------------------------------------#

.PHONY: all clean fclean re

all: $(NAME)

-include $(OBJECTS:.o=.d)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	@$(CC) -o $@ $^ $(LDFLAGS)
	@echo "$(SUCCESS)"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)objects deleted$(X)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)binaries deleted$(X)"

re: fclean all
