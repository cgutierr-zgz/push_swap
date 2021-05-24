/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:03:30 by cgutierr          #+#    #+#             */
/*   Updated: 2021/05/24 16:22:56 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//gcc srcs/*.c srcs/lists/*.c srcs/utils/*.c && ARG="2 3 32 5 2   532  25 2 3 23 " && ./a.out $ARG 2 3 0 -2 +2

void	print_lst(int i)
{
	printf("[%d]\n", i);
}

void iter_ps_list(t_push_swap *ps, t_stack *a, void (*f)(t_push_swap *, void *))
{
	t_stack *ptr;

	if (a)
	{
		while (a)
		{
			ptr = a->next;
			f(ps, a->num);
			a = ptr;
		}
	}
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
					print_error(ps, "Invalid value, not a number or \"-\"/\"+\"");
				i += 1;
			}
			//TODO: checkear que es menor que INT_MAX y mayor que INT_MIN
			i = ft_atoi(tmp, ps);
			printf("%- 11d:[%s]\n", ps->index, tmp);
			tmp = ft_strtok(NULL, " ");
			//TODO: ft_stackiter(ps->a, check_repeated());
			ft_stackadd_back(&ps->a, ft_stacknew(i));
			ps->index += 1;
		}
		arg += 1;
	}

	//TODO: ft_stackiter(ps->, check que no esté vacío) // $ARG=" "
	if(ps->a == NULL)
		print_error(ps, "No value was added");
	ft_stackiter(ps->a, print_lst);
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
