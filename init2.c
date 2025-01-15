/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:54:03 by hamad             #+#    #+#             */
/*   Updated: 2025/01/15 15:55:57 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

/**
 * @brief This function is responsible to destroy the forks mutexes.
 * @param prog The t_prog struct.
 * @return Void.
 */
void	destroy_forks(t_prog *prog)
{
	int	i;

	i = 0;
	while (i < prog->n_philo)
	{
		pthread_mutex_destroy(&prog->forks[i]);
		i++;
	}
}
