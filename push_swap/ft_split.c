/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oturkan <oturkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 11:16:55 by oturkan           #+#    #+#             */
/*   Updated: 2022/07/08 16:49:11 by oturkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_count(int c, char **args, t_p *p)
{
	int	i;

	i = 0;
	while (i < c)
		ft_split(args[i++], 32, p);
}

static int	count_words(char const *str, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i])
			count++;
		while (str[i] != c && str[i])
			i++;
	}
	return (count);
}

static char	*create_str(char const *str, char c)
{
	int		i;
	char	*ptr;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	ptr = (char *) malloc(sizeof(char) * (i + 1));
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, str, i + 1);
	return (ptr);
}

static void	*ft_free(char **ptr, int i)
{
	while (i > 0)
		free(ptr[i--]);
	free(ptr);
	return (0);
}

char	**ft_split(char const *s, char c, t_p *p)
{
	int		i;
	int		len;
	char	**ptr;

	if (!s)
		return (0);
	len = count_words(s, c);
	p->size += len;
	ptr = (char **)malloc(sizeof(char *) * (len + 1));
	if (!(ptr))
		return (0);
	i = -1;
	while (++i < len)
	{
		while (s[0] == c)
			s++;
		ptr[i] = create_str(s, c);
		if (!ptr[i])
			return (ft_free(ptr, i));
		s = s + ft_strlen(ptr[i]);
	}
	ptr[i] = 0;
	return (ptr);
}
