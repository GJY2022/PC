int move()
{ //控制虚拟键盘的指针移动函数
    int i, k, flag = 1;
    char ch, ch1, ch2;
    while (ch != ' ')
    {
        ch = getch();
        if (if_game == 2 && ch != ' ')
            flag = 0;
        if (ch != 'w' && ch != 'a' && ch != 's' && ch != 'd' && ch != -32 && ch != ' ')
            continue;
        lx = x, ly = y;
        if (ch == -32)
        { //同时启用wasd  和上下左右键   //如果读取到第一个是-32那么 继续读取一个字符
            ch1 = getch();
            switch (ch1)
            {
            case 72:
                ch = 'w';
                break;
            case 75:
                ch = 'a';
                break;
            case 80:
                ch = 's';
                break;
            case 77:
                ch = 'd';
                break;
            }
        }
        if (if_game != 2)
            system("color 70");
        else
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 07);
        gotoxy(0, tx);
        printf("%s", map[tx]);
        switch (ch)
        {
        case 'a':
            y = y - 1;
            break;
        case 'd':
            y = y + 1;
            break;
        case 'w':
            x = x - 1;
            break;
        case 's':
            x = x + 1;
            break;
        case ' ':
            break;
        }
        if (keyboard[x][y] == 0)
        {
            x = lx;
            y = ly;
        }
        num = board_place[keyboard[x][y]][2];
        tx = board_place[keyboard[x][y]][3];
        ty = board_place[keyboard[x][y]][4];
        gotoxy(ty, tx);
        for (i = 0; i < num; i++)
        {
            if (qpz == 1)
            {
                printf(" ");
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 57);
                printf("%c", temp[i]);
            }
        }
        if (if_game == 2)
            break;
    }
    if (if_game != 2)
        system("color 70");
    if (if_game == 2 && ch == ' ')
        ch = ' ';
    if (board_place[keyboard[x][y]][0] == 0 || flag == 0)
        return 0;
    else if (board_place[keyboard[x][y]][0] >= 1 && board_place[keyboard[x][y]][0] <= 9)
    {
        function = board_place[keyboard[x][y]][0];
        /*gotoxy(0,41);
        printf("%d",board_place[ keyboard[x][y] ][0]);*/
        return 2;
    }
    else
    {
        letter = if_shift ? board_place[keyboard[x][y]][1] : board_place[keyboard[x][y]][0];
        /*gotoxy(0,41);
        printf("%c",board_place[ keyboard[x][y] ][0]);*/
        return 1;
    }
}