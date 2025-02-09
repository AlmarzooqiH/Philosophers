/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_activites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:09:12 by hamad             #+#    #+#             */
/*   Updated: 2025/02/09 13:09:22 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

void	print_status(t_philo philo, int activity)
{
	if (activity == e_pick_up_fork)
		printf("%ld %ld has taken a fork\n", get_timestamp_ms(), philo.id);
	else if (activity == e_eat)
		printf("%ld %ld eating\n", get_timestamp_ms(), philo.id);
	else if (activity == e_sleep)
		printf("%ld %ld sleeping\n", get_timestamp_ms(), philo.id);
	else if (activity == e_think)
		printf("%ld %ld thinking\n", get_timestamp_ms(), philo.id);
	else if (activity == e_dead)
		printf("%ld %ld died\n", get_timestamp_ms(), philo.id);
}

void	get_forks(t_philo philo)
{
	print_status(philo, e_pick_up_fork);
}

void	eat(t_philo philo)
{
	print_status(philo, e_eat);
}

void	think(t_philo philo)
{
	print_status(philo, e_think);
}

void	psleep(t_philo philo)
{
	print_status(philo, e_sleep);
}
