/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:12:43 by mdenys            #+#    #+#             */
/*   Updated: 2021/05/24 19:42:32 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_header.h"

void	*run_trhead(t_philo *philo)
{
	while (1)
	{
		cycle(philo);
	}
	return (NULL);
}

void	take_forks(t_philo *philo)
{
	t_all	*all;

	all = philo->all_struct;
	sem_wait(all->bucket);
	sem_wait(all->data_philo->sems);
	messages(philo->all_struct, philo, "has taken a fork");
	sem_wait(all->data_philo->sems);
	messages(philo->all_struct, philo, "has taken a fork");
	sem_post(all->bucket);
}

void	eating(t_philo *philo)
{
	t_all	*all;

	all = philo->all_struct;
	sem_wait(philo->eat_sem);
	messages(philo->all_struct, philo, "is eating");
	philo->last_eat = ft_get_time() - philo->all_struct->start_time;
	philo->count_eat++;
	ft_msleep(philo->all_struct->time_to_eat);
	sem_post(philo->eat_sem);
}

void	sleeping(t_philo *philo)
{
	t_all	*all;

	all = philo->all_struct;
	messages(philo->all_struct, philo, "is sleeping");
	sem_post(all->data_philo->sems);
	sem_post(all->data_philo->sems);
	ft_msleep(philo->all_struct->time_to_sleep);
}

void	cycle(t_philo *philo)
{
	messages(philo->all_struct, philo, "is thinking");
	take_forks(philo);
	eating(philo);
	sleeping(philo);
}
