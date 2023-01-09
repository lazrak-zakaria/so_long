/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlazrak <zlazrak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:30:24 by zlazrak           #+#    #+#             */
/*   Updated: 2023/01/09 12:32:28 by zlazrak          ###   ########.fr       */
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
	return (answer);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_free_and_print(char **mem, int status, char *s)
{
	ft_mem_free(mem);
	if (*s)
		ft_putstr(s);
	exit(status);
}
