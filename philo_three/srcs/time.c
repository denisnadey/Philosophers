/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:13:01 by mdenys            #+#    #+#             */
/*   Updated: 2021/05/20 12:13:01 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_header.h"

time_t	ft_get_time(void)
{
	time_t			return_value;
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return_value = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (return_value);
}

void	ft_msleep(time_t interval_ms)
{
	time_t	end_ms;
	time_t	now_ms;

	end_ms = ft_get_time() + interval_ms;
	now_ms = ft_get_time();
	while (now_ms < end_ms)
	{
		usleep(_SLEEP_STEP);
		now_ms = ft_get_time();
	}
}

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((long)(time.tv_sec * 1000 + time.tv_usec / 1000));
}

void	my_usleep(long time)
{
	long	t;

	t = get_time();
	while (get_time() - t < time)
		usleep(1);
}
