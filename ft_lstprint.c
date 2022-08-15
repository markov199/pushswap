/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkovoor <mkovoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:44:31 by mkovoor           #+#    #+#             */
/*   Updated: 2022/08/15 11:49:48 by mkovoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft/libft.h"
#include"pushswap.h"

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
