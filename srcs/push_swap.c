/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:03:30 by cgutierr          #+#    #+#             */
/*   Updated: 2021/05/20 17:34:02 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void print_lst(t_list *lst)
{
	int num;

	num = (int)lst->content;
	printf("num%d\n", num);
}

int main(int argc, char **argv)
{
	t_list a;
	t_list b;

	ft_bzero(&a, sizeof(t_list));
	ft_bzero(&b, sizeof(t_list));
	if (argc != 2)
		print_error(&a, &b);
	// Introducir el contenido en un t_list de ints
	// O en un t_list de ints enlazados
	char *tmp;
	tmp = strtok(argv[1], " ");
	while (tmp != NULL)
	{
		int x = atoi(tmp);
		printf("	[%s]\n", tmp);
		tmp = strtok(NULL, " ");
		ft_lstadd_back(&a, ft_lstnew(&x));
	}
	ft_lstiter(&a, print_lst);
	/*
	while (tmp) // FIXME: && strlen(tmp) > 0 (Maybe?)
	{
		printf("%s\n", argv[1]);
		tmp = strtok(argv[1]," ");
		printf("%s\n", tmp);
		printf("%s\n\n_________________\n", argv[1]);
		break;
		ft_lstadd_back(&a, ft_lstnew(atoi(tmp)));
	}

	ft_lstiter(&a, print_lst);*/

	return (0);
}
