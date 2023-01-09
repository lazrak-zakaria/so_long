/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlazrak <zlazrak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:29:52 by zlazrak           #+#    #+#             */
/*   Updated: 2023/01/09 14:05:33 by zlazrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	int		l;
	t_map	map;

	if (ac != 2)
	{
		ft_putstr("NUMBER OF ARGUMENT IS NOT VALID");
		return (1);
	}
	l = ft_strlen(av[1]) - 4;
	if (!ft_cmp(av[1] + l, ".ber", 4))
	{
		ft_putstr("THE MAP FILE SHOULD END WITH '.ber'");
		return (1);
	}
	ft_memset(&map, 0, sizeof(map));
	ft_map(av, &map);
	game(&map, ft_strlen(map.map[0]));
	return (0);
}
