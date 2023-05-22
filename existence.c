/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   existence.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:58:36 by dcella-d          #+#    #+#             */
/*   Updated: 2023/05/22 18:25:10 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "magician.h"

void	*existence(void *magic)
{
	t_magician *magician;

	magician = ((t_magician *)magic);
	if(check_alive(magician) == 1)
	mutex_print(magician, "ALIVE PORRA!");
	return (NULL);
}

void	magic_eat(t_magician *magicians)
{
	pthread_mutex_lock(&magicians->sorceryx);
	if (magicians->sorcery != -1 && magicians->sorcery > 0)
		magicians->sorcery--;
	mutex_print(magicians, "IS SORCERYING!!!!!");
	pthread_mutex_unlock(&magicians->sorceryx);
	
}

void	set_dead(t_magician *magic)
{
	pthread_mutex_lock(&magic->cat->dead);
	if (magic->cat->alive == 1)
		magic->cat->alive = 0;
	pthread_mutex_unlock(&magic->cat->dead);
}

int	check_alive(t_magician *magic)
{
	int	alive;
	
	pthread_mutex_lock(&magic->cat->dead);
	alive = magic->cat->alive;
	pthread_mutex_unlock(&magic->cat->dead);
	return (alive);
}

void	magic_sleep(t_magician *magicians)
{
	mutex_print(magicians, "FUCKING SLEEPING BITCH!\n");
}

void	magic_studying(t_magician *magicians)
{
	mutex_print(magicians, "FUCKING STUDYING BITCH!\n");
}

void	mutex_print(t_magician *magic , char *text)
{
	pthread_mutex_lock(&magic->cat->dead);
	if (magic->cat->alive == 1)
	{
		pthread_mutex_lock(&magic->cat->print);
		printf("%d %d %s\n", time_keep(magic->cat->start), magic->id, text);
		pthread_mutex_unlock(&magic->cat->print);
	}
	pthread_mutex_unlock(&magic->cat->dead);
}
