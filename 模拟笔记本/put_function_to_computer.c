void put_function_to_computer(int function)
{ //���Դ�����Ӧ����   1 ~ ����    2 ~ɾ��     3ȷ��   4shift  5�� 6�� 7�� 8��  9����
    int ncx, ncy;
    char ch;
    if (function == 9)
    { //����
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
    { //ɾ���ַ���������Խ��
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
    { //�л���Сд
        if (if_shift)
            if_shift = 0;
        else
            if_shift = 1;
    }
    if (function == 3 && if_input == 1 && if_game == 0)
    { //ȷ�϶�Ӧ��ͬģʽ�µĲ�ͬ����
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
            printf("�� �� �� �� ������");
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
    //if(if_game == 1 && function >= 5 && function <= 8))     �ƶ�������Ϸ��δ����  (3.19���¿�����)
    else if (if_game == 2 && function >= 5 && function <= 8)
    {
        //5�� 6�� 7�� 8��
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
        if (computer_map[cx][cy] == 1) //1  - ��ŵ��  2 - ��ש��
        {
            load_game();
            if_game = 1;
        }
        else if (computer_map[cx][cy] == 2) //��ש��
        {
            if_into_desktop = 0;
            init_brick();
            if_game = 2;
            system("color 07");
        }
        else if (computer_map[cx][cy] == 3)
        { //���ҵĵ��ԣ�
            my_computer();
        }
        else if (computer_map[cx][cy] == 4) // ������Ϣ
        {
            load_more();
            getch();
            getch();
            getch();
            load_desktop();
        }
        else if (computer_map[cx][cy] == 5)
        { //���������Ϊ��֧�֣�����ʹ�þ���������������
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
    { //����
        load_desktop();
    }
}