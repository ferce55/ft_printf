/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsarri-c <rsarri-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 12:25:07 by rsarri-c          #+#    #+#             */
/*   Updated: 2021/09/16 13:03:03 by rsarri-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include <unistd.h>

int		ft_printf(const char *cad, ...);
int		ft_putchar_fd(char c, int fd);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(char const *s);
void	ft_putnbr_fd(int n, int fd, int *pchar);

#endif