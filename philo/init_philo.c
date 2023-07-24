/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchbouki <rchbouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 14:49:15 by rchbouki          #+#    #+#             */
/*   Updated: 2023/07/24 13:36:03 by rchbouki         ###   ########.fr       */
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
	if (size < 5 || size >= 7)
		return (0);
	else
		if (!ft_isdigit(size, s) || !ft_limits(size, s))
			return (0);
	return (1);
}

/* This function will be : 
	- Initializing the data structure
	- Setting the times of death, sleep and food of the philos
	- Setting the death int to 0 which will only turn to 1 if someone dies and the max_meals will be -1 only if it hasn't been given
	- Initializing the fork mutexes, fork number equals number of philos */
t_data	*ft_init_philo(int size, char **s)
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
	data->forks = malloc(sizeof(pthread_mutex_t) * data->number);
	if (!data->forks)
		return (NULL);
	while (i < data->number)
		pthread_mutex_init(&(data->forks[i++]), NULL);
	pthread_mutex_init(&(data->write), NULL);
	pthread_mutex_init(&(data->death), NULL);
	data->start = get_time();
	return (data);
}

/* This function will be freeing all of the allocated elements and destroying all of the mutexes before exiting the program. */
void	ft_finish(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number)
		pthread_mutex_destroy(&(data->forks[i++]));
	pthread_mutex_destroy(&(data->write));
	pthread_mutex_destroy(&(data->death));
	free(data->forks);
	free(data->tid);
	free(data->philos);
	free(data);
}
