/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opex_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:31:25 by mchamma           #+#    #+#             */
/*   Updated: 2024/02/13 22:12:44 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *src, t_stack *dest)
{
	t_list	*aux;

	src->size = ft_lstsize(src->lst);
	if (src->size < 1)
		return ;
	aux = ft_lstnew(src->lst->content);
	ft_lstadd_front(&dest->lst, aux);
	aux = src->lst;
	src->lst = src->lst->next;
	free(aux);
	if (dest->name == 'a')
		ft_printf("pa\n");
	else if (dest->name == 'b')
		ft_printf("pb\n");
}
