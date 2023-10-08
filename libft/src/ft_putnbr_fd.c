/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:28:19 by jahernan          #+#    #+#             */
/*   Updated: 2022/09/26 18:58:08 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr(long int n, int fd)
{
	if (n / 10 > 0)
	{
		ft_putnbr(n / 10, fd);
	}
	ft_putchar_fd('0' + (n % 10), fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	long int	num;

	num = (long int) n;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num = -num;
	}
	ft_putnbr(num, fd);
}
