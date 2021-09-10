#include "libft.h"

int ft_lstsorted(t_list *lst)
{
	 while (lst->next)
	 {
		if (lst->data > lst->next->data)
			return (0);
		lst = lst->next;
	 }
	 return (1);
}