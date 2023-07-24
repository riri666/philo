/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchbouki <rchbouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 14:49:13 by rchbouki          #+#    #+#             */
/*   Updated: 2023/07/24 12:45:30 by rchbouki         ###   ########.fr       */
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
	while ((s[i] >= '0') && (s[i] <= '9'))
		res = res * 10 + s[i++] - '0';
	return (res);
}
