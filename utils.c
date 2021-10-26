/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 08:05:09 by akhalid           #+#    #+#             */
/*   Updated: 2021/10/26 08:06:56 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int error_handler(char *str)
{
    printf("%s", str);
    return (-1);
}

int ft_atoi(char *str)
{
    int res;
    
    res = 0;
    while(*str)
    {
        if (*str < '0' || *str > '9')
            return error_handler("Arguments contain bad character.");
        res += res * 10 + *str++;
    }
    return (res);
}