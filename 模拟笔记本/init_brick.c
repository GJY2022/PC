//----------------------------------------------------------------------------打砖块/-----------------------------------------------------------------------------
void init_brick()
{
    int l, r, i, j, a, b;
    cnt = 0;
    HideCursor();

    width2 = 16, length2 = 124;
    wall = '#', food = '*', air = ' ', brick = 'O';
    head2 = 0, tail2 = 0, max2 = 20, step2 = 0, if_miss = 0, food_num = 400, goal = 0, color = 0;
    debug = 0, life = 3;                                                         //debug模式调成1手动开启
    temp_x2 = 2, temp_y2 = 2, menu_x = 18, menu_y = 68, left2 = 25, right2 = 35; //临时坐标
    gotoxy(0, 0);
    memset(s, 0, sizeof(s));
    r = length2;
    l = 0;
    if (if_my_map == 0)
    {
        for (i = 0; i <= width2; i++)
        { //生成地图模板
            for (j = 0; j <= length2; j++)
            {
                if (i == 0 || i == width2)
                    map2[i][j] = wall;
                else if (j <= l || j >= r)
                    map2[i][j] = wall;
                else if ((i == width2 * 2 / 3) && (j >= length2 * 2 / 5 && j <= length2 * 3 / 5))
                    map2[i][j] = wall;
                else if (i == width2 - 1 && j >= left2 && j <= right2)
                    map2[i][j] = wall;
                else
                    map2[i][j] = air;
            }
            l++;
            r--;
        }
        if (if_load_snake_mod == 1)
        {
            food_num = 400;
            while (food_num--)
            { //贪吃蛇生成食物
                a = rand() % width2;
                b = rand() % length2;
                if ((a >= width2 / 3 && a <= width2 * 2 / 3) && (b >= length2 * 2 / 5 && b <= length2 * 3 / 5) || a == 0 || b == 0)
                    continue;
                map2[a][b] = food;
            }
        }
        for (i = 0; i <= width2; i++)
        { //布置砖块brick
            for (j = 0; j <= length2; j++)
            {
                if (((i >= width2 * 2 / 3 && i <= width2 * 2 / 3 + 1) && (j >= 0 && j <= length2 / 5)) || ((i >= width2 * 2 / 3 && i <= width2 * 2 / 3 + 1) && (j >= length2 * 4 / 5 && j <= length2)))
                    map2[i][j] = brick;
                if ((i >= width2 / 3 && i <= width2 / 3 + 1) && ((j >= length2 / 10 && j <= length2 * 7 / 20) || (j >= length2 * 17 / 20 && j <= length2 * 9 / 10)))
                    map2[i][j] = brick;
            }
        }
    }
    else
    {
        for (i = 0; i <= width2; i++)
        {
            strcpy(map2[i], my_map[i]);
        }
    }
    r = length2;
    l = 0;
    gotoxy(0, 0);
    for (i = 0; i <= width2; i++)
    { //打印地图
        for (j = 0; j <= length2; j++)
        {
            if (j >= l && j <= r)
            {
                gotoxy(j, i);
                if (i == width2)
                    printf("!");
                else
                    printf("%c", map2[i][j]);
            }
        }
        l++;
        r--;
        Sleep(50);
        printf("\n");
    }
    //构建初始位置以及速度和方向角度
    X2 = width2 - 6;
    Y2 = rand() % 5 + 23;
    old_x2 = (int)X2;
    old_y2 = (int)Y2;
    s[step2].x2 = old_x2;
    s[step2].y2 = old_y2;
    V = 15;
    Vx = -V * sin(C[3] * pi / 180.0); //速度向右向下为正方向
    Vy = V * cos(C[3] * pi / 180.0);
    gotoxy(4, 1);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 07);
    printf("life:");
    for (i = 0; i < life; i++)
        printf("■");
}
