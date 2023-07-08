/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchbouki <rchbouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:52:15 by rchbouki          #+#    #+#             */
/*   Updated: 2023/07/08 19:40:13 by rchbouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_data	*philos;
	
	if (!check_arguments(argc, argv))
	{
		printf("You need to type in valid numeric arguments as follows :\n[number_of_philosophers] [time_to_die]");
		printf(" [time_to_eat] [time_to_sleep] [OPTIMAL : number_of_times_each_philosopher_must_eat]\n");
		exit(EXIT_FAILURE);
	}
	philos = ft_init_philo(argc, argv);
	
}
