/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:43:15 by nboucher          #+#    #+#             */
/*   Updated: 2025/05/25 18:43:15 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"

/**
 * @brief check that the format rgb is good 
 *
 * @param line line checked
 * @return 0 on success
 */
int	check_format_rgb(char *line)
{
	int	j;
	int	color_element;

	line = skip_space(skip_space(line) + 1);
	if (!ft_isdigit(*line))
		return (1);
	color_element = 0;
	j = 0;
	while (*line && (ft_isdigit(*line) || *line == ','))
	{
		if (*line == ',')
		{
			if (!(*line) || !ft_isdigit(*(line + 1)) || ft_atoi(line - j) > 255)
				return (1);
			color_element++;
			j = 0;
		}
		else
			j++;
		if (j > 3)
			return (1);
		line++;
	}
	return (!(color_element == 2));
}

/**

	* @brief checked the line and set it at floor or celling
	* (if no doublon and color format ok)
 *
 * @param total_elements tab of id already traited
 * @param elements nb of id already traided
 * @param line current line with the id
 * @param game_info struct filled with the info
 * @return 0 on succes
 */
int	set_color(int *total_elements, char elements[6][2], char *line,
		t_game_info *game_info)
{
	t_color	*element;
	char	*temp;

	if (check_doublon(total_elements, elements, line) || check_format_rgb(line))
		return (1);
	line = skip_space(line);
	if (*line == 'F')
		element = &(game_info->spirits.f);
	else
		element = &(game_info->spirits.c);
	line++;
	line = skip_space(line);
	element->r = (char)ft_atoi(line);
	temp = ft_strchr(line, ',');
	element->g = (char)ft_atoi(++temp);
	temp = ft_strchr(temp, ',');
	element->b = (char)ft_atoi(++temp);
	return (0);
}
