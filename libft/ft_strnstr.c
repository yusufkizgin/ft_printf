/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykizgin <ykizgin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:46:53 by ykizgin           #+#    #+#             */
/*   Updated: 2024/10/28 11:36:24 by ykizgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *string, const char *substring, size_t len)
{
	size_t	i;

	if (*substring == 0)
		return ((char *)string);
	i = ft_strlen((char *)substring);
	if (len == 0)
		return (0);
	while (*string && i <= len)
	{
		if (*string == *substring && ft_strncmp(string, substring, i) == 0)
			return ((char *)string);
		++string;
		--len;
	}
	return (0);
}
