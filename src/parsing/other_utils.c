/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:42:16 by nboucher          #+#    #+#             */
/*   Updated: 2025/05/25 18:42:16 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "get_next_line.h"
#include "parsing.h"

/**
 * @brief gnl but delete the ending \n if exist
 *
 * @param fd readen
 * @return ptr to line read
 */
char	*gnl_no_nl(int fd)
{
	char	*line;
	int		i;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line)
		line[i] = '\0';
	return (line);
}

/**
 * @brief return the len of the longuest string in a tab of strings
 *
 * @param tab of string
 * @return len of string max
 */
int	tab_string_max_len(char **tab)
{
	int	y;
	int	max_x;

	y = 0;
	max_x = 0;
	while (tab && tab[y])
	{
		if ((int)ft_strlen(tab[y]) > max_x)
			max_x = (int)ft_strlen(tab[y]);
		y++;
	}
	return (max_x);
}

/**
 * @brief return the lenght y of tab of string
 *
 * @param tab taba of string
 * @return len y of the string tab
 */
int	tab_string_len_y(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
		i++;
	return (i);
}

/**
 * @brief print a string tab
 *
 * @param tab tab to print
 */
void	print_strings_tab(char **tab)
{
	while (tab && *tab)
		ft_printf("%s\n", *tab++);
}

/**
 * @brief debug function print parsing info
 *
 * @param test sturct of the parsing
 */
void	print_parsing(t_game_info test)
{
	ft_printf("texture we:%s\n", test.spirits.we);
	ft_printf("texture ea:%s\n", test.spirits.ea);
	ft_printf("texture so:%s\n", test.spirits.so);
	ft_printf("texture no:%s\n", test.spirits.no);
	ft_printf("color c.r:%i\n", (int)test.spirits.c.r);
	ft_printf("color c.g:%i\n", (int)test.spirits.c.g);
	ft_printf("color c.b:%i\n", (int)test.spirits.c.b);
	ft_printf("color f.r:%i\n", (int)test.spirits.f.r);
	ft_printf("color f.g:%i\n", (int)test.spirits.f.g);
	ft_printf("color f.b:%i\n", (int)test.spirits.f.b);
	print_strings_tab(test.map);
}
