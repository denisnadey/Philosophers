/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:12:48 by mdenys            #+#    #+#             */
/*   Updated: 2021/05/20 16:10:56 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_header.h"

void	messages(t_all *all, t_philo *philo, char *str)
{
	time_t	timestemp;

	timestemp = ft_get_time() - all->start_time;
	sem_wait(all->write);
	printf("%ld %d %s\n", timestemp, philo->nbr_philo + 1, str);
	sem_post(all->write);
}
