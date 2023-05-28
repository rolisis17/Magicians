/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magician.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:25:54 by dcella-d          #+#    #+#             */
/*   Updated: 2023/05/28 14:56:56 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "magician.h"

int	main(int ac, char **av)
{
	t_talkingcat	cat;

	if (ac == 5 || ac == 6)
		magic_cat_init(&cat, av);
	if (!cat.exist)
		return (1);
	create_threads(cat.magicians);
	magic_free(&cat);
	return (0);
}

void	magic_free(t_talkingcat *cat)
{
	t_magician	*temp;
	int			counter;

	counter = cat->exist->magician_nbr;
	while (counter--)
	{
		temp = cat->magicians;
		cat->magicians = cat->magicians->prev;
		pthread_mutex_destroy(&temp->book_of_spells);
		pthread_mutex_destroy(&temp->sorceryx);
		free(temp);
	}
	pthread_mutex_destroy(&cat->print);
	pthread_mutex_destroy(&cat->dead);
	free(cat->exist);
	cat = NULL;
}

int	mutex_print(t_magician *magicians, char *text, int arg)
{
	int	alive;

	pthread_mutex_lock(&magicians->cat->dead);
	alive = magicians->cat->alive;
	pthread_mutex_unlock(&magicians->cat->dead);
	if (alive == 1 && !arg)
	{
		pthread_mutex_lock(&magicians->cat->print);
		printf("\033[0;31m%d\033[0m \033[0;93m%d\033[0m \033[0;95m%s\033[0m\n",
		time_checker(magicians->cat->start), magicians->id, text);
		pthread_mutex_unlock(&magicians->cat->print);
		return (0);
	}
	else if (alive == 1 && arg)
		return (print_eat(magicians));
	return (1);
}
		// printf("\033[0;31m%d\033[0m \033[0;93m%d\033[0m \033[0;95m%s\033[0m\n",
		// printf("%d %d %s\n",

int	print_eat(t_magician *magicians)
{
	pthread_mutex_lock(&magicians->cat->print);
	// printf("\033[0;31m%d\033[0m \033[0;93m%d\033[0m \033[0;95m%s\033[0m\n",
	// time_checker(magicians->cat->start), magicians->id, "HAS TAKEN A BOOK!");
	printf("\033[0;31m%d\033[0m \033[0;93m%d\033[0m \033[0;95m%s\033[0m\n",
	time_checker(magicians->cat->start), magicians->id, "HAS TAKEN THE BOOK!");
	printf("\033[0;31m%d\033[0m \033[0;93m%d\033[0m \033[0;95m%s\033[0m\n",
	time_checker(magicians->cat->start), magicians->id, "IS SORCERYING!!!");
	pthread_mutex_unlock(&magicians->cat->print);
	return (0);
}
