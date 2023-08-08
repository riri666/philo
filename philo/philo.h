/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchbouki <rchbouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:52:17 by rchbouki          #+#    #+#             */
/*   Updated: 2023/08/08 17:05:22 by rchbouki         ###   ########.fr       */
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
	long long		start;
	int				enough_meals;
}	t_data;

/* Structure each philo will have of its own */
typedef struct s_philo
{
	struct s_data	*data;
	int				id;
	long long		time_after_food;
	int				times_eaten;
	pthread_mutex_t time;
}	t_philo;

int			check_arguments(int size, char **s);

long int	ft_atoi(char *s);
int			ft_strlen(char *s);
int			ft_strcmp(char *s1, char *s2);

u_int64_t	get_time(void);
int			ft_usleep(useconds_t time);
void		ft_printf(t_data *data, char *msg, int id);

t_data		*ft_init_philo(int size, char **s);
void		philo_creation(t_data *philos);
void		food_utils(t_data *data, t_philo *philo);
int			philo_death(t_philo *philo);
void		main_death(t_data *data, t_philo *philo);
void		ft_finish(t_data *philos);

#endif