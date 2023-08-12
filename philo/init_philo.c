/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchbouki <rchbouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 14:49:15 by rchbouki          #+#    #+#             */
/*   Updated: 2023/08/12 16:46:17 by rchbouki         ###   ########.fr       */
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
		if (ft_atoi(s[i]) > 2147483647 || ft_atoi(s[i]) == -1)
			return (0);
		i++;
	}
	return (1);
}

int	check_arguments(int size, char **s)
{
	if (size < 5 || size >= 7)
		return (0);
	else
		if (!ft_isdigit(size, s) || !ft_limits(size, s))
			return (0);
	return (1);
}

/* This function will be : Initializing the data structure */
t_data	*ft_init_data(int size, char **s)
{
	int		i;
	t_data	*data;

	i = 0;
	data = malloc(sizeof(t_data) * 1);
	if (!data)
		return (NULL);
	data->number = ft_atoi(s[1]);
	data->t_die = ft_atoi(s[2]);
	data->t_eat = ft_atoi(s[3]);
	data->t_sleep = ft_atoi(s[4]);
	if (size == 5)
		data->max_meals = -1;
	else
		data->max_meals = ft_atoi(s[5]);
	data->finished = 0;
	data->enough_meals = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->number);
	if (!data->forks)
		return (NULL);
	while (i < data->number)
		pthread_mutex_init(&(data->forks[i++]), NULL);
	pthread_mutex_init(&(data->death), NULL);
	pthread_mutex_init(&(data->meals), NULL);
	return (data);
}

void	ft_init_philo(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->number)
	{
		philo[i].id = i;
		philo[i].data = data;
		pthread_mutex_init(&(philo[i++].time), NULL);
	}
}
