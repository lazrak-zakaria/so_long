/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlazrak <zlazrak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:30:24 by zlazrak           #+#    #+#             */
/*   Updated: 2023/01/15 14:03:55 by zlazrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_lines(int fd)
{
	char	*answer;
	char	rd[7];
	char	*tmp;
	int		b;

	answer = "";
	b = read(fd, rd, 6);
	while (b > 0)
	{
		rd[b] = '\0';
		tmp = answer;
		answer = ft_strjoin(answer, rd);
		if (!answer)
		{
			if (*tmp)
				free (tmp);
			return (NULL);
		}
		if (*tmp)
			free (tmp);
		b = read(fd, rd, 6);
	}
	if (!(*answer))
		return (NULL);
	return (answer);
}

int	check_map_new_line(char *s)
{
	int	i;

	i = 1;
	while (s[i])
	{
		if (s[i] == '\n' && s[i - 1] == '\n')
			return (0);
		++i;
	}
	if (s[i - 1] == '\n')
		return (0);
	return (1);
}

char	*ft_read_map(char **av)
{
	int		fd;
	char	*mem;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	mem = get_lines(fd);
	close(fd);
	if (!mem)
		ft_free_and_print(NULL, 1, "Error");
	if (!check_map_new_line(mem))
	{
		free (mem);
		ft_free_and_print(NULL, 1, "the map must be rectangular");
	}
	return (mem);
}

void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_free_and_print(char **mem, int status, char *s)
{
	int	fd;

	fd = 1;
	if (mem)
		ft_mem_free(mem);
	if (status)
		fd = 2;
	if (*s)
		ft_putstr(s, fd);
	exit(status);
}
