/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magician.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 13:17:28 by dcella-d          #+#    #+#             */
/*   Updated: 2023/05/22 18:24:51 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAGICIAN_H
#define	MAGICIAN_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct			s_magician
{
	int					left_hand;
	int					right_hand;
	int					id;
	pthread_t			p_id;
	int					sorcery;
	struct timeval		life_spell_delay;
	pthread_mutex_t		book_of_spells;
	pthread_mutex_t		sorceryx;
	struct s_talkingcat	*cat;
	struct s_magician	*next;
	struct s_magician	*prev;
}						t_magician;

typedef struct	s_existence
{
	int		all_good;
	long	time_to_die;
	long	time_to_sleep;
	long	time_to_study;
	int		sorcery_times;
	int		magician_nbr;
}				t_existence;

typedef struct	s_talkingcat
{
	struct timeval		start;
	pthread_mutex_t		print;
	int					alive;
	pthread_mutex_t		dead;
	pthread_t			p_id;
	struct s_existence	*exist;
	struct s_magician	*magicians;
}				t_talkingcat;



t_magician		*new_magician(int id);
t_magician		*prepare_table(int magician_nbr);
t_existence		*parse_entry(char **av);
t_talkingcat	*magic_cat_init(t_talkingcat *cat, char **av);
int				check_args(char **av);
int				check_nbrs(char *av);
void			*existence(void *magic);
void			create_threads(t_magician *magicians);
void			mutex_print(t_magician *magic , char *text);
void			magic_eat(t_magician *magicians);
void			magic_sleep(t_magician *magicians);
void			magic_studying(t_magician *magicians);
void			make_it_talk(t_talkingcat *cat);
void			*checking_loop(void *cat);
void			set_dead(t_magician *magic);
int				check_alive(t_magician *magic);
void			timer_check(int time);
int				time_keep(struct timeval start);

//		UTILS

void			print_lst(t_magician *magicians);
int				ft_atoi(const char *nptr);

#endif