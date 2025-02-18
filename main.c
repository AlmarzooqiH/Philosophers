/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:20:35 by hamad             #+#    #+#             */
/*   Updated: 2025/02/19 01:26:26 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

int	is_dead(t_prog *prog)
{
	int		i;
	long	ctime;

	if (prog->n_philo == 1)
	return (prog->dead_philo = 1,
		print_status(&prog->philo[0], e_dead), 1);
	ctime = gtms();
	i = 0;
	while (i < prog->n_philo)
	{
		if ((ctime - prog->philo[i].last_meal) > prog->td)
			return (prog->dead_philo = 1,
				print_status(&prog->philo[i], e_dead), 1);
		usleep(TTT * 100);
		i++;
	}
	return (0);
}

int	all_ate(t_prog *prog)
{
	int	i;
	int	count;

	while (i < prog->n_philo)
	{
		if (prog->philo[i].n_meals == prog->neat)
			count++;
	}
	return (prog->n_philo == count);
}

void	*monitor(void *arg)
{
	t_prog	*prog;

	prog = (t_prog *)arg;
	usleep(TTT	* 1000);
	while (!prog->dead_philo)
	{
		if (prog->neat > 0 && all_ate(prog))
			return (prog->dead_philo = 1, NULL);
		is_dead(prog);
		usleep(TTT * 1000);
	}
	return (NULL);
}

void	*simu(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	if (p->prog->n_philo == 1)
	{
		plf(p);
		usleep(TTT * 1000);
		return (NULL);
	}
	while (!p->prog->dead_philo)
	{
		if (p->prog->neat > 0 && p->n_meals == p->prog->neat)
			return (NULL);
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

	if (pthread_create(&prog->monitor, NULL, monitor, prog))
		return (printf("%s", FTT), 0);
		i = 0;
		while (i < prog->n_philo)
	{
		if (pthread_create(&prog->philo[i].tid, NULL, simu, &prog->philo[i]))
			return (printf("%s", FTT), 0);
		i++;
	}
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
