/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhati <aalkhati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 19:19:55 by aalkhati          #+#    #+#             */
/*   Updated: 2025/11/01 19:44:22 by aalkhati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int	len;

	len = 1;
	if (n < 0)
		len++;
	while (n / 10)
	{
		len++;
		n /= 10;
	}
	return (len);
}

// static void	ft_putnbr(int nb)
//{
//	char	c;

//	if (nb == -2147483648)
//	{
//		write(1, "-2147483648", 11);
//		return ;
//	}
//	if (nb < 0)
//	{
//		write(1, "-", 1);
//		nb = -nb;
//	}
//	if (nb >= 10)
//	{
//		ft_putnbr(nb / 10);
//		c = (nb % 10) + '0';
//		write(1, &c, 1);
//	}
//}

char	*ft_itoa(int n)
{
	char	*str;
	long	nb;
	int		len;

	nb = (long)n;
	len = ft_intlen(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		str[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}

// int	main(void)
//{
//	char	*str;

//	str = ft_itoa(0);
//	printf("ft_itoa(0) = %s\n", str);
//	free(str);

//	str = ft_itoa(42);
//	printf("ft_itoa(42) = %s\n", str);
//	free(str);

//	str = ft_itoa(-42);
//	printf("ft_itoa(-42) = %s\n", str);
//	free(str);

//	return (0);
//}
