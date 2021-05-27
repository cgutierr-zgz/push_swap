/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 16:45:55 by cgutierr          #+#    #+#             */
/*   Updated: 2021/05/27 17:46:21 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int get_meidan(t_stack *lst)
{
	int sum;
	int count;
	t_stack *ptr;

	sum = 0;
	count = 0;
	if (lst)
	{
		while (lst)
		{
			ptr = lst->next;
			count++;
			sum += lst->num;
			lst = ptr;
		}
	}
	return (sum / count);
}

void push_below_median(t_push_swap *ps, int median)
{
	t_stack *ptr;
	int size;

	size = ft_stacksize(ps->a);
	int position = 0;
	if (ps->a)
	{
		while (ps->a)
		{
			position += 1;
			ptr = ps->a->next;
			if (ps->a->num < median)
			{
				// obtener la posicion actual, mover parriba o pabajo
				// en funcion de si position >= size/2
				if (position >= size / 2)
				{
					while (position != 0)
					{
						rule_rx_rrx(ps, 'a', 2, 1);
						position += 1;
						if (position > size)
							position = 0;
						printf(".\n");
					}
				}
				else
				{
					while (position != 0)
					{
						rule_rx_rrx(ps, 'a', 1, 1);
						position -= 1;
						if (position < 0)
							position = size;
						printf("1\n");
					}
				}
				// si rra position +=1 exceto si es >size -> 0
				// si ra -1
				//TODO: get position and perform ra/rra antes de pb
				rule_px(ps, 'b', 1);
			}
			ps->a = ptr;
		}
	}
}

int check_order(t_stack *lst)
{
	int x;
	t_stack *ptr;

	if (lst)
	{
		while (lst)
		{
			x = lst->num;
			ptr = lst->next;
			if (ptr)
			{
				if (x > ptr->num)
					return (1);
			}
			lst = ptr;
		}
	}
	return (0);
}
