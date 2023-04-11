void manchange(char ch) //人为输入更新
{
    if (ch == 'a' || ch == 's' || ch == 'd' || ch == 'w' || ch == ' ' || ch == 'p' || ch == 'b') //目前只开放aswd
    {
        if (ch == 'a' && map2[width2 - 1][left2 - 1] != wall)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 07);
            left2--;
            gotoxy(left2, width2 - 1);
            map2[width2 - 1][left2] = wall;
            printf("%c", wall);

            gotoxy(right2, width2 - 1);
            map2[width2 - 1][right2] = air;
            printf(" ");
            right2--;
        }
        else if (ch == 'd' && map2[width2 - 1][right2 + 1] != wall)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 07);
            right2++;
            gotoxy(right2, width2 - 1);
            map2[width2 - 1][right2] = wall;
            printf("%c", wall);
            gotoxy(left2, width2 - 1);
            map2[width2 - 1][left2] = air;
            printf(" ");
            left2++;
        }
        else if (ch == 'p')
        {
            /*gotoxy(2, width2 + 5);
            printf("游戏暂停，按'p'继续游戏");
            ch2 = getch();
            while (ch2 != 'p')
            {
                ch2 = getch();
            }
            gotoxy(2, width2 + 5);
            printf("                        ");*/
        }
        else if (ch == 'b')
        {
            init_brick();
        }
    }
    //function = move(&temp_x2,&temp_y2,0,width2,0,length2,1,1,ch);
    //function = move(&menu_x,&menu_y,18,24,68,68,2,0,ch);
}