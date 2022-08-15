/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkovoor <mkovoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:36:08 by mkovoor           #+#    #+#             */
/*   Updated: 2022/08/15 12:57:51 by mkovoor          ###   ########.fr       */
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
	int			chunk;
	t_list		*stack;

	stack = *list;
	chunk = size / 54;
	stack_temp = ft_chunk_500(list, stack_temp, chunk, 54);
	while (*list)
		ft_push(&stack_temp, list, 'b');
	while (stack_temp)
		ft_optimalpush(list, &stack_temp, ft_max(&stack_temp), 'a');
}

void	ft_sort_100(t_list **list, t_list *stack_temp, int size)
{
	int			chunk;
	t_list		*stack;

	stack = *list;
	chunk = size / 24;
	stack_temp = ft_chunk_100(list, stack_temp, chunk, 24);
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
	else if (i == 3)
		ft_sort_3(list);
	else if (i < 16)
		ft_sort_5(list, stack_temp);
	else if (i < 101)
		ft_sort_100(list, stack_temp, i);
	else
		ft_sort_500(list, stack_temp, i);
	return (0);
}
