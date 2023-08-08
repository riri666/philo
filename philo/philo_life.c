/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchbouki <rchbouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 19:40:47 by rchbouki          #+#    #+#             */
/*   Updated: 2023/08/08 16:19:01 by rchbouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_death(t_data *data, t_philo *philo)
{
	int	res;
	int	second_fork;
	
	if (philo->id == 0)
		second_fork = data->number - 1;
	else
		second_fork = philo->id - 1;
	pthread_mutex_lock(&(data->death));
	res = data->finished;
	if (res == 1)
	{	
		pthread_mutex_lock(&(philo->first_mutex));
		if (philo->first_lock == 1)
			pthread_mutex_unlock(&(data->forks[philo->id]));
		pthread_mutex_unlock(&(philo->first_mutex));
		pthread_mutex_lock(&(philo->second_mutex));
		if (philo->second_lock == 1)
			pthread_mutex_unlock(&(data->forks[second_fork]));
		pthread_mutex_unlock(&(philo->second_mutex));
	}
	pthread_mutex_unlock(&(data->death));
	return (res);
}

/* This function will lock the forks if they are available and wait for the philo to finish eating to unlock them */
static int	philo_food(t_philo *philo, t_data *data, int id)
{
	int	second_fork;

	if (id == 0)
		second_fork = data->number - 1;
	else
		second_fork = id - 1;
	pthread_mutex_lock(&(data->forks[id]));
	pthread_mutex_lock(&(philo->first_mutex));
	philo->first_lock = 1;
	pthread_mutex_unlock(&(philo->first_mutex));
	if (check_death(data, philo))
		return (0);
	ft_printf(data, "took his first fork", id);
	pthread_mutex_lock(&(data->forks[second_fork]));
	pthread_mutex_lock(&(philo->second_mutex));
	philo->second_lock = 1;
	pthread_mutex_unlock(&(philo->second_mutex));
	if (check_death(data, philo))
		return (0);
	ft_printf(data, "took his second fork", id);
	ft_printf(data, "is eating", id);
	ft_usleep(data->t_eat);
	pthread_mutex_lock(&(philo->time));
	philo->time_after_food = get_time();
	philo->times_eaten++;
	pthread_mutex_unlock(&(philo->time));
	food_utils(data, philo);
	pthread_mutex_unlock(&(data->forks[id]));
	pthread_mutex_lock(&(philo->first_mutex));
	philo->first_lock = 0;
	pthread_mutex_unlock(&(philo->first_mutex));
	pthread_mutex_unlock(&(data->forks[second_fork]));
	pthread_mutex_lock(&(philo->second_mutex));
	philo->second_lock = 0;
	pthread_mutex_unlock(&(philo->second_mutex));
	return (1);
}

/* The thread function that is the real gestion of the philo */
static void	*thread_function(void *args)
{
	int			id;
	t_philo		*philo;
	t_data		*data;

	philo = (t_philo *)args;
	data = philo->data;
	id = philo->id;
	if (id % 2 == 0)
		ft_usleep(50);
	pthread_mutex_lock(&(philo->time));
	philo->times_eaten = 0;
	pthread_mutex_unlock(&(philo->time));
	while (1)
	{
		if (philo_food(philo, data, id) == 0)
			break;
		if (check_death(data, philo))
			return (0);
		ft_printf(data, "is sleeping", id);
		ft_usleep(data->t_sleep);
		if (check_death(data, philo))
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
	i = 0;
	while (i < data->number)
	{
		philo[i].id = i;
		philo[i].data = data;
		pthread_mutex_init(&(philo[i].time), NULL);
		pthread_mutex_init(&(philo[i].first_mutex), NULL);
		pthread_mutex_init(&(philo[i++].second_mutex), NULL);
		philo[i].first_lock = 0;
		philo[i].second_lock = 0;
	}
	i = 0;
	while (i < data->number)
	{
		philo[i].time_after_food = get_time();
		pthread_create(&(data->tid[i]), NULL, &thread_function, &(philo[i]));
		i++;
	}
	main_death(data, philo);
	i = 0;
	while (i < data->number)
		pthread_join(data->tid[i++], NULL);
}
