#include "libft.h"
#include <stdio.h>
int	ft_isint(char *str)
{
	long int	tmp;

	tmp = ft_atoi(str);
	if (tmp < 0 && (str[0] != '-'))
		return (0);
	else if (tmp == 0 && (str[0] != '0'))
		return (0);
	if (ft_intlen(tmp) != ft_strlen(str))
		return (0);
	return (1);
}
