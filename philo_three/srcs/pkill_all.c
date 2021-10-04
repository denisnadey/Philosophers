/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pkill_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:12:48 by mdenys            #+#    #+#             */
/*   Updated: 2021/05/20 23:04:26 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_header.h"

void	pkill_all(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->nbr_phils)
		kill(all->data_philo->philors[i++].pid, SIGKILL);
}
