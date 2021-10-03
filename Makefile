# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/23 19:42:48 by rbourgea          #+#    #+#              #
#    Updated: 2021/10/03 14:12:44 by dgoudet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	webserv

SRCS	=	parser.cpp \
			webserv.cpp \
			CGIget.cpp

OBJS	=	$(SRCS:.cpp=.o)

CC		=	g++

#On VM, function "ifstream" of parser.cpp only compiles with c++11 flag
CFLAGS	=	-Wall -Werror -Wextra -std=c++11 -fsanitize=address -g
#CFLAGS = -Wall -Werror -Wextra -std=c++98 -fsanitize=address -g

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $@

%.o: %.cpp
			$(CC) $(CFLAGS) -o $@ -c $<

clean:
			rm -f $(OBJS)

fclean: 	clean
			rm -f $(NAME)

re: 		fclean all

.PHONY: 	clean all fclean re
