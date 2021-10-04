/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_simulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 21:17:47 by mdenys            #+#    #+#             */
/*   Updated: 2021/05/24 19:27:48 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_header.h"

void	get_fork_for_philo(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->nbr_phls)
	{
		if (i == 0)
		{
			all->data->philors[i].less_fork = 0;
			all->data->philors[i].more_fork = all->nbr_phls - 1;
		}
		else
		{
			all->data->philors[i].less_fork = i - 1;
			all->data->philors[i].more_fork = i;
		}
		all->data->philors[i].nbr_philo = i;
		all->data->philors[i].can_run_simulation = 0;
		all->data->philors[i].all_struct = all;
		all->data->philors[i].eat_etarate = 0;
		all->data->philors[i].worked = 0;
		i++;
	}
}

int	prepare_resources(t_all *all)
{
	int	i;

	i = 0;
	all->data = ft_calloc(sizeof(t_philo_data), 1);
	all->data->mutex = (pthread_mutex_t *) \
	ft_calloc(all->nbr_phls + 1, sizeof(pthread_mutex_t));
	while (i < all->nbr_phls)
	{
		pthread_mutex_init(&all->data->mutex[i], NULL);
		i++;
	}
	all->data->philors = (t_philo *) \
	ft_calloc(all->nbr_phls + 1, sizeof(t_philo));
	get_fork_for_philo(all);
	return (0);
}

void	run_all_phils(t_all *all)
{
	int		i;
	void	*philo;

	i = 0;
	while (i < all->nbr_phls)
	{
		philo = (void *)(&all->data->philors[i]);
		if (pthread_create(&all->data->philors[i].thread, \
			 NULL, (void *)run_trhead, philo) == -1)
			printf("I can't create a thread t%d\n", i);
		else
			pthread_detach(all->data->philors[i].thread);
		i++;
	}
}
