/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_split_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromatv <afromatv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 20:20:42 by afromatv          #+#    #+#             */
/*   Updated: 2025/05/25 20:20:42 by afromatv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	count_words(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != ' ')
			i++;
	}
	return (count);
}

static char	*extract_word(char *str, int *i)
{
	char	*word;
	int		len;
	int		start;

	start = *i;
	len = 0;
	while (str[*i] && str[*i] != ' ')
	{
		len++;
		(*i)++;
	}
	word = malloc(len + 1);
	if (!word)
		error_exit("Error: Memory allocation failed");
	ft_strncpy(word, &str[start], len);
	word[len] = '\0';
	return (word);
}

static void	fill_args(char **args, char *cmd)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (cmd[i])
	{
		while (cmd[i] && cmd[i] == ' ')
			i++;
		if (cmd[i])
			args[j++] = extract_word(cmd, &i);
	}
	args[j] = NULL;
}

char	**split_cmd(char *cmd)
{
	char	**args;

	args = malloc(sizeof(char *) * (count_words(cmd) + 1));
	if (!args)
		error_exit("Error: Memory allocation failed");
	fill_args(args, cmd);
	return (args);
}
