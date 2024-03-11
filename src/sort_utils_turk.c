/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_turk.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:46:23 by mchamma           #+#    #+#             */
/*   Updated: 2024/02/22 13:28:09 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	arrage_stack(t_stack *stack, int num)
{
	int	moves;

	moves = ft_intabs(distance_top(stack, num)) + 1;
	if (distance_top(stack, num) < 0)
	{
		while (--moves > 0)
			reverse(stack, 1);
	}
	else
	{
		while (--moves > 0)
			rotate(stack, 1);
	}
}

int	find_cheapest_a(t_stack *a, int num_b)
{
	t_list	*aux;
	int		num_a;

	aux = a->lst;
	num_a = INT_MAX;
	while (aux)
	{
		if (num_b < (*(int *)aux->content) && (*(int *)aux->content) < num_a)
			num_a = (*(int *)aux->content);
		aux = aux->next;
	}
	if (num_b > find_max(a) || num_b < find_min(a))
		num_a = find_min(a);
	return (num_a);
}

int	find_cheapest_b(t_stack *a, t_stack *b)
{
	t_list	*aux;
	int		num_a;
	int		num_b;
	int		count;
	int		result;

	count = INT_MAX;
	aux = b->lst;
	while (aux)
	{
		num_b = *(int *)aux->content;
		num_a = find_cheapest_a(a, num_b);
		if (count > ft_intabs(distance_top(a, num_a))
			+ ft_intabs(distance_top(b, num_b)))
		{
			count = ft_intabs(distance_top(a, num_a))
				+ ft_intabs(distance_top(b, num_b));
			result = num_b;
		}
		aux = aux->next;
	}
	return (result);
}
