/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_to_ascii.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:31:41 by jdavis            #+#    #+#             */
/*   Updated: 2022/03/18 12:21:58 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> //remove

char	*ft_num_toa(long long int nb, char c, int choice)
{
	int		count = 0;
	char	*str;
	unsigned long long int		dup_nb;
	int		sign;

	sign = 1;
	str = NULL;
	if (c == '%')
	{
		str = ft_strdup("%");
		return (str);
	}
	//if (nb == (long long int)-9223372036854775808)
	//	return (ft_strdup("-9223372036854775808"));
	if (nb < 0)
	{
		dup_nb = nb * -1;
		sign = -1;
		++count;
	}
	else
		dup_nb = nb;
	if (nb == 0)
	{
		str = ft_strdup("0");
		return (str);
	}
	while (dup_nb > 0)
	{
		dup_nb /= choice;
		count++;
	}
	str = ft_strnew(count);
	if (nb < 0)
		dup_nb = nb * -1;
	else
		dup_nb = nb;
	while (dup_nb > 0)
	{
		str[--count] = ft_char_digit((char)(dup_nb % choice), c);
		dup_nb /= choice;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}
