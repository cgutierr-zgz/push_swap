/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:05:43 by cgutierr          #+#    #+#             */
/*   Updated: 2021/05/25 19:40:25 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	print_lst(int i)
{
	printf("\t  %d\n", i);
}

void	print_stacks(t_push_swap *ps)
{
	write(1, "\n\tSTACK A\n", 10);
	ft_stackiter(ps->a, print_lst);
	write(1, "\tSTACK B\n", 10);
	ft_stackiter(ps->b, print_lst);
}

void	print_error(t_push_swap *ps, char *msg)
{
	write(1, "Error\n", 7);
	ft_stackclear(&ps->a, free);
	ft_stackclear(&ps->b, free);
	if (1)
		printf("%s\nValue [%s]\n", msg, ps->argv);
	if (0)
		system("leaks push_swap");
	exit(1);
}
