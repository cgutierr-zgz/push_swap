/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:03:30 by cgutierr          #+#    #+#             */
/*   Updated: 2021/05/27 19:42:38 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_push_swap *ps)
{
	if (!check_order(ps->a) && ps->b == NULL)
		exit_push_swap(ps);
	if (ps->a->num > ps->a->next->num && ps->a->num < ps->a->next->next->num
		&& ps->a->next->num < ps->a->next->next->num)
		rule_sx(ps, 'a', 1);
	else if (ps->a->num > ps->a->next->num && ps->a->num
		> ps->a->next->next->num && ps->a->next->num > ps->a->next->next->num)
	{
		rule_sx(ps, 'a', 1);
		rule_rx_rrx(ps, 'a', 2, 1);
	}
	else if (ps->a->num > ps->a->next->num && ps->a->num
		> ps->a->next->next->num && ps->a->next->num < ps->a->next->next->num)
		rule_rx_rrx(ps, 'a', 1, 1);
	else if (ps->a->num < ps->a->next->num && ps->a->num
		< ps->a->next->next->num && ps->a->next->num > ps->a->next->next->num)
	{
		rule_sx(ps, 'a', 1);
		rule_rx_rrx(ps, 'a', 1, 1);
	}
	else if (ps->a->num < ps->a->next->num && ps->a->num
		> ps->a->next->next->num && ps->a->next->num > ps->a->next->next->num)
		rule_rx_rrx(ps, 'a', 2, 1);
}

static void	sort(t_stack **lst, int *position, t_stack **ptr, long *smaller)
{
	int	aux;

	aux = 0;
	if (*lst)
	{
		while (*lst)
		{
			*ptr = (*lst)->next;
			if (*smaller == -2147483649)
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
	long	smaller;
	int		position;
	int		aux;
	int		size;

	size = ft_stacksize(ps->a);
	smaller = -2147483649;
	position = 0;
	sort(&lst, &position, &ptr, &smaller);
	while (ps->a->num != smaller)
	{
		if (position >= (size / 2))
			rule_rx_rrx(ps, 'a', 2, 1);
		else
			rule_rx_rrx(ps, 'a', 1, 1);
	}
}


float roundme(float var)
{
    float value = (int)(var * 100 + .5);
    return (float)value / 100;
}

void	sort_more(t_push_swap *ps, int size)
{
	int	x;

	x = 0;
	while (x < size - 3)
	{
		put_smaller_on_top(ps->a, ps);
		rule_px(ps, 'b', 1);
		x++;
	}
	sort_three(ps);
	x = 0;
	while (x < size - 3)
	{
		rule_px(ps, 'a', 1);
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
			rule_sx(ps, 'a', 1);
	}
	else if (size == 3)
		sort_three(ps);
	else if (size <= 5)
		sort_more(ps, size);
	else if (size <= 100)
	{
		// Dividir la lista en 5 chunks
		// Si son 100 números -> 0-19 20-39 40-59 60-79 80-99
		float chunkstart = 0;
		float chunkend = 0;
		printf("SIZE: %d\n", size);
		//TODO: float step -> += roundme NO -> += step :)
		for(int i = 0; i < 5; i++)
		{
			chunkstart = chunkend + 1;
			chunkend += roundme(size / 5);
		// TODO: Fix esto puede que me lo esté redondeando
			printf("[CHUNK %d]|[%f] to [%f]\n", i + 1, chunkstart, chunkend);
		}
		
	}
	else
	{
		// Dividir la lista en 11 chunks
	}
	exit_push_swap(ps);
}
