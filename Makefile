NAME_SERVER = server
NAME_CLIENT = client

CLIENT_SRC = srcs/client.c
SERVER_SRC = srcs/server.c
CLIENT_SRC_BONUS = srcs_bonus/client_bonus.c
SERVER_SRC_BONUS = srcs_bonus/server_bonus.c

CLIENT_O = ${CLIENT_SRC:.c=.o}
SERVER_O = ${SERVER_SRC:.c=.o}
CLIENT_O_BONUS = ${CLIENT_SRC_BONUS:.c=.o}
SERVER_O_BONUS = ${SERVER_SRC_BONUS:.c=.o}

LIBFT_PATH	= ./incs/libft
LIBFT_NAME	= libft.a

DEPS = incs/minitalk.h

CC = cc
CFLAGS = -Wall -Wextra -Werror

all:	${SERVER_O} ${CLIENT_O} ${DEPS} 
		make -C ${LIBFT_PATH}
		${CC} ${CFLAGS} ${SERVER_SRC} ${LIBFT_PATH}/${LIBFT_NAME} -o ${NAME_SERVER}
		${CC} ${CFLAGS} ${CLIENT_SRC} ${LIBFT_PATH}/${LIBFT_NAME} -o ${NAME_CLIENT}

bonus:	${SERVER_O_BONUS} ${CLIENT_O_BONUS} ${DEPS}
		make -C ${LIBFT_PATH}
		${CC} ${CFLAGS} ${SERVER_SRC_BONUS} ${LIBFT_PATH}/${LIBFT_NAME} -o ${NAME_SERVER}
		${CC} ${CFLAGS} ${CLIENT_SRC_BONUS} ${LIBFT_PATH}/${LIBFT_NAME} -o ${NAME_CLIENT}

clean:
		rm -rf ${CLIENT_O} ${SERVER_O} ${CLIENT_O_BONUS} ${SERVER_O_BONUS}
		cd $(LIBFT_PATH) && make clean

fclean: clean
		rm -rf ${NAME_CLIENT} ${NAME_SERVER}
		cd $(LIBFT_PATH) && make fclean
re: fclean all

.PHONY: all client server clean fclean re bonus
