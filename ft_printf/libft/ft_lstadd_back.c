/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oturkan <oturkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:39:13 by oturkan           #+#    #+#             */
/*   Updated: 2022/01/21 18:43:45 by oturkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*son;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	son = ft_lstlast(*lst);
	son->next = new;
}
