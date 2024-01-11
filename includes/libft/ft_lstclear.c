/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbach <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:53:45 by bbach             #+#    #+#             */
/*   Updated: 2023/05/15 11:43:14 by bbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*actuel;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		actuel = *lst;
		*lst = (*lst)->next;
		free(actuel);
	}
	*lst = NULL;
}
