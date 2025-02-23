/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarvaj <ancarvaj@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 20:24:13 by ancarvaj          #+#    #+#             */
/*   Updated: 2025/02/10 14:49:26 by ancarvaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(const char	*s)
{
	int	i;

	if (!s || !s[0])
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
/*int	main()
{
	printf("%d", ft_strlen("hola"));
}*/
