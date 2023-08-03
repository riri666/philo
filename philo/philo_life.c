/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchbouki <rchbouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 19:40:47 by rchbouki          #+#    #+#             */
/*   Updated: 2023/08/03 14:41:28 by rchbouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	philo_death(t_philo philo)
{
	t_data	*data;
	int		i;

	i = 0;
	data = philo.data;
	pthread_mutex_lock(&(data->death));
	if (data->finished == 1)
	{
		pthread_mutex_unlock(&(data->death));
		return (data->finished);
	}
	else if ((philo.times_eaten != data->max_meals) && (get_time() - philo.time_after_food) >= data->t_die)
	{
		printf("IN DEATH %ld %d\n", get_time() - philo.time_after_food, philo.id);
		data->finished = 1;
		ft_printf(data, "is dead", philo.id);
		while (i < data->number)
			pthread_mutex_unlock(&(data->forks[i++]));
		pthread_mutex_unlock(&(data->write));
		pthread_mutex_unlock(&(philo.time));
	}
	else
		data->finished = 0;
	pthread_mutex_unlock(&(data->death));
	return (data->finished);
}

/* This function will lock the forks if they are available and wait for the philo to finish eating to unlock them */
static int	philo_food(t_philo philo, t_data *data, int id)
{
	int	second_fork;

	if (id == 0)
		second_fork = data->number - 1;
	else
		second_fork = id - 1;
	pthread_mutex_lock(&(data->forks[id]));
	ft_printf(data, "took his first fork", id);
	if (philo_death(philo))
		return (0);
	pthread_mutex_lock(&(data->forks[second_fork]));
	if (philo_death(philo))
		return (0);
	ft_printf(data, "took his second fork", id);
	ft_printf(data, "is eating", id);
	ft_usleep(data->t_eat);
	philo.time_after_food = get_time();
	printf("FOOD %ld %d\n", get_time() - philo.time_after_food, philo.id);
	pthread_mutex_unlock(&(data->forks[id]));
	pthread_mutex_unlock(&(data->forks[second_fork]));
	philo.times_eaten++;
	if (philo_death(philo))
		return (0);
	return (1);
}

/* The thread function that is the real gestion of the philo */
static void	*thread_function(void *args)
{
	int			id;
	t_philo		philo;
	t_data		*data;

	philo = *((t_philo *)args);
	data = philo.data;
	id = philo.id;
	if (id % 2 == 0)
		ft_usleep(50);
	philo.times_eaten = 0;
	while (1)
	{
		if (((data->max_meals != -1) && (philo.times_eaten < data->max_meals)) || data->max_meals == -1)
			if (philo_food(philo, data, id) == 0)
				break;
		printf("BEFORE SLEEP %ld %d\n", get_time() - philo.time_after_food, philo.id);
		ft_printf(data, "is sleeping", id);
		ft_usleep(data->t_sleep);
		if (philo_death(philo))
			break;
		ft_printf(data, "is thinking", id);
	}
	return (NULL);
}

/* This function will be : Creating each thread, thus each philosophers cycle and later, waiting for them to finish in pthread_join */
void	philo_creation(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = malloc(sizeof(t_philo) * data->number);
	if (!philo)
		return ;
	data->tid = malloc(sizeof(pthread_t) * data->number);
	if (!data->tid)
		return ;
	data->philos = philo;
	while (i < data->number)
	{
		philo[i].id = i;
		philo[i].data = data;
		philo[i].time_after_food = get_time();
		pthread_create(&(data->tid[i]), NULL, &thread_function, &(philo[i]));
		i++;
	}
	int	test = 0;
	while (1)
	{
		i = 0;
		while (i < data->number)
		{
			test = philo_death(philo[i++]);
			if (test)
				break;
		}
		if (test)
			break;
	}
	i = 0;
	while (i < data->number)
		pthread_join(data->tid[i++], NULL);
	ft_finish(data);
}
