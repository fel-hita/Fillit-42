/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hita <felix.riddick@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 15:01:10 by fel-hita          #+#    #+#             */
/*   Updated: 2018/10/30 18:41:22 by fel-hita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct	s_pos
{
	int			i;
	int			j;
}				t_pos;

typedef struct	s_tetris
{
	t_pos			*pos;
	char			c;
	int				checked;
	struct s_tetris	*next;
}				t_tetris;

t_tetris		*ft_newtetris(t_pos *p, char c);
void			ft_addtetris(t_tetris **t, t_pos *p, char c);
t_tetris		*ft_gettetris(t_tetris *t);
int				lstchecked(t_tetris *t);
void			removetetrise(char **tab, t_tetris *t, t_pos pos);
void			addtetris(char **tab, t_tetris *t, t_pos pos);
int				checkposition(char **tab, int size, t_tetris *t, t_pos pos);
char			**init(int n);
size_t			input_handler(char *line);
void			ft_freetab(char **tab, int n);
int				ft_nextindex(char **tab, int size);
void			ft_printtable(char **tab, int size);
void			ft_err(void);
void			ft_solve(t_tetris *t);
t_pos			*ft_aloc(t_pos *iter);
t_tetris		*ft_readtetris(int fd, int *r);
int				ft_sqrt(t_tetris *t);

#endif
