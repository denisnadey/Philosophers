/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old_utilc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 21:17:55 by mdenys            #+#    #+#             */
/*   Updated: 2021/05/18 21:17:56 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_header.h"

int	check_f(char ch)
{
	if (ch == '\t' || ch == '\n' || ch == ' ' || \
		ch == '\v' || ch == '\f' || ch == '\r')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int					i;
	unsigned long int	result;
	int					operator;

	i = 0;
	operator = 1;
	result = 0;
	while (check_f(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			operator *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result > 922337203685477580 && operator == -1)
			return (0);
		else if (result > 922337203685477580 && operator == 1)
			return (-1);
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * operator);
}

void	*ft_calloc(size_t num, size_t size)
{
	void			*addr;
	unsigned int	nbytes;

	nbytes = num * size;
	addr = malloc(nbytes);
	if (!size || !num || (size == 0 && num == 0))
		return ((void *)addr);
	if (!addr)
		return (NULL);
	else
	{
		memset(addr, '\0', nbytes);
	}
	return ((void *)addr);
}
