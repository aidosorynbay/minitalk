SRCS		=	client.c server.c

OBJS		=	${SRCS:.c=.o}

NAME		=	minitalk

LIBFT_DIR	=	./libft

LIBFT		=	${LIBFT_DIR}/libft.a

CC			=	cc

CFLAGS		=	-Wall -Werror -Wextra -g3

all			:	${NAME}

%.o			:	%.c
			${CC} ${CFLAGS} -c $< -o $@

${LIBFT}	:
			make -C ${LIBFT_DIR}

${NAME}		:	${LIBFT} ${OBJS}
			${CC} ${CFLAGS} -I ${LIBFT_DIR} ${OBJS} ${LIBFT} -o ${NAME}

clean		:
			rm -f &{OBJS}
			make -C ${LIBFT_DIR} clean

fclean		:	clean
			rm -f ${NAME}
			make -C {LIBFT_DIR} fclean

re			:	fclean all

.PHONY		: 	all clean fclean re