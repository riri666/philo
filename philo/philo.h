/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchbouki <rchbouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:52:17 by rchbouki          #+#    #+#             */
/*   Updated: 2023/07/08 19:33:16 by rchbouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

typedef struct	s_data
{
	int	number;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	max_meals;
	int	finished;
	pthread_mutex_t *forks;
	pthread_t		*tid;
} t_data;

typedef struct	s_philo
{
	int	id;
}	t_philo;

long int	ft_atoi(char *s);
int			ft_strlen(char *s);

t_data		*ft_init_philo(int size, char **s);
void		ft_finish(t_data *philos);
int			check_arguments(int size, char **s);

#endif