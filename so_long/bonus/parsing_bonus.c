/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 11:47:14 by daekim            #+#    #+#             */
/*   Updated: 2021/10/10 21:41:13 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	get_newline(char *argv, t_map *map_info)
{
	int		ret;
	char	buf;
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (-1);
	map_info->row = 0;
	ret = read(fd, &buf, 1);
	while (ret > 0)
	{
		if (buf == '\n')
			map_info->row++;
		ret = read(fd, &buf, 1);
	}
	close(fd);
	if (ret == -1)
		return (ret);
	return (map_info->row);
}

char	**map_parser(t_map *map_info, char *argv, int fd)
{
	int		idx;
	int		ret;

	map_info->row = get_newline(argv, map_info);
	if (map_info->row == -1)
		print_error(2);
	map_info->map = (char **)ft_calloc(map_info->row + 1, sizeof(char *));
	if (!map_info->map)
		return (NULL);
	idx = -1;
	ret = get_next_line(fd, &(map_info->map[++idx]));
	map_info->col = ft_strlen(map_info->map[idx]);
	while (ret)
	{
		ret = get_next_line(fd, &(map_info->map[++idx]));
		map_info->temp_col = ft_strlen(map_info->map[idx]);
		if (idx == map_info->row - 1)
			break ;
		if (map_info->col != map_info->temp_col)
			return (NULL);
	}
	if (ret == -1)
		return (NULL);
	return (map_info->map);
}

void	info_init(t_info *info)
{
	info->map.walk = 0;
	info->map.way = 13;
	info->map.c = 2;
	info->map.v_f = -1;
	info->map.v_d = 0;
	info->map.v_x = -1;
	info->map.v_y = -1;
}

void	parsing(t_info *info, char *argv)
{
	int		check;
	int		fd;

	info_init(info);
	check = check_extention(argv);
	if (check == -1)
		print_error(1);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		print_error(2);
	info->map.map = map_parser(&info->map, argv, fd);
	close(fd);
	if (!info->map.map)
		print_error(3);
	check = check_map_valid(&info->map);
	if (check == -1)
		print_error(4);
	check = check_comp_valid(&info->map);
	if (check == -1)
		print_error(5);
}
