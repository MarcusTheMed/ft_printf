
#include "../includes/ft_printf.h"

int	ft_view_char(char c, t_flags flags)
{
	if (flags.minus == 1)
		ft_putchar(c);
	ft_view_width(flags.width, 1, 0);
	if (flags.minus == 0)
		ft_putchar(c);
	return (0);
}
