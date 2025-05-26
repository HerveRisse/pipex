/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromatv <afromatv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 20:20:42 by afromatv          #+#    #+#             */
/*   Updated: 2025/05/25 20:20:42 by afromatv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*init_path_search(void)
{
	char	*path;

	path = getenv("PATH");
	if (!path)
		error_exit("Error: PATH not found");
	path = ft_strdup(path);
	if (!path)
		error_exit("Error: Memory allocation failed");
	return (path);
}

static char	*search_in_path(char **cmd_args)
{
	char	*path;
	char	*dir;
	char	*full_path;

	path = init_path_search();
	dir = ft_strtok(path, ':');
	while (dir)
	{
		full_path = try_path_dir(dir, cmd_args[0]);
		if (full_path)
		{
			free_search_resources(path, cmd_args);
			return (full_path);
		}
		dir = ft_strtok(NULL, ':');
	}
	free_search_resources(path, cmd_args);
	error_exit("Error: Command not found");
	return (NULL);
}

char	*get_cmd_path(char *cmd)
{
	char	**cmd_args;

	cmd_args = split_cmd(cmd);
	if (!cmd_args[0])
		error_exit("Error: Invalid command");
	if (cmd_args[0][0] == '/' || cmd_args[0][0] == '.')
		return (try_direct_path(cmd_args));
	return (search_in_path(cmd_args));
}
