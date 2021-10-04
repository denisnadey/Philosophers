/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 21:18:00 by mdenys            #+#    #+#             */
/*   Updated: 2021/05/18 21:32:45 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_header.h"

void	messages(t_all *all, t_philo *philo, char *str)
{
	time_t	timestemp;

	timestemp = ft_get_time() - all->start_time;
	if (philo->all_struct->smert != 42)
	{
		pthread_mutex_lock(&all->write);
		printf("%ld %d %s\n", timestemp, philo->nbr_philo + 1, str);
		pthread_mutex_unlock(&all->write);
	}
}
