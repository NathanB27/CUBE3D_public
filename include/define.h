/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:21:52 by nboucher          #+#    #+#             */
/*   Updated: 2025/05/25 18:21:52 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

// raycasting

# define _N -1
# define _S 1
# define _W 2
# define _E -2

// Windows

# define WIDTH 1000
# define HEIGHT 1000
# define FOV 53

// dir

# define W 'W'
# define E 'E'
# define N 'N'
# define S 'S'

//  event
# define ESC_KEY 65307
# define LEFT_KEY 65361
# define RIGHT_KEY 65363
# define UP_KEY 65362
# define DOWN_KEY 65364

// const movement
# define TRANSLATE_SPEED 0.3
# define THETA 0.1

/// parsing

# define EXT_MAPDESC ".cub"
# define NO "NO "
# define SO "SO "
# define WE "WE "
# define EA "EA "
# define F "F "
# define C "C "
# define MAP_CHARSET " 10NSWE"
# define MAP_CHARSET_NO_SPACE "10NSWE"
# define MAP_FLOOR "0NSWE"
# define MAP_PLAYER "NSWE"
# define MAP_WALL '1'
# define MAP_VOID ' '

enum
{
	color = 1,
	texture = 2,
};

/// touche clavier

# define KEY_W 119
# define KEY_P 112
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

enum
{
	RIGHT = 1,
	LEFT = 2,
	UP = 3,
	DOWN = 2,
};

#endif // !DEFINE_H
