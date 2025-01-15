/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 10:57:22 by hamad             #+#    #+#             */
/*   Updated: 2025/01/15 09:35:27 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

/**
 * @brief This function is responsible on freeing the t_prog data.
 * @param prog The t_prog that we want to free.
 * @return Void.
 */
void	free_prog2(t_prog *prog)
{
	if (prog)
	{
		prog->n_philo = 0;
		prog->td = 0;
		prog->te = 0;
		prog->ts = 0;
		prog->neat = 0;
		prog->time = 0;
		free(prog);
		prog = NULL;
	}
}

/**
 * @brief This function is responsible on freeing the t_prog data.
 * @param prog The t_prog that we want to free.
 * @return Void.
 */
void	free_prog(t_prog *prog)
{
	int	i;

	if (prog->philo)
	{
		i = 0;
		while (i < prog->n_philo)
		{
			prog->philo[i].id = i;
			prog->philo[i].lh = 0;
			prog->philo[i].rh = 0;
			prog->philo[i].mstf = 0;
			prog->philo[i].mse = 0;
			prog->philo[i].mss = 0;
			prog->philo[i].mst = 0;
			prog->philo[i].msd = 0;
			pthread_mutex_destroy(&prog->philo[i].mfork);
			i++;
		}
		free(prog->philo);
		prog->philo = NULL;
	}
	free_prog2(prog);
}

/**
 * @brief This functiom is resposible to init the t_philo struct.
 * @param prog The t_prog that we want to initalize.
 * @return 0 On success.
 * @return 1 on Failure.
 */

int	init_philo(t_prog *prog)
{
	int	i;

	if (!prog)
		return (1);
	i = 0;
	while (i < prog->n_philo)
	{
		prog->philo[i].id = i;
		prog->philo[i].lh = 0;
		prog->philo[i].rh = 0;
		prog->philo[i].es = 0;
		prog->philo[i].ts = 0;
		prog->philo[i].ss = 0;
		prog->philo[i].ds = 0;
		prog->philo[i].mstf = 0;
		prog->philo[i].mse = 0;
		prog->philo[i].mss = 0;
		prog->philo[i].mst = 0;
		prog->philo[i].msd = 0;
		if (pthread_mutex_init(&prog->philo[i].mfork, NULL) != 0)
			return (printf("%s", FTIM), 1);
		i++;
	}
	return (0);
}

/**
 * @brief This functiom is resposible to init the t_prog struct.
 * @param ac Argument count.
 * @param av Arguments.
 * @param prog The t_prog that we want to initalize.
 * @return 0 On success.
 * @return 1 on Failure.
 */
int	init(int ac, char **av, t_prog *prog)
{
	int		i;

	prog->n_philo = ft_atol(av[1]);
	prog->td = ft_atol(av[2]);
	prog->te = ft_atol(av[3]);
	prog->ts = ft_atol(av[4]);
	prog->time = 0;
	if (ac == 6)
		prog->neat = ft_atol(av[5]);
	else
		prog->neat = -1;
	prog->philo = (t_philo *)ft_calloc((prog->n_philo), sizeof(t_philo));
	if (!prog->philo)
		return (printf("%s", FTCP), free_prog(prog), 1);
	if (init_philo(prog))
		return (printf("%s", FTIP), free_prog(prog), 1);
	return (0);
}
