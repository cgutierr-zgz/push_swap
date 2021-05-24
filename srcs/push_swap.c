/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:03:30 by cgutierr          #+#    #+#             */
/*   Updated: 2021/05/24 19:45:36 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//gcc srcs/*.c srcs/lists/*.c srcs/utils/*.c && ARG="2 3 32 5 2   532  25 2 3 23 " && ./a.out $ARG 2 3 0 -2 +2

void iter_ps_list(t_push_swap *ps, t_stack *a)
{
	t_stack *ptr;

	if (a)
	{
		while (a)
		{
			if (ps->check_repeat == a->num)
				print_error(ps, "Repeated value");
			ptr = a->next;
			a = ptr;
		}
	}
}

static void init_args(int argc, char **argv, t_push_swap *ps)
{
	char *tmp;
	int i;
	int arg;

	arg = 0;
	ps->index = 1;
	while (arg < argc)
	{
		tmp = ft_strtok(argv[arg + 1], " ");
		ps->argv = argv[arg + 1];
		while (tmp != NULL)
		{
			i = ft_atoi(tmp, ps);
			tmp = ft_strtok(NULL, " ");
			ps->check_repeat = i;
			iter_ps_list(ps, ps->a);
			ft_stackadd_back(&ps->a, ft_stacknew(i));
			ps->index += 1;
		}
		arg += 1;
	}
	print_stacks(ps);
}

int main(int argc, char **argv)
{
	t_push_swap ps;
	t_stack *a;
	t_stack *b;

	if (argc < 2)
		print_error(&ps, "Not enough arguments");
	init_args(argc, argv, &ps);
	return (0);
}
