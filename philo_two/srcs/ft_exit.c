/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:16:23 by mdenys            #+#    #+#             */
/*   Updated: 2021/05/20 13:21:37 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_header.h"

int	ft_exit(t_all *all, int ret)
{
	int	i;

	i = 0;
	while (i < all->nbr_phils)
	{
		sem_close(all->data_philo->philors[i].eat_sem);
		sem_close(&all->data_philo->sems[i]);
		free(all->data_philo->philors[i].name);
		i++;
	}
	free(all->data_philo->philors);
	free(all->data_philo);
	free(all);
	return (ret);
}
