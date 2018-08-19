#include <stdlib.h>

char	*ft_concat_params(int argc, char **argv)
{
	int		total_size;
	int 	i;
	int 	cursor;
	char	*tab;
	
	total_size = 0;
	i = 1;
	while (i < argc)
	{
		cursor = 0;
		while (argv[i][cursor++])
			total_size++;
		i++;
	}
	tab = (char*)malloc((sizeof(*tab))*(total_size + argc + 1));
	total_size = 0;
	while (i > 1)
	{
		cursor = 0;
		while (argv[argc - i + 1][cursor])
			tab[total_size++] = argv[argc - i + 1][cursor++];
		tab[total_size++] = '\n';
		i--;
	}
	tab[total_size + argc]= '\0';
	return(tab);
}
