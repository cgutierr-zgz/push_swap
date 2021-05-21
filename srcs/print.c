/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:05:43 by cgutierr          #+#    #+#             */
/*   Updated: 2021/05/21 23:57:43 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_error(t_push_swap *ps, char *msg)
{
	printf("Error\n");
	if (1)
	{
		// todo si no es necesario decir esto no ponerlo
		printf("%s\n[%d] : Value \"%s\"\n", msg, ps->index,ps->argv);
	}
	ft_stackclear(&ps->a, free);
	ft_stackclear(&ps->b, free);
	system("leaks a.out");
	exit(1);
}
