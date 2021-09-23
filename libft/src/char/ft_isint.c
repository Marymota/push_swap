#include "libft.h"

int	ft_isint(char *str)
{
	int		i;
	long	tmp;

	tmp = ft_atoi(str);
	i = 0;
	if (tmp < 0 && (str[0] != '-'))
		return (0);
	else if (tmp == 0 && (str[0] != '0'))
		return (0);
	if (tmp < 0)
		i++;
	if (ft_intlen(tmp) != ft_strlen(str))
		return (0);
	return (1);
}
