/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_activities2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 22:39:26 by hamad             #+#    #+#             */
/*   Updated: 2025/02/26 11:33:45 by hamad            ###   ########.fr       */
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

/**
 * @brief This function will be used by the monitor thread where it will check
 * if all the philosophers have eaten the required number of meals.
 * @param prog The program struct.
 * @return 1 If all the philos have eaten the required number of meals.
 * @return 0 If not all the philo's have eaten the required number of meals.
 */
int	all_ate(t_prog *prog)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < prog->n_philo)
	{
		pthread_mutex_lock(&prog->philo[i].meal);
		if (prog->philo[i].n_meals == prog->neat)
			count++;
		pthread_mutex_unlock(&prog->philo[i].meal);
		i++;
	}
	if (prog->n_philo == count)
	{
		pthread_mutex_lock(&prog->dead);
		prog->dead_philo = 1;
		pthread_mutex_unlock(&prog->dead);
		return (1);
	}
	return (0);
}

/**
 * @brief This function will check if the philosopher has eaten the required
 * number of meals.
 * @param p The philosopher.
 * @return 1 If the philosopher has eaten the required number of meals.
 * @return 0 If the philosopher has not eaten the required number of meals.
 */
int	is_full(t_philo *p)
{
	pthread_mutex_lock(&p->meal);
	if (p->prog->neat > 0 && p->n_meals == p->prog->neat)
		return (pthread_mutex_unlock(&p->meal), 1);
	pthread_mutex_unlock(&p->meal);
	return (0);
}
