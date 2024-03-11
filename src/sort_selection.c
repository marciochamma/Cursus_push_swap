/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_selection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 09:36:13 by mchamma           #+#    #+#             */
/*   Updated: 2024/02/22 13:03:36 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_selection(t_stack *a, t_stack *b)
{
	a->size = ft_lstsize(a->lst);
	while (a->size > 3)
	{
		take_num_to_top(a);
		push(a, b);
		a->size = ft_lstsize(a->lst);
	}
	sort_three(a);
	b->size = ft_lstsize(b->lst);
	while (b->size > 0)
	{
		push(b, a);
		b->size = ft_lstsize(b->lst);
	}
}
