/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykizgin <ykizgin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 22:38:15 by ykizgin           #+#    #+#             */
/*   Updated: 2024/10/28 11:28:25 by ykizgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

unsigned int	ft_nbrlen(long *n)
{
	int		i;
	long	num;

	num = *n;
	i = 0;
	if (num <= 0)
	{
		i = 1;
		*n = -*n;
	}
	while (num)
	{
		i++;
		num /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	copy;

	copy = n;
	len = ft_nbrlen(&copy);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (n < 0)
		n = -1;
	while (len >= 0)
	{
		str[len] = (copy % 10) + '0';
		copy /= 10;
		len--;
	}
	if (n == -1)
		str[0] = '-';
	return (str);
}
