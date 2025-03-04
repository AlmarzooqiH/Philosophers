/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:20:35 by hamad             #+#    #+#             */
/*   Updated: 2025/03/04 22:33:54 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

/**
 * @brief This function will be executed by the monitor thread where it will ch
 * eck if one of the philosophers has died or not.
 * @param prog The program struct.
 * @return 1 If one of the philosophers has died.
 * @return 0 If none of the philosophers has died.
 */
int	is_dead(t_prog *prog)
{
	int		i;

	pthread_mutex_lock(&prog->dead);
	i = 0;
	while (i < prog->n_philo)
	{
		pthread_mutex_lock(&prog->philo[i].meal);
		if ((gtms() - prog->philo[i].last_meal) >= prog->td)
			return (prog->dead_philo = 1,
				print_status(&prog->philo[i], e_dead),
				pthread_mutex_unlock(&prog->philo[i].meal),
				pthread_mutex_unlock(&prog->dead), 1);
		pthread_mutex_unlock(&prog->philo[i].meal);
		i++;
	}
	pthread_mutex_unlock(&prog->dead);
	return (0);
}

/**
 * @brief This function is the routine of the monitor thread.
 * @param arg The program struct.
 * @return NULL
 */
void	*monitor(void *arg)
{
	t_prog	*prog;

	prog = (t_prog *)arg;
	while (1)
	{
		if (is_dead(prog) || (prog->neat > 0 && all_ate(prog)))
			break ;
		usleep(10);
	}
	return (NULL);
}

/**
 * @brief This function is the routine of the philosopher thread.
 * @param arg The philosopher struct.
 * @return NULL
 */
void	*simu(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	if (p->id % 2 == 1)
		my_usleep(1, p->prog);
	if (p->prog->n_philo == 1)
		return (plf(p), my_usleep(p->prog->td, p->prog), NULL);
	while (1)
	{
		pthread_mutex_lock(&p->prog->dead);
		if (p->prog->dead_philo == 1)
			return (pthread_mutex_unlock(&p->prog->dead), NULL);
		pthread_mutex_unlock(&p->prog->dead);
		plf(p);
		prf(p);
		eat(p);
		dlf(p);
		drf(p);
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
	prog->time = gtms();
	while (i < prog->n_philo)
	{
		prog->philo[i].last_meal = prog->time;
		if (pthread_create(&prog->philo[i].tid, NULL, simu, &prog->philo[i]))
			return (printf("%s", FTT), 0);
		i++;
	}
	if (pthread_create(&prog->monitor, NULL, monitor, prog))
		return (printf("%s", FTT), 0);
	i = 0;
	while (i < prog->n_philo)
	{
		if (pthread_join(prog->philo[i].tid, NULL))
			return (printf("%s", FTJT), 0);
		i++;
	}
	if (pthread_join(prog->monitor, NULL))
		return (printf("%s", FTJT), 0);
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
