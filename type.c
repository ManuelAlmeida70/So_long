/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalmeid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:41:26 by maalmeid          #+#    #+#             */
/*   Updated: 2024/08/31 21:20:11 by maalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_check_file_extension(const char *file_name)
{
	char	*file_extension;

	file_extension = ft_strchr(file_name, '.');
	if (file_extension != NULL)
		return ((file_extension));
	return (NULL);
}

void	ft_type(const char *file_name, const char *extension)
{
	const char	*file_extension;

	file_extension = ft_check_file_extension(file_name);
	if (file_extension && ft_strcmp(file_name, extension) == 0)
	{
		ft_printf("Error\na extensao do mapa nao e .ber\n");
		exit(1);
	}
}

void	ft_extension(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	i--;
	if (!(s[i] == 'r' && s[i - 1] == 'e'
			&& s[i - 2] == 'b' && s[i - 3] == '.'
			&& s[i + 1] == '\0'))
	{
		ft_printf("Errror\na extensao do mapa nao e .ber\n");
		exit(1);
	}
}
