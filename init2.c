/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:54:03 by hamad             #+#    #+#             */
/*   Updated: 2025/02/17 13:07:59 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

/**
 * @brief This function is responsible to destroy the mforks mutexes.
 * @param prog The t_prog struct.
 * @return Void.
 */
void	destroy_forks(t_prog *prog)
{
	int	i;

	i = 0;
	while (i < prog->n_philo)
	{
		pthread_mutex_destroy(&prog->mforks[i]);
		i++;
	}
}

/**
 * @brief This function will initalize the prog mutexes.
 * @param prog The t_prog struct.
 * @return 0 On Success.
 * @return 1 On Failure.
 */
int	init_prog_mutex(t_prog *prog)
{
	if (pthread_mutex_init(&prog->print, NULL) != 0)
		return (printf("%s", FTIPM), 1);
	return (0);
}

void	destroy_mutex(t_prog *prog)
{
	pthread_mutex_destroy(&prog->print);
}
