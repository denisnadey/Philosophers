/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:12:56 by mdenys            #+#    #+#             */
/*   Updated: 2021/05/20 14:11:43 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_header.h"

int	check_param(t_all *all, int optional)
{
	if (optional)
	{
		if (all->nbr_phils <= 0)
			return (1);
		if (all->time_to_die <= 0)
			return (1);
		if (all->time_to_eat <= 0)
			return (1);
		if (all->time_to_sleep <= 0)
			return (1);
		if (all->etarate_meal <= 0)
			return (1);
	}
	else
	{
		if (all->nbr_phils <= 0)
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

int	parse_param(t_all *all, int optional, char **argv)
{
	all->smert = 0;
	if (optional)
	{
		all->nbr_phils = ft_atoi(argv[1]);
		all->time_to_die = ft_atoi(argv[2]);
		all->time_to_eat = ft_atoi(argv[3]);
		all->time_to_sleep = ft_atoi(argv[4]);
		all->etarate_meal = ft_atoi(argv[5]);
		all->opt = 1;
		return (check_param(all, 1));
	}
	else
	{
		all->nbr_phils = ft_atoi(argv[1]);
		all->time_to_die = ft_atoi(argv[2]);
		all->time_to_eat = ft_atoi(argv[3]);
		all->time_to_sleep = ft_atoi(argv[4]);
		all->etarate_meal = -1;
		all->opt = 0;
		return (check_param(all, 0));
	}
}

static void	parse_and_check_part2(int quantity, int *bool)
{
	if (quantity == 5)
		*bool = 0;
	if (quantity == 6)
		*bool = 1;
}

int	parse_and_check_values(char **argv, int quantity)
{
	t_all	*all;
	int		bool;

	parse_and_check_part2(quantity, &bool);
	all = structalloc_and_bzero();
	if (quantity == 5 || quantity == 6)
	{
		if (!parse_param(all, bool, argv))
		{
			if (runner(all) == 2)
				return (2);
			return (1);
		}
		else
		{
			printf("bad arg\n");
			return (0);
		}
	}
	else
	{
		printf("error please use argument 5 (optional) or 4 (standart)\n");
		free(all);
		return (0);
	}
}
