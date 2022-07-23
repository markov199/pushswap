/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkovoor <mkovoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 11:47:35 by mkovoor           #+#    #+#             */
/*   Updated: 2022/07/22 16:22:29 by mkovoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include"libft/libft.h"

// void ft_radix_sort(t_list **list);
int	ft_count_args(char *str);

static int	ft_isspace(char ch)
{
	if (ch == ' ' || ch == '\f' || ch == '\n' || ch == '\r'
		|| ch == '\t' || ch == '\v')
		return (1);
	else
		return (0);
}

int	ft_push_swap_atoi(char *str)
{
	int				sign;
	unsigned long	num;
	int				i;

	i = 0;
	sign = 1;
	num = 0;
	while (ft_isspace(str[i]))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = str[i] - '0' + (num * 10);
		i++;
	}
	if ((num > 2147483647 && sign == 1) || (num > 2147483648 && sign == -1))
	{
		write(1, "Error\n", 6);
		exit (1);
	}
	return (num * sign);
}

void	ft_lstprint(t_list *list)
{
	t_list	*ptr;
	int		i;

	i = ft_lstsize(list);
	ptr = list;
	while (i)
	{		
		ft_printf("%d ", *(int *)ptr ->content);
		ptr = ptr ->next;
		i--;
	}
	ft_printf("\n");
	return ;
}

int ft_swap(t_list **list)
{
	t_list *ptr;
	t_list *temp;

	ptr = *list;
	temp = ptr ->next;
	if (temp)
	{
		ptr ->next = temp ->next;
		temp ->next = ptr;
		*list = temp;
	}
	return (0);
}


int ft_double_swap(t_list **l1, t_list **l2)
{
	ft_swap(l1);
	ft_swap(l2);
	return (0);
}

int ft_push(t_list **l1, t_list **l2)
{
	t_list	*temp1;
	
	if(*l2)
	{
		temp1 = *l2;
		*l2 = temp1 ->next;
		temp1 ->next = *l1;
		*l1 = temp1;
	}
	return (0);
}


int ft_rotate (t_list **list)
{
	t_list	*ptr;
	t_list	*temp;

	temp = *list;
	ptr = ft_lstlast(temp);
	if (ptr)
	{
		ptr ->next = temp;
		*list = temp ->next;
		temp ->next = NULL;
	}
	return (0);
}

int	rra(t_list **list)
{
	t_list	*ptr;
	t_list	*temp;

	ptr = *list;
	temp = *list;
	if (ptr ->next)
	{
		while(ptr ->next ->next)
			ptr = ptr ->next;
		ptr ->next ->next = temp;
		*list = ptr ->next;
		ptr ->next = NULL;
		return (0);
	}
return (0);
}

int ft_min(t_list **list)
{
	t_list	*ptr1;
	t_list	*ptr2;
	int		i;
	int 	j;

	if (*list)
	{
		i = 1;
		j = i + 1;
		ptr1 = *list;
		ptr2 = ptr1 ->next;
		while (ptr2)
		{
			
			if (*(int *)ptr1 ->content > *(int *)ptr2 ->content)
			{
				ptr1 = ptr2;
				i = j;
			}
			j++;
			ptr2 = ptr2 ->next;
		}
		return (i);
	}
	return (-1);
}

int	ft_max(t_list **list)
{
	t_list	*ptr1;
	t_list	*ptr2;
	int		i;
	int		j;

	if (*list)
	{
		ptr1 = *list;
		ptr2 = ptr1 ->next;
		i = 1;
		j = i + 1;		
		while (ptr2)
		{			
			if (*(int *)ptr1 ->content < *(int *)ptr2 ->content)
			{
				ptr1 = ptr2;
				i = j;
			}
			j++;
			ptr2 = ptr2 ->next;
		}
	}
	return (i);
}


void ft_sort_3(t_list **list)
{
	t_list	*ptr;
	int		max;
	int		min;

	ptr = *list;
	min = ft_min(list);
	max = ft_max(list);
	if (min == 2 && max == 3)
		ft_swap(list);
	else if (min == 3 && max ==1)
	{
		ft_swap (list);
		rra (list);
	}
	else if (min == 2 && max == 1)
		ft_rotate(list);
	else if (min == 1 && max == 2)
	{
		ft_swap (list);
		ft_rotate (list);
	}
	else if (min == 3 && max == 2)
		rra (list);
	return ;
}
void	ft_sort_100(t_list **list)
{
	int	count;
	int	size;
	t_list	*stack;
	t_list	*stack_temp;

	stack = *list;
	stack_temp = NULL;
	count = ft_max(&stack);
	size = ft_lstsize(stack);
	
	if (count > (size + 1) / 2)
	{
		count = size - count + 1;
		while (count--)
			rra(&stack);
	}
	else 
		while (count--)
			ft_rotate(&stack);
	ft_lstprint(stack);
	
}

int	ft_sort(t_list **list)
{
	int	i;
	t_list	*ptr;

	ptr = *list;
	i = ft_lstsize(ptr);
	if (i == 2)
	{
		if (*(int *)ptr ->content > *(int *)ptr ->next->content)
			ft_swap(list);
	}
	if (i == 3)
		ft_sort_3(list);
	else
		ft_sort_100(list);
	return (0);		
}

int	ft_check_repeats(t_list *list)
{
	t_list	*ptr1;
	t_list	*ptr2;

	ptr1 = list;
	while (ptr1)
	{
		ptr2 = ptr1 ->next;
		while (ptr2)
		{
			if (*(int *)ptr1 ->content == *(int *)ptr2 ->content)
			{
				write(1, "Error\n", 6);
				exit (1);
			}
			ptr2 = ptr2 ->next;
		}
		ptr1 = ptr1 ->next;		
	}
	return (0);
}

int	ft_valid_input(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '-' || str[i] == '+'))
		{
			write(1, "Error\n", 6);
			exit(1);
		}
	return (1);
}

int	ft_count_args(char *str)
{
	int	string;
	int	count;

	if (str)
	{
		count = 0;
		
		while (*str)
		{
			string = 0;
			while (*str == ' ')
				str++;
			while (*str && *str != ' ')
			{
				string = 1;
				str++;
			}
			if (string)
				count++;
		}
		return (count);
	}
	return (-1);
}

int	*ft_pushswap_split(int *nbr, char *str, int count)
{
	int		i;
	int		j;
	int		len;
	char	*word;

	i = 0;
	j = -1;
	while (count--)
	{
		while (str[i] == ' ')
		i++;
		len = 0;
		while (str[i + len] && str[i + len] != ' ')
			len++;
		if (len)
			word = ft_substr(str, i, len);
		if (!word || !ft_valid_input(word))
			exit (1);
		nbr[++j] = ft_push_swap_atoi(word);
			free (word);
		i = i + len;
	}
	return (nbr);
}

t_list	*ft_init_stack(t_list *stack, char *str)
{
	int		*args;
	int		i;
	t_list	*list;
	int		count;

	i = 0;
	list = stack;
	count = ft_count_args(str);
	if (count)
	{
		args = (int *)malloc(sizeof(int) * (count));
		if (!args)
			return (NULL);
		args = ft_pushswap_split(args, str, count);
		while (i < count)
		{
			ft_lstadd_back(&list, ft_lstnew(&args[i]));
			i++;
		}
		
	}
	return (list);
}

int	ft_is_sorted(t_list *list)
{
	t_list *ptr;

	ptr = list;
	while( ptr ->next)
	{
		if (*(int *)ptr ->content > *(int *)ptr ->next->content)
			return (0);
		ptr = ptr ->next;
	}
	return (1);
}

t_list	*ft_index_list(t_list *list)
{
	t_list	*ptr1;
	t_list	*ptr2;
	int 	*count;
	t_list *stack;

	stack = NULL;
	ptr1 = list;
	while (ptr1)
	{
		ptr2 = list;
		count = (int *)malloc (sizeof(int *) * 1);
		*count = 0;
		while (ptr2)
		{
			if (*(int *)ptr1 ->content > *(int *)ptr2->content)
				(*count)++;
			ptr2 = ptr2 ->next;
		}
		ft_lstadd_back(&stack, ft_lstnew(count));
		ptr1 = ptr1 ->next;
	}
	return (stack);
}

// void ft_radix_sort(t_list **list)
// {
// 	t_list *stack_b;
// 	t_list	*ptr;
// 	int i;
// 	int	j;
// 	int	count;

// 	stack_b = NULL;
	
// 	i = 0;
// 	j = 0;
// 	count = ft_max(list);
	
// 	while (count >> j)
// 	{
// 		i = 0;
// 		ptr = *list;
// 		while (ptr)
// 		{
// 			if((*(int *)ptr->content >> j) && 1)
// 			{
// 				pb(list, &stack_b);
// 				rb(&stack_b);
				
// 			}
// 			else ra(list);
// 			ptr = ptr ->next;
// 			i++;
// 		}
// 		while(stack_b)
// 		{
// 			pa(list, &stack_b);
// 			ra(list);
// 		}
// 		ft_lstprint(*list);
// 		j++;
// 	}
// }

int	main(int ac, char *av[])
{
	int		i;
	int		j;
	t_list	*stack_a;
	t_list	*stack_b;

	if (ac > 1)
	{
		j = 0;
		stack_a = NULL;
		stack_b = NULL;
		while (++j < ac)
			stack_a = ft_init_stack(stack_a, av[j]);
		if (!stack_a)
		{
			ft_printf("Error\n");
			exit(1);
		}
		ft_check_repeats(stack_a);
		if (ft_is_sorted(stack_a))
			exit (0);
		ft_printf("\nstack_a\n");
		ft_lstprint(stack_a);
		stack_a = ft_index_list(stack_a);
		ft_lstprint(stack_a);
		ft_sort(&stack_a);		
		return (0);
	}
	return (0);
}
