/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atou.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:31:36 by flmarsou          #+#    #+#             */
/*   Updated: 2024/09/10 15:34:11 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

unsigned int	ft_atou(const char *str)
{
	unsigned int	i;
	int				sign;
	unsigned int	result;

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