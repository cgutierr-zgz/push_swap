/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_px.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 20:04:57 by cgutierr          #+#    #+#             */
/*   Updated: 2021/05/24 21:11:17 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
px || pb
push x
Toma el primer elemento en la parte superior de y y ponerlo en la
parte superior de x. No hace nada si y está vacío.
*/

static void	operation(t_stack *x, t_stack *y)
{
	//TODO: Fix this >:(
	ft_stackadd_front(&x, ft_stacknew(y->num));
	if(y->next)
	{
		y->num = y->next->num;
		y->next = NULL;
		ft_stackdelone(y->next);
	}
	else
	{
		y = NULL;
		ft_stackdelone(y);
	}
}

void	rule_px(t_push_swap *ps, char identifier)
{
	if (identifier == 'a')
	{
		if (ps->b)
			operation(ps->a, ps->b);
		write(1, "pa\n", 4);
	}
	else if (identifier == 'b')
	{
		if (ps->a)
			operation(ps->b, ps->a);
		write(1, "pb\n", 4);
	}
}
