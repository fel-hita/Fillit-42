/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functetris.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hita <felix.riddick@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 11:01:43 by fel-hita          #+#    #+#             */
/*   Updated: 2018/10/30 18:41:24 by fel-hita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_freetab(char **tab, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	removetetrise(char **tab, t_tetris *t, t_pos pos)
{
	int h;

	h = 0;
	while (h < 4)
	{
		tab[pos.i][pos.j] = '.';
		pos.i += (t->pos[h + 1].i - t->pos[h].i);
		pos.j += (t->pos[h + 1].j - t->pos[h].j);
		h++;
	}
	t->checked = 0;
}

void	addtetris(char **tab, t_tetris *t, t_pos pos)
{
	int h;

	h = 0;
	while (h < 4)
	{
		tab[pos.i][pos.j] = t->c;
		pos.i += (t->pos[h + 1].i - t->pos[h].i);
		pos.j += (t->pos[h + 1].j - t->pos[h].j);
		h++;
	}
	t->checked = 1;
}

int		checkposition(char **tab, int size, t_tetris *t, t_pos pos)
{
	int h;

	h = 0;
	while (h < 4)
	{
		if (pos.i < 0 || pos.i >= size || pos.j < 0 || pos.j >= size)
			return (0);
		if (tab[pos.i][pos.j] != '.')
			return (0);
		pos.i += (t->pos[h + 1].i - t->pos[h].i);
		pos.j += (t->pos[h + 1].j - t->pos[h].j);
		h++;
	}
	return (1);
}

int		ft_nextindex(char **tab, int size)
{
	int len;
	int i;

	i = 0;
	len = size * size;
	while (i < len)
	{
		if (tab[i / size][i % size] == '.')
			return (i);
		i++;
	}
	return (0);
}
