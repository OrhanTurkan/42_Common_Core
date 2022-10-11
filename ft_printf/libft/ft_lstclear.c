/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oturkan <oturkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:39:20 by oturkan           #+#    #+#             */
/*   Updated: 2022/01/30 15:18:37 by oturkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tut;

	while (*lst)
	{
		tut = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tut;
	}
	*lst = 0;
}
