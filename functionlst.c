/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functionlst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hita <felix.riddick@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 11:02:35 by fel-hita          #+#    #+#             */
/*   Updated: 2018/10/30 18:36:50 by fel-hita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetris	*ft_newtetris(t_pos *p, char c)
{
	t_tetris *t;

	if (!(t = (t_tetris *)malloc(sizeof(t_tetris))))
		ft_err();
	t->pos = p;
	t->checked = 0;
	t->c = c;
	t->next = NULL;
	return (t);
}

void		ft_addtetris(t_tetris **t, t_pos *p, char c)
{
	t_tetris	*tmp;
	t_tetris	*tp;

	tmp = ft_newtetris(p, c);
	if (*t == NULL)
		*t = tmp;
	else
	{
		tp = *t;
		while (tp->next)
			tp = tp->next;
		tp->next = tmp;
	}
}

t_tetris	*ft_gettetris(t_tetris *t)
{
	t_tetris *tmp;

	tmp = t;
	while (tmp)
	{
		if (!tmp->checked)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

int			lstchecked(t_tetris *t)
{
	while (t)
	{
		if (!t->checked)
			return (0);
		t = t->next;
	}
	return (1);
}

char		**init(int n)
{
	int		i;
	int		j;
	char	**t;

	t = malloc(n * sizeof(char *));
	if (!t)
		ft_err();
	i = 0;
	while (i < n)
	{
		t[i] = malloc(n * sizeof(int));
		if (!t[i])
			ft_err();
		i++;
	}
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
			t[i][j++] = '.';
		i++;
	}
	return (t);
}
