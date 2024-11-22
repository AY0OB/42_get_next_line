/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amairia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:30:59 by amairia           #+#    #+#             */
/*   Updated: 2024/11/13 22:53:34 by amairia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*feed_res(char *res, char *s1, char const *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
		res[i++] = s2[j++];
	free(s1);
	return (res);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*res;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] || s2[j])
	{
		if (s1[i])
			i++;
		if (s2[j])
			j++;
	}
	res = ft_calloc(i + j + 1, sizeof(char));
	if (!res)
		return (NULL);
	return (feed_res(res, s1, s2));
}

char	*ft_strchr(const char *s, int c )
{
	int				i;
	unsigned char	ch;

	ch = (unsigned char)c;
	if (ch == 0)
	{
		return ((char *)(s + ft_strlen(s)));
	}
	i = 0;
	while (s[i])
		if (ch == s[i++])
			return ((char *)(s + i - 1));
	return (NULL);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*res;

	if (!s)
		return ;
	i = 0;
	res = (unsigned char *)s;
	while (i < n)
	{
		res[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;

	if (nmemb == 0 || size == 0)
	{
		res = malloc(1);
		ft_bzero(res, 1);
		return (res);
	}
	if (nmemb > 2147483647 || size > 2147483647 || nmemb * size > 2147483647)
		return (NULL);
	res = malloc(size * nmemb);
	if (!res)
		return (NULL);
	ft_bzero(res, size * nmemb);
	return (res);
}
