# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/07 13:43:15 by mleblanc          #+#    #+#              #
#    Updated: 2021/05/18 14:48:25 by mleblanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c $\
			ft_memchr.c ft_memcmp.c ft_strlen.c ft_isalpha.c ft_isdigit.c $\
			ft_isalnum.c ft_isascii.c ft_isprint.c ft_isupper.c ft_islower.c $\
			ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c $\
			ft_strlcpy.c ft_strnlen.c ft_strlcat.c ft_strnstr.c ft_isspace.c $\
			ft_atoi.c ft_strdup.c ft_calloc.c ft_substr.c ft_strjoin.c $\
			ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c $\
			ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_itoa_base.c $\
			ft_utoa_base.c ft_utoa.c ft_ptoa_base.c ft_ptoa.c ft_ltoa.c $\
			ft_ltoa_base.c ft_ultoa_base.c ft_ultoa.c
OBJS	=	$(SRCS:.c=.o)
B_SRCS	=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c $\
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c $\
			ft_lstmap.c
BONUS	=	$(B_SRCS:.c=.o)
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

norme:
			norminette $(SRCS) $(B_SRCS) libft.h

all:		$(NAME)

clean:
			$(RM) $(OBJS) $(BONUS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus norme