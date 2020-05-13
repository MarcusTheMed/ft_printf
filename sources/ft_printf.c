/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csnowbal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 19:06:24 by csnowbal          #+#    #+#             */
/*   Updated: 2020/05/13 14:10:07 by csnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** "0" Значение добавляет нули. При преобразованиях типа: d, i, o, u, x, X -
** преобразуемое значение слева дополняется нулями (вместо пробелов).
** Если присутствуют флаги 0, и -, то флаг 0 игнорируется. Если преобразование
** указано точно (d, i, o, u, x и X), то флаг 0 игнорируется.
**
** "-" Выравнивает результат преобразования по левой границе поля.
**(По умолчанию выравнивание выполняется справа.) Отменяет флаг 0.
**
** "*" Модификатор ширины.
** Указывает минимальную ширину поля(включая знак для чисел).Если представление
** величины больше, чем ширина поля, то запись выходит за пределы поля.
**
** "." Модификатор точности. Указывает на минимальное количество символов,
** которое должно появиться при обработке типов d, i, o, u, x, X;
** Максимальное число символов, которые будут выведены для типа s.
*/

t_flags			ft_init_flags(void)
{
	t_flags		flags;

	flags.dot = -1;
	flags.minus = 0;
	flags.star = 0;
	flags.type = 0;
	flags.width = 0;
	flags.zero = 0;
	return (flags);
}

int				ft_flag_scan(const char *input, int i, t_flags *flags,
								va_list av)
{
	while (input[i])
	{
		if (!ft_isdigit(input[i]) && !ft_type(input[i]) && !ft_flags(input[i]))
			break ;
		if (input[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (input[i] == '.')
			i = ft_flag_dot(input, i, flags, av);
		if (input[i] == '-')
			*flags = ft_flag_minus(*flags);
		if (input[i] == '*')
			*flags = ft_flag_width(av, *flags);
		if (ft_isdigit(input[i]))
			*flags = ft_flag_digit(input[i], *flags);
		if (ft_type(input[i]))
		{
			flags->type = input[i];
			break ;
		}
		i++;
	}
	return (i);
}

/*
** Check each element of the 'input'. Check % -> check flags -> check type ->
** -> go to the spreader. If just symbol print it.
*/

int				ft_view_input(const char *input, va_list av)
{
	int			i;
	t_flags		flags;
	int			count;

	count = 0;
	i = 0;
	while (input[i])
	{
		flags = ft_init_flags();
		if (input[i] == '%' && input[i + 1] == '\0')
			return (-1);
		if (input[i] == '%' && input[i + 1])
		{
			i++;
			i = ft_flag_scan(input, i, &flags, av);
			if (ft_type(input[i]))
				count += ft_spreader((char)flags.type, flags, av);
			else if (input[i])
			{
				count += ft_putchar(input[i]);
				return (-1);
			}
		}
		else if (input[i] != '%')
			count += ft_putchar(input[i]);
		i++;
	}
	return (count);
}

int				ft_printf(const char *input_str, ...)
{
	const char	*input;
	va_list		av;
	int			count;

	count = 0;
	input = ft_strdup(input_str);
	va_start(av, input_str);
	count += ft_view_input(input, av);
	va_end(av);
	free((char *)input);
	return (count);
}
