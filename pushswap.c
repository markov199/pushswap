/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkovoor <mkovoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 11:47:35 by mkovoor           #+#    #+#             */
/*   Updated: 2022/08/15 13:54:06 by mkovoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft/libft.h"
#include"pushswap.h"

int	ft_count_args(char *str)
{
	int	string;
	int	count;

	if (str)
	{
		count = 0;
		while (*str)
		{
			string = 0;
			while (*str == ' ')
				str++;
			while (*str && *str != ' ')
			{
				string = 1;
				str++;
			}
			if (string)
				count++;
		}
		return (count);
	}
	return (-1);
}

int	*ft_pushswap_split(int *nbr, char *str, int count)
{
	int		i;
	int		j;
	int		len;
	char	*word;

	i = 0;
	j = -1;
	while (count--)
	{
		while (str[i] == ' ')
		i++;
		len = 0;
		while (str[i + len] && str[i + len] != ' ')
			len++;
		if (len)
			word = ft_substr(str, i, len);
		if (!word || !ft_valid_input(word))
			exit (1);
		nbr[++j] = ft_push_swap_atoi(word);
		free (word);
		i = i + len;
	}
	return (nbr);
}

t_list	*ft_init_stack(t_list *stack, char *str)
{
	int		*args;
	int		i;
	t_list	*list;
	int		count;

	i = 0;
	list = stack;
	count = ft_count_args(str);
	if (count)
	{
		args = (int *)malloc(sizeof(int) * (count));
		if (!args)
			return (NULL);
		args = ft_pushswap_split(args, str, count);
		while (i < count)
		{
			ft_lstadd_back(&list, ft_lstnew(&args[i]));
			i++;
		}		
	}
	return (list);
}

t_list	*ft_index_list(t_list *list)
{
	t_list	*ptr1;
	t_list	*ptr2;
	int		*count;
	t_list	*stack;

	stack = NULL;
	ptr1 = list;
	while (ptr1)
	{
		ptr2 = list;
		count = (int *)malloc (sizeof(int *) * 1);
		*count = 0;
		while (ptr2)
		{
			if (*(int *)ptr1 ->content > *(int *)ptr2->content)
				(*count)++;
			ptr2 = ptr2 ->next;
		}
		ft_lstadd_back(&stack, ft_lstnew(count));
		ptr1 = ptr1 ->next;
	}
	return (stack);
}

int	main(int ac, char *av[])
{
	int		j;
	t_list	*stack_a;
	char	*str;

	if (ac > 1)
	{
		j = 0;
		stack_a = NULL;
		str = " ";
		while (++j < ac)
		{
			str = ft_strjoin_ps(str, av[j]);
			str = ft_strjoin_ps(str, " ");
		}
		ft_check_int_limits(str);
		stack_a = ft_init_stack(stack_a, str);
		ft_check_errors(stack_a);
		stack_a = ft_index_list(stack_a);
		ft_sort(&stack_a);
		return (0);
	}
	return (0);
}
