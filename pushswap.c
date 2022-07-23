/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkovoor <mkovoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:15:36 by mkovoor           #+#    #+#             */
/*   Updated: 2022/07/11 11:44:52 by mkovoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<stdio.h>
#include"libft/libft.h"

int	ft_no_repeats(int *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if(str[i] == str[j])
			return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_all_digits(char *str)
{
	if (str)
	{
		if (*str == '-' || *str == '+')
			str++;
		while (*str >= '0' && *str <= '9')
			str++;
		if (*str == '\0')
			return (1);
		else
			return (0);
	}
	return (-1);
}

char	*ft_get_next_word(char *str, int *i)
{
	int			start;

	if (str)
	{
		ft_printf("%d..i\n", *i);
		while (str[*i])
		{
			if (str[*i] == ' ')
				(*i)++;
			start = *i;
			while (str[*i] && str[*i] != ' ')
				(*i)++;
			if (*i - start)
				return (ft_substr(str, start, *i - start));
		}
	}
	return (NULL);
}

int	ft_count_words(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (*str)
		{
			while (*str == ' ')
				str++;
			if (*str)
				i++;
			while (*str && *str != ' ')
				str++;
		}
	}
	return (i);
}

int	*ft_split_str(char *str)
{
	int		i;
	int		count;
	int		*stack_a;
	char	*word;

	i = -1;
	count = ft_count_words(str);
	stack_a = (int *)ft_calloc(sizeof(int), count + 1);
	if (!stack_a)
		return (NULL);
	while (count > ++i)
	{
		word = ft_get_next_word(str, &i);
		// ft_printf("%s word\n", word);
		if (!ft_all_digits(word))
		{
			free (stack_a);
			ft_printf("Error in input. check format");
			return (NULL);
		}
		stack_a[i] = ft_atoi(word);
	}
	return (stack_a);
}

int ft_print_list(t_list *list)
{
	ft_printf("list print\n");
	while(list)
	{		
		ft_printf("%d\n", *(int *)list ->content);
		list = list ->next;
	}
	return (0);
}

int sa(t_list **list)
{
	t_list *ptr;
	t_list *temp;

	ptr = *list;
	temp = ptr ->next;
	if (temp)
	{
		ptr ->next = temp ->next;
		temp ->next = ptr;
		*list = temp;
	}
	return (0);
}

int sb(t_list **list)
{
	t_list *ptr;
	t_list *temp;

	ptr = *list;
	temp = ptr ->next;
	if (temp)
	{
		ptr ->next = temp ->next;
		temp ->next = ptr;
		*list = temp;
	}
	return (0);
}

int ss(t_list **l1, t_list **l2)
{
	sa(l1);
	sb(l2);
	return (0);
}

int pa(t_list **l1, t_list **l2)
{
	t_list	*temp1;
	
	if(*l2)
	{
		temp1 = *l2;
		*l2 = temp1 ->next;
		temp1 ->next = *l1;
		*l1 = temp1;
	}
	return (0);
}

int pb(t_list **l1, t_list **l2)
{
	t_list	*temp;

	if (*l1)
	{
		temp = *l1;
		*l1 = temp ->next;
		temp ->next = *l2;
		*l2 = temp;
	}
	return (0);
}

int ra (t_list **list)
{
	t_list	*ptr;

	ptr = ft_lstlast(*list);
	if (ptr)
	{
		ptr ->next = *list;
		*list = ptr ->next ->next;
		ptr ->next = NULL;
	}
	return (0);
}

int rb(t_list **list)
{
	t_list	*ptr;

	ptr = ft_lstlast(*list);
	if (ptr)
	{
		ptr ->next = *list;
		*list = ptr ->next ->next;
		ptr ->next = NULL;
	}
	return (0);
}

int rr (t_list **l1, t_list **l2)
{
	ra(l1);
	rb(l2);
	return (0);
}

// int rra()
// {}

int	main(int ac, char *av[])
{
	int	i;
	int	j;
	int	*args;
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*ptr;

	
	j = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (ac >= 2)
	{
		while (++j < ac)
		{
			i = 0;
			args = ft_split_str(av[j]);
			if (!args)
				return (0);
			// if (!ft_no_repeats(args))
			// 	ft_printf("Error!! arguments are repeated");
			
			else
			{
				
				while (args[i])
				{					
					ft_lstadd_back(&stack_a, ft_lstnew(&args[i]));
					i++;
				}
			}
		}
		ft_print_list(stack_a);
	}	
	return (0);
}
