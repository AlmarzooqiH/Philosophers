/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_activites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:09:12 by hamad             #+#    #+#             */
/*   Updated: 2025/02/11 02:11:15 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

void	print_status(t_philo *philo, int activity)
{
	pthread_mutex_lock(&philo->prog->print);
	if (activity == e_pick_up_fork)
		printf("%ld %ld %s", (gtms() - philo->prog->time), philo->id, TF);
	else if (activity == e_eat)
		printf("%ld %ld %s", gtms() - philo->prog->time, philo->id, EAT);
	else if (activity == e_sleep)
		printf("%ld %ld %s", gtms() - philo->prog->time, philo->id, SLP);
	else if (activity == e_think)
		printf("%ld %ld %s", gtms() - philo->prog->time, philo->id, TK);
	else if (activity == e_dead)
		printf("%ld %ld %s", gtms() - philo->prog->time, philo->id, DEAD);
	pthread_mutex_unlock(&philo->prog->print);
}

void	get_forks(t_philo *philo)
{
	if (!philo->lh)
	{
		while (!philo->lh)
		{
			pthread_mutex_lock(&philo->prog->forks[philo->id]);
			philo->lh = 1;
			print_status(philo, e_pick_up_fork);
			pthread_mutex_unlock(&philo->prog->forks[philo->id]);
			if (!philo->lh)
				usleep(TTT);
		}
	}
	else if (!philo->rh)
	{
		while (!philo->rh)
		{
			pthread_mutex_lock(&philo->prog->forks[(philo->id + 1) % philo->prog->n_philo]);
			philo->rh = 1;
			print_status(philo, e_pick_up_fork);
			pthread_mutex_unlock(&philo->prog->forks[(philo->id + 1) % philo->prog->n_philo]);
			if (!philo->rh)
				usleep(TTT);
		}
	}
}

void	eat(t_philo *philo)
{
	print_status(philo, e_eat);
	usleep(philo->prog->te);
}

void	think(t_philo *philo)
{
	print_status(philo, e_think);
	usleep(TTT);
}

void	psleep(t_philo *philo)
{
	print_status(philo, e_sleep);
	usleep(philo->prog->ts);
}
