/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbach <bbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:25:42 by bbach             #+#    #+#             */
/*   Updated: 2024/01/10 13:00:19 by bbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	two_commas_only(t_cub *cub)
{
    int i;
    int j;
    int k;

    i = 0;
    j = 0;
    k = 0;
    while (cub->couleurs_path[i])
    {
        while (cub->couleurs_path[i][j])
        {
            if (cub->couleurs_path[i][j] == ',')
                k++;
            j++;
        }
        if (k != 2)
            clean_exit("Error\nWrong color format\nPlease use as :\nF XXX, XXX, XXX", cub);
        k = 0;
        j = 0;
        i++;
    }
}

void    check_first_letter(t_cub *cub)
{
    int i;
    
    i = 0;
    while (cub->couleurs_path[i])
    {
        if (cub->couleurs_path[i][0] != 'F' && cub->couleurs_path[i][0] != 'C')
            clean_exit("Error\nWrong color format\nPlease use as :\nF XXX, XXX, XXX", cub);
        i++;
    }
}

void    three_spaces_only(t_cub *cub)
{
    int i;
    int j;
    int k;

    i = 0;
    j = 0;
    k = 0;
    while (cub->couleurs_path[i])
    {
        while (cub->couleurs_path[i][j])
        {
            if (cub->couleurs_path[i][j] == ' ')
                k++;
            j++;
        }
        if (k != 3)
            clean_exit("Error\nWrong color format\nPlease use as :\nF XXX, XXX, XXX", cub);
        k = 0;
        j = 0;
        i++;
    }
}

void    check_format(t_cub *cub)
{
    int i;
    int j;

    i = 0;
    while (cub->couleurs_path[i])
    {
        j = 1;
        while (cub->couleurs_path[i][j])
        {
            if (cub->couleurs_path[i][j] != ' ' && cub->couleurs_path[i][j] != ',' 
            && !ft_isdigit(cub->couleurs_path[i][j]))
                clean_exit("Error\nWrong color format\nPlease use as :\nF XXX, XXX, XXX", cub);
            j++;
        }
        i++;
    }
}

void    get_atoi_color(t_cub *cub)
{
    int i;
    int j;
    int k;

    i = 0;
    j = 0;
    k = 0;
    while (cub->couleurs_path[i])
    {
        while (cub->couleurs_path[i][j])
        {
            if (ft_isdigit(cub->couleurs_path[i][j]) && cub->couleurs_path[i][0] == 'F')
            {
                if (k == 0)
                    cub->data.red_f = ft_atoi(&cub->couleurs_path[i][j]);
                if (k == 1)
                    cub->data.green_f = ft_atoi(&cub->couleurs_path[i][j]);
                if (k == 2)
                    cub->data.blue_f = ft_atoi(&cub->couleurs_path[i][j]);
                while (ft_isdigit(cub->couleurs_path[i][j]))
                    j++;
                k++;
            }
            else if (ft_isdigit(cub->couleurs_path[i][j]) && cub->couleurs_path[i][0] == 'C')
            {
                if (k == 0)
                    cub->data.red_c = ft_atoi(&cub->couleurs_path[i][j]);
                if (k == 1)
                    cub->data.green_c = ft_atoi(&cub->couleurs_path[i][j]);
                if (k == 2)
                    cub->data.blue_c = ft_atoi(&cub->couleurs_path[i][j]);
                while (ft_isdigit(cub->couleurs_path[i][j]))
                    j++;
                k++;
            } 
            j++;
        }
        k = 0;
        j = 0;
        i++;
    }
}
void    check_if_between_0_255(t_cub *cub)
{
    if (cub->data.red_f < 0 || cub->data.red_f > 255)
        clean_exit("Error\nWrong color format\nPlease use as :\nF (0->255), (0->255), (0->255)", cub);
    if (cub->data.green_f < 0 || cub->data.green_f > 255)
        clean_exit("Error\nWrong color format\nPlease use as :\nF (0->255), (0->255), (0->255)", cub);
    if (cub->data.blue_f < 0 || cub->data.blue_f > 255)
        clean_exit("Error\nWrong color format\nPlease use as :\nF (0->255), (0->255), (0->255)", cub);
    if (cub->data.red_c < 0 || cub->data.red_c > 255)
        clean_exit("Error\nWrong color format\nPlease use as :\nF (0->255), (0->255), (0->255)", cub);
    if (cub->data.green_c < 0 || cub->data.green_c > 255)
        clean_exit("Error\nWrong color format\nPlease use as :\nF (0->255), (0->255), (0->255)", cub);
    if (cub->data.blue_c < 0 || cub->data.blue_c > 255)
        clean_exit("Error\nWrong color format\nPlease use as :\nF (0->255), (0->255), (0->255)", cub);
}
void    check_colors(t_cub *cub)
{
    two_commas_only(cub);
    check_first_letter(cub);
    three_spaces_only(cub);
    check_format(cub);
    get_atoi_color(cub);
    check_if_between_0_255(cub);
}
