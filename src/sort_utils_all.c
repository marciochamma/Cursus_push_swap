/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:32:04 by mchamma           #+#    #+#             */
/*   Updated: 2024/02/22 13:25:16 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_stack *stack)
{
	t_list	*aux;
	int		max;

	aux = stack->lst;
	max = *(int *)aux->content;
	while (aux != NULL)
	{
		if (max < *(int *)aux->content)
			max = *(int *)aux->content;
		aux = aux->next;
	}
	return (max);
}

int	find_min(t_stack *stack)
{
	t_list	*aux;
	int		min;

	aux = stack->lst;
	min = *(int *)aux->content;
	while (aux != NULL)
	{
		if (min > *(int *)aux->content)
			min = *(int *)aux->content;
		aux = aux->next;
	}
	return (min);
}

int	distance_top(t_stack *stack, int num)
{
	t_list	*aux;
	int		distance;

	stack->size = ft_lstsize(stack->lst);
	aux = stack->lst;
	distance = 0;
	while (*(int *)aux->content != num)
	{
		distance++;
		aux = aux->next;
	}
	if (distance < (stack->size - distance))
		return (distance);
	else
		return (distance - stack->size);
}

void	take_num_to_top(t_stack *stack)
{
	int	num;
	int	distance;

	num = find_min(stack);
	distance = distance_top(stack, num);
	stack->size = ft_lstsize(stack->lst);
	while (num != *(int *)stack->lst->content)
	{
		if (distance > 0)
			rotate(stack, 1);
		else
			reverse(stack, 1);
	}
}
