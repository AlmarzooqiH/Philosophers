/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_activities2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 22:39:26 by hamad             #+#    #+#             */
/*   Updated: 2025/02/12 17:03:47 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

/**
 * @brief This funcion will release the left fork of the philosopher.
 * @param p The philosopher.
 * @return Void.
 */
void	release_left_fork(t_philo *p)
{
	pthread_mutex_lock(&p->prog->forks[p->id]);
	if (p->prog->fs[p->id] == 1)
		p->prog->fs[p->id] = 0;
	pthread_mutex_lock(&p->prog->forks[p->id]);
}

/**
 * @brief This funcion will release the right fork of the philosopher.
 * @param p The philosopher.
 * @return Void.
 */
void	release_right_fork(t_philo *p)
{
	int	fork_pos;

	fork_pos = (p->id + 1) % p->prog->n_philo;
	pthread_mutex_lock(&p->prog->forks[fork_pos]);
	if (p->prog->fs[fork_pos] == 1)
		p->prog->fs[fork_pos] = 0;
	pthread_mutex_lock(&p->prog->forks[fork_pos]);
}

void	psleep(t_philo *p)
{
	print_status(p, e_sleep);
	usleep(p->prog->ts);
}
