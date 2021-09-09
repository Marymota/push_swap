#include "libft.h"

/*	This function compares a string of digits
	and its conversion to number.
	The string and the number must have the same length
	and keep the same value.
*/
int ft_isint(char *str)
{
	int i;
	long tmp;

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