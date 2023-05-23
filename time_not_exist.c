/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_not_exist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:28:56 by dcella-d          #+#    #+#             */
/*   Updated: 2023/05/23 20:34:44 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "magician.h"

int	time_keep(int time)
{
	struct timeval start;
	struct timeval end;

    gettimeofday(&start, NULL);
	while (1)
	{
		usleep(15);
    	gettimeofday(&end, NULL);
		if ((end.tv_sec - start.tv_sec) * 1000 \
		+ (end.tv_usec - start.tv_usec) / 1000 >= time)
			return (1);
	}
	return (0);
}

int	time_checker(struct timeval start)
{
	struct timeval			end;

    gettimeofday(&end, NULL);
	return((end.tv_sec - start.tv_sec) * 1000 \
	+ (end.tv_usec - start.tv_usec) / 1000);
}
