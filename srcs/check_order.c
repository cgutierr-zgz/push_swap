/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 16:45:55 by cgutierr          #+#    #+#             */
/*   Updated: 2021/05/27 18:37:32 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_meidan(t_stack *lst)
{
	int		sum;
	int		count;
	t_stack	*ptr;

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

int	check_order(t_stack *lst)
{
	int		x;
	t_stack	*ptr;

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
