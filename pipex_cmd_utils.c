/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_cmd_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromatv <afromatv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 20:20:42 by afromatv          #+#    #+#             */
/*   Updated: 2025/05/25 20:20:42 by afromatv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*try_direct_path(char **cmd_args)
{
	char	*full_path;

	if (access(cmd_args[0], F_OK | X_OK) == 0)
	{
		full_path = ft_strdup(cmd_args[0]);
		free_array(cmd_args);
		return (full_path);
	}
	free_array(cmd_args);
	error_exit("Error: Command not found");
	return (NULL);
}

char	*try_path_dir(char *dir, char *cmd)
{
	char	*full_path;

	full_path = malloc(ft_strlen(dir) + ft_strlen(cmd) + 2);
	if (!full_path)
		return (NULL);
	ft_strcpy(full_path, dir);
	ft_strcat(full_path, "/");
	ft_strcat(full_path, cmd);
	if (access(full_path, F_OK | X_OK) == 0)
		return (full_path);
	free(full_path);
	return (NULL);
}

void	free_search_resources(char *path, char **cmd_args)
{
	free(path);
	free_array(cmd_args);
}
