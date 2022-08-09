/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkovoor <mkovoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 07:30:36 by mkovoor           #+#    #+#             */
/*   Updated: 2022/08/09 08:22:03 by mkovoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft/libft.h"
#include"pushswap.h"

void ft_sort_5(t_list **list)
{
	int i;
	t_list *stack_temp;

	stack_temp = NULL;
	ft_optimalpush(&stack_temp, *list, 0, 'b');
	ft_optimalpush(&stack_temp, *list, 1, 'b');
	ft_sort_3(list);
	ft_push(list, &stack_temp, 'a');
	ft_push(list, &stack_temp, 'a');
}