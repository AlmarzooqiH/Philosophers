/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:20:35 by hamad             #+#    #+#             */
/*   Updated: 2025/01/15 07:40:53 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

int	start_threads(t_prog *prog)
{
	int	i;

	i = 0;
	while (i < prog->n_philo)
	{
		if (pthread_create(&prog->philo[i].tid, NULL, NULL, &prog->philo[i]))
			return (0);
		i++;
	}
	i = 0;
	while (i < prog->n_philo)
	{
		if (pthread_join(prog->philo[i].tid, NULL))
			return (0);
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
		return (printf("Failed to calloc t_prog\n"), EXIT_FAILURE);
	if (init(ac, av, prog))
		return (EXIT_FAILURE);
	if (!start_threads(prog))
		return (printf("%s", FTT), free_prog(prog), EXIT_FAILURE);
	free_prog(prog);
	return (EXIT_SUCCESS);
}
