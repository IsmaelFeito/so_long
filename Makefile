NAME = so_long

SRC =   src/main.c src/utils_so_long.c

RM = rm -rf
CFLAGS = -Werror -Wall -Wextra -g3 -g

CC = cc
LIBFT = libft.a
LIBFT_PATH = libft/

OBJS_S = ${SRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJS_S} ${LIBFT_PATH}${LIBFT}
	@${CC} ${CFLAGS} ${OBJS_S} ${LIBFT_PATH}${LIBFT} -o ${NAME}

${LIBFT_PATH}${LIBFT}:
	@make bonus -C ${LIBFT_PATH} --silent

clean:
	@${RM} ${OBJS_S}
	@make clean -C ${LIBFT_PATH}

fclean: clean
	@${RM} ${NAME} ${LIBFT_PATH}${LIBFT} ${LIBFT_PATH}.bonus 

re: fclean all
.PHONY: all re clean fclean