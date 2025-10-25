/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:49:51 by nboucher          #+#    #+#             */
/*   Updated: 2025/03/11 13:37:40 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdbool.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft.h"
# include "ft_printf.h"

char	*ft_get_path(char *cmd, char **env);
char	*my_getenv(char *name, char **env);
void	ft_exit_handler(int n_exit, bool is_there_here_doc);
int		open_file(char *file, int in_or_out);
void	ft_free_tab(char **tab);
void	exec(char *cmd, char **env);
void	here_doc_put_in(char **av, int *p_fd);
void	here_doc(char **av);
pid_t	do_pipe(char *cmd, char **env);

#endif // PIPEX_BONUS_H
