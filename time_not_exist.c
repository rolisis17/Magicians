/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_not_exist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:28:56 by dcella-d          #+#    #+#             */
/*   Updated: 2023/05/25 19:11:17 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "magician.h"

int	time_keep(t_magician *magic, int time)
{
	struct timeval	start;
	struct timeval	end;

	gettimeofday(&start, NULL);
	while (1)
	{
		usleep(5);
		gettimeofday(&end, NULL);
		if ((end.tv_sec - start.tv_sec) * 1000 \
		+ (end.tv_usec - start.tv_usec) / 1000 >= time)
			return (1);
		if (!check_alive(magic))
			break ;
	}
	return (0);
}

int	time_checker(struct timeval start)
{
	struct timeval			end;

	gettimeofday(&end, NULL);
	return ((end.tv_sec - start.tv_sec) * 1000 \
	+ (end.tv_usec - start.tv_usec) / 1000);
}
