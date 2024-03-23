/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottet <ccottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 22:07:13 by ccottet           #+#    #+#             */
/*   Updated: 2023/12/29 16:48:13 by ccottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/ft_printf.h"

int	ft_printchar(char n)
{
	ft_putchar_fd(n, 1);
	return (1);
}

int	ft_inputs(va_list *args, const char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_printchar((char)va_arg(*args, int));
	if (c == 's')
		len += ft_printstr(va_arg(*args, char *));
	if (c == 'p')
		len += ft_printptr(va_arg(*args, unsigned long long));
	if (c == 'd' || c == 'i')
		len += ft_printnbr(va_arg(*args, int));
	if (c == 'u')
		len += ft_print_unsigned(va_arg(*args, unsigned int));
	if (c == 'x')
		len += ft_print_hex(va_arg(*args, unsigned int), c);
	if (c == 'X')
		len += ft_print_hex(va_arg(*args, unsigned int), c);
	return (len);
}

int	ft_printf(const char *input, ...)
{
	va_list			args;
	unsigned int	i;
	int				j;

	i = 0;
	j = 0;
	va_start(args, input);
	while (input[j])
	{
		if (input[j] == '%')
		{
			j++;
			if (ft_strchr("cspdiuxX", input[j]))
				i += ft_inputs(&args, input[j]);
			else if (input[j] == '%')
				i += ft_printchar('%');
		}
		else
			i = i + ft_printchar(input[j]);
		j++;
	}
	va_end(args);
	return (i);
}
