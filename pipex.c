/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromatv <afromatv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 20:20:42 by afromatv          #+#    #+#             */
/*   Updated: 2025/05/25 20:20:42 by afromatv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_pipex(t_pipex *pipex, int argc, char **argv)
{
	if (argc != 5)
		error_exit("Error: Invalid number of arguments");
	init_files(pipex, argv);
	if (pipe(pipex->pipe_fd) < 0)
		error_exit("Error: Pipe failed");
	init_commands(pipex, argv);
}

void	wait_for_children(t_pipex *pipex)
{
	int	status;

	waitpid(pipex->pid1, &status, 0);
	waitpid(pipex->pid2, &status, 0);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	init_pipex(&pipex, argc, argv);
	execute_cmd1(&pipex, envp);
	execute_cmd2(&pipex, envp);
	close(pipex.pipe_fd[0]);
	close(pipex.pipe_fd[1]);
	wait_for_children(&pipex);
	cleanup(&pipex);
	return (0);
}
