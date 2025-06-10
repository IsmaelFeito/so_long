NAME = so_long

SRC =   src/main.c 

RM = rm -rf
CFLAGS = -Werror -Wall -Wextra 

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
	@make fclean -C ${LIBFT_PATH}

fclean: clean
	@${RM} ${NAME} ${LIBFT_PATH}${LIBFT}

re: fclean all
.PHONY: all re clean fclean