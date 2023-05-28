/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magician.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 13:17:28 by dcella-d          #+#    #+#             */
/*   Updated: 2023/05/28 14:41:29 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAGICIAN_H
# define MAGICIAN_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_magician
{
	int					id;
	pthread_t			p_id;
	struct timeval		life_spell_delay;
	pthread_mutex_t		book_of_spells;
	int					sorcery;
	pthread_mutex_t		sorceryx;
	struct s_talkingcat	*cat;
	struct s_magician	*next;
	struct s_magician	*prev;
}						t_magician;

typedef struct s_existence
{
	int		time_to_die;
	int		time_to_study;
	int		time_to_spell;
	int		sorcery_times;
	int		magician_nbr;
}				t_existence;

typedef struct s_talkingcat
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
t_magician		*make_magic(int magician_nbr);
t_existence		*parse_entry(char **av);
t_talkingcat	*magic_cat_init(t_talkingcat *cat, char **av);
void			gettimeofday2(t_magician *magic);
void			*existence(void *magic);
void			create_threads(t_magician *magicians);
void			create_cat_thread(t_talkingcat *cat);
int				mutex_print(t_magician *magicians, char *text, int arg);
int				print_eat(t_magician *magicians);
int				magic_eat(t_magician *magicians);
int				magic_sleep(t_magician *magicians);
int				magic_studying(t_magician *magicians);
int				check_life_spell(t_talkingcat *cat);
int				check_sorceryx(t_magician *magicians);
int				grab_books(t_magician *magicians);
int				die_alone(t_magician *magicians);
void			make_it_talk(t_talkingcat *kat);
void			*checking_loop(void *cat);
int				set_dead(t_magician *magicians);
int				check_alive(t_magician *magicians);
int				time_keep(t_magician *magic, int time);
int				time_checker(struct timeval start);
int				check_sorcery_times(t_talkingcat *cat);
void			magic_free(t_talkingcat *cat);

//		UTILS

void			print_lst(t_magician *magicians);
int				ft_atoi(const char *nptr);
int				check_args(char **av);
int				check_nbrs(char *av);
void			*ft_calloc(size_t nmemb, size_t size);

#endif