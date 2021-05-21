/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:05:43 by cgutierr          #+#    #+#             */
/*   Updated: 2021/05/20 21:42:09 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_error(t_push_swap *ps, char *msg)
{
	printf("Error\n");
	if (1)
	{
		//TODO: Invalid value at argument [0 + 1], index[aux], char [ps->c] global index[index];
		/*
		Error
		"Mensaje"
		[ps->index] : Value "argv[x]"" at index[ps->aux] => Invalid char [c]
		*/
		printf("%s\n[%d] : Value \"%s\" at index %d \'%c\'", ps->index,ps->argv,ps->aux, ps->c)
		//printf("\t%s\nValue at index %d, %c[%d]\n", msg, ps->index, ps->c, ps->aux);
	}
	ft_stackclear(&ps->a, free);
	ft_stackclear(&ps->b, free);
	exit(1);
}
