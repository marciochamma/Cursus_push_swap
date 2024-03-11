/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:19:16 by mchamma           #+#    #+#             */
/*   Updated: 2024/02/22 13:04:04 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_turk(t_stack *a, t_stack *b)
{
	int	num_a;
	int	num_b;

	while (ft_lstsize(a->lst) > 3)
		push(a, b);
	sort_three(a);
	while (ft_lstsize(b->lst) != 0)
	{
		num_b = find_cheapest_b(a, b);
		num_a = find_cheapest_a(a, num_b);
		arrage_stack(a, num_a);
		arrage_stack(b, num_b);
		push(b, a);
	}
	take_num_to_top(a);
}
