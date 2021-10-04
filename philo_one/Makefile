# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdenys <mdenys@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/18 21:18:31 by mdenys            #+#    #+#              #
#    Updated: 2021/05/24 18:22:39 by mdenys           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:			all clean fclean re

SRCS			=	main.c utilc.c parser.c logic.c logic_cycle.c messages.c prepare_simulation.c old_utilc.c time.c checker.c


SRC_DIR = ./srcs/
OBJ_DIR = ./obj/

OBJS			= $(SRCS:%.c=%.o)

OBJS_FILES = $(addprefix $(OBJ_DIR), $(OBJS))

HEADER = philo_header.h

vpath %.h includes
vpath %.o $(OBJ_DIR)
vpath %.c $(SRC_DIR)

CC				= gcc
RM				= rm -f
CFLAGS			= -O1 -Wall -Wextra -Werror -I  ./includes/

NAME			= philo_one

all:	$(OBJ_DIR) $(NAME)

norme :
	norminette  $(addprefix $(SRC_DIR), $(SRCS))

$(OBJ_DIR):
	mkdir -p obj

$(NAME):		$(OBJS_FILES)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS_FILES) -lpthread

clean:
				$(RM) $(OBJS_FILES)

$(OBJ_DIR)%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $<  -o $@

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)
