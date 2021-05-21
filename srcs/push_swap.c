/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:03:30 by cgutierr          #+#    #+#             */
/*   Updated: 2021/05/20 21:58:20 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//gcc srcs/*.c srcs/lists/*.c srcs/utils/*.c && ARG="2 3 32 5 2   532  25 2 3 23 " && ./a.out $ARG 2 3 0 -2 +2

void	print_lst(int i)
{
	printf("[%d]\n", i);
}

static void	init_args(int argc, char **argv, t_push_swap *ps)
{
	char	*tmp;

	ps->arg = 0;
	ps->i = 1;
	while (ps->arg < argc)
	{
		tmp = ft_strtok(argv[arg + 1], " ");
		ps->argv = argv[arg + 1];
		while (tmp != NULL)
		{
			ps->aux = 0;
			while (tmp[ps->aux])
			{
				ps->c = tmp[ps->aux];
				if ((tmp[ps->aux] < '0' || tmp[ps->aux] > '9')
					&& tmp[ps->aux] != '-' && tmp[ps->aux] != '+')
					print_error(ps->a, ps->b, "Invalid value");
				ps->aux += 1;
			}
			ps->aux = ft_atoi(tmp, a, b);
			printf("%- 11d:[%s]\n", i, tmp);
			tmp = ft_strtok(NULL, " ");
			ft_stackadd_back(&ps->a, ft_stacknew(ps->aux));
			ps->i += 1;
		}
		ps->arg += 1;
	}
	ft_stackiter(ps->a, print_lst);
}

int main(int argc, char **argv)
{
	t_push_swap	ps;
	t_stack		*a;
	t_stack		*b;

	if (argc < 2)
		print_error(ps.a, ps.b, "Not enough arguments");
	init_args(argc, argv, &ps);
	return (0);
}
