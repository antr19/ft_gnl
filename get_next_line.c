/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarsha <fmarsha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 03:22:58 by fmarsha           #+#    #+#             */
/*   Updated: 2022/01/11 06:39:26 by fmarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h> //TODO
#include <unistd.h>
#include <stdio.h> // TODO

char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

int	ft_get_str(int fd, char *s, int first)
{
	int				n;

	n = read(fd, s, BUFFER_SIZE);
	if (first && !n)
		n = -1;
	if (n != -1)
		s[n] = '\0';
	else
		s = 0;
	return (n);
}

int	ft_handler(char *s, int i, int n, char *gen)
{
	if (n == 0)
		ft_strlcpy(s, "", BUFFER_SIZE);
	else if (n == -1)
	{
		free(gen);
		return (0);
	}
	else
		ft_strlcpy(s, s + i + 1, BUFFER_SIZE);
	return (1);
}

char	*get_next_line(int fd)
{
	char			*gen;
	static char		s[BUFFER_SIZE + 1];
	int				i;
	int				n;

	gen = ft_strdup("");
	if (!(*s))
		n = ft_get_str(fd, s, 1);
	while (1)
	{
		i = 0;
		while (s[i] && s[i] != '\n')
			i++;
		gen = ft_strjoin(gen, s, i + 1);
		if ((i != BUFFER_SIZE && s[i]) || (n <= 0))
		{
			if (ft_handler(s, i, n, gen))
				return (gen);
			else
				return (NULL);
		}
		else
			n = ft_get_str(fd, s, 0);
	}
}

// int	main()
// {
// 	int	fd;

// 	fd = open("file.txt", O_RDONLY);
// 	printf("#%i\n", get_next_line(fd) == NULL);
// 	printf("#%s", get_next_line(fd));
// 	printf("#%s", get_next_line(fd));
// 	printf("#%s", get_next_line(fd));
// 	printf("#%s", get_next_line(fd));
// 	printf("#%s", get_next_line(fd));
// 	printf("#%s", get_next_line(fd));
// 	// printf("#%d", *get_next_line(fd));
// 	close(fd);
// }
