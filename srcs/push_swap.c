/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:03:30 by cgutierr          #+#    #+#             */
/*   Updated: 2021/05/20 20:27:42 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//gcc srcs/*.c libft/*.c && ./a.out $ARG

void print_lst(int i)
{
	printf("[%d]\n",i);
}


static void init_args(int argc, char **argv, t_stack *a, t_stack *b)
{
	char *tmp;
	int arg = 0;
	int i = 1;
	//ft_stackiter(a, print_lst);
	while (arg < argc)
	{ //printf("%d,%d\n", arg, argc);
		tmp = strtok(argv[arg + 1], " ");

		while (tmp != NULL)
		{
			int c = 0;
			while (tmp[c])
			{ //FIXME: menoses, masases, etc - y mas solitos
				if ((tmp[c] < '0' || tmp[c] > '9') && tmp[c] != '-' && tmp[c] != '+')
					print_error(); //&a, &b);
				c++;
			}
			int x = ft_atoi(tmp);
		//	printf("%- 11d:[%s]\n", i, tmp);
			tmp = strtok(NULL, " "); // TODO: Implement my own strtok
		//	printf(">>%d<<\n", x);
			
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

	//printf("%d", atoi("+12345"));
	//printf("%d", ft_atoi("+12345"));

	if (argc < 2)
		print_error(); //&a, &b);
	// Introducir el contenido en un t_list de ints
	// O en un t_list de ints enlazados
	init_args(argc, argv, a, b);

	return (0);
}
