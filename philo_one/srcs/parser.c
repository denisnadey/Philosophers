/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 21:17:51 by mdenys            #+#    #+#             */
/*   Updated: 2021/05/18 21:17:52 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_header.h"

int	check_param(t_all *all, int optional)
{
	if (optional)
	{
		if (all->nbr_phls <= 0)
			return (1);
		if (all->time_to_die <= 0)
			return (1);
		if (all->time_to_eat <= 0)
			return (1);
		if (all->time_to_sleep <= 0)
			return (1);
		if (all->iteration_eat <= 0)
			return (1);
	}
	else
	{
		if (all->nbr_phls <= 0)
			return (1);
		if (all->time_to_die <= 0)
			return (1);
		if (all->time_to_eat <= 0)
			return (1);
		if (all->time_to_sleep <= 0)
			return (1);
	}
	return (0);
}
