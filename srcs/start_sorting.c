/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:03:30 by cgutierr          #+#    #+#             */
/*   Updated: 2021/05/31 19:13:22 by cgutierr         ###   ########.fr       */
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
#include <math.h>
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
	else
	{
		// Dividir la lista en 5 chunks
		// Si son 100 números -> 0-19 20-39 40-59 60-79 80-99

//TODO: mi propia raiz cuadrá
		float chunksize = (size)/((sqrt(size))/2);// (float)size/5.0;
		//si 100 son 5
		//si 500 son 11
		
		// calcuar hasta llenarlo
		float chunkstart = 0;
		float chunkend = 0;
		printf("\n\nSize: %d\n\n", size);
		//TODO: Rellenar los chunks con su round chunksize o size
		for (int i = 0; i < 5; i++)
		{
			chunkstart = chunkend + 1;
			if(i == 4)
				chunkend = size;
			else
				chunkend += round(chunksize);
			printf("[CHUNK %d]|[%f] to [%f]\n", i + 1, chunkstart, chunkend);
			printf("Total: %f\n\n", (chunkend-1)-chunkstart);
		}
		
	}
	exit_push_swap(ps);
}
