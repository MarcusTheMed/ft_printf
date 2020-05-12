
#include "../includes/ft_printf.h"

int	ft_view_width(int width, int minus, int zero)
{
	while (width - minus > 0)
	{
		if (zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		width -= 1;
	}
	return (0);
}
