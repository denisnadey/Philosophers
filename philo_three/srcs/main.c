/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:12:46 by mdenys            #+#    #+#             */
/*   Updated: 2021/05/20 13:26:16 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_header.h"

int	main(int argc, char **argv)
{
	if (parse_and_check_values(argv, argc) == 2)
		return (0);
	else
		return (1);
	return (0);
}
