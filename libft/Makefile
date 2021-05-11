# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/07 13:43:15 by mleblanc          #+#    #+#              #
#    Updated: 2021/05/07 18:24:30 by mleblanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS	=	ft_memset.o ft_bzero.o ft_memcpy.o ft_memccpy.o ft_memmove.o $\
			ft_memchr.o ft_memcmp.o ft_strlen.o ft_isalpha.o ft_isdigit.o $\
			ft_isalnum.o ft_isascii.o ft_isprint.o ft_isupper.o ft_islower.o $\
			ft_toupper.o ft_tolower.o ft_strchr.o ft_strrchr.o ft_strncmp.o $\
			ft_strlcpy.o ft_strnlen.o ft_strlcat.o ft_strnstr.o ft_isspace.o $\
			ft_atoi.o ft_strdup.o ft_calloc.o ft_substr.o ft_strjoin.o $\
			ft_strtrim.o ft_split.o ft_itoa.o ft_strmapi.o ft_putchar_fd.o $\
			ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o
BONUS	=	ft_lstnew.o ft_lstadd_front.o ft_lstsize.o ft_lstlast.o $\
			ft_lstadd_back.o ft_lstdelone.o ft_lstclear.o ft_lstiter.o $\
			ft_lstmap.o
NAME	=	libft.a
CC		=	clang
LIBC	=	ar rcs
CFLAGS	=	-Wall -Werror -Wextra
RM		=	rm -rf

%.o:		%.c
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
			$(LIBC) $(NAME) $(OBJS)

bonus:		$(OBJS) $(BONUS)
			$(LIBC) $(NAME) $(OBJS) $(BONUS)

all:		$(NAME)

clean:
			$(RM) $(OBJS) $(BONUS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus