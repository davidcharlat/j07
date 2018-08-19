#include <stdlib.h>

int		find_charset(char *str, char *to_find, int pos)
{
	int i;
	
	i = 0;
	while ((str[pos + i]) && (to_find[i]) && (to_find[i] == str[pos + i]))
		i++;
	if (to_find[i] == '\0')
		return (1);
	return (0);
}

char	*copy_wd_till_charset(char *str, char *charset, int pos)
{
	char *new_wd;
	int wd_len;
	
	wd_len = 0;
	while ((str[wd_len + pos]) && (find_charset(str, charset, pos) == 0))
		wd_len++;
	new_wd = (char*)malloc(sizeof(char) * (wd_len + 1));
	wd_len = 0;
	while ((str[wd_len + pos]) 
			&& (find_charset(str, charset, wd_len + pos) == 0))
		new_wd[wd_len] = str[wd_len++ + pos];
	new_wd[wd_len] = '\0';
	return (new_wd);
}

int		is_new_wd(char *str, char *charset, int cursor)
{
	int charset_len;
	int i;
	int test;
	
	i = 0;
	test = 1;
	charset_len = 0;
	while (charset[charset_len])
		charset_len++;
	while ((cursor - i >= 0) && (i < charset_len))
	{
		if (find_charset(str, charset, cursor-i))
			test = 0;
		i++;
	}
	if ((test == 1) && 
		(((cursor >= charset_len) 
				&& find_charset(str, charset, cursor - charset_len))
			 || (cursor == 0)))
		return (1);
	return (0);
}

int		count_wd(char *str, char *charset)
{
	int cursor;
	int count;
	
	count = 0;
	cursor = 0;
	while (str[cursor])
	{
		if (is_new_wd(str, charset, cursor++))
			count++;
	}
	return (count);
}

char	**ft_split(char *str, char *charset)
{
	char **tab;
	int cursor;
	int count;
	
	count = 0;
	cursor = 0;
	tab = (char**)malloc(sizeof(char*) * (count_wd(str, charset)) + 1);
	while (str[cursor])
	{
		if (is_new_wd(str, charset, cursor))
			tab[count++] = copy_wd_till_charset(str, charset, cursor);
		cursor++;
	}
	tab[count] = 0;
	return (tab);
}
