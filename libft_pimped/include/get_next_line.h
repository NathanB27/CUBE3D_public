/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tle-Prig <tom.leprigent@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:29:44 by Tle-Prig          #+#    #+#             */
/*   Updated: 2024/12/01 12:38:18 by Tle-Prig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

// return the first line of a given fd
char	*get_next_line(int fd);

// UTILS
int		add_to_rtn(char *buffer, char **rtn, long long i, long long *rtn_size);
int		saved_buffer(char *buffer, long long i);
int		no_line(char *buffer, char **rtn, long long *rtn_size);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#endif
