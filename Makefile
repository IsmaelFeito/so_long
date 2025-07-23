# NAME = so_long

# SRC =   src/so_long.c src/utils_so_long.c

# RM = rm -rf
# CFLAGS = -Werror -Wall -Wextra -g3 -g

# CC = cc
# LIBFT = libft.a
# LIBFT_PATH = libft/

# OBJS_S = ${SRC:.c=.o}

# all: ${NAME}

# ${NAME}: ${OBJS_S} ${LIBFT_PATH}${LIBFT}
# 	@${CC} ${CFLAGS} ${OBJS_S} ${LIBFT_PATH}${LIBFT} -o ${NAME}

# ${LIBFT_PATH}${LIBFT}:
# 	@make bonus -C ${LIBFT_PATH} --silent

# clean:
# 	@${RM} ${OBJS_S}
# 	@make clean -C ${LIBFT_PATH}

# fclean: clean
# 	@${RM} ${NAME} ${LIBFT_PATH}${LIBFT} ${LIBFT_PATH}.bonus 

# re: fclean all
# .PHONY: all re clean fclean

NAME = so_long

SRC = 	src/main.c src/utils.c src/cleaning_utils.c \
		src/get_map.c src/moves.c src/renders.c src/validate_map.c
OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -Iincludes -Iminilibx-linux
LDFLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm -lbsd

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) $(LIBFT) $(LDFLAGS) -o $@
	@echo "✅ Compilación exitosa!"

$(LIBFT):
	@make -C libft --no-print-directory

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@make clean -C libft --no-print-directory

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft --no-print-directory

re: fclean all

.PHONY: all clean fclean re