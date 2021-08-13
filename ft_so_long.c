#include "ft_so_long.h"

// 기능: 맵 이름이 .ber로 끝나는 지 확인, 리턴: .ber이면 1, 아니면 0
int	check_map_name(char *argv)
{
	int len;

	len = ft_strlen(argv);
	if (argv[len - 1] != 'r')
		return (0);
	if (argv[len - 2] != 'e')
		return (0);
	if (argv[len - 3] != 'b')
		return (0);
	if (argv[len - 4] != '.')
		return (0);
	len = len - 4;
	while (len--)
	{
		if (argv[len] == '.')
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;
	
	if (argc != 2 || !check_map_name(*(++argv)))
		error_msg();
	printf("good");
	return (0);
}

/* 
TODO
1. 맵 파싱
2. 맵에 따라 그리기
3. 캐릭터 움직임
4. 벽 안 움직임 (노 스왑)
5. 아이템 먹기 
6. 탈출하기 (아이템 다 먹었을 경우)
 */
