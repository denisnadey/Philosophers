/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 21:18:03 by mdenys            #+#    #+#             */
/*   Updated: 2021/05/18 21:18:04 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_header.h"

int	main(int argc, char **argv)
{
	if (parse_and_check_values(argv, argc) == 2)
		return (0);
	else
	{
		return (1);
	}
	return (0);
}
