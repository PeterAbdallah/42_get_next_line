/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabdalla <pabdalla@student.42beirut.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 21:44:49 by pabdalla          #+#    #+#             */
/*   Updated: 2025/11/30 01:35:42 by pabdalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>

char	*get_next_line(int fd);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif