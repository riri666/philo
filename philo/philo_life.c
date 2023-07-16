/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchbouki <rchbouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 19:40:47 by rchbouki          #+#    #+#             */
/*   Updated: 2023/07/15 16:42:45 by rchbouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_food(t_philo *philo, t_data *data)
{
	
}

static void	*thread_function(void *args)
{
	t_philo	*philo;
	t_data	*data;
	int		id;

	philo = (t_philo *)args;
	data = philo->data;
	id = philo->id;
	while (1)
	{
		pthread_mutex_lock(&(data->forks[id]));
		printf("Philosopher %d took his first fork\n", id);
		if (id == 0)
			pthread_mutex_lock(&(data->forks[data->number - 1]));
		else
			pthread_mutex_lock(&(data->forks[id - 1]));
		printf("Philosopher %d took his second fork fork\n", id);
		pthread_mutex_lock(&write);
		printf("Philosopher %d is eating\n", id);
		ft_usleep(philo->data->t_eat);
		pthread_mutex_unlock(&write);
		pthread_mutex_lock(&write);
		printf("Philosopher %d is sleeping\n", id);
		ft_usleep(philo->data->t_sleep);
		pthread_mutex_unlock(&write);
		pthread_mutex_lock(&write);
		printf("Philosopher %d is sleeping\n", id);
		pthread_mutex_unlock(&write);
	}
	return (NULL);
}

void	philo_creation(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = malloc(sizeof(t_philo) * data->number);
	if (!philo)
		return (NULL);
	data->tid = malloc(sizeof(pthread_t) * data->number);
	if (!data->tid)
		return ;
	while (i < data->number)
	{
		philo[i].data = data;
		philo[i].id = i;
		pthread_create(&(data->tid[i++]), NULL, &thread_function, philo);
	}
	i = 0;
	while (i < data->number)
		pthread_join(data->tid[i++], NULL);
	ft_finish(data);
}
