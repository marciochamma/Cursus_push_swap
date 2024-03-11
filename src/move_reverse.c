/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opex_reverse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:40:23 by mchamma           #+#    #+#             */
/*   Updated: 2024/02/20 11:50:32 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse(t_stack *stack, int print)
{
	t_list	*last;
	t_list	*prev;

	stack->size = ft_lstsize(stack->lst);
	if (stack->size < 2)
		return ;
	last = ft_lstlast(stack->lst);
	last = ft_lstnew(last->content);
	ft_lstadd_front(&stack->lst, last);
	prev = NULL;
	last = stack->lst;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	free(last);
	if (print && stack->name == 'a')
		ft_printf("rra\n");
	else if (print && stack->name == 'b')
		ft_printf("rrb\n");
}

void	double_reverse(t_stack *a, t_stack *b)
{
	reverse(a, 0);
	reverse(b, 0);
	ft_printf("rrr\n");
}
