/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sttjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 16:48:57 by rdiederi          #+#    #+#             */
/*   Updated: 2018/06/05 21:26:17 by rdiederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;
	int		len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (s1 && s2)
	{
		if (!(tmp = (char *)malloc(sizeof(char) * (len))))
		{
			return (NULL);
		}
		ft_strcpy(tmp, (char *)s1);
		tmp = ft_strcat(tmp, s2);
		return (tmp);
	}
	return (NULL);
}
