/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 19:42:58 by cgutierr          #+#    #+#             */
/*   Updated: 2021/06/02 19:44:42 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_add_smallest(t_stack *lst, int cantidad, int *chunk)//(ps->a, ((int)chunkend - (int)chunkstart) + 1, chunk)
{
	t_stack	*ptr;
	long smaller = -2147483649;

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
