/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:47:32 by mchamma           #+#    #+#             */
/*   Updated: 2024/02/15 15:30:45 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Print the node content of the linked list

#include "libft.h"

void	ft_lstprint(t_list *list)
{
	t_list	*aux;

	aux = list;
	while (aux != NULL)
	{
		if (aux->next == NULL)
			ft_printf("%d", *(int *)aux->content);
		else
			ft_printf("%d ", *(int *)aux->content);
		aux = aux->next;
	}
	ft_printf("\n");
}
