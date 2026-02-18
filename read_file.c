/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:37:58 by ebichan           #+#    #+#             */
/*   Updated: 2026/02/18 16:11:59 by ebichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool lex_line(t_elem *elem, int fd)
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
            return(false);
        }
        if(parse_line(elem, strs) == false)
        {
            free_strs(strs);
            return(false);
        }
        free_strs(strs);
        line = get_next_line(fd);
    }
    return(env_check(elem));
}

t_elem *read_file(char *filename)
{
    t_elem *elem;
    int fd;

    fd = open(filename, O_RDONLY);
    if(fd < 0)
    {
        perror("Error\nopen");
        return(NULL);
    }
    elem = (t_elem *)malloc(sizeof(t_elem));
    if(elem == NULL)
    {
        perror("Error\nmalloc");
        return(NULL);
    }
    ft_bzero(elem, sizeof(t_elem));
    if(lex_line(elem, fd) == false)
    {
        close(fd);
        free_elem(elem);
        print_error("Invalid file content\n");
        return(NULL);
    }
    close(fd);
    return(elem);
}
