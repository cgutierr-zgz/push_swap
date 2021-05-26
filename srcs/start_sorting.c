/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:03:30 by cgutierr          #+#    #+#             */
/*   Updated: 2021/05/26 18:02:07 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_push_swap *ps)
{
	if (!check_order(ps->a) && ps->b == NULL)
		exit_push_swap(ps);
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

void	put_smaller_on_top(t_stack *lst, t_push_swap *ps)
{
	int		smaller;
	t_stack	*ptr;

	smaller = 0;
	if (lst)
	{
		while (lst)
		{
			ptr = lst->next;
			if(!smaller)
				smaller = lst->num;
			if(lst->num < smaller)
				smaller = lst->num;
			lst = ptr;
		}
	}
	while (ps->a->num != smaller)
		rule_rx_rrx(ps, 'a', 1);
}

void	start_push_swap(int argc, char **argv, t_push_swap *ps)
{
	int	size;

	size = ft_stacksize(ps->a);
	if (!check_order(ps->a))
		exit_push_swap(ps);
	else if (size == 2)
	{
		if (ps->a->num > ps->a->next->num)
			rule_sx(ps, 'a');
	}
	else if (size == 3)
		sort_three(ps);
	else if (size == 4)
	{
		put_smaller_on_top(ps->a, ps);
		rule_px(ps, 'b');
		sort_three(ps);
		rule_px(ps, 'a');
	}
	else if (size == 5)
	{
		put_smaller_on_top(ps->a, ps);
		rule_px(ps, 'b');
		rule_px(ps, 'b');
		sort_three(ps);
		rule_px(ps, 'a');
		rule_px(ps, 'a');
	}
	// pa 4 poner el mas peque arriba y moverlo a b hacer 3 en a y meter de b a ->>a
	// pa5 poner el mas peque arriba y ell segundo mas peque abajo y moverlo a b hacer 3 en a y meter de b a ->>a x 2
	exit_push_swap(ps);
}
