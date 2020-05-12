#include "../includes/ft_printf.h"

static int	ft_output_int(char *nbr_str, int nbr_tmp, t_flags flags, size_t len)
{
	if (nbr_tmp < 0 && flags.dot >= 0)
		ft_putchar('-');
	if (flags.dot >= 0)
		ft_view_width(flags.dot - 1, len - 1, 1);
	ft_putstr(nbr_str, len);
	return (0);
}

static int	ft_put_int(char *nbr_str, int nbr_tmp, t_flags flags)
{
	const size_t	len = ft_strlen(nbr_str);

	if (flags.minus == 1)
		ft_output_int(nbr_str, nbr_tmp, flags, len);
	if (flags.dot >= 0 && (size_t)flags.dot < len)
		flags.dot = len;
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		ft_view_width(flags.width, 0, 0);
	}
	else
		ft_view_width(flags.width, len, flags.zero);
	if (flags.minus == 0)
		ft_output_int(nbr_str, nbr_tmp, flags, len);
	return (0);
}

int			ft_view_int(int nbr, t_flags flags)
{
	char	*nbr_str;
	int		nbr_tmp;

	nbr_tmp = nbr;
	if (flags.dot == 0 && nbr == 0)
	{
		ft_view_width(flags.width, 0, 0);
		return (0);
	}
	if (nbr < 0 && (flags.dot >= 0 || flags.zero == 1))
	{
		if (flags.zero == 1 && flags.dot == -1)
			ft_putstr("-", 1);
		nbr *= -1;
		flags.zero = 1;
		flags.width--;
	}
	nbr_str = ft_itoa(nbr);
	ft_put_int(nbr_str, nbr_tmp, flags);
	free(nbr_str);
	return (0);
}
