#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char c = 'F';
	char *str = "Test";
	int nb = 1234;
	int unsigned_nb = 123;
	char *addr;

	addr = (char *)malloc(sizeof(char) * 10);
	ft_printf("coucou %c %s %d %% %x %X %u\n", c, str, nb, nb, nb, unsigned_nb);
	printf("coucou %c %s %d %% %x %X %u\n", c, str, nb, nb, nb, unsigned_nb);
	ft_printf("ma fonction : %p\n", addr);
	printf("adresse : %p\n", addr);
	free(addr);
}