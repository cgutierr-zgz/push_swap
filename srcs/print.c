/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:05:43 by cgutierr          #+#    #+#             */
/*   Updated: 2021/05/24 16:48:46 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
static void	print_lst(int i)
{
	printf("\t  %d\n", i);
}

void	print_stacks(t_push_swap *ps)
{
	printf("\tSTACK A\n");
	ft_stackiter(ps->a, print_lst);
	printf("\n\tSTACK B\n");
	ft_stackiter(ps->b, print_lst);
}

void	print_error(t_push_swap *ps, char *msg)
{
	printf("Error\n");
	ft_stackclear(&ps->a, free);
	ft_stackclear(&ps->b, free);
	if (1)
	{
		printf("%s\n[%d] : Value \"%s\"\n\n\n", msg, ps->index, ps->argv);
		//system("leaks a.out"); //TODO: valgrind
	}
	exit(1);
}
