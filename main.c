/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:46:21 by ebichan           #+#    #+#             */
/*   Updated: 2026/02/04 00:47:36 by ebichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool check_arg(char *str)
{
    int i;

    i = 0;
    while(str[i] != '\0')
    {
        if(str[i] == '.')
        {
            if(str[i + 1] == 'r')
            {
                if(str[i + 2] == 't')
                {
                    if(str[i + 3] == '\0')
                        return(TRUE);
                    else
                        return(FALSE);
                }
                else
                    return(FALSE);
            }
            else
                return(FALSE);
        }
        i++;
    }
    return(FALSE);
}

int main(int argc, char *argv[])
{
    t_elem *elem;
    t_minirt *minirt;
    
    if(argc != 2)
    {
        print_error("Invalid argument number\n");
        return(1);
    }
     if(check_arg(arg) == FALSE)
    {
        print_error("Invalid argument\n");
        return(1);
    }
    elem = parse_file(argv[1]);
    minirt = init_minirt(elem);
}
