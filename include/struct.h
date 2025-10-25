/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:34:21 by nboucher          #+#    #+#             */
/*   Updated: 2025/05/25 18:34:21 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_color
{
	unsigned char		r;
	unsigned char		g;
	unsigned char		b;
}						t_color;

typedef struct s_coor
{
	int					x;
	int					y;
}						t_coor;

typedef struct s_point
{
	double				x;
	double				y;
}						t_point;

typedef struct s_point	t_vector;
typedef struct s_point	t_dist;

typedef struct s_spirits
{
	char				*no;
	char				*so;
	char				*we;
	char				*ea;
	t_color				f;
	t_color				c;
}						t_spirits;

typedef struct s_img
{
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
	t_coor				size;
}						t_img;

typedef struct s_ray
{
	t_vector			dir;
	t_dist				delta;
	t_dist				dist;
	double				final_dist;
	t_point				step;
	float				texture;
	int					x;
	double				x_texture;
}						t_ray;

typedef struct s_player
{
	t_point				pos;
	t_vector			dir;
	t_vector			plan;
}						t_player;

typedef struct s_game
{
	t_player			player;
	char				**map;
	t_spirits			spirits;
}						t_game;

typedef struct s_data
{
	void				*mlx;
	void				*window;
	t_img				textures[4];
	int					colors[2];
	t_img				i_game;
	t_game				game;
	int					display_map;
	int					tile_size;
}						t_data;

typedef struct s_game_info
{
	char				**map;
	t_point				startpos;
	char				startdir;
	t_spirits			spirits;
}						t_game_info;

#endif // !STRUCT_H
