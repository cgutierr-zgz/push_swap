/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_px.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 20:04:57 by cgutierr          #+#    #+#             */
/*   Updated: 2021/05/26 15:54:38 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
px || pb
push x
Toma el primer elemento en la parte superior de y y ponerlo en la
parte superior de x. No hace nada si y está vacío.
*/

void	rule_px(t_push_swap *ps, char identifier)
{
	ps->num_movements += 1;
	if (identifier == 'a')
	{
		if (ps->b)
		{
			ft_stackadd_front(&ps->a, ft_stacknew(ps->b->num));
			ft_stackdelone(ps->b);
			if (ps->b->next)
				ps->b = ps->b->next;
			else
				ps->b = NULL;
		}
		write(1, "pa\n", 4);
	}
	else if (identifier == 'b')
	{
		if (ps->a)
		{
			ft_stackadd_front(&ps->b, ft_stacknew(ps->a->num));
			ft_stackdelone(ps->a);
			if (ps->a->next)
				ps->a = ps->a->next;
			else
				ps->a = NULL;
		}
		write(1, "pb\n", 4);
	}
}
