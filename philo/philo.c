/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchbouki <rchbouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:52:15 by rchbouki          #+#    #+#             */
/*   Updated: 2023/08/10 13:43:24 by rchbouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* This function will free the allocated elements and destroy the mutexes */
void	ft_finish(t_data *data)
{
	int		i;
	t_philo	*philos;

	i = 0;
	philos = data->philos;
	pthread_mutex_destroy(&(data->write));
	pthread_mutex_destroy(&(data->death));
	pthread_mutex_destroy(&(data->meals));
	while (i < data->number)
	{
		pthread_mutex_destroy(&(data->forks[i]));
		pthread_mutex_destroy(&(philos[i++].time));
	}
	free(philos);
	free(data->tid);
	free(data->forks);
	free(data);
}

int	main(int argc, char *argv[])
{
	t_data	*data;

	if (!check_arguments(argc, argv))
	{
		printf("You need to type in valid numeric arguments as follows :\n");
		printf("[number_of_philosophers] [time_to_die] [time_to_eat] ");
		printf("[time_to_eat] [time_to_sleep] [OPTIMAL : max_times_of_food]\n");
		exit(EXIT_FAILURE);
	}
	data = ft_init_data(argc, argv);
	if (!data)
		return (0);
	philo_creation(data);
	ft_finish(data);
}
