/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:31:19 by mchamma           #+#    #+#             */
/*   Updated: 2024/02/24 13:13:28 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(char **mtx, long int *arr)
{
	ft_printf("Error\n");
	if (arr != NULL)
		free (arr);
	free_matrix(mtx);
	exit (0);
}

char	**parse_input(int argc, char **argv)
{
	char	**argv_adj;
	int		i;

	if (argc < 2)
		exit (0);
	else if (argc == 2)
		argv_adj = ft_split(argv[1], ' ');
	else
	{
		argv_adj = (char **)calloc((argc), sizeof(char *));
		if (!argv_adj)
			exit(1);
		i = 0;
		while (++i < argc)
			argv_adj[i - 1] = ft_strdup(argv[i]);
	}
	i = 0;
	while (argv_adj[i])
	{
		if (!ft_isinteger(argv_adj[i]))
			error_exit(argv_adj, NULL);
		i++;
	}
	return (argv_adj);
}

void	check_input(int argc, char **argv, t_arg *array)
{
	char		**argv_adj;
	int			i;

	argv_adj = parse_input(argc, argv);
	array->size = 0;
	while (argv_adj[array->size])
		array->size++;
	array->content = (long int *)calloc((array->size + 1), sizeof(long int));
	if (!array->content)
		exit(1);
	i = 0;
	while (i < array->size)
	{
		array->content[i] = ft_atol(argv_adj[i]);
		if (array->content[i] > INT_MAX || array->content[i] < INT_MIN)
			error_exit(argv_adj, array->content);
		i++;
	}
	if (ft_array_repeat(array->content, i))
		error_exit(argv_adj, array->content);
	free_matrix(argv_adj);
}

void	create_stack(t_stack *a, t_stack *b, t_arg *array)
{
	t_list	*aux;
	int		i;

	a->lst = NULL;
	b->lst = NULL;
	a->name = 'a';
	b->name = 'b';
	a->size = array->size;
	b->size = 0;
	i = 0;
	while (i < a->size)
	{
		aux = ft_lstnew(&array->content[i]);
		ft_lstadd_back(&a->lst, aux);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_arg	array;
	t_stack	a;
	t_stack	b;

	check_input(argc, argv, &array);
	create_stack(&a, &b, &array);
	sort(&a, &b);
	ft_lstfree(a.lst);
	ft_lstfree(b.lst);
	free (array.content);
	return (0);
}
