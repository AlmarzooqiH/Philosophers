/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_activites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:09:12 by hamad             #+#    #+#             */
/*   Updated: 2025/01/18 13:52:57 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

void	get_forks(t_philo philo)
{
	int	f1;
	int	f2;
	int	temp;

	f1 = philo.id;
	f2 = (philo.id + 1) % philo.prog->n_philo;
	if (f1 > f2)
	{
		temp = f1;
		f1 = f2;
		f2 = temp;
	}
	pthread_mutex_lock(&philo.prog->forks[f1]);
	printf("%ld has taken a fork\n", philo.id + 1);
	philo.lh = 1;
	pthread_mutex_lock(&philo.prog->forks[f2]);
	philo.rh = 1;
	printf("%ld has taken a fork\n", philo.id + 1);
	if (philo.lh && philo.rh)
		eat(philo);
	pthread_mutex_unlock(&philo.prog->forks[f1]);
	philo.lh = 0;
	pthread_mutex_unlock(&philo.prog->forks[f2]);
	philo.rh = 0;
}

void	eat(t_philo philo)
{
	printf("%ld is eating\n", philo.id + 1);
	usleep(philo.prog->te * 1000);
}

void	think(t_philo philo)
{
	//The philosopher should think when he is not eat or sleeping.
	//So keep usleep until able to eat or sleep.
	printf("%ld is thinking\n", philo.id + 1);
}

void	psleep(t_philo philo)
{
	printf("%ld is sleeping\n", philo.id + 1);
	usleep(philo.prog->ts * 1000);
}
