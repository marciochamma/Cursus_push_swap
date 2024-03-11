/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opex_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 09:17:03 by mchamma           #+#    #+#             */
/*   Updated: 2024/02/13 22:18:00 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, int print)
{
	t_list	*aux;

	stack->size = ft_lstsize(stack->lst);
	if (stack->size < 2)
		return ;
	aux = stack->lst;
	stack->lst = stack->lst->next;
	aux->next = stack->lst->next;
	stack->lst->next = aux;
	if (print && stack->name == 'a')
		ft_printf("sa\n");
	else if (print && stack->name == 'b')
		ft_printf("sb\n");
}

void	double_swap(t_stack *a, t_stack *b)
{
	swap(a, 0);
	swap(b, 0);
	ft_printf("ss\n");
}
