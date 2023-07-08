/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchbouki <rchbouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 14:49:15 by rchbouki          #+#    #+#             */
/*   Updated: 2023/07/08 19:44:53 by rchbouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isdigit(int size, char **s)
{
	int	i;
	int	j;

	i = 1;
	while (i < size)
	{
		j = 0;
		while (s[i][j])	
		{
			if ((s[i][j] < '0') || (s[i][j] > '9'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	ft_limits(int size, char **s)
{
	int	i;

	i = 1;
	while (i < size)
	{
		if (ft_atoi(s[i]) > 2147483647)
			return (0);
		i++;
	}
	return (1);
}

int	check_arguments(int size, char **s)
{
	int	i;

	i = 0;
	if (size < 5 || size >= 7)
		return (0);
	else
		if (!ft_isdigit(size, s) || !ft_limits(size, s))
			return (0);
	return (1);
}

t_data	*ft_init_philo(int size, char **s)
{
	t_data	*philos;
	
	int		i;

	i = 0;
	philos->number = ft_atoi(s[1]);
	philos->t_die = ft_atoi(s[2]);
	philos->t_eat = ft_atoi(s[3]);
	philos->t_sleep = ft_atoi(s[4]);
	if (size == 5)
		philos->max_meals = -1;
	else
		philos->max_meals = ft_atoi(s[5]);
	philos->finished = 0;
	philos->forks = malloc(sizeof(pthread_mutex_t) * philos->number);
	if (!philos->forks)
		return (NULL);
	while (i < philos->number)
		pthread_mutex_init(&(philos->forks[i++]), NULL);
	return (philos);
}

void	ft_finish(t_data *philos)
{
	int	i;

	i = 0;
	while (i < philos->number)
		pthread_mutex_destroy(&(philos->forks[i++]));
	free(philos->forks);
}