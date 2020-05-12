#include "../includes/ft_printf.h"

static size_t	ft_nbrlen(long nbr, int base)
{
	size_t	len;

	len = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		len++;
	while (nbr)
	{
		nbr /= base;
		len++;
	}
	return (len);
}

char			*ft_uns_itoa(unsigned int n)
{
	size_t	i;
	size_t	size;
	char	*str;
	long	nbr;

	i = 0;
	nbr = n;
	if (nbr == -2147483648)
		return (ft_strdup("-2147483648"));
	size = ft_nbrlen(nbr, 10);
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	str[size] = 0;
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
		i++;
	}
	while (i < size--)
	{
		str[size] = (nbr % 10) + 48;
		nbr /= 10;
	}
	return (str);
}
