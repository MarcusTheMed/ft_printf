#include "includes/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char a1 = 'a';			//c
	char *a2 = "kekw";		//s
	void *a3 = a2;			//p
	char a4 = 5;			//d
	int a5 = 5;				//i
	unsigned int a6 = 123;	//u
	unsigned int a7 = 11;	//x
	unsigned int a8 = 11;	//X
							//%
	printf("st c = a: %c\n", a1);
	ft_printf("my c = a: %c\n\n", a1);

	printf("st s = kekw: %s\n", a2);
	ft_printf("my s = kekw: %s\n\n", a2);

	printf("st p = a2: %p\n", a3);
	ft_printf("my p = a2: %p\n\n", a3);

	printf("st d = 5: %d\n", a4);
	ft_printf("my d = 5: %d\n\n", a4);
	printf("st d = 5: %*d\n", a4);
	ft_printf("my d = 5: %*d\n\n", a4);
	printf("st d = 5: %.d\n", a4);
	ft_printf("my d = 5: %.d\n\n", a4);
	printf("st d = 5: %0d\n", a4);
	ft_printf("my d = 5: %0d\n\n", a4);
	printf("st d = 5: %-d\n", a4);
	ft_printf("my d = 5: %-d\n\n", a4);

	printf("st i = 5: %i\n", a5);
	ft_printf("my i = 5: %i\n\n", a5);

	printf("st u = 123: %u\n", a6);
	ft_printf("my u = 123: %u\n\n", a6);

	printf("st x = 11: %x\n", a7);
	ft_printf("my x = 11: %x\n\n", a7);

	printf("st X = 11: %X\n", a8);
	ft_printf("my X = 11: %X\n\n", a8);

	printf("st: %% %% %%\n");
	ft_printf("my: %% %% %%\n\n");
	return (0);
}
