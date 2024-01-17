/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:47:16 by vopekdas          #+#    #+#             */
/*   Updated: 2024/01/17 17:39:19 by vopekdas         ###   ########.fr       */
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
int		checking_errors_pid(pid_t pid);
int		checking_errors_pipe(int pipe);
#endif 