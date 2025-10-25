/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:37:48 by nboucher          #+#    #+#             */
/*   Updated: 2025/05/25 18:37:48 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "struct.h"

void		start_game(t_game_info parsing_data);
t_game_info	parse(char *path);
int			exit_prog(t_data *data);
void		exit_failure(t_data *data);
void		free_path_textures(t_game_info parsing);

#endif // !CUBE3D
