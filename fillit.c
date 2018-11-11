/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hita <felix.riddick@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 14:58:37 by fel-hita          #+#    #+#             */
/*   Updated: 2018/10/30 18:41:32 by fel-hita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_solvit(t_tetris *t, char **tab, int size, int index)
{
	t_pos		pos;
	t_tetris	*tmp;
	int			tabsize;

	if (lstchecked(t))
		return (1);
	pos.i = index / size;
	pos.j = index % size;
	tmp = ft_gettetris(t);
	tabsize = size * size;
	while (tabsize-- && tmp)
	{
		if (checkposition(tab, size, tmp, pos) == 1)
		{
			addtetris(tab, tmp, pos);
			if (ft_solvit(t, tab, size, ft_nextindex(tab, size)))
				return (1);
			removetetrise(tab, tmp, pos);
		}
		index++;
		pos.i = index / size;
		pos.j = index % size;
		tmp = ft_gettetris(t);
	}
	return (0);
}

void		ft_solve(t_tetris *t)
{
	int		size;
	char	**tab;

	size = ft_sqrt(t);
	while (size <= 20)
	{
		tab = init(size);
		if (ft_solvit(t, tab, size, 0))
			break ;
		ft_freetab(tab, size);
		size++;
	}
	if (size != 20)
		ft_printtable(tab, size);
	else
		ft_err();
}

t_pos		*ft_aloc(t_pos *iter)
{
	t_pos		*pos;

	(*iter).i = 0;
	(*iter).j = 0;
	pos = (t_pos *)malloc(4 * sizeof(t_pos));
	if (!pos)
		ft_err();
	return (pos);
}

t_tetris	*ft_readtetris(int fd, int *r)
{
	char		*line;
	char		c;
	t_tetris	*tetris;
	t_pos		*pos;
	t_pos		iter;

	tetris = NULL;
	line = ft_strnew(20);
	c = 'A';
	while (read(fd, line, 20))
	{
		input_handler(line);
		pos = ft_aloc(&iter);
		while (line[iter.i++])
			if (line[iter.i - 1] == '#')
			{
				pos[iter.j].i = (iter.i - 1) / 5;
				pos[iter.j++].j = (iter.i - 1) % 5;
			}
		*r = read(fd, line, 1);
		ft_addtetris(&tetris, pos, c++);
		ft_bzero(line, 20);
	}
	return (tetris);
}

int			main(int s, char **ag)
{
	int			fd;
	t_tetris	*tetris;
	int			r;

	if (s != 2)
	{
		ft_putstr("usage : need name of file as argument\n");
		return (0);
	}
	fd = open(ag[1], O_RDONLY);
	tetris = ft_readtetris(fd, &r);
	if (!tetris || r != 0)
		ft_err();
	ft_solve(tetris);
	return (0);
}
