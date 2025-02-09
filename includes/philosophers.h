/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:20:04 by hamad             #+#    #+#             */
/*   Updated: 2025/02/10 01:47:25 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <limits.h>
# include "struct.h"
# include "error.h"

# define TF "Taken a fork\n"
# define EAT "Eating\n"
# define SLP "Sleeping\n"
# define TK "Thinking\n"
# define DEAD "Died\n"

// void	print_data(t_prog *prog);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *str);
int		ft_isdigit(int c);
long	ft_atol(const char *str);
int		ft_isspace(int c);
int		validate(int ac, char **av);
int		validate2(char *str);
void	free_prog2(t_prog *prog);
void	free_prog(t_prog *prog);
int		init_forks(t_prog *prog);
void	destroy_forks(t_prog *prog);
int		init(int ac, char **av, t_prog *prog);
int		ft_isonlyspace(const char *s);
void	*simu(void *arg);
int		start_threads(t_prog *prog);
void	get_forks(t_philo philo);
void	eat(t_philo philo);
void	think(t_philo philo);
void	psleep(t_philo philo);
long	gtms(void);
void	print_status(t_philo philo, int activity);
#endif