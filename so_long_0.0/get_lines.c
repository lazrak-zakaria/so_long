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
		//protect
		if (*tmp)
			free (tmp);
		b = read(fd, rd, 6);
	}
	
	return (answer);
}