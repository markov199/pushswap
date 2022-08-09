/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkovoor <mkovoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:36:08 by mkovoor           #+#    #+#             */
/*   Updated: 2022/08/09 15:35:11 by mkovoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft/libft.h"
#include"pushswap.h"

void	ft_sort_5(t_list **list, t_list *stack_temp)
{
	int	i;
	int	push_count;

	push_count = 0;
	i = ft_lstsize(*list);
	while (i-- > 3)
	{
		ft_optimalpush(&stack_temp, list, ft_min(list), 'b');
		push_count++;
	}
	ft_sort_3(list);
	while (push_count--)
		ft_push(list, &stack_temp, 'a');
}

void	ft_sort_3(t_list **list)
{
	t_list	*ptr;
	int		max;
	int		min;

	ptr = *list;
	min = ft_position(*list, ft_min(list));
	max = ft_position(*list, ft_max(list));
	if (min == 0 && max == 1)
	{
		ft_swap(list, 'a');
		ft_rotate(list, 'a');
	}
	else if (min == 1 && max == 0)
		ft_rotate(list, 'a');
	else if (min == 1 && max == 2)
		ft_swap(list, 'a');
	else if (min == 2 && max == 0)
	{
		ft_swap (list, 'a');
		rra(list, 'a');
	}
	else if (min == 2 && max == 1)
		rra(list, 'a');
	return ;
}

void	ft_sort_500(t_list **list, t_list *stack_temp, int size)
{
	int			count;
	int			chunk;
	int			i;
	t_list		*stack;
	stk_size	stacksize;

	stack = *list;
	chunk = 1;
	stacksize.b = 0;
	stacksize.a = size;
	i = (stacksize.a / 54);
	while (i --)
	{
		count = stacksize.a;
		while (count-- && stacksize.a > 3)
		{
			if (*(int *)stack ->content < chunk * 54)
			{
				ft_optimalpush(&stack_temp, list, *(int *)stack ->content, 'b');
				if (stack_temp ->next)
				{
					if (*(int *)stack_temp ->content < ((2 * chunk - 1) * 27))
						ft_rotate(&stack_temp, 'b');
				}
				stacksize.a--;
				stacksize.b++;
				stack = *list;
			}
			else
				stack = stack ->next;
		}
		chunk++;
	}
	while (stacksize.a--)
	{
		ft_push(&stack_temp, list, 'b');
		stacksize.b++;
	}
	while (stacksize.b--)
		ft_optimalpush(list, &stack_temp, ft_max(&stack_temp), 'a');
}

void	ft_sort_100(t_list **list, t_list *stack_temp, int size)
{
	int			chunk;
	int			i;
	t_list		*stack;
	stk_size	stacksize;

	stack = *list;
	chunk = 1;
	stacksize.b = 0;
	stacksize.a = size;
	i = (stacksize.a / 24);
	while (i --)
	{
		ft_chunk(list, &stack_temp, chunk);
		chunk++;
	}
	while (*list)
		ft_push(&stack_temp, list, 'b');
	while (stack_temp)
		ft_optimalpush(list, &stack_temp, ft_max(&stack_temp), 'a');
}

int	ft_sort(t_list **list)
{
	int		i;
	t_list	*ptr;
	t_list	*stack_temp;

	ptr = *list;
	stack_temp = NULL;
	i = ft_lstsize(ptr);
	if (i == 2)
	{
		if (*(int *)ptr ->content > *(int *)ptr ->next->content)
			ft_swap(list, 'a');
	}
	if (i == 3)
		ft_sort_3(list);
	else if (i < 16)
		ft_sort_5(list, stack_temp);
	else if (i < 101)
		ft_sort_100(list, stack_temp, i);
	else
		ft_sort_500(list, stack_temp, i);
	return (0);
}
