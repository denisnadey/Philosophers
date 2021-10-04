/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 21:18:08 by mdenys            #+#    #+#             */
/*   Updated: 2021/05/24 19:26:42 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_header.h"

void	*run_trhead(t_philo *philo)
{
	while (1)
	{
		cycle(philo);
		if (philo->count_eat == philo->all_struct->iteration_eat)
			philo->eat_etarate = 1;
	}
	return (NULL);
}

int	run_observer42(t_all *all, int i)
{
	time_t	time_eat;

	pthread_mutex_lock(&all->data->philors[i].eat_mutex);
	time_eat = (ft_get_time() - all->start_time) \
	- all->data->philors[i].last_eat;
	if (time_eat > all->time_to_die)
	{
		pthread_mutex_lock(&all->write);
		all->smert = 42;
		printf("%ld %d died\n", \
		ft_get_time() - all->start_time, i + 1);
		return (2);
	}
	pthread_mutex_unlock(&all->data->philors[i].eat_mutex);
	return (0);
}

int	run_observer(t_all *all)
{
	int	i;

	i = 0;
	while (1)
	{
		i = 0;
		while (i < all->nbr_phls)
		{
			if (all->smert != 42)
			{
				if ((run_observer42(all, i) == 2))
					return (2);
				if (all->opt)
				{
					if (check_eat(all))
						return (0);
				}
			}
			else
				return (ft_exit(all));
			i++;
		}
		ft_msleep(5);
	}
	return (0);
}

int	runner(t_all *all)
{
	prepare_resources(all);
	all->start_time = ft_get_time();
	run_all_phils(all);
	if (!run_observer(all))
		return (0);
	return (1);
}
