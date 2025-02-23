#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>
#include "libft.h"
#include "mlx.h"

#define WALL '1'
#define FLOOR '0'
#define VOID ' '

#define UP 0
#define DOWN 1
#define RIGHT 2
#define LEFT 3
#define STRAFE_LEFT 4 
#define STRAFE_RIGHT 5

#define TEXTURE_NUM 4

#define COLOR_NUM 2

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define TEXTURE_WIDTH 64
#define TEXTURE_HEIGHT 64

#define NORTH 2
#define SOUTH 3
#define EAST 4
#define WEST 5

#define TEX_NORTH 0
#define TEX_SOUTH 1
#define TEX_EAST 2
#define TEX_WEST 3

#define CORRECT_IDENTIFIER 63

enum e_identifier
{
	MAP_CHAR = -2,
	ERR = -1,
	NO = 1,
	SO = 2,
	WE = 4,
	EA = 8,
	F = 16,
	C = 32
};

typedef struct s_address
{
	char	*address;
	int		endian;
	int		bpp;
	int		size_line;
}	t_address;

typedef struct s_iaddress
{
	int		*address;
	int		endian;
	int		bpp;
	int		size_line;
}	t_iaddress;

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;


typedef struct s_player
{
	t_point position;
	t_point direction;
	t_point camera;
} t_player;

typedef struct s_dimension
{
	int	width;
	int	height;
}	t_dimension;

typedef struct s_map
{
	int	**map;
	t_dimension dimension;
}	t_map;

typedef struct s_textures
{
	char	*texture_path[TEXTURE_NUM];
	void	*texture[TEXTURE_NUM];
	t_iaddress _texture[TEXTURE_NUM];
	int		color[COLOR_NUM];
}	t_textures;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	t_address _img;
} t_mlx;

typedef struct s_cub3d
{
	t_textures	textures;
	t_map		map;
	t_player	player;
	t_mlx		mlx;
}	t_cub3d;

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_draw_params
{
    int     x;              // Coordenada x actual en la pantalla
    int     draw_start;     // Inicio de la columna a dibujar
    int     draw_end;       // Fin de la columna a dibujar
    int     line_height;    // Altura de la columna a dibujar
    double  wall_distance;  // Distancia perpendicular al muro
    int     tex_num;        // Índice de la textura a usar
} t_draw_params;


typedef struct s_raycast
{
	t_point		ray_dir;
	t_point		delta_dist;
	t_point		side_dist;
	t_point		step;
	t_point		wall_tex;
	double		perp_wall_dist;
	int			side_hit;
	t_vector	texture;
	t_vector	 map;
}	t_raycast;

char
	*ft_strdup_len(const char *s, int len);
int
	ft_error(char const *err);
char
	**ft_strdup_double(char **s, char *_new);
char
	**ft_get_file_content(char *file_name);
int
	ft_strlen_double(char **s);
void
	ft_free_double(char **s);
int
	ft_check_name(char const *fmap);
int
	ft_is_map(char c);
int
	check_character(char c);
int
	ft_check_map_char(char **map);
int
	ft_check_file(char **s, char **texture_files);
enum e_identifier
	ft_get_identifier(const char *line);
int
	ft_check_map(char **map);
int
	get_position(char **map, int *x, int *y);
int
	ft_top(char **map, int *x, int *y);
int
	ft_right(char **map, int *x, int *y);
int
	ft_check_map_wall(char **map);
int
	**matomi(char **matrix, int *line);
char
	**get_map(char **file);
int
	parse_texture(enum e_identifier id, char **files, char *texture);
void
	game_start(t_cub3d *cub3d);
char
	*skip_pattern(char *s, char const *follow);
int
	goto_pattern(char const *s, char *skip);
int
	ft_check_file_elements(char **file);
void
	game_start(t_cub3d *cub3d);
void
	cub3d_init(t_cub3d *cub3d, char **file_content);
void
	textures_init(t_textures *textures, char **file_content);
void
	player_init(t_player *player, t_map *map);
void
	my_mlx_init(t_mlx *mlx);
void
	map_init(t_map *map, char **char_map);
void
	load_textures(t_textures *textures, t_mlx *mlx);
void
	get_textures(char **content, t_textures *textures);
enum e_identifier
	ft_identifier(char *line);
void
	ft_up_player(t_cub3d *data, const double moveSpeed);
void
	ft_down_player(t_cub3d *data, const double moveSpeed);
void
	ft_right_player(t_cub3d *data, const double rotSpeed);
void
	ft_left_player(t_cub3d *data, const double rotSpeed);
void
	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
void
	print_floor_ceiling(t_cub3d *data, int color_floor, int color_ceiling);
void
	render_frame(t_cub3d *data);
int
	key_press(int key_code, t_cub3d *data);
int
	parse_color(enum e_identifier id, int *color, char *path);
char
	*get_path(char *line, enum e_identifier *tmp);

int
	floor_not_surround_by_wall(char **map, int x, int y);

int
	void_surronded_by_floor(char **map, int x, int y);

int
	check_collision(t_cub3d *data, double new_x, double new_y);

void
	get_player_direction(t_player *player, int vector);

int
	check_empty_line(char **content);

void
	ft_right_player(t_cub3d *data, const double rotSpeed);

void
	ft_left_player(t_cub3d *data, const double rotSpeed);

void
	ft_strafe_left(t_cub3d *data, const double move_speed);

void
	ft_strafe_right(t_cub3d *data, const double move_speed);

void
	render_frame(t_cub3d *data);

void
	init_dda_params(t_raycast *ray, t_player *player);

void
	set_step_and_side(t_raycast *ray, t_player *player);

void
	perform_dda(t_raycast *ray, t_map *map, int *side);

void
	draw_textured_column(t_cub3d *data, t_raycast *ray, int tex_num, t_draw_params params);

double
	calculate_perp_dis(t_raycast *ray, t_player *player, int side);

double
	safe_divide(double numerator, double denominator);

#endif
