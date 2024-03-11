/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opex_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:22:28 by mchamma           #+#    #+#             */
/*   Updated: 2024/02/13 22:16:26 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack, int print)
{
	t_list	*first;

	stack->size = ft_lstsize(stack->lst);
	if (stack->size < 2)
		return ;
	first = ft_lstnew(stack->lst->content);
	ft_lstadd_back(&stack->lst, first);
	first = stack->lst;
	stack->lst = stack->lst->next;
	free(first);
	if (print && stack->name == 'a')
		ft_printf("ra\n");
	else if (print && stack->name == 'b')
		ft_printf("rb\n");
}

void	double_rotate(t_stack *a, t_stack *b)
{
	rotate(a, 0);
	rotate(b, 0);
	ft_printf("rr\n");
}
