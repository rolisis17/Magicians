/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:55:50 by dcella-d          #+#    #+#             */
/*   Updated: 2023/05/24 21:17:49 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "magician.h"

void	create_threads(t_talkingcat *cat)
{
	int	counter;

	counter = cat->magicians->prev->id;
	// printf("%ld\n", magicians->cat->start.tv_sec);
	// printf("%ld\n", magicians->next->cat->start.tv_sec);
	
	// time_keep(magicians->cat->start);
	gettimeofday(&cat->start, NULL);
	while (counter--)
	{
		pthread_create(&cat->magicians->p_id, NULL, existence, cat->magicians);
		cat->magicians = cat->magicians->next;
		usleep(1);
	}
	create_cat_thread(cat);
	counter = cat->magicians->prev->id;
	while (counter--)
	{
		pthread_join(cat->magicians->p_id, NULL);
		cat->magicians = cat->magicians->next;
	}
	// printf("%d\n", counter);
}

void	create_cat_thread(t_talkingcat *cat)
{
	pthread_create(&cat->p_id, NULL, checking_loop, cat);
	pthread_join(cat->p_id, NULL);
}
