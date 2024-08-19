SRCS_CLIENT	=	client.c

SRCS_SERVER	=	server.c

OBJS_CLIENT	=	${SRCS_CLIENT:.c=.o}

OBJS_SERVER	=	${SRCS_SERVER:.c=.o}

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

clean		:
			rm -f ${OBJS_SERVER} ${OBJS_CLIENT}
			make -C ${LIBFT_DIR} clean

fclean		:	clean
			$(MAKE) fclean -C ./libft
			rm -rf $(SERVER) $(CLIENT)

re			:	fclean all

.PHONY		: 	all clean fclean re