/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchbouki <rchbouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 19:40:47 by rchbouki          #+#    #+#             */
/*   Updated: 2023/07/08 19:45:07 by rchbouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_philo(t_data *philos)
{
	int	i;

	i = 0;
	philos->tid = malloc(sizeof(pthread_t) * philos->number);
	if (!philos->tid)
		return (NULL);
	/* while (i < philos->number)
		pthread_create(&(philos->tid[i++]), NULL); */
}
