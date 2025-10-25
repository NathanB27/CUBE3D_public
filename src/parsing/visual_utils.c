/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:43:03 by nboucher          #+#    #+#             */
/*   Updated: 2025/05/25 18:43:03 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "libft.h"

/**
 * @brief return a ptr to first char different of a space
 *
 * @param ptr of a string
 * @return a ptr of the first char different of a space on success
 */
char	*skip_space(char *str)
{
	if (!str)
		return (NULL);
	while (*str && *str == ' ')
		str++;
	return (str);
}

/**
 * @brief check if the file description don t contain multiple id
 * @param total_elements id we already got @param elements nb of elements
 * @param line new elements checked if new
 * @return 0 on succes
 */
int	check_doublon(int *total_elements, char elements[6][2], char *line)
{
	int	i;

	i = 0;
	line = skip_space(line);
	while (i < *total_elements)
	{
		if (ft_strncmp(line, elements[i], 2) == 0)
			return (1);
		i++;
	}
	ft_strncpy(elements[*total_elements], line, 2);
	(*total_elements)++;
	return (0);
}

/**
	* @brief check that a line is valid: contain and id and one arg of this id 
	* and can be seperated by space
 *
 * @param line line checked
 * @return the id on succces or 0 if line is not valid
 */
int	check_line(char *line)
{
	int	type;

	type = 0;
	skip_space(line);
	if (ft_strncmp(line, NO, 3) == 0 || ft_strncmp(line, SO, 3) == 0
		|| ft_strncmp(line, EA, 3) == 0 || ft_strncmp(line, WE, 3) == 0)
		type = texture;
	else if (ft_strncmp(line, C, 2) == 0 || ft_strncmp(line, F, 2) == 0)
		type = color;
	line = skip_space(line + type);
	if (!line)
		return (0);
	line = ft_strchr(line, ' ');
	while (line && *line)
	{
		if (*line != ' ')
			return (0);
		line++;
	}
	return (type);
}

/**

	* @brief return a new allocated string ending at c char
	* or \0 if c is not present
 *
 * @param str string dup
 * @param c end of new str
 * @return ptr to new allocated string on succes
 */
char	*ft_strcdup(char *str, char c)
{
	char	*new;
	size_t	len;
	size_t	i;

	len = 0;
	if (!str)
		return (NULL);
	while (str[len] && str[len] != c)
		len++;
	new = malloc((len + 1) * sizeof(char));
	i = 0;
	while (len > i)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	if (!new)
		return (NULL);
	return (new);
}
