
#include "../includes/ft_printf.h"

int	ft_type(int c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i')
			|| (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'));
}

int	ft_flags(int c)
{
	return ((c == '-') || (c == ' ') || (c == '0') || (c == '.') || (c == '*'));
}

int	ft_view(int c, t_flags flags, va_list args)
{
	if (c == 'c')
		ft_view_char(va_arg(args, int), flags);
	else if (c == 's')
		ft_view_str(va_arg(args, char *), flags);
	else if (c == 'p')
		ft_view_ptr(va_arg(args, unsigned long long), flags);
	else if (c == 'd' || c == 'i')
		ft_view_int(va_arg(args, int), flags);
	else if (c == 'u')
		ft_view_uint((unsigned int)va_arg(args, unsigned int), flags);
	else if (c == 'x')
		ft_view_hex(va_arg(args, unsigned int), 1, flags);
	else if (c == 'X')
		ft_view_hex(va_arg(args, unsigned int), 0, flags);
	else if (c == '%')
		ft_view_percent(flags);
	return (0);
}
