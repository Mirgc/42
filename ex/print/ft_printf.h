/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 15:21:29 by migarcia          #+#    #+#             */
/*   Updated: 2021/09/16 13:59:15 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
int	ft_putchar(char c);
int	ft_putstr(char *str_arg);
int	ft_len(long long num, int base);
int	ft_putnbr(long num);
int	ft_puthex(unsigned long long num, int c_count);
int	check_flag(char s, va_list arg);
int	ft_printf(const char *orig, ...);
#endif
