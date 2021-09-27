#include "libft.h"
/*Function to find the smallest value in a linked-list*/

long int	ft_lstget_min(t_list *lst)
{
	void	*min;

	if (!lst)
		return (INT_MIN);
	min = lst->data;
	while (lst)
	{
		if (lst->data < min)
			min = lst->data;
		lst = lst->next;
	}
	return ((long int)min);
}
