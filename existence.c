/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   existence.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:58:36 by dcella-d          #+#    #+#             */
/*   Updated: 2023/05/25 19:41:45 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "magician.h"

void	*existence(void *magic)
{
	t_magician	*magician;

	magician = ((t_magician *)magic);
	gettimeofday2(magician);
	if (magician->id == magician->next->id)
		die_alone(magician);
	while (1)
	{
		if (magic_eat(magician))
			break ;
		if (magic_sleep(magician))
			break ;
	}
	return (NULL);
}

int	magic_eat(t_magician *magicians)
{
	int	f;

	f = 0;
	if (magicians->cat->exist->sorcery_times != -1)
		check_sorceryx(magicians);
	if (check_alive(magicians))
	{
		grab_books(magicians);
		if (!mutex_print(magicians, "IS SORCERYING!!!!!", 1))
		{
			gettimeofday2(magicians);
			time_keep(magicians, magicians->cat->exist->time_to_spell);
		}
		else
			f = 1;
		pthread_mutex_unlock(&magicians->next->book_of_spells);
		pthread_mutex_unlock(&magicians->book_of_spells);
	}
	else
		return (1);
	return (f);
}

int	grab_books(t_magician *magicians)
{
	if (magicians->id % 2 != 0)
	{
		pthread_mutex_lock(&magicians->next->book_of_spells);
		pthread_mutex_lock(&magicians->book_of_spells);
	}
	else
	{
		pthread_mutex_lock(&magicians->book_of_spells);
		pthread_mutex_lock(&magicians->next->book_of_spells);
	}
	return (1);
}

int	die_alone(t_magician *magicians)
{
	pthread_mutex_lock(&magicians->cat->print);
	printf("%d %d %s\n", \
	time_checker(magicians->cat->start), magicians->id, "has taken a fork!");
	pthread_mutex_unlock(&magicians->cat->print);
	return (1);
}

int	magic_sleep(t_magician *magicians)
{
	if (mutex_print(magicians, "is sleeping!", 0) == 1)
		return (1);
	else
		time_keep(magicians, magicians->cat->exist->time_to_sleep);
	if (mutex_print(magicians, "is thinking!", 0))
		return (1);
	return (0);
}
