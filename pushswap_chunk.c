/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_chunk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkovoor <mkovoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 14:53:10 by mkovoor           #+#    #+#             */
/*   Updated: 2022/08/15 14:20:38 by mkovoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft/libft.h"
#include"pushswap.h"

t_list	*ft_chunk_100(t_list **list, t_list *stack_temp, int chnk, int chnksze)
{
	int			count;
	t_list		*stack;

	stack = *list;
	while (chnk--)
	{
		count = ft_lstsize(*list);
		while (count--)
		{		
			if (*(int *)stack ->content < chnksze)
			{
				ft_optimalpush(&stack_temp, list, *(int *)stack ->content, 'b');
				if (stack_temp -> next \
				&& *(int *)stack_temp->content < (chnksze - 24) + 12)
					ft_rotate(&stack_temp, 'b');
				stack = *list;
			}
			else
				stack = stack ->next;
		}
		chnksze += 24;
	}
	return (stack_temp);
}

t_list	*ft_chunk_500(t_list **list, t_list *stack_temp, int chnk, int chnksze)
{
	int			count;
	t_list		*stack;

	stack = *list;
	while (chnk--)
	{
		count = ft_lstsize(*list);
		while (count--)
		{		
			if (*(int *)stack ->content < chnksze)
			{
				ft_optimalpush(&stack_temp, list, *(int *)stack ->content, 'b');
				if (stack_temp -> next \
				&& *(int *)stack_temp->content < (chnksze - 54) + 27)
					ft_rotate(&stack_temp, 'b');
				stack = *list;
			}
			else
				stack = stack ->next;
		}
		chnksze += 54;
	}
	return (stack_temp);
}

void	ft_check_errors(t_list *list)
{
	if (!list)
	{
		ft_printf("Error\n");
		exit(1);
	}
	ft_check_repeats(list);
	if (ft_is_sorted(list))
		exit (0);
}

char	*ft_strjoin_ps(char *s1, char *s2)
{
	char			*string;
	int				j;

	j = 0;
	string = malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof (char) + 1);
	if (string == NULL)
		return (NULL);
	while (*s1)
	{
		string[j++] = *s1;
		s1 ++;
	}
	while (*s2)
	{
		string[j++] = *s2;
		s2 ++;
	}
	string[j] = '\0';
	return (string);
}

void	ft_check_int_limits(char *str)
{
	int		i;
	int		len;
	char	*word;

	i = 0;
	while (str[i])
	{
		while (str[i] == ' ')
		i++;
		len = 0;
		while (str[i + len] && str[i + len] != ' ')
			len++;
		if (len)
		{
			word = ft_substr(str, i, len);
			ft_push_swap_atoi(word);
			free (word);
		}	
		i = i + len;
	}
}
