/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oturkan <oturkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:02:39 by oturkan           #+#    #+#             */
/*   Updated: 2022/02/07 13:02:39 by oturkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*yedek(char *tut)
{
	int		i;
	int		j;
	char	*yedek;

	i = 0;
	j = 0;
	while (tut[i] && tut[i] != '\n')
		i++;
	if (!tut[i])
		return (ft_free(tut));
	i++;
	if (!tut[i])
		return (ft_free(tut));
	yedek = (char *)malloc(ft_strlen(tut) - i + 1);
	if (!yedek)
		return (0);
	while (tut[i])
		yedek[j++] = tut[i++];
	yedek[j] = '\0';
	free(tut);
	return (yedek);
}

char	*ayikla(char *tut)
{
	int		i;
	char	*ilk;

	i = 0;
	if (!tut[i])
		return (0);
	while (tut[i] && tut[i] != '\n')
		i++;
	ilk = (char *)malloc(i + 2);
	if (!ilk)
		return (0);
	i = 0;
	while (tut[i] && tut[i] != '\n')
	{
		ilk[i] = tut[i];
		i++;
	}
	if (tut[i] == '\n')
	{
		ilk[i] = '\n';
		i++;
	}
	ilk[i] = '\0';
	return (ilk);
}

char	*oku(int fd, char *tut)
{
	char	*buff;
	int		guvenlik;
	char	*temp;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	if (!tut)
		tut = calloc(1, 1);
	guvenlik = 123;
	while (!ft_strchr(tut, '\n') && guvenlik != 0)
	{
		guvenlik = read(fd, buff, BUFFER_SIZE);
		if (guvenlik == -1)
		{
			free(buff);
			free(tut);
			return (0);
		}
		buff[guvenlik] = '\0';
		temp = ft_strjoin(tut, buff);
		tut = temp;
	}
	free(buff);
	return (tut);
}

char	*get_next_line(int fd)
{
	static char	*tut[256];
	char		*ilk;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	tut[fd] = oku(fd, tut[fd]);
	if (!tut[fd])
		return (0);
	ilk = ayikla(tut[fd]);
	tut[fd] = yedek(tut[fd]);
	return (ilk);
}
