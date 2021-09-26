/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsarri-c <rsarri-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 11:33:17 by rsarri-c          #+#    #+#             */
/*   Updated: 2021/09/26 13:01:16 by rsarri-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int nb, int fd, int *l)
{
	*l = *l + 1;
	if (nb == -2147483648)
	{
		write(fd, "-2147483648", 11);
		*l = 11;
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-', fd);
		nb = -nb;
		ft_putnbr_fd(nb, fd, l);
	}
	else
	{
		if (nb > 9)
		{
			ft_putnbr_fd(nb / 10, fd, l);
			ft_putchar(nb % 10 + '0', fd);
		}
		else
			ft_putchar(nb + '0', fd);
	}
}
