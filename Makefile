NAME_SERVER = server
NAME_CLIENT = client

CLIENT_SRC = srcs/client.c
SERVER_SRC = srcs/server.c
CLIENT_SRC_BONUS = srcs_bonus/client_bonus.c
SERVER_SRC_BONUS = srcs_bonus/server_bonus.c

LIBFT_PATH	= ./incs/libft
LIBFT_NAME	= libft.a
 
DEPS = incs/minitalk.h
DEPS_BONUS = incs/minitalk_bonus.h

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: server client

${LIBFT_PATH}/${LIBFT_NAME}:
	make -C ${LIBFT_PATH}

execs/client: ${LIBFT_PATH}/${LIBFT_NAME} ${CLIENT_SRC} ${DEPS}
	${CC} ${LIBFT_PATH}/${LIBFT_NAME} ${CLIENT_SRC} -o $@

execs/server: ${LIBFT_PATH}/${LIBFT_NAME} ${SERVER_SRC} ${DEPS}
	${CC} ${LIBFT_PATH}/${LIBFT_NAME} ${SERVER_SRC} -o $@

execs/client_bonus: ${LIBFT_PATH}/${LIBFT_NAME} ${CLIENT_SRC_BONUS} ${DEPS_BONUS}
	${CC} ${LIBFT_PATH}/${LIBFT_NAME} ${CLIENT_SRC_BONUS} -o $@

execs/server_bonus: ${LIBFT_PATH}/${LIBFT_NAME} ${SERVER_SRC_BONUS} ${DEPS_BONUS}
	${CC} ${LIBFT_PATH}/${LIBFT_NAME} ${SERVER_SRC_BONUS} -o $@

client: execs/client
	ln -fs execs/client

server: execs/server
	ln -fs execs/server

bonus: execs/client_bonus execs/server_bonus
	ln -fs execs/client_bonus client
	ln -fs execs/server_bonus server

clean:
		rm -rf execs/client execs/server execs/client_bonus execs/server_bonus
		cd $(LIBFT_PATH) && make clean

fclean: clean
		rm -rf ${NAME_CLIENT} ${NAME_SERVER}
		cd $(LIBFT_PATH) && make fclean

re: fclean all

.PHONY: all clean fclean re bonus client server FORCE