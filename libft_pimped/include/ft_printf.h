/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:34:15 by nboucher          #+#    #+#             */
/*   Updated: 2024/12/11 13:20:30 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include "libft.h"

int		ft_printf(const char *str, ...);
int		ft_scan(const char c, va_list args);
int		ft_putchar(int c);
int		ft_printstr(char *str);
int		ft_print_ptr(unsigned long long ptr);
int		ft_printnbr(int n);
int		ft_print_unsigned(unsigned int n);
int		ft_print_hex(unsigned int num, const char format);
int		ft_print_percent(void);
int		ft_ptr_len(unsigned long int num);
int		ft_len_num(unsigned int n);
int		ft_hex_len(unsigned int num);

void	ft_putstr(char *str);
void	ft_put_ptr(unsigned long int num);
char	*ft_uitoa(unsigned int n);
void	ft_put_hex(unsigned int num, const char format);

#endif
