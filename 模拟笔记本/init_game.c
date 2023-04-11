void init_game(int n)
{ //初始化汉诺塔
    int i, j;
    mid_x = 7, mid_y = 60;
    ttx = 10, tty = 10;
    time = 50 / n;
    left = 1, mid = 2 * (n + 1), right = mid + 2 * n + 1;
    len = 3 * (2 * n + 1);
    width = n + 1;
    ttx = mid_x - width / 2;
    tty = mid_y - len / 2;

    for (i = 0; i <= width; i++)
    {
        for (j = 0, num = i; j <= len; j++)
        {
            if (i == 0 || j == 0 || i == width || j == len)
                game_map[i][j] = '';
            if ((i > 1 && i < width) && (j == mid - 1 || j == right - 1))
                game_map[i][j] = '|';
            if (num && (i >= 1 && i <= width - 1) && j % 2 != 0 && j < mid)
            {
                game_map[i][j] = -95;
                game_map[i][j + 1] = -10; //打印 ■  ■占2个字节可以拆开来
                num--;
            }
        }
    }
    //容易出现东西卡顿
    for (i = 0; i <= width; i++)
    {
        gotoxy(tty, ttx + i);
        for (j = 0; j <= len; j++)
            printf("%c", game_map[i][j]);
        printf("\n");
    }
}