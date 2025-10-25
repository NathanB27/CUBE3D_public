/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:19:57 by nboucher          #+#    #+#             */
/*   Updated: 2025/05/27 11:19:57 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "struct.h"

// General
//
void	exit_parsing(char *message, t_game_info game_info, int fd);
char	*gnl_no_nl(int fd);
void	print_parsing(t_game_info test);
void	print_strings_tab(char **tab);

// File
//
int		check_extension(char *path, char *extension);

// Map
//
int		map_to_tab(int fd, t_game_info *info_game);
int		map_to_rec(t_game_info *info_game);
int		check_map_validity(char **map, char *start_dir, t_point *start_pos);
int		is_space(char *str);
int		check_end_map(int fd, char *line);
int		map_line_is_ok(char *str);
int		tab_string_max_len(char **tab);
int		tab_string_len_y(char **tab);
int		is_charset(int c, char *set);
void	set_t_point(int x, int y, t_point *data);

// Textures and Colors
//
char	*set_texture(int *total_elements, char elements[6][2], char *line,
			t_game_info *game_info);
int		set_color(int *total_elements, char elements[6][2], char *line,
			t_game_info *game_info);
char	*skip_space(char *str);
int		check_doublon(int *total_elements, char elements[6][2], char *line);
int		check_line(char *line);
char	*ft_strcdup(char *str, char c);

#endif // !PARSING_H
