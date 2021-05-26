/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_rx_rrx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 11:44:56 by cgutierr          #+#    #+#             */
/*   Updated: 2021/05/26 17:56:25 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
ra || rb || rr
rotate x
Desplazar hacia arriba todos los elementos de la pila x en 1. El
primer elemento se convierte en el último.

rra || rrb || rrr
reverse rotate x
desplazar hacia abajo todos los elementos de la pila x
en 1. El último elemento se convierte en el primero.
*/

static void	rotate(t_stack **head_ref, int k)
{
	t_stack	*current;
	t_stack	*kthNode;
	int		count;

	if (k == 0)
		return ;
	current = *head_ref;
	count = 1;
	while (count < k && current != NULL)
	{
		current = current->next;
		count++;
	}
	if (current == NULL)
		return ;
	kthNode = current;
	while (current->next != NULL)
		current = current->next;
	current->next = *head_ref;
	*head_ref = kthNode->next;
	kthNode->next = NULL;
}

static void	rule_rrx(t_push_swap *ps, char identifier)
{
	if (identifier == 'a')
	{
		rotate(&ps->a, ft_stacksize(ps->a) - 1);
		write(1, "rra\n", 5);
	}
	else if (identifier == 'b')
	{
		rotate(&ps->b, ft_stacksize(ps->b) - 1);
		write(1, "rrb\n", 5);
	}
	else if (identifier == 'r')
	{
		rotate(&ps->a, ft_stacksize(ps->a) - 1);
		rotate(&ps->b, ft_stacksize(ps->b) - 1);
		write(1, "rrr\n", 5);
	}
}

static void	rule_rx(t_push_swap *ps, char identifier)
{
	if (identifier == 'a')
	{
		rotate(&ps->a, 1);
		write(1, "ra\n", 4);
	}
	else if (identifier == 'b')
	{
		rotate(&ps->b, 1);
		write(1, "rb\n", 4);
	}
	else if (identifier == 'r')
	{
		rotate(&ps->a, 1);
		rotate(&ps->b, 1);
		write(1, "rr\n", 4);
	}
}

void	rule_rx_rrx(t_push_swap *ps, char identifier, int operation)
{
	ps->num_movements += 1;
	if (operation == 1)
		rule_rx(ps, identifier);
	else if (operation == 2)
		rule_rrx(ps, identifier);
}
