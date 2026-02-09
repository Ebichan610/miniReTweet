/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:46:21 by ebichan           #+#    #+#             */
/*   Updated: 2026/02/09 17:30:18 by ebichan          ###   ########.fr       */
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
                        return(true);
                    else
                        return(false);
                }
                else
                    return(false);
            }
            else
                return(false);
        }
        i++;
    }
    return(false);
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
     if(check_arg(arg) == false)
    {
        print_error("Invalid argument\n");
        return(1);
    }
    elem = parse_file(argv[1]);
    minirt = init_minirt(elem);
}
