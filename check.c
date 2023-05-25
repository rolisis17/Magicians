/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:39:26 by dcella-d          #+#    #+#             */
/*   Updated: 2023/05/25 19:42:41 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "magician.h"

void	gettimeofday2(t_magician *magic)
{
	pthread_mutex_lock(&magic->cat->dead);
	gettimeofday(&magic->life_spell_delay, NULL);
	pthread_mutex_unlock(&magic->cat->dead);
}

int	set_dead(t_magician *magicians)
{
	pthread_mutex_lock(&magicians->cat->dead);
	if (magicians->cat->alive == 1)
		magicians->cat->alive = 0;
	pthread_mutex_unlock(&magicians->cat->dead);
	return (1);
}

int	check_alive(t_magician *magicians)
{
	int	alive;

	if (magicians->id == magicians->next->id)
		return (0);
	pthread_mutex_lock(&magicians->cat->dead);
	alive = magicians->cat->alive;
	pthread_mutex_unlock(&magicians->cat->dead);
	return (alive);
}

int	check_sorceryx(t_magician *magicians)
{
	pthread_mutex_lock(&magicians->sorceryx);
	magicians->sorcery++;
	pthread_mutex_unlock(&magicians->sorceryx);
	return (magicians->sorcery);
}
