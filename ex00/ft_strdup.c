#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		src_lenght;
	int		cursor;
	char	*new_str;
	
	src_lenght = 0;
	cursor = 0;
	while (src[src_lenght])
		src_lenght++;
	new_str = (char*)malloc(sizeof(*src) * (src_lenght + 1));
	cursor = 0;
	while (cursor <= src_lenght)
		new_str[cursor] = src[cursor++];
	return (new_str);
}
