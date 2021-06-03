/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 19:42:58 by cgutierr          #+#    #+#             */
/*   Updated: 2021/06/03 17:34:57 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Si el elemento ya existe en el array devuelve 1 si no, 0
int contains(int *array, int size, int num)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (array[i] == num)
			return (1);
		i++;
	}
	return (0);
}

// Obtenemos el número más pequeño que NO contenga el array ahora mismo
int get_smallest(t_stack *list, int *chunk, int cantidad)
{
	t_stack *current = list;
	long min;
	int position;
	int aux = 0; // 1?

	min = 2147483648;
	if (current)
	{
		if (!contains(chunk, cantidad, aux))
		{
			min = current->num;
			position = aux;
		}
		//printf("Min:%d\n", min);
		while (current != NULL)
		{
			//./push_swap 744 320 870 701 397 362
			if (min > current->num && !contains(chunk, cantidad, aux)) // current->num))
			//if (min > current->num && !contains(chunk, cantidad,  current->num))
			{
				min = current->num;
				position = aux;
			}
			aux += 1;
			current = current->next;
		}
	}
	//return (min);
	return (position);
}

void store_smallest(t_push_swap *ps, int *chunk, int cantidad)
{
	int i;

	i = 0;
	while (i < cantidad)
	{
		chunk[i] = get_smallest(ps->a, chunk, cantidad);

		printf("[%d]:%d\n", i, chunk[i]);
		i += 1;
	}
	printf("\n");

	long hold1st = 2147483648;
	i = 0;
	while (i < cantidad)
	{
		if (chunk[i] < hold1st)
			hold1st = chunk[i];

		i++;
	}

	long hold2nd = -2147483649;
	i = 0;
	while (i < cantidad)
	{
		if (chunk[i] > hold2nd)
			hold2nd = chunk[i];

		i++;
	}
	///CAMBIAR HOLD 1st y hold 2nd creo que ta mal
	printf("1st:%d, 2nd:%d\n", (int)hold1st, (int)hold2nd);
	printf("1 MOVS=%d\n2 MOVS=%d\n\n", ((0 - hold1st) * -1), (ft_stacksize(ps->a) - (int)hold2nd));
	if (((0 - hold1st) * -1) > ft_stacksize(ps->a) - (int)hold2nd)
	{
		printf("hold2\n\n");
	}
	else
	{

		printf("hold1st\n\n");
	}
	// hacer bucle cantidad --
}
