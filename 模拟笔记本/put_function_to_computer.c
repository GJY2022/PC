void put_function_to_computer(int function)
{ //电脑处理相应共呢   1 ~ 返回    2 ~删除     3确认   4shift  5上 6左 7下 8又  9开机
    int ncx, ncy;
    char ch;
    if (function == 9)
    { //开机
        system("color 70");
        if (if_start == 0)
        {
            if_input_password = 1;
            init_start();
            if_start = 1;
        }
        else
        {
            if (if_game == 2)
                system("color 07");
            end();
            if_start = 0;
            if_into_desktop = 0;
            if_input = 0;
        }
    }
    if (function == 2 && put_in_num > 0 && if_input == 1)
    { //删除字符，但不可越界
        put_in_num--;
        put_in_computer[put_in_num] = '\0';
        if (if_input_password == 1)
        {
            gotoxy(input_y + put_in_num, input_x);
            printf(" ");
        }
        else
        {
            gotoxy(input_y, input_x);
            printf("%s", put_in_computer);
            printf(" ");
        }
    }
    if (function == 4)
    { //切换大小写
        if (if_shift)
            if_shift = 0;
        else
            if_shift = 1;
    }
    if (function == 3 && if_input == 1 && if_game == 0)
    { //确认对应不同模式下的不同功能
        if (strcmp(password_0, put_in_computer) == 0)
        {
            if_input_password = 0;
            load_desktop();
            if_input = 0;
            put_in_num = 0;
            put_in_computer[put_in_num] = '\0';
        }
        else
        {
            put_in_num = 0;
            put_in_computer[put_in_num] = '\0';
            gotoxy(input_y, input_x);
            printf("密 码 错 误 ！！！");
            gotoxy(input_y, input_x);
            Sleep(1200);
            printf("                  ");
            gotoxy(input_y, input_x);
            printf("|");
        }
    }
    else if (function == 3 && if_game == 1 && put_in_num == 1 && put_in_computer[0] >= '1' && put_in_computer[0] <= '9')
    {
        int i, j;
        if_into_desktop = 0;
        gotoxy(mid_y - 16, mid_x);
        printf("                                               ");
        init_game(put_in_computer[0] - '0');
        move_hnt(left, mid, right, 'a', 'b', 'c', put_in_computer[0] - '0');
        getch();
        getch();
        getch();
        for (i = 0; i <= width; i++)
        {
            for (j = 0; j <= len; j++)
            {
                game_map[i][j] = 0;
            }
        }
        if_game = 0;
        if_input = 0;
        load_desktop();
        if_into_desktop = 1;
        put_in_num = 0;
        put_in_computer[0] = '\0';
    }
    //if(if_game == 1 && function >= 5 && function <= 8))     移动类型游戏暂未开放  (3.19更新可用了)
    else if (if_game == 2 && function >= 5 && function <= 8)
    {
        //5上 6左 7下 8又
        ch = 'a';
        switch (function)
        {
        case 5:
            ch = 'w';
            break;
        case 6:
            ch = 'a';
            break;
        case 7:
            ch = 's';
            break;
        case 8:
            ch = 'd';
            break;
        }
        manchange(ch);
        return;
    }
    else if (function == 3 && if_into_desktop)
    {
        if (computer_map[cx][cy] == 1) //1  - 汉诺塔  2 - 打砖块
        {
            load_game();
            if_game = 1;
        }
        else if (computer_map[cx][cy] == 2) //打砖块
        {
            if_into_desktop = 0;
            init_brick();
            if_game = 2;
            system("color 07");
        }
        else if (computer_map[cx][cy] == 3)
        { //（我的电脑）
            my_computer();
        }
        else if (computer_map[cx][cy] == 4) // 更多信息
        {
            load_more();
            getch();
            getch();
            getch();
            load_desktop();
        }
        else if (computer_map[cx][cy] == 5)
        { //浏览器（因为不支持，所以使用就蓝屏（滑稽））
            blue_screen();
        }
    }
    if (if_into_desktop && function >= 5 && function <= 8)
    {
        ncx = cx + next[function][0], ncy = cy + next[function][1];
        if (computer_map[ncx][ncy])
        {
            gotoxy(tcy, tcx);
            printf("  ");
            cx = ncx, cy = ncy;
            tcx = computer_map_place[computer_map[cx][cy]][0];
            tcy = computer_map_place[computer_map[cx][cy]][1];
            lcx = cx, lcy = cy;
            gotoxy(tcy, tcx);
            printf("[]");
        }
    }
    if (function == 1 && if_into_desktop)
    { //返回
        load_desktop();
    }
}