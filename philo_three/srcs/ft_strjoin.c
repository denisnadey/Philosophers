/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:12:40 by mdenys            #+#    #+#             */
/*   Updated: 2021/05/20 12:12:41 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_header.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	char	*new;

	if (s1 && s2)
	{
		len1 = ft_strlen((char *)s1);
		len2 = ft_strlen((char *)s2);
		new = malloc(sizeof(char *) * len1 + len2 + 1);
		if (new)
		{
			ft_strlcpy(new, s1, len1 + 1);
			ft_strlcat(new, s2, len1 + len2 + 1);
			return ((void *)(new));
		}
	}
	return (0);
}
