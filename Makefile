SRCS_CLIENT	=	client.c

SRCS_SERVER	=	server.c

SRCS_CLIENT_BONUS	=	client_bonus.c

SRCS_SERVER_BONUS	=	server_bonus.c

OBJS_CLIENT	=	${SRCS_CLIENT:.c=.o}

OBJS_SERVER	=	${SRCS_SERVER:.c=.o}

OBJS_CLIENT_BONUS	=	${SRCS_CLIENT_BONUS:.c=.o}

OBJS_SERVER_BONUS	=	${SRCS_SERVER_BONUS:.c=.o}

SERVER		=	server

CLIENT		=	client

LIBFT_DIR	=	./libft

LIBFT		=	${LIBFT_DIR}/libft.a

CCFLAGS		=	cc -Wall -Werror -Wextra -g3

all			:	${SERVER} ${CLIENT}

%.o			:	%.c
			${CCFLAGS} -c $< -o $@

${LIBFT}	:
			make -C ${LIBFT_DIR}

${SERVER} ${CLIENT}: ${OBJS_SERVER} ${OBJS_CLIENT} ${LIBFT}
			${CCFLAGS} ${OBJS_SERVER} libft/libft.a -o ${SERVER}
			${CCFLAGS} ${OBJS_CLIENT} libft/libft.a -o ${CLIENT}

bonus		:	${OBJS_SERVER_BONUS} ${OBJS_CLIENT_BONUS} ${LIBFT}
			${CCFLAGS} ${OBJS_SERVER_BONUS} libft/libft.a -o ${SERVER}
			${CCFLAGS} ${OBJS_CLIENT_BONUS} libft/libft.a -o ${CLIENT}

clean		:
			rm -f ${OBJS_SERVER} ${OBJS_CLIENT} ${OBJS_SERVER_BONUS} ${OBJS_CLIENT_BONUS}
			make -C ${LIBFT_DIR} clean

fclean		:	clean
			${MAKE} fclean -C ./libft
			rm -rf ${SERVER} ${CLIENT}

re			:	fclean all

.PHONY		: 	all clean fclean re