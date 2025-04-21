#include "pipex.h"

static char	*try_direct_path(char **cmd_args)
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

static char	*try_path_dir(char *dir, char *cmd)
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

static void	free_search_resources(char *path, char **cmd_args)
{
	free(path);
	free_array(cmd_args);
}

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
