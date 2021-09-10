#include "libft.h"

void	ft_lstrm_node(t_list **lst)
{
	if (lst && *lst)
	{
		*lst = (*lst)->next;
	}
}
