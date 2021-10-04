/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilc2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 17:34:52 by mdenys            #+#    #+#             */
/*   Updated: 2021/05/24 19:43:44 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_header.h"

sem_t	*reopen_sem(const char *name, int value)
{
	sem_unlink(name);
	return (sem_open(name, O_RDWR | O_CREAT, S_IRWXU, value));
}

int	check_eat(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->nbr_phils)
	{
		if (all->data_philo->philors[i].each_eat)
			i++;
	}
	return (1);
}
