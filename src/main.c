/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:44:36 by juestrel          #+#    #+#             */
/*   Updated: 2024/03/18 14:24:01 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MLX42/include/MLX42/MLX42.h"
#include "../libft/libft.h"
#include "fdf.h"

/*void	ft_leaks(void)
{
	system("leaks -q fdf");
}

	atexit(ft_leaks);*/

static bool			ft_parse_url(char *url);
static unsigned int	get_width(t_coord **coord);

int	main(int argc, char *argv[])
{
	t_coord		**coord;
	t_map_data	*map_data;

	coord = NULL;
	if (argc != 2)
		print_error_msg(INVALID_ARGC);
	if (ft_parse_url(argv[1]) == false)
		print_error_msg(INVALID_FILE_EXTENSION);
	map_data = (t_map_data *)malloc(sizeof(t_map_data));
	if (map_data == NULL)
	{
		free(map_data);
		print_error_msg(MALLOC_ERROR);
	}
	map_data->height = load_matrix(argv[1], &map_data, &coord);
	map_data->map = coord;
	map_data->width = get_width(map_data->map);
	input_to_screen(&map_data);
	return (0);
}

static bool	ft_parse_url(char *url)
{
	const char	*extension;

	extension = ft_strrchr(url, '.');
	if (extension == NULL || ft_strncmp(extension, ".fdf", 4) != 0
		|| extension[4] != '\0')
		return (false);
	return (true);
}

static unsigned int	get_width(t_coord **coord)
{
	unsigned int	x;

	x = 0;
	while (coord[0][x].end_of_row != true)
		x++;
	return (x + 1);
}
