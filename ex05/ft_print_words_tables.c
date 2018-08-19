void	ft_putchar(char c);

void	ft_print_words_tables(char **tab)
{
	int tab_cursor;
    int letter_cursor;
    
    tab_cursor = 0;
    while (tab[tab_cursor])
    {
		letter_cursor = 0;
		while(tab[tab_cursor][letter_cursor])
			ft_putchar(tab[tab_cursor][letter_cursor++]);
		ft_putchar('\n'); 
 		tab_cursor++;   
    }
}
