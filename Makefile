# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsarri-c <rsarri-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/14 14:11:06 by rsarri-c          #+#    #+#              #
#    Updated: 2021/09/26 13:06:12 by rsarri-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	./srcs/ft_printf.c ./utils/ft_putchar_fd.c ./utils/ft_strdup.c \
			./utils/ft_strlen.c ./utils/ft_putnbr_fd.c ./utils/ft_strlcpy.c \
			./utils/ft_putunbr.c ./utils/ft_itoh.c ./utils/ft_memcpy.c

OBJS	= $(SRCS:.c=.o)

CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

NAME	= libftprintf.a

all:		$(NAME)

$(NAME):	$(OBJS)
				ar -rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:		clean
				$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re bonus