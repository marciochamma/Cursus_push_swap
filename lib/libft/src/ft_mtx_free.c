/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtx_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:17:35 by mchamma           #+#    #+#             */
/*   Updated: 2024/02/21 13:18:24 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Free the memory allocation of a matrix (two dimension array)

#include "libft.h"

void	free_matrix(char **mtx)
{
	int	i;

	i = 0;
	while (mtx[i])
	{
		free (mtx[i]);
		i++;
	}
	free (mtx);
}
