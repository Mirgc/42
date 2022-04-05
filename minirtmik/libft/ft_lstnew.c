#include "libft.h"
t_list	*ft_lstnew(void *content)
{
	t_list *list;

	list = malloc(sizeof(t_list) * 1);
	if(!list)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}
