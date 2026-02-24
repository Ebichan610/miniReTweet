/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 01:47:53 by ebichan           #+#    #+#             */
/*   Updated: 2026/02/24 14:28:35 by ebichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool set_plane(t_elem *elem, t_point point, t_vector vector, t_color color)
{
    t_plane *new_node;
    t_plane *last;

    new_node = (t_plane *)malloc(sizeof(t_plane));
    if(new_node == NULL)
        return(false);
    new_node->point = point;
    new_node->vector = vector;
    new_node->color = color;
    new_node->next = NULL;
    if(elem->plane == NULL)
        elem->plane = new_node;
    else
    {
        last = elem->plane;
        while(last->next != NULL)
            last = last->next;
        last->next = new_node;
    }
    return(true);
}

bool parse_plane(t_elem *elem, char **strs)
{
    t_point point;
    t_vector vector;
    t_color color;
    
    if(count_str(strs) != 4)
        return(false);
    point = apply_point(strs[1]);
    if(isnan(point.x) || isnan(point.y) || isnan(point.z))
        return(false);
    vector = apply_vector(strs[2]);
    if(isnan(vector.vx) || isnan(vector.vy) || isnan(vector.vz))
        return(false);
    color = apply_color(strs[3]);
    if(color.r == -1 || color.g == -1 || color.b == -1)
        return(false);
    return(set_plane(elem, point, vector, color));
}

static bool set_cylinder(t_elem *elem, t_point point, t_vector vector, t_cylen len, t_color color)
{
    t_cylinder *new_node;
    t_cylinder *last;

    new_node = (t_cylinder *)malloc(sizeof(t_cylinder));
    if(new_node == NULL)
        return(false);
    new_node->point = point;
    new_node->vector = vector;
    new_node->r = len.r;
    new_node->h = len.h;
    new_node->color = color;
    new_node->next = NULL;
    if(elem->cylinder == NULL)
        elem->cylinder = new_node;
    else
    {
        last = elem->cylinder;
        while(last->next != NULL)
            last = last->next;
        last->next = new_node;
    }
    return(true);
}

bool parse_cylinder(t_elem *elem, char **strs)
{
    t_point point;
    t_vector vector;
    t_cylen len;
    t_color color;
    
    if(count_str(strs) != 6)
        return(false);
    point = apply_point(strs[1]);
    if(isnan(point.x) || isnan(point.y) || isnan(point.z))
        return(false);
    vector = apply_vector(strs[2]);
    if(isnan(vector.vx) || isnan(vector.vy) || isnan(vector.vz))
        return(false);
    if(!in_double_range(strs[3], DOUBLE_POSITIVE) || !in_double_range(strs[4], DOUBLE_POSITIVE))
        return(false);
    len.r = ft_atof(strs[3]);
    len.h = ft_atof(strs[4]);
    color = apply_color(strs[5]);
    if(color.r == -1 || color.g == -1 || color.b == -1)
        return(false);
    return(set_cylinder(elem, point, vector, len, color));
}
