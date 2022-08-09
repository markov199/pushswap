/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movec.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkovoor <mkovoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 10:58:08 by mkovoor           #+#    #+#             */
/*   Updated: 2022/08/09 11:05:28 by mkovoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushswap.h"
#include"libft/libft.h"

int	ft_swap(t_list **list, char ch)
{
	t_list	*ptr;
	t_list	*temp;

	ptr = *list;
	temp = ptr ->next;
	if (temp)
	{
		ptr ->next = temp ->next;
		temp ->next = ptr;
		*list = temp;
	}
	ft_printf("s%c\n", ch);
	return (0);
}

int	ft_double_swap(t_list **l1, t_list **l2)
{
	ft_swap(l1, 'a');
	ft_swap(l2, 'b');
	return (0);
}

int	ft_push(t_list **to_list, t_list **from_list, char ch)
{
	t_list	*temp1;

	if (*from_list)
	{
		temp1 = *from_list;
		*from_list = temp1 ->next;
		temp1 ->next = *to_list;
		*to_list = temp1;
	}
	ft_printf("p%c\n", ch);
	return (0);
}

int	ft_rotate(t_list **list, char ch)
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
	ft_printf("r%c\n", ch);
	return (0);
}

void	rra(t_list **list, char ch)
{
	t_list	*ptr;
	t_list	*temp;

	ptr = *list;
	temp = *list;
	if (ptr ->next)
	{
		while (ptr ->next ->next)
			ptr = ptr ->next;
		ptr ->next ->next = temp;
		*list = ptr ->next;
		ptr ->next = NULL;
		ft_printf("rr%c\n", ch);
	}
	return ;
}
