/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 01:48:01 by ebichan           #+#    #+#             */
/*   Updated: 2026/02/18 16:26:04 by ebichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool parse_amb(t_elem *elem, char **strs)
{
    double ratio;
    t_color color;
    t_amb *amb;

    if(count_str(strs) != 3)
        return(false);
    if(!in_ratio_range(strs[1]))
        return(false);
    ratio = ft_atof(strs[1]);
    color = apply_color(strs[2]);
    if(color.r == -1 || color.g == -1 || color.b == -1)
        return(false);
    amb = (t_amb *)malloc(sizeof(t_amb));
    if(amb == NULL)
        return(false);
    amb->ratio = ratio;
    amb->color = color;
    elem->amb = amb;
    elem->amb_flag = true;
    return(true);
}

static bool parse_camera(t_elem *elem, char **strs)
{
    t_point point;
    t_vector vector;
    double   fov;
    t_camera *camera;

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
    camera = (t_camera *)malloc(sizeof(camera));
    if(camera == NULL)
        return(false);
    camera->point = point;
    camera->vector = vector;
    camera->fov = fov;
    elem->camera = camera;
    elem->camera_flag = true;
    return(true);
}

static bool parse_light(t_elem *elem, char **strs)
{
    t_point point;
    double ratio;
    t_color color;
    t_light *light;
    
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
    light = (t_light *)malloc(sizeof(t_light));
    if(light == NULL)
        return(false);
    light->point = point;
    light->ratio = ratio;
    light->color = color;
    elem->light = light;
    elem->light_flag = true;
    return(true);
}

bool parse_line(t_elem *elem, char **strs)
{
    if(ft_strcmp(strs[0], "A") == 0 && elem->amb_flag == false)
        return(parse_amb(elem, strs));
    else if(ft_strcmp(strs[0], "C") == 0 && elem->camera_flag == false)
        return(parse_camera(elem, strs));
    else if(ft_strcmp(strs[0], "L") == 0 && elem->light_flag == false)
        return(parse_light(elem, strs));
    else if(ft_strcmp(strs[0], "sp") == 0)
        return(parse_sphere(elem, strs));
    else if(ft_strcmp(strs[0], "pl") == 0)
        return(parse_plane(elem, strs));
    else if(ft_strcmp(strs[0], "cy") == 0)
        return(parse_cylinder(elem, strs));
    return(false);
}
