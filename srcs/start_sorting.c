/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:03:30 by cgutierr          #+#    #+#             */
/*   Updated: 2021/05/26 13:34:17 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void start_push_swap(int argc, char **argv, t_push_swap *ps)
{
	int size = ft_stacksize(ps->a);
	if (size == 1)
		exit(0);
	else if (size == 2)
	{
		if (ps->a->num > ps->a->next->num)
			rule_sx(ps, 'a');
		exit(0);
	}
	else if (size == 3)
	{
		if (ps->a->num > ps->a->next->num && ps->a->num < ps->a->next->next->num && ps->a->next->num < ps->a->next->next->num)
		{
			rule_sx(ps, 'a');
			exit(0);
		}
		else if (ps->a->num > ps->a->next->num && ps->a->num > ps->a->next->next->num && ps->a->next->num > ps->a->next->next->num)
		{
			rule_sx(ps, 'a');
			rule_rx_rrx(ps, 'a', 2);
			exit(0);
		}
		else if (ps->a->num > ps->a->next->num && ps->a->num > ps->a->next->next->num && ps->a->next->num < ps->a->next->next->num)
		{
			rule_rx_rrx(ps, 'a', 1);
			exit(0);
		}
		else if (ps->a->num < ps->a->next->num && ps->a->num < ps->a->next->next->num && ps->a->next->num > ps->a->next->next->num)
		{
			rule_sx(ps, 'a');
			rule_rx_rrx(ps, 'a', 1);
			exit(0);
		}
		else if (ps->a->num < ps->a->next->num && ps->a->num > ps->a->next->next->num && ps->a->next->num > ps->a->next->next->num)
		{
			rule_rx_rrx(ps, 'a', 2);
			exit(0);
		}
	}

	if (0)
		system("leaks push_swap");
	exit(0);
}
