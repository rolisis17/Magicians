/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:55:50 by dcella-d          #+#    #+#             */
/*   Updated: 2023/05/23 19:35:28 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "magician.h"

void	create_threads(t_magician *magicians)
{
	int	counter;

	counter = magicians->prev->id;
	// printf("%ld\n", magicians->cat->start.tv_sec);
	// printf("%ld\n", magicians->next->cat->start.tv_sec);
	
	// time_keep(magicians->cat->start);
	while (counter--)
	{
		gettimeofday(&magicians->start, NULL);
		gettimeofday(&magicians->life_spell_delay, NULL);
		pthread_create(&magicians->p_id, NULL, existence, magicians);
		// usleep(10);
		magicians = magicians->next;
	}
	create_cat_thread(magicians->cat);
	counter = magicians->prev->id;
	while (counter--)
	{
		pthread_join(magicians->p_id, NULL);
		magicians = magicians->next;
	}
}

void	create_cat_thread(t_talkingcat *cat)
{
	pthread_create(&cat->p_id, NULL, checking_loop, cat);
	pthread_join(cat->p_id, NULL);
}
