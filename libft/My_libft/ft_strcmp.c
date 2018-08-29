/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiederi <rdiederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 11:34:18 by rdiederi          #+#    #+#             */
/*   Updated: 2018/08/29 12:40:14 by rdiederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	int				index;
	unsigned int	ret;

	index = 0;
	while ((s1[index] == s2[index]) && (s1[index] != '\0') &&
			(s2[index != '\0']))
	{
		++index;
	}
	ret = (const unsigned char)s1[index] - (const unsigned char)s2[index];
	return (ret);
}
