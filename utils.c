/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:03:14 by dcella-d          #+#    #+#             */
/*   Updated: 2023/05/19 15:11:35 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "magician.h"

int	ft_atoi(const char *nptr)
{
	int	f;
	int	sign;
	int	res;

	f = 0;
	sign = 1;
	res = 0;
	while ((nptr[f] == 32) || ((nptr[f] >= 9) && (nptr[f] <= 13)))
		f++;
	if ((nptr[f] == '-') || (nptr[f] == '+'))
	{
		if (nptr[f] == '-')
			sign *= -1;
		f++;
	}
	while ((nptr[f] >= 48) && (nptr[f] <= 57))
	{
		res = res * 10 + (nptr[f] - 48);
		f++;
	}
	return (res * sign);
}
