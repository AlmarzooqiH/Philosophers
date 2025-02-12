/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_activites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:09:12 by hamad             #+#    #+#             */
/*   Updated: 2025/02/12 15:25:59 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

void	print_status(t_philo *p, int activity)
{
	pthread_mutex_lock(&p->prog->print);
	if (activity == e_pick_up_fork)
		printf("%ld %ld %s", (gtms() - p->prog->time), p->id, TF);
	else if (activity == e_eat)
		printf("%ld %ld %s", gtms() - p->prog->time, p->id, EAT);
	else if (activity == e_sleep)
		printf("%ld %ld %s", gtms() - p->prog->time, p->id, SLP);
	else if (activity == e_think)
		printf("%ld %ld %s", gtms() - p->prog->time, p->id, TK);
	else if (activity == e_dead)
		printf("%ld %ld %s", gtms() - p->prog->time, p->id, DEAD);
	pthread_mutex_unlock(&p->prog->print);
}

void	get_left_fork(t_philo *p)
{
	int	fork;

	fork = 0;
	if (!fork)
	{
		while (!fork)
		{
			pthread_mutex_lock(&p->prog->forks[p->id]);
			p->prog->fs[p->id] = 1;
			fork = 1;
			print_status(p, e_pick_up_fork);
			pthread_mutex_unlock(&p->prog->forks[p->id]);
			if (!fork)
				usleep(TTT);
		}
	}
}

void	get_right_fork(t_philo *p)
{
	int	fork_pos;
	int	fork;

	fork = 0;
	fork_pos = (p->id + 1) % p->prog->n_philo;
	if (!fork)
	{
		while (!fork)
		{
			pthread_mutex_lock(&p->prog->forks[fork_pos]);
			p->prog->fs[fork_pos] = 1;
			fork = 1;
			print_status(p, e_pick_up_fork);
			pthread_mutex_unlock(&p->prog->forks[fork_pos]);
			if (!fork)
				usleep(TTT);
		}
	}
}

void	eat(t_philo *p)
{
	print_status(p, e_eat);
	usleep(p->prog->te);
}

void	think(t_philo *p)
{
	print_status(p, e_think);
	usleep(TTT);
}
