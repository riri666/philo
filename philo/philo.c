/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchbouki <rchbouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:52:15 by rchbouki          #+#    #+#             */
/*   Updated: 2023/08/09 20:55:34 by rchbouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	data = ft_init_philo(argc, argv);
	if (!data)
		return (0);
	philo_creation(data);
	ft_finish(data);
}
