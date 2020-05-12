#include "../includes/ft_printf.h"

static int	ft_output_hex(char *hex, t_flags flags, size_t len)
{
	if (flags.dot >= 0)
		ft_view_width(flags.dot - 1, len - 1, 1);
	ft_putstr(hex, len);
	return (0);
}

static int	ft_put_hex(char *hex, t_flags flags)
{
	const size_t	len = ft_strlen(hex);

	if (flags.minus == 1)
		ft_output_hex(hex, flags, len);
	if (flags.dot >= 0 && (size_t)flags.dot < len)
		flags.dot = len;
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		ft_view_width(flags.width, 0, 0);
	}
	else
		ft_view_width(flags.width,
		len, flags.zero);
	if (flags.minus == 0)
		ft_output_hex(hex, flags, len);
	return (0);
}

int			ft_view_hex(unsigned int nbr, int lower, t_flags flags)
{
	char	*hex;

	nbr = (unsigned int)(4294967295 + 1 + nbr);
	if (flags.dot == 0 && nbr == 0)
	{
		ft_view_width(flags.width, 0, 0);
		return (0);
	}
	hex = ft_nbr_base((unsigned long long)nbr, 16);
	if (lower == 1)
		hex = ft_str_tolower(hex);
	ft_put_hex(hex, flags);
	free(hex);
	return (0);
}
