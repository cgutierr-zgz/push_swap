/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackiter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 12:17:11 by cgutierr          #+#    #+#             */
/*   Updated: 2021/05/24 16:20:38 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void ft_stackiter(t_stack *lst, void (*f)(int))
{
	t_stack *ptr;

	if (lst)
	{
		while (lst)
		{
			ptr = lst->next;
			f(lst->num);
			lst = ptr;
		}
	}
}
