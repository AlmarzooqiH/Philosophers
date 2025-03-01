/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:20:04 by hamad             #+#    #+#             */
/*   Updated: 2025/03/02 01:52:40 by hamalmar         ###   ########.fr       */
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

# define TF "has taken a fork\n"
# define EAT "is eating\n"
# define SLP "is sleeping\n"
# define TK "is thinking\n"
# define DEAD "died\n"

//Time To Wait
# define TTW 150

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
int		init_prog_mutex(t_prog *prog);
void	destroy_mutex(t_prog *prog);
int		is_dead(t_prog *prog);
int		all_ate(t_prog *prog);
int		ft_isonlyspace(const char *s);
void	*simu(void *arg);
int		start_threads(t_prog *prog);
long	gtms(void);
void	print_status(t_philo *philo, int activity);
void	plf(t_philo *p);
void	dlf(t_philo *p);
void	eat(t_philo *p);
void	psleep(t_philo *p);
void	think(t_philo *p);
void	prf(t_philo *p);
void	drf(t_philo *p);
void	my_usleep(long time, t_prog *prog);
#endif