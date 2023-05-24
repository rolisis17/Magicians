/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   existence.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:58:36 by dcella-d          #+#    #+#             */
/*   Updated: 2023/05/24 21:19:11 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "magician.h"

void	*existence(void *cat)
{
	t_magician	*magician;

	magician = ((t_magician *)magic);
	gettimeofday(&magician->life_spell_delay, NULL);
	while (1)//check_alive(magician))
	{
		if (magic_eat(cat))
			break ;
		if (magic_sleep(magician))
			break ;
		// if (magic_studying(magician))
		// 	break ;
	}
	// magician->
	return (NULL);
}

int	magic_eat(t_talkingcat *cat)
{
	if (cat->exist->sorcery_times != -1)
		check_sorceryx(cat->magicians);
	if (check_alive(cat->magicians))
	{
		grab_books(cat->magicians);
		if (mutex_print(cat->magicians, "IS SORCERYING!!!!!", 1))
			return (1);
		gettimeofday(&cat->magicians->life_spell_delay, NULL);
		time_keep(cat->magicians, cat->exist->time_to_spell);
		pthread_mutex_unlock(&cat->magicians->next->book_of_spells);
		pthread_mutex_unlock(&cat->magicians->book_of_spells);
	}
	else
		return (1);
	return (0);
}

int	check_sorceryx(t_talkingcat *cat)
{
	pthread_mutex_lock(&cat->magicians->sorceryx);
	cat->magicians->sorcery++;
	pthread_mutex_unlock(&cat->magicians->sorceryx);
	return (cat->magicians->sorcery);
}

int	grab_books(t_talkingcat *cat)
{
	if (cat->magicians->id == cat->magicians->next->id)
		die_alone(cat->magicians);
	if (cat->magicians->id % 2 != 0)
	{
		pthread_mutex_lock(&cat->magicians->next->book_of_spells);
		pthread_mutex_lock(&cat->magicians->book_of_spells);
	}
	else
	{
		pthread_mutex_lock(&cat->magicians->book_of_spells);
		pthread_mutex_lock(&cat->magicians->next->book_of_spells);
	}
	return (1);
}

int	die_alone(t_talkingcat *cat)
{
	pthread_mutex_lock(&cat->print);
	// printf("\033[0;31m%d\033[0m \033[0;93m%d\033[0m \033[0;95m%s\033[0m\n", 
	printf("%d %d %s\n", \
	time_checker(cat->start), cat->magicians->id, "has taken a fork!");
	pthread_mutex_unlock(&cat->print);
	return (1);
}

int	set_dead(t_talkingcat *cat)
{
	pthread_mutex_lock(&cat->dead);
	if (cat->alive == 1)
		cat->alive = 0;
	pthread_mutex_unlock(&cat->dead);
	return (1);
}

int	check_alive(t_talkingcat *cat)
{
	int	alive;

	if (cat->magicians->id == cat->magicians->next->id)
		return (0);
	pthread_mutex_lock(&cat->dead);
	alive = cat->alive;
	pthread_mutex_unlock(&cat->dead);
	return (alive);
}

int	magic_sleep(t_talkingcat *cat)
{
	if(mutex_print(cat->magicians, "is sleeping!", 0) == 1)
		return (1);
	else
		time_keep(cat->magicians, cat->exist->time_to_sleep);
	if (mutex_print(cat->magicians, "is thinking!", 0))
		return (1);
	return (0);
}

// int	magic_studying(t_magician *magicians)
// {
// 	return ();
// }

int	mutex_print(t_talkingcat *cat, char *text, int arg)
{
	int	alive;
	
	pthread_mutex_lock(&cat->dead);
	alive = cat->alive;
	pthread_mutex_unlock(&cat->dead);
	if (alive == 1 && !arg)
	{
		pthread_mutex_lock(&cat->print);
		// printf("\033[0;31m%d\033[0m \033[0;93m%d\033[0m \033[0;95m%s\033[0m\n",
		printf("%d %d %s\n", \
		time_checker(cat->start), cat->magicians->id, text);
		pthread_mutex_unlock(&cat->print);
		return (0);
	}
	else if (alive == 1 && arg)
		return (print_eat(cat->magicians));
	return (1);
}

int	print_eat(t_talkingcat *cat)
{
	pthread_mutex_lock(&cat->print);
	//  printf("\033[0;31m%d\033[0m \033[0;93m%d\033[0m \033[0;95m%s\033[0m\n", 
	printf("%d %d %s\n", \
	time_checker(cat->start), cat->magicians->id, "has taken a fork!");
	// printf("\033[0;31m%d\033[0m \033[0;93m%d\033[0m \033[0;95m%s\033[0m\n", 
	printf("%d %d %s\n", \
	time_checker(cat->start), cat->magicians->id, "has taken a fork!");
	// printf("\033[0;31m%d\033[0m \033[0;93m%d\033[0m \033[0;95m%s\033[0m\n", 
	printf("%d %d %s\n", \
	time_checker(cat->start), cat->magicians->id, "is eating!");
	pthread_mutex_unlock(&cat->print);
	return (0);
}
