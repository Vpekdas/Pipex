/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:07:10 by vopekdas          #+#    #+#             */
/*   Updated: 2024/01/19 17:10:52 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_get_path(char **env)
{
	char	**path;

	if (!env)
		return (NULL);
	path = NULL;
	while (*env)
	{
		if (ft_strncmp(*env, "PATH=", 5) == 0)
		{
			path = ft_split(*env + 5, ':');
			if (!path)
				return (NULL);
			return (path);
		}
		env++;
	}
	return (NULL);
}

char	*ft_create_path(char *command, char **envp)
{
	char 	**path;
	char	*new_path;

	if (!envp || !command)
		return (NULL);
	path = NULL;
	path = ft_get_path(envp);
	while (*path)
	{
		new_path = *path;
		new_path = ft_strjoin(new_path, "/");
		new_path = ft_strjoin_and_free(new_path, command);
		if (access(new_path, F_OK) == 0)
			return (new_path);
		free(new_path);
		path++;
	}
	return (NULL);
}
