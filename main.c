/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:20:35 by hamad             #+#    #+#             */
/*   Updated: 2025/02/12 16:46:37 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

int	is_dead(t_philo *philo)
{
	if (philo->mse > philo->prog->td)
		return (print_status(philo, e_dead), 1);
	return (0);
}

void	*monitor(void *arg)
{
	t_prog	*prog;

	prog = (t_prog *)arg;
	prog->time++;
}

void	*simu(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	while (!is_dead(p))
	{
		get_left_fork(p);
		if (p->prog->n_philo == 1)
		{
			usleep(p->prog->td);
			return (NULL);
		}
		get_right_fork(p);
		pthread_mutex_lock(&p->prog->eat);
		eat(p);
		p->n_meals++;
		pthread_mutex_unlock(&p->prog->eat);
		release_forks(p);
		release_forks(p);
		psleep(p);
		think(p);
	}
	return (NULL);
}

/**
 * @brief This function will create a thread for each philosopher and join it
 * to the main thread.
 * @param prog The program struct.
 * @return 0 On Failure.
 * @return 1 On Success.
 */
int	start_threads(t_prog *prog)
{
	int	i;

	i = 0;
	while (i < prog->n_philo)
	{
		if (pthread_create(&prog->philo[i].tid, NULL, simu, &prog->philo[i]))
			return (printf("%s", FTT), 0);
		i++;
	}
	if (pthread_create(&prog->monitor, NULL, monitor, prog))
		return (printf("%s", FTT), 0);
	if (pthread_join(prog->monitor, NULL))
		return (printf("%s", FTJT), 0);
	i = 0;
	while (i < prog->n_philo)
	{
		if (pthread_join(prog->philo[i].tid, NULL))
			return (printf("%s", FTJT), 0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_prog	*prog;

	if (validate(ac, av))
		return (EXIT_FAILURE);
	prog = (t_prog *)ft_calloc(1, sizeof(t_prog));
	if (!prog)
		return (printf("%s", FTCT), EXIT_FAILURE);
	if (init(ac, av, prog))
		return (EXIT_FAILURE);
	if (!start_threads(prog))
		return (free_prog(prog), EXIT_FAILURE);
	free_prog(prog);
	return (EXIT_SUCCESS);
}
