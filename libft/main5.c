#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "ft_itoa.c"

static void             ft_print_result(char const *s)
{
        int             len;

        len = 0;
        while (s[len])
                len++;
        write(1, s, len);
}

int main ()
{
	// ft_lstnew
	printf ("-----------------\n");
	t_list          *elem;

        elem = NULL;
	elem = ft_lstnew("lorem ipsum dolor sit");
        ft_print_result((char *)elem->content);
        write(1, "\n", 1);
	if (!elem->next)
		write(1, "null", 4);
        write(1, "\n", 1);

	// ft_lstadd_front
	printf ("-----------------\n");
	t_list          *new;
        
        new = (t_list *)malloc(sizeof(t_list));
        if (!new)
                return (0);
        new->content = "abcdef";
        new->next = NULL;
	printf("Valor lst antes: %s\n", elem[0].content); 
        ft_lstadd_front(&elem, new);
//        while (elem)
//        {
		printf("Valor despues: %s\n", elem[0].content); 
//        	elem = elem->next;
//        }

	// ft_lstsize
	printf ("-----------------\n");
	int	len;
	
	len = ft_lstsize(elem);
	printf("El tamaño de la lista es: %i\n", len);	

	// ft_lstlast
	printf ("-----------------\n");

	printf("el valor del ultimo elemento es '%s'\n", ft_lstlast(elem)->content);
	return (0);
}
