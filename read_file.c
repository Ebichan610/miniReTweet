/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:37:58 by ebichan           #+#    #+#             */
/*   Updated: 2026/02/09 17:30:41 by ebichan          ###   ########.fr       */
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
            free(strs);
            return(false);
        }
        line = get_next_line(fd);
    }
    if(env_check(elem) == false)
        return(false);
    return(true);
}

t_elem *read_file(char *filename)
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
    if(lex_line(elem, fd) == false)
    {
        close(fd);
        free(elem);
        print_error("Invalid file content\n");
        exit(errno);
    }
    close(fd);
    return(elem);
}
