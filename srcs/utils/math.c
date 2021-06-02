/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 01:49:52 by cgutierr          #+#    #+#             */
/*   Updated: 2021/06/03 01:50:40 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	roundme(double x)
{
	if (x < 0.0)
		return (int)(x - 0.5);
	else
		return (int)(x + 0.5);
}

int	sqrtme(int num)
{
	float	temp;
	float	sqrt;

	sqrt = num / 2;
	temp = 0;
	while (sqrt != temp)
	{
		temp = sqrt;
		sqrt = (num / temp + temp) / 2;
	}
	return sqrt;
}
