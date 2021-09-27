#include "libft.h"
/*Function to find the largest value in a linked-list*/

long int	ft_lstget_max(t_list *lst)
{
	void	*max;

	if (!lst)
		return (INT_MAX);
	max = lst->data;
	while (lst)
	{
		if (lst->data > max)
			max = lst->data;
		lst = lst->next;
	}
	return ((long int)max);
}
