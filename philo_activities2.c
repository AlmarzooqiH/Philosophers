/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_activities2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 22:39:26 by hamad             #+#    #+#             */
/*   Updated: 2025/02/11 01:09:32 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

void	release_forks(t_philo *philo)
{
	if (philo->lh)
		philo->lh = 0;
	else if (philo->rh)
		philo->rh = 0;
}

