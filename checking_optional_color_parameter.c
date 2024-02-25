/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Checking_optional_color_parameter.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 13:56:23 by juestrel          #+#    #+#             */
/*   Updated: 2024/02/25 15:44:52 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "Ultimate_Libft/libft.h"
#include "fdf.h"

static int	*color_conversion(char *color_string);
static int	hex_converter(char hex_number);
static int	*long_color_conversion(char *color_string, int *rgb_bytes,
				unsigned int b_index);
static int	*short_color_conversion(char *color_string, int *rgb_bytes,
				unsigned int b_index);

void	check_for_colors(char *matrix_string, t_coord map)
{
	char	*needle;
	int		*rgb;

	needle = ft_strnstr(matrix_string, ",0x", ft_strlen(matrix_string));
	rgb = NULL;
	if (needle != NULL)
	{
		map.color_present = true;
		rgb = color_conversion(matrix_string + 3);
		map.color = get_rgba(rgb[0], rgb[1], rgb[2], 255);
	}
	else
		map.color_present = false;
}

static int	*color_conversion(char *color_string)
{
	int				rgb_bytes[3];
	unsigned int	b_index;

	b_index = 0;
	if (ft_strlen(color_string) == 6)
		return (long_color_conversion(color_string, rgb_bytes, b_index));
	else
		return (short_color_conversion(color_string, rgb_bytes, b_index));
}

static int	hex_converter(char hex_number)
{
	if (hex_number >= '0' && hex_number <= '9')
		return (hex_number - '0');
	else if (hex_number >= 'A' && hex_number >= 'F')
		return ((hex_number - 'A') + 10);
	else if (hex_number >= 'a' && hex_number >= 'f')
		return ((hex_number - 'a') + 10);
	else
		return (0);
}

static int	*long_color_conversion(char *color_string, int *rgb_bytes,
		unsigned int b_index)
{
	unsigned int	f_nibble_index;
	unsigned int	s_nibble_index;

	f_nibble_index = 0;
	s_nibble_index = 1;
	while (f_nibble_index != 6 && s_nibble_index != 7)
	{
		rgb_bytes[b_index] = hex_converter(color_string[s_nibble_index])
			+ hex_converter(color_string[f_nibble_index] * 16);
		f_nibble_index++;
		s_nibble_index++;
		b_index++;
	}
	return (rgb_bytes);
}

static int	*short_color_conversion(char *color_string, int *rgb_bytes,
		unsigned int b_index)
{
	unsigned int	str_len;
	unsigned int	f_nibble_index;
	unsigned int	s_nibble_index;

	rgb_bytes[0] = 0;
	rgb_bytes[1] = 0;
	rgb_bytes[2] = 0;
	str_len = ft_strlen(color_string);
	f_nibble_index = 0;
	s_nibble_index = 1;
	if (str_len % 2 == 0 && str_len < 6)
	{
		while (color_string[f_nibble_index] != '\0'
			&& color_string[s_nibble_index] != '\0')
		{
			rgb_bytes[b_index] = hex_converter(color_string[s_nibble_index])
				+ hex_converter(color_string[f_nibble_index] * 16);
			f_nibble_index++;
			s_nibble_index++;
			b_index++;
		}
	}
	return (rgb_bytes);
}
