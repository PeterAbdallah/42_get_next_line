/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabdalla <pabdalla@student.42beirut.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 01:12:37 by pabdalla          #+#    #+#             */
/*   Updated: 2025/12/05 02:29:01 by pabdalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*read_and_append(int fd, char *stash, char *buffer)
{
	int	nbread;

	nbread = read(fd, buffer, BUFFER_SIZE);
	if (nbread <= 0)
		return (NULL);
	buffer[nbread] = '\0';
	return (ft_strjoin(stash, buffer));
}

char	*read_until_nl(int fd, char *stash, char *buffer)
{
	char	*new_stash;

	while (!stash || !ft_strchr(stash, '\n'))
	{
		new_stash = read_and_append(fd, stash, buffer);
		if (!new_stash)
		{
			if (stash && *stash)
				return (stash);
			return (free(stash), NULL);
		}
		stash = new_stash;
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*leftovers[1024];
	char		*buffer;
	char		*stash;
	char		*result;
	char		*nl_index;

	if (fd < 0 || fd >= 1024)
		return (NULL);
	buffer = (char *)malloc ((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	stash = leftovers[fd];
	leftovers[fd] = NULL;
	stash = read_until_nl(fd, stash, buffer);
	free(buffer);
	if (!stash)
		return (NULL);
	nl_index = ft_strchr(stash, '\n');
	if (!nl_index)
		return (result = ft_strdup(stash), free(stash), result);
	result = ft_substr(stash, 0, nl_index - stash + 1);
	leftovers[fd] = ft_substr(stash, nl_index - stash + 1,
			ft_strlen(stash) - (nl_index - stash + 1));
	free(stash);
	return (result);
}
