/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_chunk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkovoor <mkovoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 14:53:10 by mkovoor           #+#    #+#             */
/*   Updated: 2022/08/09 15:39:19 by mkovoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft/libft.h"
#include"pushswap.h"

void	ft_chunk(t_list **list, t_list **stack_temp, int chunk)
{
	int			count;
	int			stacksize;
	t_list		*stack;
	t_list		*temp;

	stack = *list;
	temp = *stack_temp;
	stacksize = ft_lstsize(*list);
	count = stacksize;
	while (count--)
	{
		if (*(int *)stack ->content < chunk * 24)
		{
			ft_optimalpush(stack_temp, list, *(int *)stack ->content, 'b');
			if (temp ->next)
				if (*(int *)temp->content < ((2 * chunk - 1) * 12))
					ft_rotate(stack_temp, 'b');
			stacksize--;
			stack = *list;
		}
		else
			stack = stack ->next;
	}
}
