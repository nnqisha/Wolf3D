#include "libft.h"

int		ft_count(const char *s, char c)
{
	char	**split;
	int		ret;

	split = ft_strsplit(s, ' ');
	ret = 0;
	while (split[ret])
	{
		free(split[ret]);
		ret++;
	}
	free(split);
	return (ret);
}
