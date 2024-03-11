/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:42:08 by mchamma           #+#    #+#             */
/*   Updated: 2024/02/15 15:32:46 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Frees the memory of the entire linked list

#include "libft.h"

void	ft_lstfree(t_list *list)
{
	t_list	*aux;

	while (list != NULL)
	{
		aux = list->next;
		free(list);
		list = aux;
	}
}
