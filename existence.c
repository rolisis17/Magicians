/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   existence.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:58:36 by dcella-d          #+#    #+#             */
/*   Updated: 2023/05/23 20:59:29 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "magician.h"

void	*existence(void *magic)
{
	t_magician *magician;

	magician = ((t_magician *)magic);
	while (check_alive(magician))
	{
		if (magician->id % 2 != 1)
			usleep(1);
		if (magic_eat(magician))
			break ;
		if (magic_sleep(magician))
			break ;
		if (magic_studying(magician))
			break ;
		// if (!check_alive(magician))
			// break ;
		usleep(10);
	}
	// mutex_print(magician, "IS DEAD!");
	return (NULL);
}



int	magic_eat(t_magician *magicians)
{
	if (magicians->sorcery != -1)
	{
		if (!check_sorceryx(magicians))
			return (1);
	}
	if (check_alive(magicians))
	{
		grab_books(magicians);
		gettimeofday(&magicians->life_spell_delay, NULL);
		mutex_print(magicians, "IS SORCERYING!!!!!");
		time_keep(magicians->cat->exist->time_to_spell);
		pthread_mutex_unlock(&magicians->book_of_spells);
		pthread_mutex_unlock(&magicians->next->book_of_spells);
	}
	return (0);
}

int	check_sorceryx(t_magician *magic)
{
	pthread_mutex_lock(&magic->sorceryx);
	if (magic->sorcery != -1 && magic->sorcery > 0)
		magic->sorcery--;
	pthread_mutex_unlock(&magic->sorceryx);
	return (magic->sorcery);
}

int	grab_books(t_magician *magic)
{
	if (magic->id % 2 != 0)
	{
		pthread_mutex_lock(&magic->book_of_spells);
		pthread_mutex_lock(&magic->next->book_of_spells);
	}
	else
	{
		pthread_mutex_lock(&magic->next->book_of_spells);
		pthread_mutex_lock(&magic->book_of_spells);
	}
	return (1);
}

// int	let_books(t_magician *magic)
// {
// 	pthread_mutex_lock(&magic->book_of_spells);
// 	magic->right_hand = 0;
// 	pthread_mutex_lock(&magic->next->book_of_spells);
// 	magic->left_hand = 0;
// }

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

int	magic_sleep(t_magician *magicians)
{
	if(mutex_print(magicians, "SLEEPING!") == 1)
		return (1);
	else
		time_keep(magicians->cat->exist->time_to_sleep);
	return (0);
}

int	magic_studying(t_magician *magicians)
{
	return (mutex_print(magicians, "STUDYING!"));
}

int	mutex_print(t_magician *magic , char *text)
{
	int	dead;
	
	pthread_mutex_lock(&magic->cat->dead);
	dead = magic->cat->alive;
	pthread_mutex_unlock(&magic->cat->dead);
	if (dead == 1)
	{
		pthread_mutex_lock(&magic->cat->print);
		printf("\033[0;31m%d\033[0m \033[0;93m%d\033[0m \033[0;95m%s\033[0m\n", time_checker(magic->start), magic->id, text);
		pthread_mutex_unlock(&magic->cat->print);
		return (0);
	}
	else
		return (1);
}
