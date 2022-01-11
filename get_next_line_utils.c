/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarsha <fmarsha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 06:04:33 by fmarsha           #+#    #+#             */
/*   Updated: 2022/01/11 06:08:53 by fmarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	d_len;
	size_t	s_len;

	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	if (d_len >= dstsize)
		return (dstsize + s_len);
	else
	{
		i = 0;
		while ((d_len + i++) < (dstsize - 1) && src[i - 1])
			dst[d_len + i - 1] = src[i - 1];
		dst[d_len + i - 1] = 0;
		return (d_len + s_len);
	}
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize)
	{
		while (i++ < (dstsize - 1) && src[i - 1])
			dst[i - 1] = src[i - 1];
		dst[i - 1] = 0;
	}
	return (ft_strlen(src));
}

char	*ft_strjoin(char *s1, char *s2, size_t dstsize)
{
	size_t	len;
	char	*s;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + dstsize + 1;
	s = (char *)malloc(len);
	if (s)
	{
		ft_strlcpy(s, s1, len);
		ft_strlcat(s, s2, len);
		free(s1);
	}
	return (s);
}

char	*ft_strdup(const char *s1)
{
	char	*s;
	size_t	len;

	len = ft_strlen(s1) + 1;
	s = (char *)malloc(len);
	if (s)
		len = ft_strlcpy(s, s1, len);
	return (s);
}
