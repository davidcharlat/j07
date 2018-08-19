#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int *ptr;
	int i;
	
	i = 0;
	if (max <= min)
		return (NULL);
	ptr = (int*)malloc((sizeof(*ptr))*(max - min));
	while (i < max - min)
	{
		ptr[i] = (min + i);
		i++;
	}
	return (ptr);
}
