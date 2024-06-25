/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacrespo <dacrespo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:55:52 by dacrespo          #+#    #+#             */
/*   Updated: 2024/04/20 12:47:21 by dacrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	va_start (args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%') //comprueba si hay un tipo
		{
			i++;
			count = count + printf_format(str[i], args); //comprueba el tipo
		}
		else
		{
			count = count + printf_char(str[i]); // escribe directamente
		}
		i++;
	}
	va_end (args); //cierra la lista
	if (count < 0)
		return (-1);
	return (count);
}
