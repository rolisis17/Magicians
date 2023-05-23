/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magician.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:25:54 by dcella-d          #+#    #+#             */
/*   Updated: 2023/05/19 15:03:12 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "magician.h"

int	main(int ac, char **av)
{
	t_talkingcat	*cat;

	cat = NULL;
	if (ac ==5 || ac == 6)
		cat = magic_cat_init(cat, av);
	// if (cat->exist->all_good == 0)
	// 	return (1);
	return (0);
}

// t_talkingcat	*magic_cat_init(t_talkingcat *cat, char **av)
// {
// 	if (!cat)
// 		cat = (t_talkingcat *)malloc(sizeof(t_talkingcat));
// 	cat->alive = 0;
// 	pthread_mutex_init(&cat->dead, NULL);
// 	pthread_mutex_init(&cat->print, NULL);
// 	cat->exist = parse_entry(av);
// 	if (cat->exist->magician_nbr > 0)
// 	{
// 		cat->magicians = prepare_table(cat->exist->magician_nbr);
// 		print_lst(cat->magicians);
// 	}
// 	make_it_talk(cat);
// 	create_threads(cat->magicians);
// 	return (cat);
// }

// void	make_it_talk(t_talkingcat *cat)
// {
// 	int	f;
// 	t_magician	*magic;

// 	f = -1;
// 	magic = cat->magicians;
// 	while (magic->id > ++f)
// 	{
// 		printf("%d\n", magic->id);
// 		magic->cat = cat;
// 		magic = magic->next;
// 	}
// }

// t_existence	*parse_entry(char **av)
// {
// 	t_existence	*exist;

// 	exist = (t_existence *)malloc(sizeof(t_existence));
// 	if (!check_args(av) || ft_atoi(av[1]) == 0)
// 		return (NULL);
// 	if (av[4])
// 	{
// 		exist->all_good = 1;
// 		exist->magician_nbr = ft_atoi(av[1]);
// 		exist->time_to_die = ft_atoi(av[2]);
// 		exist->time_to_study = ft_atoi(av[3]);
// 		exist->time_to_sleep = ft_atoi(av[4]);
// 		if (av[5])
// 			exist->sorcery_times = ft_atoi(av[5]);
// 		else
// 			exist->sorcery_times = -1;
// 	}
// 	return (exist);
// }



// int	check_args(char **av)
// {
// 	int	f;

// 	f = 0;
// 	while (av[++f])
// 	{
// 		if (check_nbrs(av[f]) == -1)
// 			return (0);
// 	}
// 	return (1);
// }

// int	check_nbrs(char *av)
// {
// 	int	f;

// 	f = -1;
// 	while (av[++f])
// 	{
// 		if (!(av[f] >= 48 && av[f] <= 57))
// 			return (-1);
// 	}
// 	return (ft_atoi(av));
// }

// void	create_threads(t_magician *magicians)
// {
// 	pthread_t	pthread[magicians->prev->id];
// 	int			counter;

// 	counter = magicians->prev->id;
// 	while (counter--)
// 	{
// 		pthread_create(&pthread[magicians->id], NULL, existence, magicians);
// 		magicians = magicians->next;
// 	}
// 	counter = magicians->prev->id;
// 	while (counter--)
// 	{
// 		pthread_join(pthread[magicians->id], NULL);
// 		magicians = magicians->next;
// 	}
// }

// void	*existence(void *magic)
// {
// 	t_magician *magician;

// 	magician = ((t_magician *)magic);

// 	mutex_print(magician, "ALIVE PORRA!");
// 	return (NULL);
// }

// void	magic_eat(t_magician *magicians)
// {
// 	pthread_mutex_lock(&magicians->sorceryx);
// 	if (magicians->sorcery != -1 && magicians->sorcery > 0)
// 		magicians->sorcery--;
// 	mutex_print(magicians, "IS SORCERYING!!!!!");
// 	pthread_mutex_unlock(&magicians->sorceryx);
	
// }

// void	magic_sleep(t_magician *magicians)
// {
// 	mutex_print(magicians, "FUCKING SLEEPING BITCH!\n");
// }

// void	magic_studying(t_magician *magicians)
// {
// 	mutex_print(magicians, "FUCKING STUDYING BITCH!\n");
// }

// void	mutex_print(t_magician *magic , char *text)
// {
// 	pthread_mutex_lock(&magic->cat->dead);
// 	if (magic->cat->alive == 0)
// 	{
// 		pthread_mutex_lock(&magic->cat->print);
// 		printf("TIME %d %s\n", magic->id, text);
// 		pthread_mutex_unlock(&magic->cat->print);
// 	}
// 	pthread_mutex_unlock(&magic->cat->dead);
// }

// void	print_lst(t_magician *magicians)
// {
// 	while  (magicians->id < magicians->next->id)
// 	{
// 		printf("%d\n", magicians->id);
// 		magicians = magicians->next;
// 	}
// 	printf("%d\n", magicians->id);
// }
