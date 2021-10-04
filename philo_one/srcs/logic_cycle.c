/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_cycle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 21:18:12 by mdenys            #+#    #+#             */
/*   Updated: 2021/05/24 19:27:35 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_header.h"

void	take_forks(t_philo *philo)
{
	t_all	*all;

	all = philo->all_struct;
	if (philo->nbr_philo % 2 == 0)
	{
		pthread_mutex_lock(&all->data->mutex[philo->less_fork]);
		messages(philo->all_struct, philo, "has taken a fork");
		pthread_mutex_lock(&all->data->mutex[philo->more_fork]);
		messages(philo->all_struct, philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&all->data->mutex[philo->more_fork]);
		messages(philo->all_struct, philo, "has taken a fork");
		pthread_mutex_lock(&all->data->mutex[philo->less_fork]);
		messages(philo->all_struct, philo, "has taken a fork");
	}
}

void	eating(t_philo *philo)
{
	t_all	*all;

	all = philo->all_struct;
	pthread_mutex_lock(&philo->eat_mutex);
	messages(philo->all_struct, philo, "is eating");
	philo->last_eat = ft_get_time() - philo->all_struct->start_time;
	ft_msleep(philo->all_struct->time_to_eat);
	if (philo->nbr_philo % 2 == 0)
	{
		pthread_mutex_unlock(&all->data->mutex[philo->more_fork]);
		pthread_mutex_unlock(&all->data->mutex[philo->less_fork]);
	}
	else
	{
		pthread_mutex_unlock(&all->data->mutex[philo->less_fork]);
		pthread_mutex_unlock(&all->data->mutex[philo->more_fork]);
	}
	philo->count_eat++;
	pthread_mutex_unlock(&philo->eat_mutex);
}

void	sleeping(t_philo *philo)
{
	t_all	*all;

	all = philo->all_struct;
	messages(philo->all_struct, philo, "is sleeping");
	ft_msleep(philo->all_struct->time_to_sleep);
}

void	cycle(t_philo *philo)
{
	messages(philo->all_struct, philo, "is thinking");
	take_forks(philo);
	eating(philo);
	sleeping(philo);
}
