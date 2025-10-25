/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tle-Prig <tom.leprigent@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:35:11 by Tle-Prig          #+#    #+#             */
/*   Updated: 2024/12/01 12:36:37 by Tle-Prig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	saved_buffer(char *buffer, long long i)
{
	long long	j;

	j = 0;
	while (buffer[i])
		buffer[j++] = buffer[i++];
	buffer[j] = '\0';
	return (0);
}

int	add_to_rtn(char *buffer, char **rtn, long long i, long long *rtn_size)
{
	long long		j;
	long long		k;
	char			*temp;

	j = 0;
	k = 0;
	*rtn_size = (*rtn_size) + i + 2;
	temp = malloc((*rtn_size));
	if (!temp)
	{
		free((*rtn));
		return (0);
	}
	while ((*rtn) && (*rtn)[j])
		temp[j++] = (*rtn)[k++];
	k = 0;
	while (buffer[k] && (i-- >= 0))
		temp[j++] = buffer[k++];
	temp[j] = '\0';
	free((*rtn));
	*rtn = temp;
	return (1);
}

int	no_line(char *buffer, char **rtn, long long *rtn_size)
{
	long long	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			if (add_to_rtn(buffer, rtn, i, rtn_size))
				return (saved_buffer(buffer, i + 1));
			else
			{
				*rtn = NULL;
				return (1);
			}
		}
		i++;
	}
	if (add_to_rtn(buffer, rtn, i, rtn_size))
		return (1);
	*rtn = NULL;
	return (0);
}
