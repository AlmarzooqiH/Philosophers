/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_activities2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 22:39:26 by hamad             #+#    #+#             */
/*   Updated: 2025/02/23 15:22:38 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

/**
 * @brief This function will simulate the thinking behavior.
 * @param p The philosopher.
 * @return void.
 */
void	think(t_philo *p)
{
	pthread_mutex_lock(&p->prog->dead);
	if (p->prog->dead_philo)
	{
		pthread_mutex_unlock(&p->prog->dead);
		return ;
	}
	pthread_mutex_unlock(&p->prog->dead);
	print_status(p, e_think);
	usleep(TTT * 1000);
}

/**
 * @name Drop Left Fork
 * @brief This function will drop the left fork.
 * @param p The philosopher.
 * @return void.
 */
void	dlf(t_philo *p)
{
	pthread_mutex_lock(&p->prog->dead);
	if (p->prog->dead_philo)
	{
		pthread_mutex_unlock(&p->prog->dead);
		return ;
	}
	pthread_mutex_unlock(&p->prog->dead);
	pthread_mutex_lock(&p->prog->mforks[p->id]);
	p->prog->forks[p->id] = 0;
	pthread_mutex_unlock(&p->prog->mforks[p->id]);
}

/**
 * @name Drop Right Fork
 * @brief This function will drop the left fork.
 * @param p The philosopher.
 * @return void.
 */
void	drf(t_philo *p)
{
	int	f_pos;

	pthread_mutex_lock(&p->prog->dead);
	if (p->prog->dead_philo)
	{
		pthread_mutex_unlock(&p->prog->dead);
		return ;
	}
	pthread_mutex_unlock(&p->prog->dead);
	f_pos = (p->id + 1) % p->prog->n_philo;
	pthread_mutex_lock(&p->prog->mforks[f_pos]);
	p->prog->forks[f_pos] = 0;
	pthread_mutex_unlock(&p->prog->mforks[f_pos]);
}
