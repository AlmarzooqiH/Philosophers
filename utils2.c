/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 05:55:48 by hamad             #+#    #+#             */
/*   Updated: 2025/03/05 16:00:39 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	if (n <= 0)
		return ;
	i = 0;
	while (i < n)
	{
		*(unsigned char *)(s + i) = 0;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*intialize;

	intialize = malloc(count * size);
	if (intialize == NULL)
		return (NULL);
	ft_bzero(intialize, size * count);
	return (intialize);
}

/**
 * @name Get time in mili-seconds.
 * @brief This function will return the current time in mili-seconds.
 * @return The current time in mili-seconds.
 */
long	gtms(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		return (printf("Failed to get time\n"), -1);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

/**
 * @brief This function will sleep for a given time in mili-seconds.
 * @param tims The time to sleep in mili-seconds.
 * @param prog The program struct.
 * @return void
 */
void	my_usleep(long tims, t_prog *prog)
{
	long	start;

	start = gtms();
	while ((gtms() - start) < tims)
	{
		pthread_mutex_lock(&prog->dead);
		if (prog->dead_philo == 1)
		{
			pthread_mutex_unlock(&prog->dead);
			return ;
		}
		pthread_mutex_unlock(&prog->dead);
		usleep(TTW);
	}
}

/**
 * @brief This function will check the dead philo flag.
 * @param prog The program struct.
 * @return 1 If the philo is dead.
 * @return 0 If the philo is not dead.
 */
int	check_dead(t_prog *prog)
{
	pthread_mutex_lock(&prog->dead);
	if (prog->dead_philo == 1)
	{
		pthread_mutex_unlock(&prog->dead);
		return (1);
	}
	pthread_mutex_unlock(&prog->dead);
	return (0);
}
