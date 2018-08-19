#include <stdlib.h>

int		is_separator (char c)
{
	if ((c == '\t') || (c == '\n') || (c == ' '))
		return (1);
	return (0);
}

int		count_words(char *str)
{
	int	start;
	int i;
	int total;
	
	total = 0;
	start = 0;
	i = 0;
	while (str[i])
	{
		if ((start == 0 ) && (is_separator(str[i]) == 0))
			total++;
		if (is_separator(str[i]) == 0)
			start = 1;
		if (is_separator(str[i]))
			start = 0;
		i++;
	}
	return (total);
}

int		ft_strlen (char *str)
{
	int counter;

	counter = 0;
	while (*(str + counter) != '\0')
		counter++;
	return (counter);
}

char	**ft_split_whitespaces(char *str)
{
	char	**final_tab;
	char	*new_str;
	int		i;
	int		cursor_final_tab;
	int		len;
	
	len = ft_strlen(str);
	cursor_final_tab = count_words(str) + 1;
	i = len;
	new_str = (char*)malloc((sizeof(char))*(len + 1));
	final_tab = (char**)malloc((sizeof(char*))*(cursor_final_tab + 1));
	final_tab[cursor_final_tab--] = 0;
	while (i-- >= 1)
	{
		new_str[i] = str[i];
		if (is_separator(str[i]))
			new_str[i] = 0;
		if (((i > 0) && (is_separator(str[i - 1])) && ((new_str[i]) != 0))
		|| ((len > 0) && (i == 0) && (str[0] != 0)))
			final_tab[cursor_final_tab--] = &new_str[i];
	}
	final_tab[0] = &new_str[0];
	return (final_tab + 1);
}
