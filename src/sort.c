/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:27:58 by mchamma           #+#    #+#             */
/*   Updated: 2024/02/21 18:24:51 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_stack *stack)
{
	t_list	*aux;

	aux = stack->lst;
	while (aux && aux->next)
	{
		if (*(int *)aux->content > *(int *)aux->next->content)
			return (0);
		aux = aux->next;
	}
	return (1);
}

void	sort(t_stack *a, t_stack *b)
{
	if (check_sort(a))
		return ;
	a->size = ft_lstsize(a->lst);
	if (a->size == 2)
		swap(a, 1);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size < 6)
		sort_selection(a, b);
	else
		sort_turk(a, b);
}
