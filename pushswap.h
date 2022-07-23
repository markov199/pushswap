/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkovoor <mkovoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:03:07 by mkovoor           #+#    #+#             */
/*   Updated: 2022/07/19 11:18:16 by mkovoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSHSWAP_H
#define PUSHSWAP_H

# include<stdlib.h>
# include<unistd.h>
# include<stddef.h>

typedef struct d_list
{
	int value;
	int	index;
	struct d_list *next;
}int_list; 
typedef struct s_list
{
	void *content;
	struct s_list *next;
} t_list;
#endif