NAME := cub3D
CFLAGS := -Wall -Wextra -Werror
#CFLAGS += -fsanitize=address -g3
HEADER := -Iincludes -Imlx -Ilibft

LIB := -Llibft -lft -lm -Lmlx -lmlx -lXext -lX11 
SRCS = src/main.c\
	   src/error/error.c\
	   src/raycast/raycast.c src/raycast/dda.c src/raycast/rendering.c src/raycast/wall_distance.c\
	   src/movement/player_movement.c src/movement/player_rotate.c\
	   src/utils/identifier_utils.c src/utils/check_map.c src/utils/check_wall.c\
	   src/utils/parse_color.c src/utils/check_file_elements.c src/utils/init.c src/utils/libft_utils.c\
	   src/utils/map_utils.c src/utils/mlx_utils.c src/utils/player_utils.c\
	   src/utils/start_game.c src/utils/parse_textures.c src/utils/void.c src/utils/wall.c src/utils/check_character.c

OBJS := ${SRCS:c=o}

.PHONY: all
all: ${NAME}

${NAME} : $(OBJS)
	cd mlx && make
	cd libft && make
	$(CC) -o $@ $(CFLAGS) $^ $(LIB) $(HEADER)
	
.PHONY: clean
clean:
	cd libft && make clean
	$(RM) $(OBJS)

.PHONY: fclean
fclean:
	cd libft && make fclean
	cd mlx && make clean
	$(RM) $(OBJS) $(NAME)

.PHONY: re
re: fclean all

%.o: %.c
	${CC} ${CFLAGS} ${HEADER} -c -o $@ $<
