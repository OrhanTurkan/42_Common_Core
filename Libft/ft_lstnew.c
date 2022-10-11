/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oturkan <oturkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:39:31 by oturkan           #+#    #+#             */
/*   Updated: 2022/01/21 16:40:25 by oturkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*yeni;

	yeni = (t_list *)malloc(sizeof(t_list));
	if (!yeni)
		return (0);
	yeni -> content = content;
	yeni -> next = 0;
	return (yeni);
}
