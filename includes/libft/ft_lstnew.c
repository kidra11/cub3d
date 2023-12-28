/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbach <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:56:50 by bbach             #+#    #+#             */
/*   Updated: 2023/05/15 12:24:53 by bbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int content)
{
	t_list	*n_elem;

	n_elem = (t_list *)malloc(sizeof(t_list));
	if (n_elem == NULL)
		return (NULL);
	n_elem->content = content;
	n_elem->next = NULL;
	return (n_elem);
}
