/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_elem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:46:14 by ebichan           #+#    #+#             */
/*   Updated: 2026/02/24 14:49:22 by ebichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void free_sphere(t_sphere *sphere)
{
    t_sphere *tmp;

    while(sphere != NULL)
    {
        tmp = sphere->next;
        free(sphere);
        sphere = tmp;
    }
}

static void free_plane(t_plane *plane)
{
    t_plane *tmp;

    while(plane != NULL)
    {
        tmp = plane->next;
        free(plane);
        plane = tmp;
    }
}

static void free_cylinder(t_cylinder *cylinder)
{
    t_cylinder *tmp;

    while(cylinder != NULL)
    {
        tmp = cylinder->next;
        free(cylinder);
        cylinder = tmp;
    }
}

void free_elem(t_elem *elem)
{
    if(elem == NULL)
        return;
    if(elem->amb != NULL)
        free(elem->amb);
    if(elem->camera != NULL)
        free(elem->camera);
    if(elem->light != NULL)
        free(elem->light);
    if(elem->sphere != NULL)
        free_sphere(elem->sphere);
    if(elem->plane != NULL)
        free_plane(elem->plane);
    if(elem->cylinder != NULL)
        free_cylinder(elem->cylinder);
    free(elem);
}
