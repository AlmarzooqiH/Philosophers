/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:20:04 by hamad             #+#    #+#             */
/*   Updated: 2025/01/15 06:00:50 by hamad            ###   ########.fr       */
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

// void	print_data(t_prog *prog);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *str);
int		ft_isdigit(int c);
long	ft_atol(const char *str);
int		ft_isspace(int c);
int		validate(int ac, char **av);
int		validate2(char *str);
void	free_prog(t_prog *prog);
int		init(int ac, char **av, t_prog *prog);
int		ft_isonlyspace(const char *s);
#endif