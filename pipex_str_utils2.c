/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_str_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromatv <afromatv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 20:20:42 by afromatv          #+#    #+#             */
/*   Updated: 2025/05/25 20:20:42 by afromatv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}

char	*ft_strtok(char *str, char sep)
{
	static t_split	split;
	char			*token;

	if (str)
	{
		split.str = str;
		split.pos = 0;
		split.sep = sep;
	}
	if (!split.str || split.str[split.pos] == '\0')
		return (NULL);
	while (split.str[split.pos] == split.sep)
		split.pos++;
	token = &split.str[split.pos];
	while (split.str[split.pos] && split.str[split.pos] != split.sep)
		split.pos++;
	if (split.str[split.pos])
	{
		split.str[split.pos] = '\0';
		split.pos++;
	}
	return (token);
}
