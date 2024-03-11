/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 09:22:46 by mchamma           #+#    #+#             */
/*   Updated: 2024/02/22 13:26:27 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_arg
{
	long int	*content;
	int			size;
}	t_arg;

typedef struct s_stack
{
	t_list	*lst;
	int		size;
	char	name;
}	t_stack;

// --------------------------------------- //

void	push(t_stack *src, t_stack *dest);

void	reverse(t_stack *stack, int print);

void	double_reverse(t_stack *a, t_stack *b);

void	rotate(t_stack *stack, int print);

void	double_rotate(t_stack *a, t_stack *b);

void	swap(t_stack *stack, int print);

void	double_swap(t_stack *a, t_stack *b);

// --------------------------------------- //

void	sort_radix(t_stack *a, t_stack *b); // not used

void	sort_selection(t_stack *a, t_stack *b);

void	sort_three(t_stack *a);

void	sort_turk(t_stack *a, t_stack *b);

void	sort(t_stack *a, t_stack *b);

// --------------------------------------- //

int	find_max(t_stack *stack);

int	find_min(t_stack *stack);

int	distance_top(t_stack *stack, int num);

void	take_num_to_top(t_stack *stack);

int	find_cheapest_a(t_stack *a, int num_b);

int	find_cheapest_b(t_stack *a, t_stack *b);

void	arrage_stack(t_stack *stack, int num);

#endif
