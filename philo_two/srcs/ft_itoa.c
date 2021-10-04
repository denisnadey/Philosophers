/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:12:37 by mdenys            #+#    #+#             */
/*   Updated: 2021/05/20 12:12:38 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_header.h"

static int	nbleng(unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i + 1);
}

int	ft_itoa_tern(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

int	ft_itoa_tern2(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

char	*ft_itoa(int n)
{
	char			*dst;
	unsigned int	leng;
	unsigned int	nbr;
	unsigned int	i;

	nbr = ft_itoa_tern(n);
	leng = nbleng(nbr);
	i = 0;
	dst = (char *)malloc(sizeof(char) * leng + 1 + ft_itoa_tern2(n));
	if (n < 0)
	{
		dst[i] = '-';
		leng++;
	}
	i = leng - 1;
	while (nbr >= 10)
	{
		dst[i] = nbr % 10 + '0';
		nbr /= 10;
		i--;
	}
	dst[i] = nbr % 10 + '0';
	dst[leng] = '\0';
	return (dst);
}
