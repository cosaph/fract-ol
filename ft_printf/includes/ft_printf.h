/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottet <ccottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 22:09:30 by ccottet           #+#    #+#             */
/*   Updated: 2023/12/29 16:50:09 by ccottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

int		ft_printf(const char *format, ...);
int		ft_formats(va_list args, const char format);
int		ft_printchar(char c);
int		ft_inputs(va_list *args, const char c);
size_t	ft_printstr(char *str);
int		ft_printnbr(int n);
int		ft_ptr_len(uintptr_t num);
void	ft_putptr(uintptr_t num);
int		ft_printptr(unsigned long long ptr);
int		ft_printpercent(void);
int		ft_hexa_len(int nb);
void	ft_puthexa(int num, char lwrupr);
int		ft_print_hex(unsigned int num, const char format);
int		ft_unsigned_len(unsigned int nb);
char	*ft_unsigned_itoa(unsigned int n);
int		ft_print_unsigned(unsigned int n);
#endif