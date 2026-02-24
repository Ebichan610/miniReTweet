/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 01:48:01 by ebichan           #+#    #+#             */
/*   Updated: 2026/02/24 14:28:34 by ebichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool parse_amb(t_elem *elem, char **strs)
{
    double ratio;
    t_color color;
    t_amb *new_node;

    if(count_str(strs) != 3)
        return(false);
    if(!in_ratio_range(strs[1]))
        return(false);
    ratio = ft_atof(strs[1]);
    color = apply_color(strs[2]);
    if(color.r == -1 || color.g == -1 || color.b == -1)
        return(false);
    new_node = (t_amb *)malloc(sizeof(t_amb));
    if(new_node == NULL)
        return(false);
    new_node->ratio = ratio;
    new_node->color = color;
    elem->amb = new_node;
    elem->amb_flag = true;
    return(true);
}

bool parse_camera(t_elem *elem, char **strs)
{
    t_point point;
    t_vector vector;
    double   fov;
    t_camera *new_node;

    if(count_str(strs) != 4)
        return(false);
    point = apply_point(strs[1]);
    if(isnan(point.x) || isnan(point.y) || isnan(point.z))
        return(false);
    vector = apply_vector(strs[2]);
    if(isnan(vector.vx) || isnan(vector.vy) || isnan(vector.vz))
        return(false);
    if(!in_degree_range(strs[3]))
        return(false);
    fov = ft_atof(strs[3]);
    new_node = (t_camera *)malloc(sizeof(camera));
    if(new_node == NULL)
        return(false);
    new_node->point = point;
    new_node->vector = vector;
    new_node->fov = fov;
    elem->camera = new_node;
    elem->camera_flag = true;
    return(true);
}

bool parse_light(t_elem *elem, char **strs)
{
    t_point point;
    double ratio;
    t_color color;
    t_light *new_node;
    
    if(count_str(strs) != 4)
        return(false);
    point = apply_point(strs[1]);
    if(isnan(point.x) || isnan(point.y) || isnan(point.z))
        return(false);
    if(!in_ratio_range(strs[2]))
        return(false);
    ratio = ft_atof(strs[2]);
    color = apply_color(strs[3]);
    if(color.r == -1 || color.g == -1 || color.b == -1)
        return(false);
    new_node = (t_light *)malloc(sizeof(t_light));
    if(new_node == NULL)
        return(false);
    new_node->point = point;
    new_node->ratio = ratio;
    new_node->color = color;
    elem->light = new_node;
    elem->light_flag = true;
    return(true);
}

static bool set_sphere(t_elem *elem, t_point point, double r, t_color color)
{
    t_sphere *new_node;
    t_sphere *last;

    new_node = (t_sphere *)malloc(sizeof(t_sphere));
    if(new_node == NULL)
        return(false);
    new_node->point = point;
    new_node->r = r;
    new_node->color = color;
    new_node->next = NULL;
    if(elem->sphere == NULL)
        elem->sphere = new_node;
    else
    {
        last = elem->sphere;
        while(last->next != NULL)
            last = last->next;
        last->next = new_node;
    }
    return(true);
}

bool parse_sphere(t_elem *elem, char **strs)
{
    t_point point;
    double r;
    t_color color;
    
    if(count_str(strs) != 4)
        return(false);
    point = apply_point(strs[1]);
    if(isnan(point.x) || isnan(point.y) || isnan(point.z))
        return(false);
    if(!in_double_range(strs[2], DOUBLE_POSITIVE))
        return(false);
    r = ft_atof(strs[2]);
    color = apply_color(strs[3]);
    if(color.r == -1 || color.g == -1 || color.b == -1)
        return(false);
    return(set_sphere(elem, point, r, color));
}
