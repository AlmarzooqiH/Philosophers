/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_activites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:09:12 by hamad             #+#    #+#             */
/*   Updated: 2025/02/28 23:21:26 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

/**
 * @brief This function will print what is the philospher is doing.
 * @param p The philosopher.
 * @param activity The activity that the philosopher is doing.
 * @return void.
 */
void	print_status(t_philo *p, int activity)
{
	if (activity == e_dead)
	{
		printf("%ld %ld %s", gtms() - p->prog->time, p->id, DEAD);
		return ;
	}
	pthread_mutex_lock(&p->prog->dead);
	if (p->prog->dead_philo == 1)
	{
		pthread_mutex_unlock(&p->prog->dead);
		return ;
	}
	pthread_mutex_unlock(&p->prog->dead);
	pthread_mutex_lock(&p->prog->print);
	if (activity == e_pick_up_fork)
		printf("%ld %ld %s", (gtms() - p->prog->time), p->id, TF);
	else if (activity == e_eat)
		printf("%ld %ld %s", gtms() - p->prog->time, p->id, EAT);
	else if (activity == e_sleep)
		printf("%ld %ld %s", gtms() - p->prog->time, p->id, SLP);
	else if (activity == e_think)
		printf("%ld %ld %s", gtms() - p->prog->time, p->id, TK);
	pthread_mutex_unlock(&p->prog->print);
}

/**
 * @name Pick Left Fork
 * @brief This function will pick the left fork.
 * @param p The philosopher.
 * @return void.
 */
void	plf(t_philo *p)
{
	int	picked;

	picked = 0;
	while (!picked)
	{
		pthread_mutex_lock(&p->prog->dead);
		if (p->prog->dead_philo)
		{
			pthread_mutex_unlock(&p->prog->dead);
			return ;
		}
		pthread_mutex_unlock(&p->prog->dead);
		pthread_mutex_lock(&p->prog->mforks[p->id]);
		if (p->prog->forks[p->id] == 0)
		{
			p->prog->forks[p->id] = 1;
			picked = 1;
			print_status(p, e_pick_up_fork);
		}
		pthread_mutex_unlock(&p->prog->mforks[p->id]);
		if (!picked)
			usleep(TTW);
	}
}

/**
 * @name Pick Right Fork
 * @brief This function will pick the right fork.
 * @param p The philosopher.
 * @return void.
 */
void	prf(t_philo *p)
{
	int	picked;
	int	f_pos;

	picked = 0;
	f_pos = (p->id + 1) % p->prog->n_philo;
	while (!picked)
	{
		pthread_mutex_lock(&p->prog->dead);
		if (p->prog->dead_philo)
		{
			pthread_mutex_unlock(&p->prog->dead);
			return ;
		}
		pthread_mutex_unlock(&p->prog->dead);
		pthread_mutex_lock(&p->prog->mforks[f_pos]);
		if (p->prog->forks[f_pos] == 0)
		{
			p->prog->forks[f_pos] = 1;
			picked = 1;
			print_status(p, e_pick_up_fork);
		}
		pthread_mutex_unlock(&p->prog->mforks[f_pos]);
		if (!picked)
			usleep(TTW);
	}
}

/**
 * @brief This function will simulate the eating behavior.
 * @param p The philosopher.
 * @return void.
 */
void	eat(t_philo *p)
{
	pthread_mutex_lock(&p->prog->dead);
	if (p->prog->dead_philo)
	{
		pthread_mutex_unlock(&p->prog->dead);
		return ;
	}
	pthread_mutex_unlock(&p->prog->dead);
	print_status(p, e_eat);
	pthread_mutex_lock(&p->meal);
	p->last_meal = gtms();
	p->n_meals++;
	pthread_mutex_unlock(&p->meal);
	usleep(p->prog->te);
}

/**
 * @brief This function will simulate the sleeping behavior.
 * @param p The philosopher.
 * @return void.
 */
void	psleep(t_philo *p)
{
	pthread_mutex_lock(&p->prog->dead);
	if (p->prog->dead_philo)
	{
		pthread_mutex_unlock(&p->prog->dead);
		return ;
	}
	pthread_mutex_unlock(&p->prog->dead);
	print_status(p, e_sleep);
	usleep(p->prog->ts);
}
