/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchbouki <rchbouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 14:49:13 by rchbouki          #+#    #+#             */
/*   Updated: 2023/08/14 17:56:17 by rchbouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

long int	ft_atoi(char *s)
{
	int			i;
	long int	res;

	i = 0;
	res = 0;
	while (s[i] == '0')
		i++;
	if (ft_strlen(s + i) > 11)
		return (-1);
	while ((s[i] >= '0') && (s[i] <= '9'))
		res = res * 10 + s[i++] - '0';
	return (res);
}

/* My version of the time functions because they are more precise */
u_int64_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (u_int64_t)1000) + (tv.tv_usec / 1000));
}

int	ft_usleep(useconds_t time)
{
	u_int64_t	start;

	start = get_time();
	while ((get_time() - start) < time)
		usleep(time / 10);
	return (0);
}
