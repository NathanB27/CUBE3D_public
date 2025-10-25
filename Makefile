NAME = cube3D
CC = cc
CFLAGS = -Wall -Werror -Wextra -I./include/ -I./libft_pimped/include/ -I./minilibx -g
MLXFLAGS = -lXext -lX11 -lm -lz

SOURCES_DIR = src/
OBJECTS_DIR = object/

MLX = minilibx/libmlx.a
LIBFT = libft_pimped/libft.a

MAIN = src/main.c
RAYCASTING = dda_utils.c draw_3d.c mlx_utils.c raycasting.c set_raycast.c \
						 init_mlx.c
PARSING = color.c map_init.c other_utils.c parse_main.c visual_utils.c \
file_check.c map_check.c map_utils.c parse_exit.c texture.c
EVENT = event.c exit_prog.c
MOVEMENT = translate_pos.c rotate.c
MINIMAP = draw_map.c perso.c

SOURCES = $(MAIN) \
					$(addprefix $(SOURCES_DIR)raycasting/, $(RAYCASTING)) \
					$(addprefix $(SOURCES_DIR)parsing/, $(PARSING)) \
					$(addprefix $(SOURCES_DIR)event/, $(EVENT)) \
					$(addprefix $(SOURCES_DIR)movement/, $(MOVEMENT)) \
					$(addprefix $(SOURCES_DIR)minimap/, $(MINIMAP))




OBJECTS = $(addprefix $(OBJECTS_DIR), $(notdir $(SOURCES:.c=.o)))

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJECTS)
	$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJECTS) $(MLX) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -j -C libft_pimped

$(MLX):
	make -j -C minilibx

$(OBJECTS_DIR)%.o: $(SOURCES_DIR)raycasting/%.c
	mkdir -p $(OBJECTS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJECTS_DIR)%.o: $(SOURCES_DIR)event/%.c
	mkdir -p $(OBJECTS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJECTS_DIR)%.o: $(SOURCES_DIR)minimap/%.c
	mkdir -p $(OBJECTS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJECTS_DIR)%.o: $(SOURCES_DIR)parsing/%.c
	mkdir -p $(OBJECTS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJECTS_DIR)%.o: $(SOURCES_DIR)movement/%.c
	mkdir -p $(OBJECTS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJECTS_DIR)main.o: $(MAIN)
	mkdir -p $(OBJECTS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C libft_pimped fclean
	rm -rf minilibx/obj
	rm -rf $(MLX)
	rm -rf $(OBJECTS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
