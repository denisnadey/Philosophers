/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:13:03 by mdenys            #+#    #+#             */
/*   Updated: 2021/05/20 12:13:04 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_header.h"

t_all	*structalloc_and_bzero(void)
{
	t_all	*all;

	all = ft_calloc(sizeof(t_all), 1);
	all->nbr_phils = -1;
	all->time_to_die = -1;
	all->time_to_eat = -1;
	all->time_to_sleep = -1;
	all->etarate_meal = -1;
	return (all);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	count;

	count = 0;
	if (!dst && !src)
		return (0);
	while (src[count] != '\0')
	{
		++count;
	}
	i = 0;
	if (size > 0)
	{
		while (src[i] != '\0' && i < (size - 1) && src[i])
		{
			dst[i] = src[i];
			++i;
		}
		dst[i] = '\0';
	}
	return (count);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	len;

	len = 0;
	if (!dst && !src)
		return (0);
	len = ft_strlen(dst);
	i = 0;
	if (size < len)
		return (ft_strlen((char *)src) + size);
	if (size)
	{
		while (src[i] && len + 1 < size)
			dst[len++] = src[i++];
		dst[len] = '\0';
	}
	while (src[i])
	{
		i++;
		len++;
	}
	return (len);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*sem_set_name(char *str, int i)
{
	char	*temp_nbr;
	char	*returnstr;

	temp_nbr = ft_itoa(i);
	returnstr = ft_strjoin(str, temp_nbr);
	free(temp_nbr);
	return (returnstr);
}
