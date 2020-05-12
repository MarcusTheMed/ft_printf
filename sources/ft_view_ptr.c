
#include "../includes/ft_printf.h"

static int	ft_output_ptr(char *ptr, t_flags flags, size_t len)
{
	if (ft_strncmp(ptr, "(nil)", 5) != 0)
		ft_putstr("0x", 2);
	if (flags.dot >= 0)
	{
		ft_view_width(flags.dot, len, 1);
		ft_putstr(ptr, flags.dot);
	}
	else
		ft_putstr(ptr, len);
	return (0);
}

int			ft_view_ptr(unsigned long long nbr, t_flags flags)
{
	size_t	len;
	char	*ptr;

	if (!nbr)
		ptr = ft_substr("(nil)", 0, 5);
	else
	{
		ptr = ft_nbr_base(nbr, 16);
		ptr = ft_str_tolower(ptr);
	}
	len = ft_strlen(ptr);
	if ((size_t)flags.dot < len)
		flags.dot = len;
	if (flags.minus == 1)
		ft_output_ptr(ptr, flags, len);
	if (nbr)
		ft_view_width(flags.width, len + 2, 0);
	else
		ft_view_width(flags.width, len, 0);
	if (flags.minus == 0)
		ft_output_ptr(ptr, flags, len);
	free(ptr);
	return (0);
}
