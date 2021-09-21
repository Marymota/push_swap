#include "libft.h"
/*Function to find the largest value in a linked-list*/

long int	ft_lstget_max(t_list *lst)
{
	long int	max;

	if (!lst)
		return (INT_MAX);
	max = (long int)lst->data;
	while (lst)
	{
		if ((long int)lst->data > max)
			max = (long int)lst->data;
		lst = lst->next;
	}
	return (max);
}
