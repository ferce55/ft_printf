/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsarri-c <rsarri-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 12:25:07 by rsarri-c          #+#    #+#             */
/*   Updated: 2021/09/26 13:05:31 by rsarri-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *cad, ...);
int		ft_putchar_fd(char c, int fd);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(char const *s);
void	ft_putnbr_fd(int nb, int fd, int *pchar);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	ft_putunbr(unsigned int n, int *pchar);
char	*ft_itoh(unsigned long int n, int type);
void	*ft_memcpy(void *dst, const void *src, size_t n);

#endif