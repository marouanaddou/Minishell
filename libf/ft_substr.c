/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maddou <maddou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 12:53:02 by mel-gand          #+#    #+#             */
/*   Updated: 2023/06/14 20:00:54 by maddou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	sub = malloc(len + 1);
	if (!sub || !s)
		return (NULL);
	i = 0;
	while (start < (unsigned int)ft_strlen(s) && i < len)
	{
		sub[i++] = s[start++];
	}
	sub[i] = '\0';
	return (sub);
}
