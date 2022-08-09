/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkovoor <mkovoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:14:10 by mkovoor           #+#    #+#             */
/*   Updated: 2022/08/09 11:45:08 by mkovoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushswap.h"
#include"libft/libft.h"

int	ft_position(t_list *list, int x)
{
	int		count;
	int		size;
	t_list	*ptr;

	ptr = list;
	size = ft_lstsize(ptr);
	count = 0;
	while (count != size)
	{
		if (*(int *)ptr->content == x)
			return (count);
		count++;
		ptr = ptr->next;
	}
	return (0);
}

int	ft_min(t_list **list)
{
	t_list	*ptr1;
	t_list	*ptr2;
	int		i;
	int		j;

	if (*list)
	{
		i = 0;
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
		return (*(int *)ptr1 ->content);
	}
	return (-1);
}

int	ft_max(t_list **list)
{
	t_list	*ptr1;
	t_list	*ptr2;
	int		i;
	int		j;

	ptr1 = *list;
	ptr2 = ptr1 ->next;
	i = 0;
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
	return (*(int *)ptr1 ->content);
}

void	ft_optimalpush(t_list **to, t_list **from, int i, char ch)
{
	char	ch2;

	if (ch == 'a')
		ch2 = 'b';
	else
		ch2 = 'a';
	ft_optimalrotate(from, i, ch2);
	ft_push(to, from, ch);
}

void	ft_optimalrotate(t_list **list, int data, char ch)
{
	t_list	*ptr;
	int		rotate_count;
	int		size;

	ptr = *list;
	size = ft_lstsize(*list);
	rotate_count = ft_position(ptr, data);
	if (rotate_count > size / 2)
	{
		rotate_count = size - rotate_count;
		while (rotate_count--)
			rra(list, ch);
	}
	else
		while (rotate_count--)
			ft_rotate(list, ch);
}
