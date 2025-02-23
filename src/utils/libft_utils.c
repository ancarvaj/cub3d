/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarvaj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:07:47 by ancarvaj          #+#    #+#             */
/*   Updated: 2025/02/23 13:48:05 by ancarvaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strlen_double(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	**ft_strjoin_double(char **s, char *_new)
{
	char	**str;
	int		i;

	if (!_new[0])
		return (free(_new), s);
	if (!s)
	{
		str = malloc(sizeof(char *) * 2);
		str[0] = ((str[1] = NULL), _new);
		return (str);
	}
	str = malloc(sizeof(char *) * (ft_strlen_double(s) + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = _new;
	str[i + 1] = NULL;
	return (free(s), str);
}

char	**ft_get_file_content(char *file_name)
{
	char	*s;
	char	**content;
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_error("Error\nPlease create a file called: ");
		ft_error(file_name);
		ft_error(" and try again\n");
		return (NULL);
	}
	s = get_next_line(fd);
	if (!s)
		return (NULL);
	content = (NULL);
	while (s)
	{
		content = ft_strjoin_double(content, s);
		s = get_next_line(fd);
	}
	close(fd);
	return (content);
}

void	ft_free_double(char **s)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

char	*ft_strdup_len(const char *s, int len)
{
	int		i;
	char	*str;

	if (!s || !s[0])
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}
