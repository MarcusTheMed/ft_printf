/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_view_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csnowbal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 19:06:03 by csnowbal          #+#    #+#             */
/*   Updated: 2020/07/13 22:35:31 by csnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_output_int(char *nbr_str, int nbr_tmp, t_flags flags, size_t len)
{
	int		count;

	count = 0;
	if (nbr_tmp < 0 && flags.dot >= 0)
		ft_putchar('-');
	if (flags.dot >= 0)
		count += ft_output_width(flags.dot - 1, len - 1, 1);
	count += ft_putstr(nbr_str, len);
	return (count);
}

static int	ft_put_int(char *nbr_str, int nbr_tmp, t_flags flags)
{
	const size_t	len = ft_strlen(nbr_str);
	int				count;

	count = 0;
	if (flags.minus == 1)
		count += ft_output_int(nbr_str, nbr_tmp, flags, len);
	if (flags.dot >= 0 && (size_t)flags.dot < len)
		flags.dot = len;
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		count += ft_output_width(flags.width, 0, 0);
	}
	else
		count += ft_output_width(flags.width, len, flags.zero);
	if (flags.minus == 0)
		count += ft_output_int(nbr_str, nbr_tmp, flags, len);
	return (count);
}

static void	check_zero(t_flags *flags)
{
	if (flags->zero == 1 && flags->dot == -1)
		ft_putchar('-');
	flags->zero = 1;
	flags->width--;
}

int			ft_view_int(int nbr, t_flags flags)
{
	char	*nbr_str;
	int		nbr_tmp;
	int		count;
	long	nbr_long;

	count = 0;
	nbr_tmp = nbr;
	nbr_long = 0;
	if (flags.dot == 0 && nbr == 0)
		return ((count += ft_output_width(flags.width, 0, 0)));
	if (nbr < 0 && (flags.dot >= 0 || flags.zero == 1))
	{
		check_zero(&flags);
		nbr *= -1;
		nbr == -2147483648 ? nbr_long = 2147483648 : nbr;
		count++;
	}
	if (nbr_long)
		nbr_str = ft_uns_itoa_base(nbr_long, 10);
	else
		nbr_str = ft_itoa(nbr);
	count += ft_put_int(nbr_str, nbr_tmp, flags);
	free(nbr_str);
	return (count);
}
