/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabdalla <pabdalla@student.42beirut.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 21:44:34 by pabdalla          #+#    #+#             */
/*   Updated: 2025/11/30 02:01:25 by pabdalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>
#define BUFFERSIZE 42

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char	*read_to_stash(int fd, char *stash)
{
	char	buffer[BUFFERSIZE];
	int		nbread;

	nbread = 1;
	while (!ft_strchr(stash, '\n') && nbread > 0)
	{
		nbread = read(fd, buffer, BUFFERSIZE);
		if (nbread <= 0)
			break ;
		buffer[nbread] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*leftovers;
	char		*stash;
	char		*result;
	int			nbread;

	stash = NULL;
	if (leftovers)
	{
		stash = ft_strdup(leftovers);
		free(leftovers);
		leftovers = NULL;
	}
	stash = read_to_stash(fd, stash);
	if (!stash || *stash == '\0')
		return (free(stash), NULL);
	result = ft_substr(stash, 0, (ft_strchr(stash, '\n') - stash) + 1);
	leftovers = ft_substr(stash, (ft_strchr(stash, '\n') - stash) + 1,
			ft_strlen(stash) - ((ft_strchr(stash, '\n') - stash) + 1));
	free(stash);
	return (result);
}
