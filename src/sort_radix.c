/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:20:35 by mchamma           #+#    #+#             */
/*   Updated: 2024/02/22 13:31:57 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Not used, only for positive numbers

static int	get_max_bit(t_stack *stack)
{
	t_list	*aux;
	int		max_content;
	int		max_bits;

	aux = stack->lst;
	max_content = 0;
	while (aux)
	{
		if (ft_intabs(*(int *)aux->content) > max_content)
			max_content = ft_intabs(*(int *)aux->content);
		aux = aux->next;
	}
	max_bits = 0;
	while ((max_content >> max_bits) > 0)
		max_bits++;
	return (max_bits);
}

void	sort_radix(t_stack *a, t_stack *b)
{
	t_list	*aux;
	int		i;
	int		j;
	int		max_bits;
	int		size;

	max_bits = get_max_bit(a);
	size = ft_lstsize(a->lst);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			aux = a->lst;
			if (((*(int *)aux->content >> i) & 1) == 1)
				rotate(a, 1);
			else
				push(a, b);
			j++;
		}
		while (ft_lstsize(b->lst) != 0)
			push(b, a);
		i++;
	}
}
