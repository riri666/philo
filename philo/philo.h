/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchbouki <rchbouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:52:17 by rchbouki          #+#    #+#             */
/*   Updated: 2023/07/08 15:19:27 by rchbouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct	s_philo_basics
{
	int	philo_nb;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	max_meals;
} t_philo_basics;

long int	ft_atoi(char *s);
int			ft_strlen(char *s);
int			check_arguments(int size, char **s);

#endif