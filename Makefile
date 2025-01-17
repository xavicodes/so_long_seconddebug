# Nome do compilador
CC = cc

# Flags de compilação
CFLAGS = -Wall -Wextra -Werror

# Nome do executável final
NAME = so_long

# Diretórios das bibliotecas
LIBFT_DIR = libft
MLX_DIR = mlx-linux  # Diretório correto da MiniLibX

# Arquivos de cabeçalho
INCLUDES = -I$(LIBFT_DIR) -I$(MLX_DIR)

# Arquivos fonte e objeto
SRC = gameplay.c draw.c new_map.c map_utils.c map_letters.c so_long.c clean.c init_stuff.c
OBJ = $(SRC:.c=.o)

# Nome das bibliotecas e caminhos
LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx_Linux.a  # Usando o nome genérico da biblioteca
MLXFLAGS = -L mlx-linux/ -lmlx -lXext -lX11

# Alvo padrão
all: $(NAME)

# Compilar o executável
$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -L$(MLX_DIR) $(MLXFLAGS) -lm -lz -o $(NAME)

# Compilar o objeto
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -O3 -c $< -o $@

# Limpar arquivos objeto
clean:
	rm -f $(OBJ)

# Limpar arquivos objeto e o executável
fclean: clean
	rm -f $(NAME)

# Reconstruir tudo
re: fclean all

# Incluir as bibliotecas (compilá-las se necessário)
$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX):
	make -C $(MLX_DIR)

.PHONY: all clean fclean re
