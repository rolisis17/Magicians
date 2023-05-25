/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:46:00 by dcella-d          #+#    #+#             */
/*   Updated: 2023/05/25 19:32:06 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "magician.h"

void	*checking_loop(void *kat)
{
	t_talkingcat	*cat;

	cat = (t_talkingcat *)kat;
	while (cat->alive)
	{
		if (check_life_spell(cat))
		{
			set_dead(cat->magicians);
			printf("%d %d %s\n", \
			time_checker(cat->start), cat->magicians->id, "IS DEAD!");
			if (cat->magicians->id == cat->magicians->next->id)
				break ;
		}
		if (cat->exist->sorcery_times != -1)
		{
			if (check_sorcery_times(cat) == (cat->exist->magician_nbr + 2))
				if (set_dead(cat->magicians))
					break ;
		}
		cat->magicians = cat->magicians->next;
		usleep(1);
	}
	return (NULL);
}

int	check_life_spell(t_talkingcat *cat)
{
	int	f;

	f = 0;
	pthread_mutex_lock(&cat->dead);
	if (time_checker(cat->magicians->life_spell_delay) > \
	cat->exist->time_to_die)
		f = 1;
	pthread_mutex_unlock(&cat->dead);
	return (f);
}

int	check_sorcery_times(t_talkingcat *cat)
{
	static int	years;

	pthread_mutex_lock(&cat->magicians->sorceryx);
	if (cat->magicians->sorcery >= cat->exist->sorcery_times)
		years++;
	else
		years = 0;
	pthread_mutex_unlock(&cat->magicians->sorceryx);
	return (years);
}
