/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:20:35 by hamad             #+#    #+#             */
/*   Updated: 2025/01/11 16:22:03 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

int	main(int ac, char **av)
{
	t_prog	*prog;

	if (validate(ac, av))
		return (EXIT_FAILURE);
	prog = (t_prog *)malloc(sizeof(t_prog));
	if (!prog)
		return (printf("Failed to malloc t_prog"), EXIT_FAILURE);
	if (init(ac, av, prog))
		return (EXIT_FAILURE);
	printf("prog data: \n");
	printf("prog->n_philo: %d\n", prog->n_philo);
	printf("prog->td: %ldms\n", prog->td * 1000);
	printf("prog->te: %ldms\n", prog->te * 1000);
	printf("prog->ts: %ldms\n", prog->ts * 1000);
	if (prog->neat > 0)
		printf("prog->neat: %d\n", prog->neat);
	printf("====================================\nprog->philo data: \n");
	for (int i = 0; i < prog->n_philo; i++)
	{
		printf("Philosopher %d:\n", prog->philo[i].id);
		printf("  Thread ID: %lu\n", prog->philo[i].tid);
		printf("  Left hand: %d\n", prog->philo[i].lh);
		printf("  Right hand: %d\n", prog->philo[i].rh);
		printf("  Took fork at: %ldms\n", prog->philo[i].mstf * 1000);
		printf("  Started eating at: %ldms\n", prog->philo[i].mse * 1000);
		printf("  Started sleeping at: %ldms\n", prog->philo[i].mss * 1000);
		printf("  Started thinking at: %ldms\n", prog->philo[i].mst * 1000);
		printf("  Died at: %ldms\n", prog->philo[i].msd * 1000);
		printf("------------------------------------\n");
	}
	free_prog(prog);
	return (EXIT_SUCCESS);
}
