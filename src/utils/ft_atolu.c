/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atolu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:04:37 by flmarsou          #+#    #+#             */
/*   Updated: 2024/09/10 15:34:03 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

unsigned long	ft_atolu(const char *str)
{
	unsigned int	i;
	int				sign;
	unsigned long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i])
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
