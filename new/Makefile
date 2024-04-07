NAME_SERVER = server
NAME_CLIENT = client

CLIENT_SRC = srcs/client.c
SERVER_SRC = srcs/server.c
CLIENT_SRC_BONUS = srcs_bonus/client_bonus.c
SERVER_SRC_BONUS = srcs_bonus/server_bonus.c

LIBFT_PATH	= ./incs/libft
LIBFT_NAME	= libft.a

DEPS = incs/minitalk.h

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: server client

FORCE :

incs/libft/libft.a : FORCE
	make -C incs/libft

all : server client

executables/client : incs/libft/libft.a srcs/server.c ${DEPS}
	cc incs/libft/libft.a srcs/server.c -o $@

executables/server : incs/libft/libft.a srcs/client.c ${DEPS}
	cc incs/libft/libft.a srcs/client.c -o $@

executables/client_bonus : incs/libft/libft.a srcs_bonus/server_bonus.c ${DEPS}
	cc incs/libft/libft.a srcs_bonus/server_bonus.c -o $@

executables/server_bonus : incs/libft/libft.a srcs_bonus/client_bonus.c ${DEPS}
	cc incs/libft/libft.a srcs_bonus/client_bonus.c -o $@

client : executables/client
	ln -fs executables/client

server : executables/server
	ln -fs executables/server

bonus: executables/client_bonus executables/server_bonus
	ln -fs executables/client_bonus client
	ln -fs executables/server_bonus server

clean:
		rm -rf $(addprefix executables/, client server client_bonus server_bonus)
		cd $(LIBFT_PATH) && make clean

fclean: clean
		rm -rf ${NAME_CLIENT} ${NAME_SERVER}
		cd $(LIBFT_PATH) && make fclean
re: fclean all

.PHONY: all clean fclean re bonus client server
