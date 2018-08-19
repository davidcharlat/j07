#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int i;
	
	i = 0;
	if (max <= min)
	{
		*range = NULL;
		return (0);
	}
	if(*range = (int*)malloc((sizeof(int))*(max - min)))
	{	
		while (i < max - min)
			(*range)[i] = (min + i++);
		return (max - min);
	}

}
