/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabdalla <pabdalla@student.42beirut.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 21:45:06 by pabdalla          #+#    #+#             */
/*   Updated: 2025/11/30 01:36:51 by pabdalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	char	*ret;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s);
	ret = (char *) malloc((len + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	while (i < len)
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	size;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	size = len1 + len2;
	ret = (char *)malloc((size + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	if (size == 0)
	{
		ret[size] = '\0';
		return (ret);
	}
	ft_memcpy(ret, s1, len1);
	ft_memcpy(ret + len1, s2, len2);
	ret[size] = '\0';
	free(s1);
	return (ret);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*us_dest;
	unsigned char	*us_src;
	size_t			i;

	i = 0;
	us_dest = (unsigned char *)dest;
	us_src = (unsigned char *)src;
	while (i < n)
	{
		us_dest[i] = us_src[i];
		i++;
	}
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*ret;

	i = 0;
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
	{
		ret = (char *)malloc(1 * sizeof(char));
		ret[i] = '\0';
		return (ret);
	}
	ret = (char *)malloc((len + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	while (i < len && s[start + i])
	{
		ret[i] = s[start + i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
