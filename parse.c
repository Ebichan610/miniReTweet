/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:37:58 by ebichan           #+#    #+#             */
/*   Updated: 2026/02/04 17:24:02 by ebichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool struct_elems(t_elem * elem, it fd)
{
    char *line;
    char **strs;

    line = get_next_line(fd);
    while(line != NULL)
    {
        strs = ft_split(line, ' ');
        free(line);
        if(strs == NULL)
        {
            print_error("Ft_split failed\n");
            return(FALSE);
        }
        line = get_next_line(fd);
    }
    return(TRUE);
}

t_elem *parse_file(char *filename)
{
    t_elem *elem;
    int fd;

    fd = open(filename, O_RDONLY);
    if(fd < 0)
    {
        perror("Error\nopen");
        exit(errno);
    }
    elem = (t_elem *)malloc(sizeof(t_elem));
    if(elem == NULL)
    {
        perror("Error\nmalloc");
        exit(errno);
    }
    if(struct_elems(elem, fd) == FALSE)
    {
        close(fd);
        free(elem);
        print_error("Invalid file content\n");
        exit(errno);
    }
    close(fd);
    return(elem);
}
