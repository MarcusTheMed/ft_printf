
#include "../includes/ft_printf.h"

int	ft_putstr(char *str, int len)
{
	int	i;

	i = 0;
	while (str[i] && i < len)
		ft_putchar(str[i++]);
	return (0);
}
