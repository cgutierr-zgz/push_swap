/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 16:16:19 by cgutierr          #+#    #+#             */
/*   Updated: 2021/07/05 17:36:11 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
/**
 * PASOS
 * 	1·Convertir 'Stack A' en un array de enteros
 * 	2·Conseguir ChunkNum(Cantidad de chunks que va a haber) = (sizestack + 233,3333^)/66,6666^
 *  2.1·ChunkSize = sizestack / ChunkNum
 * 	3·Rellenar chunk con n(ChunkSize) de los números más pequeños de 'Stack A'
 * Crear funcion que reciba un número n y que pase al Stack B los n números más
 * chikitos de Stack A -> Dentro de un bucle | Que hace break cuando ChunkSize = 0
 * while (ChunkNum)
 * {
 * 	if (ChunkNum == 1)
 * 		ChunkSize -= 3;
 * 	funcion_chunk_al_b(Stack A/B, ChunkSize);
 * 	ChunkNum--;
 * }
 * algoritmo_de_3(Stack_A);
 *  4·Función que coja el más chikito del Stack_B, hasta que esté vacio el Stack_B
 **/

static void send_mayorcete(t_push_swap *ps)
{
	t_stack *clone;
	clone = ps->b;
	int n;
	if (clone)
	{
		n = clone->num;
		while (clone)
		{
			if (clone->num > n)
				n = clone->num;
			clone = clone->next;
		}
	}
	printf("Mayorcete = %d\n", n);
}

void sort_chunks(t_push_swap *ps)
{
	int chunk_num = ((float)ft_stacksize(ps->a) + 233.3333) / 66.6666;
	int chunk_size = ft_stacksize(ps->a) / chunk_num;
	printf("\nCantidad de Chunks = %d\nSize de cada chunk = %d\n", chunk_num, chunk_size);
	while (chunk_num)
	{
		//send_x_to_stack_b(ps, chunk_size);
		if (chunk_num == 1)
			chunk_size = ft_stacksize(ps->a) - 3;
		chunk_num -= 1;
	}

	//sort_three(ps);
	send_mayorcete(ps);
	//while (ps->b)
	//	send_mayorcete(ps);

	//take_smallest_b() -> send to a until b está VASIO
}
