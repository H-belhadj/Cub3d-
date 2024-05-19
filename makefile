NAME = cub3D

LIBFT = lib/libft.a

CFLAGS = -Wall -Wextra -Werror -I includes #-Werror / #-fsanitize=address -g

CC = cc

HEADERS = head.h

MLX42 = mlx/build/libmlx42.a

#GLFW = $(shell brew --prefix glfw)

#DEPS = -framework Cocoa -framework OpenGL -framework IOKit -lglfw -L"$(GLFW)/lib"

SRCS = main.c \
	lib/get_next_line.c \
	lib/get_next_line_utils.c \
	parsing/check_identity.c \
	parsing/space_handler.c \
	parsing/utils.c \
	parsing/utils_2.c \
	parsing/get_path.c \
	parsing/get_color.c \
	parsing/color.c \
	parsing/parse.c \
	parsing/helpers.c \



OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS) $(LIBFT) 
	@$(CC) $(CFLAGS) $(OBJS) $(MLX42) -o $(NAME) $(LIBFT) 
	@echo "Compilation done"

$(LIBFT):
	@make all -C libft

clean:
	@rm -f $(OBJS)
	@echo "Cleaning done"

fclean: clean
	@rm -f $(NAME) 
	@echo "Full cleaning done"

re: fclean all

# to be deleted
run: all
	@./cub3D maps/1.cub

test: test.c 
	@$(CC)  test.c -fsanitize=address -g -o test $(D`EPS) && ./test
	@echo "Compilation done"