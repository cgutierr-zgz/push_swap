/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_sx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 20:04:57 by cgutierr          #+#    #+#             */
/*   Updated: 2021/05/27 16:25:02 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
sa || sb || ss
swap x
Intercambiar los primeros 2 elementos en la parte superior de la pila x.
No hace nada si sólo hay uno o ningún elementos.
*/

static void	swap(t_stack *x)
{
	int	temp;

	temp = x->num;
	x->num = x->next->num;
	x->next->num = temp;
}

void	rule_sx(t_push_swap *ps, char identifier, int print)
{
	ps->num_movements += 1;
	if (identifier == 'a')
	{
		if (ps->a && ps->a->next)
			swap(ps->a);
		if (print)
			write(1, "sa\n", 3);
	}
	else if (identifier == 'b')
	{
		if (ps->b && ps->b->next)
			swap(ps->b);
		if (print)
			write(1, "sb\n", 3);
	}
	else if (identifier == 's')
	{
		if (ps->a && ps->a->next)
			swap(ps->a);
		if (ps->b && ps->b->next)
			swap(ps->b);
		if (print)
			write(1, "ss\n", 3);
	}
}
