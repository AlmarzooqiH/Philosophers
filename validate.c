/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 20:51:21 by hamad             #+#    #+#             */
/*   Updated: 2025/01/11 16:16:05 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

int	validate2(char *str)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(str))
	{
		if (ft_isspace(str[i]) || str[i] == '-' || str[i] == '+')
		{
			i++;
			continue ;
		}
		if (!ft_isdigit(str[i]))
			return (printf("Characters are not allowed\n"), 1);
		i++;
	}
	return (0);
}

int	validate(int ac, char **av)
{
	int		i;

	if (ac >= 5 && ac <= 7)
	{
		i = 1;
		while (i < ac)
		{
			if (ft_isonlyspace(av[i]) || av[i][0] == '\0')
				return (printf("Empty argument\n"), 1);
			if (validate2(av[i]))
				return (1);
			if (atol(av[i]) < 0 || atol(av[i]) > INT_MAX)
				return (printf("Number should be > 0 and < INT_MAX\n"), 1);
			i++;
		}
		return (0);
	}
	return (printf("Invalid size arguments\n"), 1);
}
