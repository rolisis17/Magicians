/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:59:09 by dcella-d          #+#    #+#             */
/*   Updated: 2023/05/22 14:09:07 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "magician.h"

t_existence	*parse_entry(char **av)
{
	t_existence	*exist;

	exist = (t_existence *)malloc(sizeof(t_existence));
	if (!check_args(av) || ft_atoi(av[1]) == 0)
		return (NULL);
	if (av[4])
	{
		exist->all_good = 1;
		exist->magician_nbr = ft_atoi(av[1]);
		exist->time_to_die = ft_atoi(av[2]);
		exist->time_to_study = ft_atoi(av[3]);
		exist->time_to_sleep = ft_atoi(av[4]);
		if (av[5])
			exist->sorcery_times = ft_atoi(av[5]);
		else
			exist->sorcery_times = -1;
	}
	return (exist);
}

void	print_lst(t_magician *magicians)
{
	while  (magicians->id < magicians->next->id)
	{
		printf("%d\n", magicians->id);
		magicians = magicians->next;
	}
	printf("%d\n", magicians->id);
}
