/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magician.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:25:54 by dcella-d          #+#    #+#             */
/*   Updated: 2023/05/25 19:41:55 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "magician.h"

int	main(int ac, char **av)
{
	t_talkingcat	*cat;

	cat = NULL;
	if (ac == 5 || ac == 6)
		magic_cat_init(cat, av);
	if (!cat)
		return (1);
	return (0);
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
		printf("%d %d %s\n", \
		time_checker(magicians->cat->start), magicians->id, text);
		pthread_mutex_unlock(&magicians->cat->print);
		return (0);
	}
	else if (alive == 1 && arg)
		return (print_eat(magicians));
	return (1);
}
		// printf("\033[0;31m%d\033[0m \033[0;93m%d\033[0m \033[0;95m%s\033[0m\n",

int	print_eat(t_magician *magicians)
{
	pthread_mutex_lock(&magicians->cat->print);
	printf("%d %d %s\n", \
	time_checker(magicians->cat->start), magicians->id, "has taken a fork!");
	printf("%d %d %s\n", \
	time_checker(magicians->cat->start), magicians->id, "has taken a fork!");
	printf("%d %d %s\n", \
	time_checker(magicians->cat->start), magicians->id, "is eating!");
	pthread_mutex_unlock(&magicians->cat->print);
	return (0);
}
