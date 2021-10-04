/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obs_for_phil.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:12:48 by mdenys            #+#    #+#             */
/*   Updated: 2021/05/24 19:46:59 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_header.h"

void	*obs_phil(t_philo *philo)
{
	time_t	time_eat;

	while (1)
	{
		sem_wait(philo->eat_sem);
		time_eat = (ft_get_time() - \
		philo->all_struct->start_time) - philo->last_eat;
		if (time_eat > philo->all_struct->time_to_die)
		{
			run_observer_return(philo->all_struct, philo->nbr_philo);
			break ;
		}
		else if (philo->all_struct->opt)
		{
			if (philo->count_eat == philo->all_struct->etarate_meal)
			{
				sem_post(philo->all_struct->bullets);
			}
		}
		sem_post(philo->eat_sem);
	}
	sem_post(philo->all_struct->bullet);
	return (NULL);
}
