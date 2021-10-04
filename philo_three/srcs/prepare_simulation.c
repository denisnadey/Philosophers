/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_simulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:12:58 by mdenys            #+#    #+#             */
/*   Updated: 2021/05/24 19:42:04 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_header.h"

void	get_data_f_philo(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->nbr_phils)
	{
		all->data_philo->philors[i].died = 0;
		all->data_philo->philors[i].nbr_philo = i;
		all->data_philo->philors[i].worked = 0;
		all->data_philo->philors[i].can_run_simulation = 0;
		all->data_philo->philors[i].all_struct = all;
		all->data_philo->philors[i].is_eat = 0;
		all->data_philo->philors[i].name = sem_set_name("philo", i);
		all->data_philo->philors[i].each_eat = 0;
		all->data_philo->philors[i].eat_sem = \
		reopen_sem(all->data_philo->philors[i].name, 1);
		sem_wait(all->bullets);
		i++;
	}
}

int	prepare_resources(t_all *all)
{
	int	i;

	i = 0;
	all->data_philo = ft_calloc(sizeof(t_philo_data), 1);
	all->data_philo->sems = reopen_sem(_SEM_NAME_FORKS, all->nbr_phils);
	all->write = reopen_sem(_SEM_WRITE_LOCK, 1);
	all->bucket = reopen_sem("bucket", 1);
	all->bullet = reopen_sem("bullet", 1);
	all->bullets = reopen_sem("bullets", all->nbr_phils);
	sem_wait(all->bullet);
	all->data_philo->philors = (t_philo *)ft_calloc(all->nbr_phils \
		+ 1, sizeof(t_philo));
	get_data_f_philo(all);
	return (0);
}

int	checker(t_all *all)
{
	int	i;

	i = 0;
	if (all->opt)
	{
		while (i < all->nbr_phils)
		{
			sem_wait(all->bullets);
			i++;
		}
		pkill_all(all);
		return (3);
	}
	else
	{
		sem_wait(all->bullet);
		pkill_all(all);
	}
	return (0);
}

void	*run_all_phils(t_all *all)
{
	void	*philo;
	int		i;

	i = 0;
	while (i < all->nbr_phils)
	{
		all->data_philo->philors[i].pid = fork();
		if (all->data_philo->philors[i].pid == 0)
		{
			philo = (void *)(&all->data_philo->philors[i]);
			if (pthread_create(&all->data_philo->philors[i].thread, NULL, \
				(void *)obs_phil, philo) == -1)
				printf("I can't create a thread t%d\n", i);
			else
				pthread_detach(all->data_philo->philors[i].thread);
			run_trhead(philo);
		}
		else
			i++;
	}
	if (checker(all))
		return (0);
	return (0);
}
