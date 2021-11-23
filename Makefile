# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/23 16:03:30 by akhalid           #+#    #+#              #
#    Updated: 2021/11/23 16:10:06 by akhalid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

RM = rm -rf

NAME = philo

SRC =	main.c		\
		routine.c	\
		time.c		\
		utils.c		\

IDIR = ./philosophers.h

CFLAGS = -Wall -Wextra -Werror -g

SRCS =	./main.c

OBJDIR = ./objs
OBJS =	$(OBJDIR)/*.o

all:	$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -I $(IDIR) $(OBJS) -o $(NAME)

$(OBJS):	$(SRCS)
			@$(CC) -c $(CFLAGS) $(SRC)
			rm -rf ./objs; mkdir ./objs
			mv *.o $(OBJDIR)

clean:
	$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re:	fclean all

.PHONY:	all, clean, fclean, re