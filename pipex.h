/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:47:16 by vopekdas          #+#    #+#             */
/*   Updated: 2024/01/22 13:32:01 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define PIPEX_H

# include "Libft/libft.h"
# include "ft_printf/include/ft_printf.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdio.h>

char	**ft_get_path(char **env);
char	*ft_create_path(char *command, char **envp);
int		ft_exec_cmd(char *av, char **envp);
int		ft_exec_first_cmd(char *av, char **envp, int infile);
int		ft_exec_last_cmd(char *av, char **envp, int pipe_in, char *out_path);
int		ft_exec_middle_cmd(char *av, char **envp, int pipe_in);
void	ft_free_split(char **split);

#endif 