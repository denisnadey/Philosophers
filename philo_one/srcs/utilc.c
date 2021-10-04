/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 21:17:31 by mdenys            #+#    #+#             */
/*   Updated: 2021/05/24 19:15:30 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_header.h"

t_all	*structalloc_and_bzero(void)
{
	t_all	*all;

	all = ft_calloc(sizeof(t_all), 1);
	all->nbr_phls = -1;
	all->time_to_die = -1;
	all->time_to_eat = -1;
	all->time_to_sleep = -1;
	all->iteration_eat = -1;
	return (all);
}

int	ft_exit(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->nbr_phls)
	{
		pthread_mutex_destroy(&all->data->philors[i].eat_mutex);
		pthread_mutex_destroy(&all->data->mutex[i]);
		i++;
	}
	free(all->data->philors);
	free(all->data);
	free(all);
	return (1);
}

int	check_eat(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->nbr_phls)
	{
		if (all->data->philors[i].eat_etarate)
			i++;
	}
	return (1);
}
