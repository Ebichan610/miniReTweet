/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 17:09:37 by ebichan           #+#    #+#             */
/*   Updated: 2026/02/09 17:29:59 by ebichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double calc_integer_part(const char **nptr)
{
    double result;

    result = 0;
    if(**nptr < '0' || **nptr > '9')
        return(INFINITY);
    while(**nptr >= '0' && **nptr <= '9')
    {
        result = result * 10 + **nptr - '0';
        (*nptr)++;
        if(isinf(result))
            return(INFINITY);
    }
    return(result);
}

static double calc_decimal_part(const char **nptr)
{
    double result;
    double factor;
    
    result = 0;
    factor = 0.1;
    (*nptr)++;
    if(**nptr < '0' || **nptr > '9')
        return(INFINITY);
    while(**nptr >= '0' && **nptr <= '9')
    {
        result += (**nptr - '0') * factor;
        (*nptr)++;
        factor *= 0.1;
    }
    return(result);
}

static bool is_overflow_or_underflow(double num, long e)
{
    double mag;
    double scaled;
    
    scaled = 0;
    mag = 0;
    if(num == 0)
        return(false);
    mag = log10(fabs(num)) + e;
    if(mag < -324 || mag > 308)
        return(true); 
    else if(mag <= -324 && mag > -325)
    {
        scaled = fabs(num) * pow(10.0, (double)e);
        if(scaled < DBL_TRUE_MIN)
            return(TRUE);
    }
    return(false);
}

static double calc_exponent_part(const char **nptr, double num)
{
    long e;
    int etype;

    e = 0;
    etype = 1;
    (*nptr)++;
    if(**nptr == '+' || **nptr == '-')
    {
        if(**nptr == '-')
            etype = -1;
        (*nptr)++;
    }
    if(**nptr < '0' || **nptr > '9')
        return(INFINITY);
    while(**nptr >= '0' && **nptr <= '9')
    {
        e = e * 10 + (**nptr - '0');
        (*nptr)++;
    }
    if(is_overflow_or_underflow(num, e * etype) == TRUE)
        return(INFINITY);
    return(num * pow(10, e * etype));
}

double ft_atof(const char *nptr)
{
    double  result;
    double  type;

    result = 0;
    type = 1;
    if(*nptr == '+' || *nptr == '-')
    {
        if(*nptr++ == '-')
            type = -1;
    }
    result = calc_integer_part(&nptr);
    if(result == INFINITY)
        return(INFINITY);
    if(*nptr == '.')
    {
        result += calc_decimal_part(&nptr);
        if(result == INFINITY)
            return(INFINITY);
    }
    if(*nptr == 'e' || *nptr == 'E')
        result = calc_exponent_part(&nptr, result);
    if(*nptr != '\0')
        return(INFINITY);
    return(result * type);
}
