/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:03:30 by cgutierr          #+#    #+#             */
/*   Updated: 2021/05/26 16:15:37 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_push_swap *ps)
{
	if (ps->a->num > ps->a->next->num && ps->a->num < ps->a->next->next->num
		&& ps->a->next->num < ps->a->next->next->num)
		rule_sx(ps, 'a');
	else if (ps->a->num > ps->a->next->num && ps->a->num
		> ps->a->next->next->num && ps->a->next->num > ps->a->next->next->num)
	{
		rule_sx(ps, 'a');
		rule_rx_rrx(ps, 'a', 2);
	}
	else if (ps->a->num > ps->a->next->num && ps->a->num
		> ps->a->next->next->num && ps->a->next->num < ps->a->next->next->num)
		rule_rx_rrx(ps, 'a', 1);
	else if (ps->a->num < ps->a->next->num && ps->a->num
		< ps->a->next->next->num && ps->a->next->num > ps->a->next->next->num)
	{
		rule_sx(ps, 'a');
		rule_rx_rrx(ps, 'a', 1);
	}
	else if (ps->a->num < ps->a->next->num && ps->a->num
		> ps->a->next->next->num && ps->a->next->num > ps->a->next->next->num)
		rule_rx_rrx(ps, 'a', 2);
}

void	start_push_swap(int argc, char **argv, t_push_swap *ps)
{
	int	size;

	print_stacks(ps);
	size = ft_stacksize(ps->a);
	if (size == 1)
		exit_push_swap(ps);
	else if (size == 2)
	{
		if (ps->a->num > ps->a->next->num)
			rule_sx(ps, 'a');
		exit_push_swap(ps);
	}
	else if (size == 3)
	{
		sort_three(ps);
		exit_push_swap(ps);
	}
	else if (size == 5)
	{
		rule_px(ps, 'b');
		rule_px(ps, 'b');
		sort_three(ps);
		rule_px(ps, 'a');
		rule_rx_rrx(ps, 'a', 1);
		rule_px(ps, 'a');
		exit_push_swap(ps);
	}
	exit_push_swap(ps);
}
