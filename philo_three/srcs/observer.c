/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:12:50 by mdenys            #+#    #+#             */
/*   Updated: 2021/05/24 19:46:28 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_header.h"

int	run_observer_return(t_all *all, int i)
{
	sem_wait(all->write);
	printf("%ld %d died\n", \
	ft_get_time() - all->start_time, i + 1);
	return (1);
}

int	run_observer(t_all *all)
{
	int		i;
	time_t	time_eat;

	i = 0;
	while (1)
	{
		i = 0;
		while (i < all->nbr_phils)
		{
			sem_wait(all->data_philo->philors[i].eat_sem);
			time_eat = (ft_get_time() - \
			all->start_time) - all->data_philo->philors[i].last_eat;
			if (time_eat > all->time_to_die)
				return (run_observer_return(all, i));
			sem_post(all->data_philo->philors[i].eat_sem);
			if (all->smert == 42)
				return (ft_exit(all, 2));
			i++;
		}
	}
	return (0);
}

int	runner(t_all *all)
{
	prepare_resources(all);
	all->start_time = ft_get_time();
	run_all_phils(all);
	return (1);
}
