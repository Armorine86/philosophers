# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/31 08:51:26 by mmondell          #+#    #+#              #
#    Updated: 2021/09/09 09:43:01 by mmondell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#*#######################################################
##*          ERASE COMMENTS FOR BONUS PARTS            ##
#*#######################################################

## -----  NAME OF THE PROGRAMM ----- ##
NAME 			= philosopher

## ----- NAME OF THE BONUS PART ----- ##
#*B_NAME			= 

## ----- CHOOSE COMPILER AND FLAGS ----- ##
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -g

## ----- PATH TO FOLDERS ----- ##
SRCS_DIR		= srcs/
#*B_SRCS_DIR		= 

OBJ_DIR			= obj/

INCLUDE_DIR		= include/

UTIL_DIR		= utility_functions/

## ----- SOURCE FILES ----- ##
SRCS_FILES		= philosophers.c init_philos.c utils.c meal_routine.c

UTIL_FILES		= ft_atoi.c ft_putchar_fd.c ft_putstr_fd.c ft_split.c ft_calloc.c ft_memset.c \
				  ft_strlcpy.c ft_strlen.c ft_isdigit.c
## ----- BONUS SOURCE FILES ----- ##
#*B_SRCS_FILES	= 

## ----- .C TO .O CONVERT ----- ##
OBJ_FILES		= $(SRCS_FILES:.c=.o) $(UTIL_FILES:.c=.o)
#*B_OBJ_FILES		= $(B_SRCS_FILES:.c=.o)

## ----- ADDPREFIX TO FILES ----- ##
# MAIN PROGRAMM #
SRCS			= $(addprefix $(SRCS_DIR), $(SRCS_FILES))
UTILS			= $(addprefix $(UTIL_DIR), $(UTIL_FILES))
OBJS			= $(addprefix $(OBJ_DIR), $(OBJ_FILES))
VPATH			= $(SRCS_DIR) $(UTIL_DIR) #$(B_SRCS_DIR)

# BONUS PART #
#*B_SRCS			= $(addprefix $(B_SRCS_DIR), $(B_SRCS_FILES))
#*B_OBJS			= $(addprefix $(OBJ_DIR), $(B_OBJ_FILES))

#--------------------------------------------------------------#

## ----- TOOLS AND COLORS ----- ##
RM				= rm -Rf
NO_PRINT		= --no-print-directory
RED 			= \033[31m
GREEN 			= \033[32m
YELLOW 			= \033[33m
BLUE 			= \033[34m
PINK 			= \033[35m
AQUA 			= \033[36m
GREY 			= \033[37m
UNDERLINE 		= \033[4m
NORMAL 			= \033[0m

#LIBFT			= $(MAKE) bonus -C $(LIBFT_DIR)

## ----- ALL ACTION DEPENDENCIES AND RECIPE FOR MAIN PROGRAM ----- ##
all: obj $(NAME)
	@echo "$(GREEN)Compilation Completed Successfully$(NORMAL)"

$(OBJ_DIR)%.o:%.c
	$(CC) $(CFLAGS) -I$(UTIL_DIR) -I$(INCLUDE_DIR) -o $@ -c $<

$(NAME): $(OBJS)
	$(CC) $(OBJS) -lpthread -o $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)

## ----- ACTIONS FOR THE BONUS PART ----- ##
#*bonus: $(B_NAME)
#*	@echo "$(GREEN)Bonus Files Compiled!$(NORMAL)"
#*
#*$(B_NAME): $(B_OBJS)
#*	$(LIBFT)
#*	$(CC) $(B_OBJS) -L$(LIBFT_DIR) -lft -o $(B_NAME)
	
## ----- CLEAN COMMANDS ----- ##
clean:
	$(RM) $(OBJS) $(B_OBJS)

fclean: clean
	@rm -rf $(NAME) $(OBJ_DIR)
#*	$(RM) $(B_NAME) $(OBJ_DIR)


re: fclean all #bonus

.PHONY: all clean fclean re