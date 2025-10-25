/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:21:41 by nboucher          #+#    #+#             */
/*   Updated: 2025/05/27 11:21:41 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "parsing.h"
#include <stdlib.h>

/**
 * @brief sett x and y in t_point struct
 *
 * @param x value for x
 * @param y value for y
 * @param data pointer of t_point
 */
void	set_t_point(int x, int y, t_point *data)
{
	if (!data)
		return ;
	data->x = x;
	data->y = y;
}

/**
 * @brief check if line contain only space
 *
 * @param str line checked
 * @return 0 on sucess
 */
int	is_space(char *str)
{
	if (!str)
		return (1);
	while (*str)
	{
		if (*str != ' ')
			return (1);
		str++;
	}
	return (0);
}

/**
 * @brief check if a char is in a charset
 *
 * @param c char checked
 * @param set charset 
 * @return 1 on succes
 */
int	is_charset(int c, char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

/**
 * @brief check if line is ok for map: containing only map_charset
 *
 * @param str line checked
 * @return 0 on succes
 */
int	map_line_is_ok(char *str)
{
	if (!str)
		return (1);
	while (*str && is_charset(*str, MAP_CHARSET))
		str++;
	if (*str)
		return (1);
	return (0);
}

// check if there is something else than new line in the file
/**
 * @brief check if it s the end of the fd: only new line in the fd
 *
 * @param fd fd checked
 * @param line last gnled line
 * @return NULL if end else a ptr to a line containing something
 */
int	check_end_map(int fd, char *line)
{
	if (!line || fd < 0)
		return (0);
	while (line)
	{
		if (!(*line) || is_space(line) == 0)
		{
			free(line);
			line = gnl_no_nl(fd);
		}
		else
			return (free(line), 1);
	}
	free(line);
	return (0);
}
