/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromatv <afromatv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 20:20:42 by afromatv          #+#    #+#             */
/*   Updated: 2025/05/25 20:20:42 by afromatv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	setup_io(t_pipex *pipex, int cmd_num)
{
	if (cmd_num == 1)
	{
		dup2(pipex->infile, STDIN_FILENO);
		dup2(pipex->pipe_fd[1], STDOUT_FILENO);
		close(pipex->pipe_fd[0]);
	}
	else
	{
		dup2(pipex->pipe_fd[0], STDIN_FILENO);
		dup2(pipex->outfile, STDOUT_FILENO);
		close(pipex->pipe_fd[1]);
	}
	close(pipex->infile);
	close(pipex->outfile);
}

void	execute_cmd1(t_pipex *pipex, char **envp)
{
	pipex->pid1 = fork();
	if (pipex->pid1 < 0)
		error_exit("Error: Fork failed");
	if (pipex->pid1 == 0)
	{
		setup_io(pipex, 1);
		execve(pipex->cmd1, pipex->cmd1_args, envp);
		error_exit("Error: Command 1 execution failed");
	}
}

void	execute_cmd2(t_pipex *pipex, char **envp)
{
	pipex->pid2 = fork();
	if (pipex->pid2 < 0)
		error_exit("Error: Fork failed");
	if (pipex->pid2 == 0)
	{
		setup_io(pipex, 2);
		execve(pipex->cmd2, pipex->cmd2_args, envp);
		error_exit("Error: Command 2 execution failed");
	}
}
