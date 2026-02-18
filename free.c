/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 01:52:21 by ebichan           #+#    #+#             */
/*   Updated: 2026/02/18 16:07:10 by ebichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void free_strs(char **strs)
{
    int i;

    i = 0;
    if(strs == NULL)
        return(NULL);
    while(strs[i] != '\0')
    {
        free(strs[i]);
        i++;
    }
    free(strs);
}

void free_all(t_minirt *minirt)
{

}
