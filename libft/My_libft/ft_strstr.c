/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 11:37:58 by rdiederi          #+#    #+#             */
/*   Updated: 2018/06/15 11:38:01 by rdiederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t len_n;

	if (!*needle)
		return ((char*)haystack);
	len_n = ft_strlen(needle);
	while (*haystack && ft_strncmp(haystack, needle, len_n))
		haystack++;
	if (*haystack)
		return ((char*)haystack);
	return (NULL);
}
