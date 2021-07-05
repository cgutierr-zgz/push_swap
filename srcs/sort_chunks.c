/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 16:16:19 by cgutierr          #+#    #+#             */
/*   Updated: 2021/07/05 19:15:28 by cgutierr         ###   ########.fr       */
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

// Obtenemos el número más pequeño que NO contenga el array ahora mismo
void send_mayorcete(t_stack *list, t_push_swap *ps)
{
	t_stack *current = list;
	long max;
	int position;
	int aux = 0;

	max = 2147483648;
	if (ft_stacksize(ps->b) == 1)
	{
		rule_px(ps, 'a', 1);
		return;
	}
	if (current)
	{
		max = current->num;
		position = aux;
		while (current != NULL)
		{
			if (max < current->num)
			{
				max = current->num;
				position = aux;
			}
			aux += 1;
			current = current->next;
		}
	}
	// Calcular que es mas rapido si rb o rrb para mover position arriba del stackb
	if (position < (ft_stacksize(ps->b) / 2))
	{
		while (position)
		{
			rule_rx_rrx(ps, 'b', 1, 1);
			position -= 1;
		}
		rule_px(ps, 'a', 1);
	}
	else
	{
		while (position)
		{
			rule_rx_rrx(ps, 'b', 2, 1);
			position += 1;
			if (position >= ft_stacksize(ps->b))
			{
				rule_px(ps, 'a', 1);
				break;
			}
		}
	}
}

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

void send_n_to_b(t_push_swap *ps, int chunk_size)
{
	/**
	 * PASOS:
	 * Conseguir los n números más pequeños de Stack A (Dónde n = chunk_size)
	 * *** CREAR UN ARRAY CON ESTOS NUMEROS CHIKITOS
	 * Moverlos a Stack B
	 * ·Hold1st -> chunk[0] ó el primer número que encuentre desde arriba
	 * ·Hold2nd -> chunk[chunkSize -1] ó el primer número que encuentre desde abajo
	 * ¿Que tardo más en mover Hold1st o Hold2nd? -> ra o rra -> pb
	 * Así hasta que chunksize = 0
	 * Repetir...
	 **/
	//TODO: Free this
	int *array_chikitos = malloc(sizeof(int *) * chunk_size);
	//	store_chikitos con contain ( position ? )
	free(array_chikitos);
}

void sort_chunks(t_push_swap *ps)
{
	int chunk_num = ((float)ft_stacksize(ps->a) + 233.3333) / 66.6666;
	int chunk_size = ft_stacksize(ps->a) / chunk_num;
	//printf("\nCantidad de Chunks = %d\nSize de cada chunk = %d\n", chunk_num, chunk_size);
	while (chunk_num)
	{
		if (chunk_num == 1)
			chunk_size = ft_stacksize(ps->a) - 3;
		//send_n_to_b(ps, chunk_size);

		chunk_num -= 1;
		break;
	}

	/* TODO: Activar esto cuando tenga bien lo de los chunks
	sort_three(ps);
	while (ps->b)
		send_mayorcete(ps->b, ps);
	*/
	//	print_stacks(ps);
	//	system("leaks push_swap");
}
