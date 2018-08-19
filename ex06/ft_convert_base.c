#include <stdlib.h>

int	ft_is_base_ok(char *base)
{
	int base_size;
	int cursor;
	int i;

	cursor = 0;
	base_size = 0;
	while (base[base_size])
		base_size++;
	if (base_size < 2)
		return (0);
	while (cursor < base_size)
	{
		i = cursor + 1;
		while (i <= base_size)
		{
			if ((base[cursor] == base[i]) || (base[i] == '-')
				|| (base[i] == '+') || (base[0] == '-') || (base[0] == '+'))
				return (0);
			i++;
		}
		cursor++;
	}
	return (1);
}

int	check_and_numerize_str(char *str, char *base, int *result, int size)
{
	int cursor;
	int i;
	int test;

	test = 1;
	cursor = 0;
	i = 0;
	while ((cursor < size) && (test > 0))
	{
		while ((base[i]) && (test == 1) && (i < 66))
		{
			if (str[size - cursor - 1] == base[i])
			{
				result[cursor] = i;
				test = 2;
			}
			i++;
		}
		test = test - 1;
		cursor++;
		i = 0;
	}
	return (test);
}

int	ft_atoui_base(char *str, char *base)
{
	int	base_size;
	int str_size;
	int	result[66]={0};
	int	cursor;
	int power;
	
	power = 1;
	cursor = 0;
	str_size = 0;
	while(str[str_size])
		str_size++;
	base_size = 0;
	while (base[base_size])
		base_size++;
	if (check_and_numerize_str(str, base, result, str_size) && ft_is_base_ok(base))
	{
		while ((cursor < str_size))
		{
			result[65] = result[65] + (result[cursor] * power);
			power = power * base_size;
			cursor++;
		}
	}
	return (result[65]);
}

char		*ft_put_nbr_in_base_to(int nbri, char *base)
{
	int		base_size;
	char	result[66]={'\0'};
	int 	cursor;
	int		result_size;
	char	*nbr_in_base_to;
	int		i;

	cursor = 0;
	result_size = 0;
	base_size = 0;
	while (base[base_size])
		base_size++;
	while ((nbri != 0) && (cursor < 66) && ft_is_base_ok(base))
	{
		result[cursor] = base[(nbri % base_size)];
		nbri = nbri / base_size;
		result_size++;
		cursor++;
	}
	nbr_in_base_to = (char*)malloc((sizeof(char))*(result_size + 1));
	cursor = 0;
	i = result_size;
	while (cursor  <= result_size)
		nbr_in_base_to[cursor++] = result[--i];
	return (nbr_in_base_to);
}

char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
 int	nbr_int;
 char	*str_result;
 
 nbr_int = ft_atoui_base(nbr, base_from);
 str_result = ft_put_nbr_in_base_to(nbr_int, base_to);
 return (str_result);
}
