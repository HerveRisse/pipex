/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromatv <afromatv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 20:20:42 by afromatv          #+#    #+#             */
/*   Updated: 2025/05/25 20:20:42 by afromatv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_files(t_pipex *pipex, char **argv)
{
	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile < 0)
		error_exit("Error: Cannot open input file");
	pipex->outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->outfile < 0)
		error_exit("Error: Cannot open output file");
}

void	init_commands(t_pipex *pipex, char **argv)
{
	pipex->cmd1 = get_cmd_path(argv[2]);
	pipex->cmd2 = get_cmd_path(argv[3]);
	pipex->cmd1_args = split_cmd(argv[2]);
	pipex->cmd2_args = split_cmd(argv[3]);
}

static void	cleanup_commands(t_pipex *pipex)
{
	if (pipex->cmd1)
		free(pipex->cmd1);
	if (pipex->cmd2)
		free(pipex->cmd2);
	if (pipex->cmd1_args)
		free_array(pipex->cmd1_args);
	if (pipex->cmd2_args)
		free_array(pipex->cmd2_args);
}

static void	cleanup_files(t_pipex *pipex)
{
	if (pipex->infile >= 0)
		close(pipex->infile);
	if (pipex->outfile >= 0)
		close(pipex->outfile);
	if (pipex->pipe_fd[0] >= 0)
		close(pipex->pipe_fd[0]);
	if (pipex->pipe_fd[1] >= 0)
		close(pipex->pipe_fd[1]);
}

void	cleanup(t_pipex *pipex)
{
	cleanup_commands(pipex);
	cleanup_files(pipex);
}
