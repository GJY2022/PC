void init()
{
    int i, j, k; //��ʼ����������
    char ch;
    HideCursor(); //�����Ƿ����������
    cx = 1, cy = 1;
    lcx = cx, lcy = cy;
    mid_x = 7, mid_y = 60;
    tcx = computer_map_place[computer_map[cx][cy]][0], tcy = computer_map_place[computer_map[cx][cy]][1];
    flag = 0, function, if_shift = 0, if_start = 0, if_input_password = 0, if_into_desktop = 0, if_game = 0;
    put_in_num = 0, if_input = 0;
    system("mode con cols=125 lines=60");
    printf("��������Ϣ����\n");
    printf("        �������ƣ�ģ��ʼǱ�����\n");
    printf("        �������ߣ�404name\n");
    printf("        ���ʱ�䣺2020.2.01\n");
    printf("        �����£�2020.4.07\n");
    printf("        ��Ŀ��ַ��https://github.com/404name/winter �����������ȥ��ϵ�ң�\n\n");
    printf("�����¼�¼����2020��\n");
    printf("        3.10 �޸�bug����ͬƽ̨��ʾ����\n");
    printf("        3.15 �޸�bug���ػ�������������\n");
    printf("        3.15 �Ż����飺���������أ��ر�ǰ��init������һ�У�\n");
    printf("        3.19 ���ƹ��ܣ�������ƶ���Ϸ���棬�����Ƶ�ͼ������ǰ��Դ����my_map���鴦�鿴\n");
    printf("        4.07 ���ƹ��ܣ����������ȫ�����£��������ƣ���������xpϵͳ����\n");
    printf("            �����������Ż�����������������һ�������ɲ����ӡ�\n");
    printf("            ���Ż���ש��Խ���ײ�㷨��������ʵ��\n");
    printf("            ���������˵��ԡ��ɲ鿴��������.\n");
    printf("            �������ػ����档\n");
    printf("            ���������������ӿ��֣���������������\n");
    printf("            ���Ż�����ϸ��.\n\n");
    printf("�����򲹳䡿\n");
    printf("        ��������ѿ������ˣ�֮ǰ��Ӧ��Ҫ���ܲٿص���Ϸ����������ɼ�����ʵ���ػ�����ûģ��ȵ�\n");
    printf("        ����Ū���ˣ��������ϳ��ˣ���lol��д������������֮��ɡ����ˣ�����һ������������������������\n\n");
    printf("������˵����\n");
    printf("        �������⣬��bug�������ݣ���ӭȥgit��������\n");
    printf("        �������������� �� �� �� �ո� ���ƹ�꼴�ɡ�\n");
    printf("        ����������Դ������һ�οո�||��������WHJY���ɵ�¼||������������Ͽ�����д������||\n");
    printf("        ����ӭʹ��XPģ��ʼǱ����ԣ�\n");
    printf("            1.�����»س����루δ�ܽ��bug:�ƶ�ʱ��Χ���ܻ�����ɫ����Ƶ��\n");
    printf("            2.��1�ٰ��س����� �����������Ƶ������걳�����͸�������ü���\n");
    ch = getchar();
    getchar();
    if (ch == '1')
        qpz = 1;
    else
        qpz = 0;
    gotoxy(0, 0);
    system("color 70");
    for (i = 0; i <= 40; i++)
    {
        printf("%s\n", map[i]);
        Sleep(50);
    }
    x = 1, y = 20, num = board_place[keyboard[x][y]][2];
    tx = board_place[keyboard[x][y]][3];
    ty = board_place[keyboard[x][y]][4];
    gotoxy(ty, tx);
    //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),02);
    for (i = 0; i < num; i++)
    {
        printf("%c", temp[i]);
    }
}