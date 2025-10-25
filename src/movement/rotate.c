/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 17:24:43 by nboucher          #+#    #+#             */
/*   Updated: 2025/05/25 17:24:43 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "struct.h"
#include <math.h>

void	get_rotation_matrix(double matrix[2][2], int sens)
{
	matrix[0][0] = cos(sens * THETA);
	matrix[0][1] = -sin(sens * THETA);
	matrix[1][0] = sin(sens * THETA);
	matrix[1][1] = cos(sens * THETA);
}

void	get_pos_matrix(t_data *data, double mat[2])
{
	mat[0] = data->game.player.dir.x;
	mat[1] = data->game.player.dir.y;
}

void	operation_matrix(float m_rot[2][2], float m_pos[2], float m_result[2])
{
	m_result[0] = (m_rot[0][0] * m_pos[0] + m_rot[0][1] * m_pos[1]);
	m_result[1] = (m_rot[1][0] * m_pos[0] + m_rot[1][1] * m_pos[1]);
}

void	rotate_vector(double rot[2][2], t_vector *v)
{
	double	x;
	double	y;

	x = v->x;
	y = v->y;
	v->x = rot[0][0] * x + rot[0][1] * y;
	v->y = rot[1][0] * x + rot[1][1] * y;
}

void	rotate_dir(t_data *data, int sens)
{
	double	rot[2][2];

	get_rotation_matrix(rot, sens);
	rotate_vector(rot, &data->game.player.dir);
	rotate_vector(rot, &data->game.player.plan);
}
