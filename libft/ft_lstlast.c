/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkovoor <mkovoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:47:29 by mkovoor           #+#    #+#             */
/*   Updated: 2022/07/14 12:18:40 by mkovoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstlast(t_list *lst)
{	
	t_list *ptr;

	ptr = lst;
	while (ptr)
	{
		if (!ptr ->next)
			return (ptr);
		ptr = ptr->next;
	}
	return (ptr);
}
