# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 14:58:05 by ayarmaya          #+#    #+#              #
#    Updated: 2025/04/27 18:58:43 by ayarmaya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

LIBFTNAME	=	libft.a

LIBFT_DIR	=	./libft

SRC		=	ft_printf \
			ft_printhex \
			ft_printint \
			ft_printptr \
			ft_printstr \
			ft_printuint \

SRCS		=	$(addsuffix .c, ${SRC})

OBJS		=	${SRCS:.c=.o}

CC		=	gcc

CFLAGS		=	-Wall -Wextra -Werror

RM		=	rm -f

AR		=	ar crs

%.o: %.c
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

all: ${NAME}

make_libft:
	@make -C ${LIBFT_DIR}
	@cp ${LIBFT_DIR}/${LIBFTNAME} .
	@mv ${LIBFTNAME} ${NAME}

$(NAME): make_libft $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) $(OBJS:.o=.d)  # Supprime .o ET .d
	@cd $(LIBFT_DIR) && make clean

fclean: clean
	$(RM) $(NAME)
	@cd $(LIBFT_DIR) && make fclean

re: fclean all

-include $(OBJS:.o=.d)

.PHONY: all clean fclean re