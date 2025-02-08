/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 20:51:21 by hamad             #+#    #+#             */
/*   Updated: 2025/02/08 14:12:15 by hamad            ###   ########.fr       */
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
			return (printf("%s", CANA), 1);
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
				return (printf("%s", EA), 1);
			if (validate2(av[i]))
				return (1);
			if (ft_atol(av[i]) < 0 || ft_atol(av[i]) > INT_MAX)
				return (printf("%s", OFB), 1);
			i++;
		}
		return (0);
	}
	return (printf("%s", IAS), 1);
}
