/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:08:37 by mchamma           #+#    #+#             */
/*   Updated: 2024/02/21 17:30:53 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *stack)
{
	int	first;
	int	second;
	int	third;

	first = *(int *)stack->lst->content;
	second = *(int *)stack->lst->next->content;
	third = *(int *)stack->lst->next->next->content;
	if (first > second && first < third && second < third)
		swap(stack, 1);
	else if (first < second && first > third && second > third)
		reverse(stack, 1);
	else if (first > second && first > third && second < third)
		rotate(stack, 1);
	else if (second > third)
	{
		swap(stack, 1);
		if (first < second && first < third)
			rotate(stack, 1);
		else if (first > second && first > third)
			reverse(stack, 1);
	}
}
