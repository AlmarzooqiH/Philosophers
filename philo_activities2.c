/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_activities2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 22:39:26 by hamad             #+#    #+#             */
/*   Updated: 2025/02/12 16:48:04 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

void	release_forks(t_philo *p)
{
	int	fork_pos;

	fork_pos = (p->id + 1) % p->prog->n_philo;
	if (p->prog->fs[p->id] == 1)
		p->prog->fs[p->id] = 0;
	else if (p->prog->fs[fork_pos] == 1)
		p->prog->fs[fork_pos] = 0;
}

void	psleep(t_philo *p)
{
	print_status(p, e_sleep);
	usleep(p->prog->ts);
}
