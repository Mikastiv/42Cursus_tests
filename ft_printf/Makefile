# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/14 19:00:56 by mleblanc          #+#    #+#              #
#    Updated: 2021/05/22 18:30:47 by mleblanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
LIBFT		=	libft/libft.a
MAKELIBFT	=	$(MAKE) -C libft

SRC			=	src
INC			=	include
LIBFT_INC	=	libft
CFILES		=	ft_printf.c do_printf.c convert.c convert_char.c convert_str.c\
				utils.c convert_ptr.c convert_percent.c convert_int.c\
				convert_uint.c convert_num_utils.c
HFILES		=	$(CFILES:.c=.h)
SRCS		=	$(addprefix $(SRC)/, $(CFILES))
OBJS		=	$(SRCS:.c=.o)

CC			=	clang
LIBC		=	ar rcs
CFLAGS		=	-Wall -Werror -Wextra

RM			=	rm -rf
CP			=	cp
NORMINETTE	=	norminette


$(SRC)/%.o:	$(SRC)/%.c
			$(CC) $(CFLAGS) -c $< -o $@ -I$(INC) -I$(LIBFT_INC)

$(NAME):	$(OBJS)
			$(MAKELIBFT) bonus
			$(CP) $(LIBFT) $(NAME)
			$(LIBC) $(NAME) $(OBJS)

norme:
			$(MAKELIBFT) norme
			$(NORMINETTE) $(SRCS) $(addprefix $(INC)/, $(HFILES))

all:		$(NAME)

clean:
			$(MAKELIBFT) clean
			$(RM) $(OBJS)

fclean:		clean
			$(MAKELIBFT) fclean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re norme