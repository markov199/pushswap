/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_chunk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkovoor <mkovoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 14:53:10 by mkovoor           #+#    #+#             */
/*   Updated: 2022/08/10 16:14:12 by mkovoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft/libft.h"
#include"pushswap.h"

t_list	*ft_chunk(t_list **list, t_list *stack_temp, int size, int chunk)
{
	int			count;
	t_list		*stack;

	stack = *list;
	count = ft_lstsize(*list);
	while (count--)
	{
		
		if (*(int *)stack ->content < chunk)
		{
			ft_optimalpush(&stack_temp, list, *(int *)stack ->content, 'b');
			if (*(int *)stack_temp->content < chunk / 2)
				ft_rotate(&stack_temp, 'b');
			stack = *list;		
		}
		else
			stack = stack ->next;
	}
	return (stack_temp);
}
