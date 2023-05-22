/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:56:20 by dcella-d          #+#    #+#             */
/*   Updated: 2023/05/22 18:32:17 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "magician.h"

t_talkingcat	*magic_cat_init(t_talkingcat *cat, char **av)
{
	if (!cat)
		cat = (t_talkingcat *)malloc(sizeof(t_talkingcat));
	cat->alive = 1;
	pthread_mutex_init(&cat->dead, NULL);
	pthread_mutex_init(&cat->print, NULL);
	cat->exist = parse_entry(av);
	if (cat->exist->magician_nbr > 0)
	{
		cat->magicians = prepare_table(cat->exist->magician_nbr);
		print_lst(cat->magicians);
	}
	make_it_talk(cat);
	create_threads(cat->magicians);
	
	return (cat);
}

void	make_it_talk(t_talkingcat *cat)
{
	int	f;
	t_magician	*magic;

	f = -1;
	magic = cat->magicians;
	printf("cat:%d\n", cat->exist->sorcery_times);
	while (magic->id > ++f)
	{
		printf("magic_id:%d\n", magic->id);
		magic->cat = cat;
		printf("magic:%d\n", magic->cat->exist->sorcery_times);
		magic = magic->next;
	}
}

t_magician	*prepare_table(int magician_nbr)
{
	int	f;
	t_magician	*head;
	t_magician	*magicians;
	t_magician *new;

	f = 0;
	head = NULL;
	while (++f <= magician_nbr)
	{
		new = new_magician(f);
		if (!head)
			head = new;
		else
		{
			if (!magicians)
				magicians = new;
			else
			{
				magicians->next = new;
				new->prev = magicians;
			}
		}
		magicians = new;
		new = NULL;
	}
	magicians->next = head;
	head->prev = magicians;
	return (head);
}

t_magician	*new_magician(int id)
{
	t_magician	*magicians;
	
	magicians = (t_magician *)malloc(sizeof(t_magician));
	if (!magicians)
		return (NULL);
	magicians->next = NULL;
	magicians->prev = NULL;
	magicians->left_hand = 0;
	magicians->right_hand = 0;
	magicians->id = id;
	pthread_mutex_init(&magicians->book_of_spells, NULL);
	pthread_mutex_init(&magicians->sorceryx, NULL);
	return (magicians);
}

void	*checking_loop(void *cat)
{
	t_talkingcat *kat;

	kat = (t_talkingcat *)cat;
	while (1)
	{
		if (!kat->alive)
			break ;
	}
	return (NULL);
}