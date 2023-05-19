/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magician.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 13:17:28 by dcella-d          #+#    #+#             */
/*   Updated: 2023/05/19 19:08:42 by dcella-d         ###   ########.fr       */
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
	int					sorcery;
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
	pthread_mutex_t	print;
	int				alive;
	pthread_mutex_t	dead;
	struct s_existence	*exist;
	struct			s_magician	*magicians;
}				t_talkingcat;



t_magician	*new_magician(int id);
t_magician	*prepare_table(int magician_nbr);
void	*existence(void *magic);
void	create_threads(t_magician *magicians);
void	mutex_print(t_magician *magic , char *text);

//		UTILS

void	print_lst(t_magician *magicians);
int	ft_atoi(const char *nptr);

#endif