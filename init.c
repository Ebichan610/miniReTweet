/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:37:46 by ebichan           #+#    #+#             */
/*   Updated: 2026/02/18 14:06:11 by ebichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_minirt *init_minirt(char *filename)
{
    t_minirt *minirt;
    
    minirt = (t_minirt *)malloc(sizeof(t_minirt));
    if(minirt == NULL)
    {
        perror("Error\nmalloc");
        return(NULL);
    }
    ft_bzero(minirt, sizeof(minirt));
    minirt->elem = read_file(filename);
    if(minirt->elem == NULL)
    {
        free_all(minirt);
        return(NULL);
    }
}
