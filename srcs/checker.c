/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:41:17 by cgutierr          #+#    #+#             */
/*   Updated: 2021/06/03 13:13:31 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:03:30 by cgutierr          #+#    #+#             */
/*   Updated: 2021/05/26 20:14:23 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**	if (0)
**		system("leaks checker");
*/

void	exit_push_swap(t_push_swap *ps)
{
	if (0)
	{
		print_stacks(ps);
		printf("\nMovements: %d\n", ps->num_movements);
	}
	exit(0);
}

static void	clean_split(char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		free(tmp[i]);
		i++;
	}
	if (tmp)
		free(tmp);
}

static void	check_repeated(t_push_swap *ps, t_stack *a)
{
	t_stack	*ptr;

	if (a)
	{
		while (a)
		{
			if (ps->check_repeat == a->num)
				print_error(ps, "Repeated number");
			ptr = a->next;
			a = ptr;
		}
	}
}

static void	init_args(int argc, char **argv, t_push_swap *ps)
{
	char	**tmp;
	int		num;
	int		arg;
	int		i;

	arg = 1;
	while (arg < argc)
	{
		tmp = ft_split(argv[arg], ' ');
		ps->argv = argv[arg];
		i = 0;
		while (tmp[i])
		{
			num = ft_atoi(tmp[i], ps);
			ps->check_repeat = num;
			check_repeated(ps, ps->a);
			ft_stackadd_back(&ps->a, ft_stacknew(num));
			i++;
		}
		clean_split(tmp);
		arg += 1;
	}
	if (ps->a == NULL)
		exit(1);
	start_checking(argc, argv, ps);
}

int	main(int argc, char **argv)
{
	t_push_swap	ps;
	t_stack		*a;
	t_stack		*b;

	ps.num_movements = 0;
	if (argc < 2)
		return (1);
	init_args(argc, argv, &ps);
	return (0);
}
