/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchbouki <rchbouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 14:49:15 by rchbouki          #+#    #+#             */
/*   Updated: 2023/07/08 17:04:53 by rchbouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isdigit(int size, char **s)
{
	int	i;
	int	j;

	i = 1;
	while (i < size)
	{
		j = 0;
		while (s[i][j])	
		{
			if ((s[i][j] < '0') || (s[i][j] > '9'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	ft_limits(int size, char **s)
{
	int	i;

	i = 1;
	while (i < size)
	{
		if (ft_atoi(s[i]) > 2147483647)
			return (0);
		i++;
	}
	return (1);
}

 /* - Check if entirely number
 	- Check if limits of int are respected
  	- Check i no negative numbers are taken in */
int	check_arguments(int size, char **s)
{
	int	i;

	i = 0;
	if (size < 5 || size >= 7)
		return (0);
	else
		if (!ft_isdigit(size, s) || !ft_limits(size, s))
			return (0);
	return (1);
}