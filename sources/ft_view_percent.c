#include "../includes/ft_printf.h"

int	ft_view_percent(t_flags flags)
{
	if (flags.minus == 1)
		ft_putstr("%", 1);
	ft_view_width(flags.width, 1, flags.zero);
	if (flags.minus == 0)
		ft_putstr("%", 1);
	return (0);
}
