/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:03:14 by dcella-d          #+#    #+#             */
/*   Updated: 2023/05/22 13:58:27 by dcella-d         ###   ########.fr       */
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

int	check_args(char **av)
{
	int	f;

	f = 0;
	while (av[++f])
	{
		if (check_nbrs(av[f]) == -1)
			return (0);
	}
	return (1);
}

int	check_nbrs(char *av)
{
	int	f;

	f = -1;
	while (av[++f])
	{
		if (!(av[f] >= 48 && av[f] <= 57))
			return (-1);
	}
	return (ft_atoi(av));
}
