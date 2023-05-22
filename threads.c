/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:55:50 by dcella-d          #+#    #+#             */
/*   Updated: 2023/05/22 18:17:56 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "magician.h"

void	create_threads(t_magician *magicians)
{
	int	counter;

	counter = magicians->prev->id;
	gettimeofday(&magicians->cat->start, NULL);
	time_keep(magicians->cat->start);
	while (counter--)
	{
		pthread_create(&magicians->p_id, NULL, existence, magicians);
		magicians = magicians->next;
	}
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
