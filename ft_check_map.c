#include "ft_so_long.h"

// 기능: 맵이 직사각형인지 확인, 리턴: void
void	check_rectangle(char **map)
{
	int	len;

	len = ft_strlen(*map);
	while (*map != NULL)
	{
		if (len != ft_strlen(*map))
			error_msg();
		map++;
	}
}

static void	check_wall2(char **map, int len, int i)
{
	int	j;

	j = 0;
	while (j < len)
	{
		if (map[j][0] != '1') // 직사각형 왼쪽 부분 1인지 확인
			error_msg();
		if (map[j][i - 1] != '1') // 직사각형 오른쪽 부분 1인지 확인
			error_msg();
		j++;
	}
}

// 기능: 맵이 1로 둘러싸여 있는지 확인, 리턴: void
void	check_wall(char **map)
{
	int		len;
	char	**tmp;
	int		i;
	int		j;

	tmp = map;
	len = 0;
	i = 0;
	j = 0;
	while (*tmp != NULL)
	{
		tmp++;
		len++; // 직사각형 세로 길이
	}
	while (map[0][i] != '\0')
	{
		if (map[0][i] != '1') // 직사각형 윗부분 1인지 확인
			error_msg();
		if (map[len - 1][i] != '1') // 직사각형 아래부분 1인지 확인
			error_msg();
		i++;
	}
	check_wall2(map, len, i);
}

// 기능: 0,1,P,C,E 이외의 요소가 있는지 확인, 리턴: void
void	check_other_element(char **map)
{
	int i;

	while (*map != NULL)
	{
		i = 0;
		while ((*map)[i] != '\0')
		{
			if (!((*map)[i] == '0' || (*map)[i] == '1' || (*map)[i] == 'E'
				|| (*map)[i] == 'C' || (*map)[i] == 'P'))
				error_msg();
			i++;
		}
		map++;
	}
}

// 기능: P,C,E 요소가 1개 이상 존재하는지 확인, 리턴: void
void	check_element(char **map)
{
	int element[3];
	int i;

	i = 0;
	while (i <= 2)
		element[i++] = 0;
	while (*map != NULL)
	{
		i = 0;
		while ((*map)[i] != '\0')
		{
			if ((*map)[i] == 'P')
				element[0] += 1;
			else if ((*map)[i] == 'C')
				element[1] += 1;
			else if ((*map)[i] == 'E')
				element[2] += 1;
			i++;
		}
		map++;
	}
	i = 0;
	while (i <= 2)
		if (element[i++] < 1 || element[0] > 1)
			error_msg();	
}