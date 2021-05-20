/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:03:30 by cgutierr          #+#    #+#             */
/*   Updated: 2021/05/20 19:05:43 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//gcc srcs/*.c libft/*.c && ./a.out $ARG
void print_lst(t_list *lst)
{
	int num;

	num = (int)lst->content;
	printf("[%d]\n", num);
}

int main(int argc, char **argv)
{
	t_list a;
	t_list b;

	if (argc < 2)
		print_error(&a, &b);
	// Introducir el contenido en un t_list de ints
	// O en un t_list de ints enlazados
	char *tmp;
	tmp = strtok(argv[1], " ");
	//	int i = 1;

	while (tmp != NULL)
	{
		int x = atoi(tmp); // TODO: Use my own atoi
						   //	printf("%- 11d:[%s]\n", i, tmp);
		int x = atoi(tmp); // TODO: Use my own atoi
		printf("[%s]\n", tmp);
		tmp = strtok(NULL, " "); // TODO: Implement my own strtok
		ft_lstadd_back(&a, ft_lstnew(x));
		//i++;
	}
	ft_lstiter(&a, print_lst);

	return (0);
}
