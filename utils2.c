/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 05:55:48 by hamad             #+#    #+#             */
/*   Updated: 2025/02/10 22:45:29 by hamad            ###   ########.fr       */
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
