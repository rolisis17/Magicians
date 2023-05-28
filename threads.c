/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:55:50 by dcella-d          #+#    #+#             */
/*   Updated: 2023/05/28 14:33:22 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "magician.h"

void	create_threads(t_magician *magicians)
{
	int	counter;

	counter = magicians->cat->exist->magician_nbr;
	gettimeofday(&magicians->cat->start, NULL);
	while (counter--)
	{
		pthread_create(&magicians->p_id, NULL, existence, magicians);
		magicians = magicians->next;
		usleep(5);
	}
	create_cat_thread(magicians->cat);
	counter = magicians->cat->exist->magician_nbr;
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
