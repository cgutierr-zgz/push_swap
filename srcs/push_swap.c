/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:03:30 by cgutierr          #+#    #+#             */
/*   Updated: 2021/05/20 19:50:44 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//gcc srcs/*.c libft/*.c && ./a.out $ARG
void print_lst(t_stack *lst)
{
	printf("aaa%d", lst->num);
	//printf("[%d]\n", lst->num);
}

int main(int argc, char **argv)
{
	t_stack a;
	t_stack b;

	if (argc < 2)
		print_error(&a, &b);
	// Introducir el contenido en un t_list de ints
	// O en un t_list de ints enlazados
	char *tmp;
	int arg = 0;
	int i = 1;
	while (arg < argc)
	{ //printf("%d,%d\n", arg, argc);
		tmp = strtok(argv[arg + 1], " ");

		while (tmp != NULL)
		{
			int c = 0;
			while (tmp[c])
			{
				if (tmp[c] < '0' || tmp[c] > '9')
					print_error(&a, &b);
				c++;
			}
			int x = ft_atoi(tmp);
			printf("%- 11d:[%s]\n", i, tmp);
			tmp = strtok(NULL, " "); // TODO: Implement my own strtok
			ft_stackadd_back(&a, ft_stacknew(&x));
			i++;
		}
		arg++;
	}
	ft_stackiter(&a, print_lst);

	return (0);
}
