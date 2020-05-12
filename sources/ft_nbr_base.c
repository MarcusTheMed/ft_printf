
#include "../includes/ft_printf.h"

static char	*view_base(unsigned long long nbr_tmp, int base, char *str, int count)
{
	while (nbr_tmp != 0)
	{
		if ((nbr_tmp % base) < 10)
			str[count - 1] = (nbr_tmp % base) + 48;
		else
			str[count - 1] = (nbr_tmp % base) + 55;
		nbr_tmp /= base;
		count--;
	}
	return (str);
}

char		*ft_nbr_base(unsigned long long nbr, int base)
{
	char				*str;
	unsigned long long	nbr_tmp;
	int					count;

	count = 0;
	nbr_tmp = nbr;
	if (nbr == 0)
		return (ft_strdup("0"));
	while (nbr != 0)
	{
		nbr /= base;
		count++;
	}
	if (!(str = malloc(sizeof(char) * (count + 1))))
		return (0);
	str[count] = '\0';
	str = view_base(nbr_tmp, base, str, count);
	return (str);
}
