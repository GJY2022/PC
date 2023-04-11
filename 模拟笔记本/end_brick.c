void end_brick()
{
    char temp;
    int i, j;
    int flag = max2;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 07);

    while (flag != 0)
    {
        if (step2 < 0)
            step2 += max2;
        gotoxy(s[step2].y2, s[step2].x2);
        map2[s[step2].x2][s[step2].y2]--;
        if (map2[s[step2].x2][s[step2].y2] == air && !(s[step2].x2 == 0 && s[step2].y2 == 0)) //防止自己吃自己
            printf("%c", air);
        s[step2].x2 = 0;
        s[step2].y2 = 0;
        step2--;
        flag--;
        Sleep(100);
    }
    for (i = 0; i <= 14; i++)
    {
        gotoxy(45, 1 + i);
        printf("%s\n", End[i]);
        Sleep(100);
    }
    temp = getch();
    system("color 70");
    if_game = 0;
    if_input = 0;
    load_desktop();
    if_into_desktop = 1;
}