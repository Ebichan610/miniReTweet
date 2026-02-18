/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 01:49:23 by ebichan           #+#    #+#             */
/*   Updated: 2026/02/18 15:46:59 by ebichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool in_ratio_range(char *nptr)
{
    double num;

    num = ft_atof(nptr);
    if(isnan(num))
        return(false);
    if(num < 0.0 || num > 1.0)
        return(false);
    return(true);
}

bool in_color_range(char *nptr)
{
    double num;

    if(check_positive_int_num(nptr) == false)
        return(false);
    num = (double)ft_atoi(nptr);
    if(isnan(num))
        return(false);
    if(num < 0.0 || num > 255.0)
        return(false);
    return(true);
}

bool in_double_range(char *nptr, double_range_mode mode)
{
    double num;

    num = ft_atof(nptr);
    if(isnan(num))
        return(false);
    if(mode == DOUBLE_POSITIVE && num < 0.0)
        return(false);
    return(true);
}

bool in_vector_range(char *nptr)
{
    double num;

    num = ft_atof(nptr);
    if(isnan(num))
        return(false);
    if(num < -1.0 || num > 1.0)
        return(false);
    return(true);
}

bool in_degree_range(char *nptr)
{
    double num;

    num = ft_atof(nptr);
    if(isnan(num))
        return(false);
    if(num < 0.0 || num > 180.0)
        return(false);
    return(true);
}
