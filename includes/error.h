/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 07:43:09 by hamad             #+#    #+#             */
/*   Updated: 2025/02/12 16:53:36 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

/* Invalid Argument Errors */
# define EA "Empty argument\n\0"
# define CANA "Characters are not allowed\n\0"
# define OFB "Number should be > 0 and < INT_MAX\n\0"
# define IAS "Invalid size arguments\n\0"

/* Malloc Errors */
# define FTCT "Failed to calloc t_prog\n\0"
# define FTCP "Failed to calloc t_philo\n\0"
# define FTCFS "Failed to calloc fork status\n\0"

/* Initialization Errors */
# define FTIP "Failed to init t_philo\n\0"
# define FTIM "Failed to init mutex fork\n\0"
# define FTIPM "Failed to init print mutex\n\0"
# define FTIEM "Failed to init eat mutex\n\0"
# define FTIDM "Failed to init dead mutex\n\0"

/* Threads Errors */
# define FTT "Failed to start threads\n\0"
# define FTJT "Failed to join threads\n\0"

#endif