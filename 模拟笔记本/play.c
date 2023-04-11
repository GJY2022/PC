void play(int x, int y)
{ //显示汉诺塔移动轨迹
    int turn_0, n = 0, i, j, k, tx, ty, flag = 0;
    if ((x == mid && y == right) || (x == left && y == mid) || (x == left && y == right))
        turn_0 = 0; //往右
    else if ((x == mid && y == left) || (x == right && y == left) || (x == right && y == mid))
        turn_0 = 1; //往左
    for (i = 1, j = y; i <= width; i++)
    { //目的地
        if (game_map[i][j] != 0)
        {
            tx = i - 1;
            ty = j;
            break;
        }
    }
    for (i = 1, j = x; i <= width; i++)
    { //出发点
        if (game_map[i][j] != 0)
        {
            break;
        }
    }
    while (1)
    {
        while ((i != 1 || j != x) && (i != 1 || j != y) && (i != tx || j != ty))
        {
            if (turn_0 == 0)
                for (k = mid - 3; k >= 0; k--)
                {
                    game_map[i + game_next[turn[turn_0][n]][0]][j + game_next[turn[turn_0][n]][1] + k] = game_map[i][j + k];
                    game_map[i][j + k] = 0;
                }
            else
                for (k = 0; k < mid - 2; k++)
                {
                    game_map[i + game_next[turn[turn_0][n]][0]][j + game_next[turn[turn_0][n]][1] + k] = game_map[i][j + k];
                    game_map[i][j + k] = 0;
                }
            gotoxy(j + tty, i + ttx);
            Sleep(time);
            for (k = 0; k < mid - 2; k++)
            {
                printf(" ");
            }
            i = i + game_next[turn[turn_0][n]][0];
            j = j + game_next[turn[turn_0][n]][1];
            gotoxy(j + tty, i + ttx);
            Sleep(time);
            for (k = 0; k < mid - 2; k++)
            {
                printf("%c", game_map[i][j + k]);
            }
        }
        n++; //改变方向;
        if (i == tx && j == ty)
            return;
        if (turn_0 == 0)
            for (k = mid - 3; k >= 0; k--)
            {
                game_map[i + game_next[turn[turn_0][n]][0]][j + game_next[turn[turn_0][n]][1] + k] = game_map[i][j + k];
                game_map[i][j + k] = 0;
            }
        else
            for (k = 0; k < mid - 2; k++)
            {
                game_map[i + game_next[turn[turn_0][n]][0]][j + game_next[turn[turn_0][n]][1] + k] = game_map[i][j + k];
                game_map[i][j + k] = 0;
            }
        gotoxy(j + tty, i + ttx);
        for (k = 0; k < mid - 2; k++)
        {
            printf(" ");
        }
        Sleep(time);
        i = i + game_next[turn[turn_0][n]][0];
        j = j + game_next[turn[turn_0][n]][1];
        gotoxy(j + tty, i + ttx);
        for (k = 0; k < mid - 2; k++)
            printf("%c", game_map[i][j + k]);
        Sleep(time);
    }
}