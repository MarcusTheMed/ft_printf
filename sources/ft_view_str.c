
#include "../includes/ft_printf.h"

static int	ft_output_str(char *str, t_flags flags, size_t len)
{
	if (flags.dot >= 0)
	{
		ft_view_width(flags.dot, len, 0);
		ft_putstr(str, flags.dot);
	}
	else
		ft_putstr(str, len);
	return (0);
}

int			ft_view_str(char *str, t_flags flags)
{
	size_t	len;
	char	*str_1;

	if (!str)
	{
		len = 6;
		str_1 = ft_substr("(null)", 0, len);
	}
	else
	{
		len = ft_strlen(str);
		str_1 = ft_substr(str, 0 , len);
	}
	if (flags.dot >= 0 && (size_t)flags.dot > len)
		flags.dot = len;
	if (flags.minus == 1)
		ft_output_str(str_1, flags, len);
	if (flags.dot >= 0)
		ft_view_width(flags.width, flags.dot, 0);
	else
		ft_view_width(flags.width, len, 0);
	if (flags.minus == 0)
		ft_output_str(str_1, flags, len);
	free(str_1);
	return (0);
}
