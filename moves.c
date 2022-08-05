#include"libft/libft.h"
#include<stdio.h>

void	sa(t_list *stack)
{
	t_list *ptr;

	ptr = stack ->next;
	stack ->next = ptr ->next;
	ptr ->next = stack;
	stack = ptr;
}

t_list	*ft_newnode(void *content)
{
	t_list	*new;

	new = NULL;
	new = (t_list *)malloc(sizeof (t_list));
	if (new == NULL)
		return (NULL);
	(new ->content) = *content;
	new ->next = NULL;
	return (new);
}

int ft_print_list(t_list * list) 
{
	printf("\nlist print\n");
	while(list)
	{		
		printf("%d\n", *(int *)list ->content);
		list = list ->next;
	}
	return (0);
}

int main (int ac, char *av[])
{
	t_list *num;
	t_list *ptr;
	int	i;
	int	nbr;

	i = 1;
	nbr = ft_atoi(av[i]);
	num = ft_lstnew(&nbr);
	ptr = num;
	while (++i < ac)
	{
		nbr = ft_atoi(av[i]);
		ptr ->next = ft_lstnew(&nbr);
		ptr = ptr ->next;
	}
	ft_print_list(num);
	sa(num);
	ft_print_list(num);
	return (0);	
}
