/* ****************** ******************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttawna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 18:48:36 by ttawna            #+#    #+#             */
/*   Updated: 2019/10/03 18:55:32 by ttawna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"
#include <fcntl.h>

int 	main(int argc, char ** argv)
{
    argv += 0;
    if (argc == 1)
    {
        int fd = open("16.fillit", O_RDONLY);
        char *l;
        while (first_check(fd, &l) > 0)
        {
            printf("%s", l);
            ft_strdel(&l);
        }
        if (l != NULL)
            ft_strdel(&l);
        close(fd);
    }
    return (0);
}