/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkovoor <mkovoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:31:52 by mkovoor           #+#    #+#             */
/*   Updated: 2022/08/09 12:09:23 by mkovoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushswap.h"
#include"libft/libft.h"

static int	ft_isspace(char ch)
{
	if (ch == ' ' || ch == '\f' || ch == '\n' || ch == '\r'
		|| ch == '\t' || ch == '\v')
		return (1);
	else
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
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!((ft_isdigit(str[i]) || str[i] == '-' || str[i] == '+')))
		{
			write(1, "Error\n", 6);
			exit(1);
		}
	}
	return (1);
}

int	ft_is_sorted(t_list *list)
{
	t_list	*ptr;

	ptr = list;
	while (ptr ->next)
	{
		if (*(int *)ptr ->content > *(int *)ptr ->next->content)
			return (0);
		ptr = ptr ->next;
	}
	return (1);
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
		num = str[i++] - '0' + (num * 10);
	if ((num > 2147483647 && sign == 1) || (num > 2147483648 && sign == -1))
	{
		write(1, "Error\n", 6);
		exit (1);
	}
	return (num * sign);
}
