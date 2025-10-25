/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:25:52 by nboucher          #+#    #+#             */
/*   Updated: 2025/05/25 18:25:52 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVEMENT_H
# define MOVEMENT_H

# include "struct.h"

void	translate_pos_left_right(t_data *data, int side);
void	translate_pos_up_down(t_data *data, int side);
void	rotate_dir(t_data *data, int sens);

#endif
