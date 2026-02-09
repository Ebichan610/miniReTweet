/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 01:48:01 by ebichan           #+#    #+#             */
/*   Updated: 2026/02/06 14:19:21 by ebichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool parse_amb(t_elem *elem, char **strs)
{
    
}

bool parse_line(t_elem *elem, char **strs)
{
    if(ft_strcmp(strs[1], "A") == 0)
        return(parse_amb(elem, strs));
    else if(ft_strcmp(strs[1], "C") == 0)
        return(parse_camera(elem, strs));
    else if(ft_strcmp(strs[1], "L") == 0)
        return(parse_light(elem, strs));
    else if(ft_strcmp(strs[1], "sp") == 0)
        return(parse_sphere(elem, strs));
    else if(ft_strcmp(strs[1], "pl") == 0)
        return(parse_plane(elem, strs));
    else if(ft_strcmp(strs[1], "cy") == 0)
        return(parse_cylinder(elem, strs));
    return(FALSE);
}
