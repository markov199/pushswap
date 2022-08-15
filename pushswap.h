/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkovoor <mkovoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:03:07 by mkovoor           #+#    #+#             */
/*   Updated: 2022/08/15 14:20:58 by mkovoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include<stdlib.h>
# include<unistd.h>
# include<stddef.h>
# include"libft/libft.h"

void	ft_radix_sort(t_list **list);
int		ft_count_args(char *str);
int		ft_sort(t_list **list);
void	rra(t_list **list, char ch);
int		ft_rotate(t_list **list, char ch);
int		ft_position(t_list *list, int x);
int		ft_push(t_list **to_list, t_list **from_list, char ch);
void	ft_lstprint(t_list *list);
void	ft_optimalrotate(t_list **list, int data, char ch);
int		ft_push_swap_atoi(char *str);
void	ft_lstprint(t_list *list);
int		ft_swap(t_list **list, char ch);
int		ft_double_swap(t_list **l1, t_list **l2);
int		ft_push(t_list **to_list, t_list **from_list, char ch);
int		ft_min(t_list **list);
int		ft_max(t_list **list);
void	ft_sort_3(t_list **list);
void	ft_optimalpush(t_list **to, t_list **from, int i, char ch);
void	ft_sort_500(t_list **list, t_list *stack_temp, int size);
int		ft_sort(t_list **list);
int		ft_check_repeats(t_list *list);
int		ft_valid_input(char *str);
int		ft_count_args(char *str);
int		*ft_pushswap_split(int *nbr, char *str, int count);
t_list	*ft_init_stack(t_list *stack, char *str);
int		ft_is_sorted(t_list *list);
t_list	*ft_index_list(t_list *list);
void	ft_sort_100(t_list **list, t_list *stack_temp, int size);
t_list	*ft_chunk_100(t_list **list, t_list *stack_temp, int size, int chunk);
t_list	*ft_chunk_500(t_list **list, t_list *stack_temp, int chnk, int chnksze);
void	ft_check_errors(t_list *list);
char	*ft_strjoin_ps(char *s1, char *s2);
void	ft_check_int_limits(char *str);
#endif