/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchbouki <rchbouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:58:23 by rchbouki          #+#    #+#             */
/*   Updated: 2023/08/09 21:22:54 by rchbouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_printf(t_data *data, char *msg, int id)
{
	pthread_mutex_lock(&(data->write));
	if (ft_strcmp(msg, "took his second fork") == 0)
	{
		printf("%lld Philospher %d %s\n", get_time() - data->start, id, msg);
		printf("%lld Philospher %d is eating\n", get_time() - data->start, id);
	}
	else
		printf("%lld Philospher %d %s\n", get_time() - data->start, id, msg);
	pthread_mutex_unlock(&(data->write));
}

void	food_utils(t_data *data, t_philo *philo)
{
	if (data->max_meals != -1)
	{
		pthread_mutex_lock(&(data->meals));
		if (philo->times_eaten == data->max_meals)
			data->enough_meals++;
		if (data->enough_meals == data->number)
		{
			pthread_mutex_lock(&(data->death));
			data->finished = 1;
			pthread_mutex_unlock(&(data->death));
		}
		pthread_mutex_unlock(&(data->meals));
	}
}

int	check_death(t_data *data)
{
	int	res;

	pthread_mutex_lock(&(data->death));
	res = data->finished;
	pthread_mutex_unlock(&(data->death));
	return (res);
}

int	philo_death(t_philo *philo)
{
	t_data	*data;
	int		i;

	i = 0;
	data = philo->data;
	pthread_mutex_lock(&(data->death));
	if (data->finished != 1)
	{
		pthread_mutex_lock(&(philo->time));
		if ((philo->times_eaten != data->max_meals)
			&& (get_time() - philo->time_after_food) > data->t_die)
		{
			data->finished = 1;
			ft_printf(data, "is dead", philo->id);
		}
		pthread_mutex_unlock(&(philo->time));
	}
	i = data->finished;
	pthread_mutex_unlock(&(data->death));
	return (i);
}

void	main_death(t_data *data, t_philo *philo)
{
	int	i;

	if (data->max_meals != 0)
	{
		while (1)
		{
			i = 0;
			while (i < data->number)
			{
				if (philo_death(&(philo[i])))
					break ;
				i++;
			}
			if (i != data->number)
				break ;
		}
	}
}
