/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:05:43 by cgutierr          #+#    #+#             */
/*   Updated: 2021/05/24 15:56:53 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_error(t_push_swap *ps, char *msg)
{
	printf("Error\n");
	ft_stackclear(&ps->a, free);
	ft_stackclear(&ps->b, free);
	if (1)
	{
		printf("%s\n[%d] : Value \"%s\"\n", msg, ps->index,ps->argv);
		//system("leaks a.out");
	}
	exit(1);
}
