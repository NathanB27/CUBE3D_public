/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:41:23 by nboucher          #+#    #+#             */
/*   Updated: 2025/05/25 18:41:23 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd("Error\nCube need one  arg\n", 2);
		return (1);
	}
	start_game(parse(argv[1]));
	return (0);
}
