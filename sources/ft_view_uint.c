
#include "../includes/ft_printf.h"

static int	ft_output_uint(char *nbr_str, t_flags flags, size_t len)
{
	if (flags.dot >= 0)
		ft_view_width(flags.dot - 1, len - 1, 1);
	ft_putstr(nbr_str, len);
	return (0);
}

static int	ft_put_uint(char *nbr_str, t_flags flags)
{
	const size_t	len = ft_strlen(nbr_str);

	if (flags.minus == 1)
		ft_output_uint(nbr_str, flags, len);
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
		ft_output_uint(nbr_str, flags, len);
	return (0);
}

int			ft_view_uint(unsigned int nbr, t_flags flags)
{
	char	*nbr_str;

	nbr = (unsigned int)(4294967295 + 1 + nbr);
	if (flags.dot == 0 && nbr == 0)
	{
		ft_view_width(flags.width, 0, 0);
		return (0);
	}
	nbr_str = ft_uns_itoa(nbr);
	ft_put_uint(nbr_str, flags);
	free(nbr_str);
	return (0);
}
