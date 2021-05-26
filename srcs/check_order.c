/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 16:45:55 by cgutierr          #+#    #+#             */
/*   Updated: 2021/05/26 16:54:35 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
