/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 20:49:35 by hamad             #+#    #+#             */
/*   Updated: 2025/01/11 17:41:25 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

long	ft_atol(const char *str)
{
	int			sign;
	long long	num;

	if (!str)
		return (0);
	sign = 1;
	num = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	if (sign == -1)
		num = -num;
	return (num);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	ft_isonlyspace(const char *s)
{
	size_t	i;

	if (!s || s[0] == '\0')
		return (0);
	i = 0;
	while (ft_isspace(s[i]))
		i++;
	return (i == ft_strlen(s));
}

// void	print_data(t_prog *prog)
// {
// 	printf("prog data: \n");
// 	printf("prog->n_philo: %d\n", prog->n_philo);
// 	printf("prog->td: %ldms\n", prog->td * 1000);
// 	printf("prog->te: %ldms\n", prog->te * 1000);
// 	printf("prog->ts: %ldms\n", prog->ts * 1000);
// 	if (prog->neat > 0)
// 		printf("prog->neat: %d\n", prog->neat);
// 	printf("====================================\nprog->philo data: \n");
// 	for (int i = 0; i < prog->n_philo; i++)
// 	{
// 		printf("Philosopher %d:\n", prog->philo[i].id);
// 		printf("  Thread ID: %lu\n", prog->philo[i].tid);
// 		printf("  Left hand: %d\n", prog->philo[i].lh);
// 		printf("  Right hand: %d\n", prog->philo[i].rh);
// 		printf("  Took fork at: %ldms\n", prog->philo[i].mstf * 1000);
// 		printf("  Started eating at: %ldms\n", prog->philo[i].mse * 1000);
// 		printf("  Started sleeping at: %ldms\n", prog->philo[i].mss * 1000);
// 		printf("  Started thinking at: %ldms\n", prog->philo[i].mst * 1000);
// 		printf("  Died at: %ldms\n", prog->philo[i].msd * 1000);
// 		printf("  Mutex fork: %p\n", &prog->philo[i].mfork);
// 		printf("------------------------------------\n");
// 	}
// }
