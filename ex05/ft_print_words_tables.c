void	ft_putchar(char c);

void	ft_print_words_tables(char **tab)
{
	while (*tab)
	{
		while(**tab)
			ft_putchar(**tab++);
		ft_putchar('\n'); 
		*tab++;
	}
}
