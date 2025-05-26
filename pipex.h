/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromatv <afromatv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 20:20:42 by afromatv          #+#    #+#             */
/*   Updated: 2025/05/25 20:20:42 by afromatv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>

typedef struct s_split	t_split;
struct s_split
{
	char		*str;
	int			pos;
	char		sep;
};

typedef struct s_pipex	t_pipex;
struct s_pipex
{
	int			infile;
	int			outfile;
	char		*cmd1;
	char		*cmd2;
	char		**cmd1_args;
	char		**cmd2_args;
	int			pipe_fd[2];
	pid_t		pid1;
	pid_t		pid2;
};

/* Main functions */
void	init_pipex(t_pipex *pipex, int argc, char **argv);
void	init_files(t_pipex *pipex, char **argv);
void	init_commands(t_pipex *pipex, char **argv);
void	wait_for_children(t_pipex *pipex);

/* Command execution */
void	execute_cmd1(t_pipex *pipex, char **envp);
void	execute_cmd2(t_pipex *pipex, char **envp);
void	setup_io(t_pipex *pipex, int cmd_num);

/* String utils (pipex_str_utils1.c) */
size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strcat(char *dst, const char *src);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);

/* String utils (pipex_str_utils2.c) */
char	*ft_strncpy(char *dst, const char *src, size_t n);
char	*ft_strtok(char *str, char sep);

/* Command utils */
char	*get_cmd_path(char *cmd);
char	*try_direct_path(char **cmd_args);
char	*try_path_dir(char *dir, char *cmd);
void	free_search_resources(char *path, char **cmd_args);

/* Split utils */
char	**split_cmd(char *cmd);
void	free_array(char **arr);

/* Memory management */
void	cleanup(t_pipex *pipex);

/* Error handling */
void	error_exit(char *msg);

#endif
