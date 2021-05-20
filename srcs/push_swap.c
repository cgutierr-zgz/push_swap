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

static void	init_args(int argc, char **argv, t_stack *a, t_stack *b)
{
	char	*tmp;
	int		arg;
	int		i;

	arg = 0;
	i = 1;
	while (arg < argc)
	{
		//tmp = strtok(argv[arg + 1], " ");
		tmp = ft_strtok(argv[arg + 1], " ");

		while (tmp != NULL)
		{
			int c = 0;
			while (tmp[c])
			{
				if ((tmp[c] < '0' || tmp[c] > '9')
					&& tmp[c] != '-' && tmp[c] != '+')
					print_error(a, b, "Invalid value");
				c++;
			}
			int x = ft_atoi(tmp, a, b);
			printf("%- 11d:[%s]\n", i, tmp);
		//tmp = strtok(NULL, " "); // TODO: Implement my own strtok
			tmp = ft_strtok(NULL, " ");
			ft_stackadd_back(&a, ft_stacknew(x));
			i++;
		}
		arg++;
	}
	ft_stackiter(a, print_lst);
}

int main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	if (argc < 2)
		print_error(a, b, "Not enough values");
	init_args(argc, argv, a, b);
	return (0);
}
