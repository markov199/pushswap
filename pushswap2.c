/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkovoor <mkovoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 11:47:35 by mkovoor           #+#    #+#             */
/*   Updated: 2022/08/08 13:06:17 by mkovoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft/libft.h"

typedef struct stack_size
{
	int	a;
	int	b;
}stk_size;

void ft_radix_sort(t_list **list);
int	ft_count_args(char *str);
int	ft_sort(t_list **list);
void	rra(t_list **list, char ch);
int ft_rotate (t_list **list, char ch);
int ft_position(t_list *list, int x);
int ft_push(t_list **to_list, t_list **from_list, char ch);
void	ft_lstprint(t_list *list);

void ft_optimalrotate(t_list **list, int data, char ch)
{
	t_list *ptr;
	int	rotate_count;
	int	size;

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

int ft_position(t_list *list, int x)
{
	int	count;
	int	size;
	t_list	*ptr;

	ptr = list;
	size = ft_lstsize(ptr);
	count = 0;
	while (count != size)
	{
		if(*(int *)ptr->content == x)
			return (count);
		count++;		
		ptr = ptr->next;

	}
	return (0);
}

static int	ft_isspace(char ch)
{
	if (ch == ' ' || ch == '\f' || ch == '\n' || ch == '\r'
		|| ch == '\t' || ch == '\v')
		return (1);
	else
		return (0);
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
	{
		num = str[i] - '0' + (num * 10);
		i++;
	}
	if ((num > 2147483647 && sign == 1) || (num > 2147483648 && sign == -1))
	{
		write(1, "Error\n", 6);
		exit (1);
	}
	return (num * sign);
}

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

int ft_swap(t_list **list, char ch)
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
	ft_printf("s%c\n",ch);
	return (0);
}


int ft_double_swap(t_list **l1, t_list **l2)
{
	ft_swap(l1, 'a');
	ft_swap(l2, 'b');
	return (0);
}

int ft_push(t_list **to_list, t_list **from_list, char ch)
{
	t_list	*temp1;
	
	if(*from_list)
	{
		temp1 = *from_list;
		*from_list = temp1 ->next;
		temp1 ->next = *to_list;
		*to_list = temp1;
	}
	ft_printf("p%c\n", ch);
	return (0);
}


int ft_rotate (t_list **list, char ch)
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
	ft_printf("r%c\n",ch);
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
		while(ptr ->next ->next)
			ptr = ptr ->next;
		ptr ->next ->next = temp;
		*list = ptr ->next;
		ptr ->next = NULL;
		ft_printf("rr%c\n", ch);
	}
return ;
}

int ft_min(t_list **list)
{
	t_list	*ptr1;
	t_list	*ptr2;
	int		i;
	int 	j;

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
		return (i);
	}
	return (-1);
}

int	ft_max(t_list **list)
{
	t_list	*ptr1;
	t_list	*ptr2;
	int		i;
	int		j;

	if (*list)
	{
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
	}
	return (*(int *)ptr1 ->content);
}


void ft_sort_3(t_list **list)
{
	t_list	*ptr;
	int		max;
	int		min;

	ptr = *list;
	min = ft_position(*list, 0);
	max = ft_position(*list, 2);
	if (min == 0 && max == 1)
	{
		ft_swap(list, 'a');
		ft_rotate(list, 'a');
	}
	else if (min == 1 && max == 0)
		ft_rotate(list, 'a');
	else if (min == 1 && max == 2)
		ft_swap(list, 'a');
	else if (min == 2 && max == 0)
	{
		ft_swap (list, 'a');
		rra(list, 'a');
	}
	else if(min == 2 && max == 1)
		rra(list, 'a');
	return ;
}

void ft_optimalpush(t_list **to, t_list **from, int i, char ch)
{
	char ch2;
	t_list *ptr;

	if(ch == 'a')
		ch2 = 'b';
	else if (ch == 'b')
		ch2 = 'a';
	ft_optimalrotate(from, i, ch2);
	ft_push(to, from, ch);
}


void	ft_sort_100(t_list **list, t_list *stack_temp, int size)
{
	int	count;
	int chunk;
	int i;
	t_list	*stack;
	stk_size	stacksize;

	stack = *list;
	chunk = 1;
	stacksize.b = 0;
	stacksize.a  = size;
	i =  (stacksize.a / 24);
	while (i--)
	{
		count = stacksize.a;
		while(count--)
		{
			if (*(int *)stack ->content < chunk * 24)
			{
				ft_optimalpush(&stack_temp, list, *(int *)stack ->content, 'b');
				if(stack_temp ->next)
					if (*(int *)stack_temp ->content < ((2 * chunk -1) * 24 / 2))
					{
						ft_rotate(&stack_temp, 'b');
					}
				stacksize.a--;
				stacksize.b++;
				stack = *list;
			}
			else
				stack = stack ->next;
		}
		chunk++;
	}
	while (stacksize.a--)
	{
		ft_push(&stack_temp, list, 'b');
		stacksize.b++;
	}
	while(stacksize.b--)
	{
		ft_optimalpush(list, &stack_temp, ft_max(&stack_temp), 'a');
	}
	ft_lstprint(*list);
}

int	ft_sort(t_list **list)
{
	int	i;
	t_list	*ptr;
	t_list	*stack_temp;
	

	ptr = *list;
	stack_temp = NULL;
	i = ft_lstsize(ptr);
	if (i == 2)
	{
		if (*(int *)ptr ->content > *(int *)ptr ->next->content)
			ft_swap(list, 'a');
	}
	if (i == 3)
		ft_sort_3(list);
	//  else if (i > 200)
	// 	ft_radix_sort(list);
	else
		ft_sort_100(list, stack_temp, i);
	// ft_optimalrotate(list, 8, 'a');
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
	int i;

	i = -1;
	while (str[++i])
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '-' || str[i] == '+'))
		{
			write(1, "Error\n", 6);
			exit(1);
		}
	return (1);
}

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

int	ft_is_sorted(t_list *list)
{
	t_list *ptr;

	ptr = list;
	while( ptr ->next)
	{
		if (*(int *)ptr ->content > *(int *)ptr ->next->content)
			return (0);
		ptr = ptr ->next;
	}
	return (1);
}

t_list	*ft_index_list(t_list *list)
{
	t_list	*ptr1;
	t_list	*ptr2;
	int 	*count;
	t_list *stack;

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

// void ft_radix_sort(t_list **list)
// {
// 	t_list	*ptr;
// 	t_list	*stack_b;
// 	int	j;
// 	int size;
// 	int rotate_count;
// 	int	count;
// 	stk_size	stack;

// 	j = 0;
// 	size = ft_lstsize(*list);
// 	stack_b = NULL;
// 	stack.b = 0;
// 	rotate_count = 0;
	
// 	while (size >> j)
// 	{	
// 		ptr = *list;	
// 		stack.a = ft_lstsize(*list);
// 		count = stack.a;
// 		while (count != 0)
// 		{
// 			if((*(int *)ptr->content >> j) & 1)
// 			{
// 				ptr = ptr ->next;
// 				rotate_count++;
// 			}
// 			else				
// 			{
// 				ft_optimalpush(&stack_b, list, *(int *)ptr ->content, 'b');
// 				stack.a--;
// 				stack.b++;
// 				ptr = *list;
// 				rotate_count = 0;
// 			}
// 			count--;
// 		}
// 		while(rotate_count--)
// 		{
// 			ft_rotate(list);
// 			ft_printf("ra\n");
// 		}
// 		// ft_lstprint(*temp_stack);	
// 		j++;
// 		count = stack.b;
// 		while(count != 0)
// 		{
// 			if(((* (int *)stack_b->content >> j) & 1))
// 			{
// 				ft_push(list, &stack_b);
// 				ft_printf("pn\n");
// 				stack.b--;
// 				stack.a++;
// 			}
// 			else
// 			{
// 				ft_rotate(&stack_b);
// 				ft_printf("rb\n");
// 			}
// 			count--;
// 		}
// 	}
// 		while (stack.b)
// 		{
// 			ft_push(list, &stack_b);
// 			ft_printf("pa\n");
// 			stack.b--;
// 		}
// }

int	main(int ac, char *av[])
{
	int		i;
	int		j;
	t_list	*stack_a;
	t_list	*stack_b;

	if (ac > 1)
	{
		j = 0;
		stack_a = NULL;
		stack_b = NULL;
		while (++j < ac)
			stack_a = ft_init_stack(stack_a, av[j]);
		if (!stack_a)
		{
			ft_printf("Error\n");
			exit(1);
		}
		ft_check_repeats(stack_a);
		if (ft_is_sorted(stack_a))
			exit (0);
		stack_a = ft_index_list(stack_a);
		ft_sort(&stack_a);
		ft_lstprint(stack_a);
		return (0);
	}
	return (0);
}
