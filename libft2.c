/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlazrak <zlazrak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 11:50:53 by zlazrak           #+#    #+#             */
/*   Updated: 2023/01/13 13:53:56 by zlazrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*answer;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	answer = malloc(sizeof(char) * (i + j + 1));
	if (!answer)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i])
		answer[i] = s1[i];
	while (s2[j])
		answer[i++] = s2[j++];
	answer[i] = '\0';
	return (answer);
}

int	ft_cmp(char *a, char *b, int n)
{
	int	i;

	i = 0;
	while (a[i] && b[i] && a[i] == b[i])
		i++;
	if (i == n)
		return (1);
	return (0);
}

void	*ft_memset(void *s, int n, int size)
{
	int		i;
	char	*s1;

	s1 = s;
	i = -1;
	while (++i < size)
		s1[i] = n;
	return (s);
}

void	ft_putnbr(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar('-', fd);
		if (n < -9)
			ft_putnbr((n / 10) * -1, fd);
		ft_putchar ((n % 10 * -1) + '0', fd);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10, fd);
		ft_putchar((n % 10) + '0', fd);
	}
	else
		ft_putchar(n + '0', fd);
}

int	ft_strlen(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		;
	return (i);
}
