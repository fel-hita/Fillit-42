/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hita <felix.riddick@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 20:18:13 by fel-hita          #+#    #+#             */
/*   Updated: 2018/10/29 20:24:08 by fel-hita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t		counter(char *line, size_t i)
{
	size_t con;

	con = 0;
	if (i < 18)
		if (line[i] == line[i + 1])
			con++;
	if (i)
		if (line[i] == line[i - 1])
			con++;
	if (i / 5)
		if (line[i] == line[i - 5])
			con++;
	if ((i / 5) < 3)
		if (line[i] == line[i + 5])
			con++;
	return (con);
}

size_t		dot_counter(char *line)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while (line[i])
	{
		if (line[i] == '.')
			c++;
		i++;
	}
	return (c);
}

size_t		input_handler(char *line)
{
	size_t	i;
	size_t	con;
	size_t	nbr;

	nbr = 0;
	con = 0;
	i = 0;
	if (line[19] != '\n' || dot_counter(line) != 12)
		ft_err();
	while (line[i])
	{
		if (line[i] == '#')
		{
			nbr++;
			con += counter(line, i);
		}
		i++;
	}
	if (nbr != 4 || (con != 6 && con != 8))
		ft_err();
	return (1);
}

void		ft_printtable(char **tab, int size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_putchar(tab[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void		ft_err(void)
{
	ft_putstr("error\n");
	exit(0);
}
