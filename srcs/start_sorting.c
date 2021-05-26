/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:03:30 by cgutierr          #+#    #+#             */
/*   Updated: 2021/05/26 19:28:00 by cgutierr         ###   ########.fr       */
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

static void	sort(t_stack **lst, int *position, t_stack **ptr, int *smaller)
{
	int	aux;

	aux = 0;
	if (*lst)
	{
		while (*lst)
		{
			*ptr = (*lst)->next;
			if (!*smaller)
				*smaller = (*lst)->num;
			if ((*lst)->num < *smaller)
			{
				*smaller = (*lst)->num;
				*position = aux;
			}
			aux += 1;
			*lst = *ptr;
		}
	}
}

void	put_smaller_on_top(t_stack *lst, t_push_swap *ps)
{
	t_stack	*ptr;
	int		smaller;
	int		position;
	int		aux;

	smaller = 0;
	position = 0;
	sort(&lst, &position, &ptr, &smaller);
	while (ps->a->num != smaller)
	{
		if (position >= (ft_stacksize(ps->a) / 2))
			rule_rx_rrx(ps, 'a', 2);
		else
			rule_rx_rrx(ps, 'a', 1);
	}
}

void	sort_more(t_push_swap *ps, int size)
{
	int	x;

	x = 0;
	while (x < size - 3)
	{
		put_smaller_on_top(ps->a, ps);
		rule_px(ps, 'b');
		x++;
	}
	sort_three(ps);
	x = 0;
	while (x < size - 3)
	{
		rule_px(ps, 'a');
		x++;
	}
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
	else// if (size <= 20)
		sort_more(ps, size);
	exit_push_swap(ps);
}
