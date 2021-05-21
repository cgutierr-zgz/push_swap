/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:03:30 by cgutierr          #+#    #+#             */
/*   Updated: 2021/05/22 00:01:29 by cgutierr         ###   ########.fr       */
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
	int i;
	int arg;

	i = 0;
	arg = 0;
	ps->index = 1;
	while (arg < argc)
	{
		tmp = ft_strtok(argv[arg + 1], " ");
		ps->argv = argv[arg + 1];
		while (tmp != NULL)
		{
			i = 0;
			while (tmp[i])
			{
				if ((tmp[i] < '0' || tmp[i] > '9')
					&& tmp[i] != '-' && tmp[i] != '+')
					print_error(ps, "Invalid value");
				i += 1;
			}// TODO: Comparar que sea menor que INT MAX o INT MIN Si todo ok atoi
			i = ft_atoi(tmp, ps);
			printf("%- 11d:[%s]\n", ps->index, tmp);
			tmp = ft_strtok(NULL, " ");
			// TODO: Check que no esté repetido antes de añadirlo al stack
			// Si sí => Error
			ft_stackadd_back(&ps->a, ft_stacknew(i));
			ps->index += 1;
		}
		arg += 1;
	}
	//TODO: Check si argumentos no hay !!!!!!!! check que el stack contenga COSAS SI ESTA VACIO ERROR NO ARGUMENTOS validos almenos

	//ft_stackiter(ps->a, print_lst);
}

int main(int argc, char **argv)
{
	t_push_swap	ps;
	t_stack		*a;
	t_stack		*b;

	if (argc < 2)
		print_error(&ps, "Not enough arguments");
	init_args(argc, argv, &ps);
	return (0);
}
