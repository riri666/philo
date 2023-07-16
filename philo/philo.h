/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchbouki <rchbouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:52:17 by rchbouki          #+#    #+#             */
/*   Updated: 2023/07/15 16:38:19 by rchbouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

typedef struct s_data
{
	int				t_die;
	int				t_eat;
	int				number;
	int				t_sleep;
	int				finished;
	int				max_meals;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write;
	pthread_t		*tid;
	t_philo			*philos;
}	t_data;

typedef struct s_philo
{
	int				id;
	struct s_data	*data;
}	t_philo;

long int	ft_atoi(char *s);
int			ft_strlen(char *s);
u_int64_t	get_time(void);
int			ft_usleep(useconds_t time);

t_data		*ft_init_philo(int size, char **s);
void		philo_creation(t_data *philos);
void		ft_finish(t_data *philos);
int			check_arguments(int size, char **s);

#endif