/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttawna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 20:19:54 by ttawna            #+#    #+#             */
/*   Updated: 2019/11/23 23:36:06 by ttawna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fcntl.h"
# include "sys/types.h"
# include "sys/uio.h"
# include "unistd.h"
# include <stdlib.h>
# include "libft/libft.h"

int f[19][6] = {
        {0, 1, 1, 1, 0, 2}, {-1, 1, 0, 1, 0, 2}, {0, 1, 1, 1, 2, 1},
        {-2, 1, -1, 1, 0, 1}, {0, 1, 0, 2, 0, 3}, {-1, 1, 0, 1, 1, 1},
        {0, 1, 1, 1, 1, 2}, {-1, 1, 0, 1, -1, 2}, {0, 1, -1, 2, 0, 2},
        {0, 1, 0, 2, 1, 2}, {1, 0, -1, 1, 0, 1}, {1, 0, 1, 1, 2, 1},
        {1, 0, 0, 1, 1, 1}, {1, 0, 1, 1, 1, 2}, {1, 0, 0, 1, 0, 2},
        {1, 0, 2, 0, 1, 1}, {1, 0, 2, 0, 2, 1}, {1, 0, 2, 0, 0, 1},
        {1, 0, 2, 0, 3, 0}};

int	ft_firstcheck(const	char *sam)//проверка на то, что фигурки в квадратах
{
	int i;
	int k;

	i = 0;
	k = 0;
	int j;

	j = ft_strlen(sam);
	while (i < j)
	{
		if (sam[5 + i] == sam[10 + i] == sam[15 + i] == sam[20 + i] == sam[21 + i])
		{
			i = i + 21;
			k++;// к показывает количество фигурок, надо его вернуть
		}
		else
			return(-1);;
	}
	return(k);
}

int first_check (int fd, char **line)//while (first_check(fd, &l) > 0)
{
	int 	sam;
	char	*buff;
	char	*k;//c ней я и буду работать
	int 	am;//количество фигур
	int		key;

	if (fd < 0 || fd > 10240)
		return(-1);
	buff = (char *)malloc(sizeof(548));
	sam = read(fd, buff, 546);
	key = ft_strlen(buff);
	k = (char *)malloc(sizeof(key + 2));
	k = ft_strsub(buff, 0, key + 1);//дописать, чтобы потом очистить буфер
	k[key] = '\n';
	am = ft_firstcheck(k);
	if (am == -1)
		return(-1);
	if (last_check(am, k) < 0)
	    return(-1);
	*line = ft_strdup(k);
	return(1);
}

int ft_tet_check(int *tet, int **f)
{
	int i;
	int j;
	j = 0;
	while (j < 19)
	{
		i = 0;
		while(tet[i] == f[j][i])
		{
			if(i == 5)
				return(j);
			i++;
		}
		j++;
	}
	return(-1);
}


int last_check(int m, char *k)//проверка на сами фигурки
{
	int x;
	int y;
	int j;//счетчик фигурок ебаных
	int i;// до 21 то есть внутри одного квадрата
	int *tet;//сюда забиваем координаты одной фигурки
	int mem; //чтобы заполнять массив сверху
	int l;
	static int stock[23];
	int kk;

	j = 1;
	kk = 0;
	tet = (int *)malloc(sizeof(6));
	while( j <= m)
	{
		i = 0;

		while (k[i] != 35)// проработать случай когда пустой
			i++;
		x = (i + 1) % 5;
		y = (i + 1) / 5;
		while (i <19)
		{
			if (k[i] == 35)
			{
				tet[mem] = ((i + 1) % 5) - x;
				tet[mem + 1] = ((i + 1) % 5) - y;
				mem = mem + 2;
			}
			i++;
		}
		if(ft_tet_check(tet, &f) == -1)//проверка фигурки по базе
				return(-1);
		stock[kk] = ft_tet_check(tet, f);
		kk++;//временно закидываю в массив
		j++;
	}
    return (1);
}
		
