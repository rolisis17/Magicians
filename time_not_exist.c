/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_not_exist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:28:56 by dcella-d          #+#    #+#             */
/*   Updated: 2023/05/22 18:25:41 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "magician.h"

void	timer_check(int time)
{
	struct timeval start;
	struct timeval end;

    gettimeofday(&start, NULL);
	while (1)
	{
    	gettimeofday(&end, NULL);
		if ((end.tv_sec - start.tv_sec == time) && \
		(end.tv_usec - start.tv_usec == time))
			break ;
	}
	return ;
}

int	time_keep(struct timeval start)
{
	struct timeval			end;

    gettimeofday(&end, NULL);
	// printf("%ld\n", ((end.tv_sec - start.tv_sec) * 1000) /
	// + ((end.tv_usec - start.tv_usec) / 1000));
	return((end.tv_sec - start.tv_sec) * 1000) /
	+ ((end.tv_usec - start.tv_usec) / 1000);
}
