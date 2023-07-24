/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchbouki <rchbouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:52:17 by rchbouki          #+#    #+#             */
/*   Updated: 2023/07/24 17:32:11 by rchbouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

/* Main structure with the elements that concern all of the philos */
typedef struct s_data
{
	int				number;
	unsigned int	t_die;
	unsigned int	t_eat;
	int				t_sleep;
	int				max_meals;
	int				finished;
	struct s_philo	*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t write;
	pthread_mutex_t	death;
	pthread_t		*tid;
	long long int	start;
}	t_data;

/* Structure each philo will have of its own */
typedef struct s_philo
{
	long long int	time_after_food;
	int				times_eaten;
	int				id;
	struct s_data	*data;
	pthread_mutex_t time;
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