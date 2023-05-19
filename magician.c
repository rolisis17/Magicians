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

	cat->exist = parse_entry(av);
	if (cat->exist == NULL)
		return (1);
	if (cat->exist->magician_nbr > 0)
	{
		if (ft_atoi(av[5]))
		cat->magicians = prepare_table(cat->exist->magician_nbr);
		print_lst(cat->magicians);
		create_threads(cat->magicians);
	}
	return (0);
}

void	link_magic_cat(t_talkingcat *cat)
{
	
}

t_existence	*parse_entry(char **av)
{
	t_existence	*exist;
	int	f;

	f = 0;
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



int	check_args(char **av)
{
	int	f;

	f = -1;
	while (av[++f])
	{
		if (check_nbrs(av[f]) == -1)
			return (0);
	}
	return (1);
}

int	check_nbrs(char *av)
{
	int	f;

	f = -1;
	while (av[++f])
	{
		if (!(av[f] >= 48 && av[f] <= 57))
			return (-1);
	}
	return (ft_atoi(av));
}

void	create_threads(t_magician *magicians)
{
	pthread_t	pthread[magicians->prev->id];
	int			counter;

	counter= magicians->prev->id;
	while (counter--)
	{
		pthread_create(&pthread[magicians->id], NULL, existence, magicians);
		magicians = magicians->next;
	}
	counter= magicians->prev->id;
	while (counter--)
	{
		pthread_join(pthread[magicians->id], NULL);
		magicians = magicians->next;
	}
}

void	*existence(void *magic)
{
	t_magician *magician;

	magician = ((t_magician *)magic);

	mutex_print(magician, "ALIVE PORRA!");
	return (NULL);
}

void	magic_eat(t_magician *magicians)
{
	pthread_mutex_lock(&magicians->sorceryx);
	if (magicians->sorcery != -1 && magicians->sorcery > 0)
		magicians->sorcery--;
	mutex_print(magicians, "IS SORCERYING!!!!!");
	pthread_mutex_unlock(&magicians->sorceryx);
	
}

void	magic_sleep(t_magician *magicians)
{
	mutex_print(magicians, "FUCKING SLEEPING BITCH!\n");
}

void	magic_studying(t_magician *magicians)
{
	printf("FUCKING STUDYING BITCH!\n");
}

void	mutex_print(t_magician *magic , char *text)
{
	pthread_mutex_lock(&magic->cat->dead);
	if (magic->cat->alive == 0)
	{
		pthread_mutex_lock(&magic->cat->print);
		printf("TIME %d %s\n", magic->id, text);
		pthread_mutex_unlock(&magic->cat->print);
	}
	pthread_mutex_unlock(&magic->cat->dead);
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
	return (magicians);
}


// void* threadFunction(void* arg)
// {
// 	pthread_mutex_t mutex;
// 	pthread_cond_t cond;

// 	int counter = 0;
//     int threadId = *((int*)arg);

//     // Lock the mutex to ensure only one thread modifies the counter at a time
//     pthread_mutex_lock(&mutex);

//     if (threadId <= 2) {
//         // Wait until threads 1 and 2 complete their work
//         while (counter < 2) {
//             pthread_cond_wait(&cond, &mutex);
//         }
//     }

//     // Perform work for threads 1 and 2 or 3 and 4
//     printf("Thread %d starting\n", threadId);
//     // ... Perform thread-specific work here ...

//     counter++;

//     if (counter == 2) {
//         // Signal threads 3 and 4 to start their work
//         pthread_cond_broadcast(&cond);
//     }

//     // Unlock the mutex
//     pthread_mutex_unlock(&mutex);

//     // Continue with thread execution
//     printf("Thread %d completed\n", threadId);
//     return NULL;
// }

// int main() {
//     pthread_t threads[4];
//     int threadIds[4] = {1, 2, 3, 4};

//     // Initialize mutex and condition variable
//     pthread_mutex_init(&mutex, NULL);
//     pthread_cond_init(&cond, NULL);

//     // Create threads 1, 2, 3, and 4
//     for (int i = 0; i < 4; i++) {
//         pthread_create(&threads[i], NULL, threadFunction, &threadIds[i]);
//     }

//     // Wait for all threads to complete
//     for (int i = 0; i < 4; i++) {
//         pthread_join(threads[i], NULL);
//     }

//     // Destroy mutex and condition variable
//     pthread_mutex_destroy(&mutex);
//     pthread_cond_destroy(&cond);

//     return 0;
// }

