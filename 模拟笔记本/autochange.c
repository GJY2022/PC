void autochange() //�Զ�����
{
    int flag = 1, i;
    double t1, t2;
    double s1, s2;
    double temp;
    double x1_t1;
    double x2_t1;
    double x3_t1;
    double x4_t1;
    //��������ǰ��https://github.com/404name/winter   ��ש����Ŀ¼������demo�ļ��ο�������ԭ��
    //����ġ��켣���Ǵ��ڡ�ѭ�����С��Ľṹ���е�
    //map����һ��ʼֻ��ӡһ�Σ������ԭ�����ϵĸı䲻��������ʾ��
    //��ʾ�켣����ʵ���Ǵ�ӡ�ո񣬵���ͬ������ɫ
    //��ȥ�켣Ҳ��ӡ��ɫ�Ŀո�SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 07);
    /*-------------------------------------------------------
                ���Ĺ�ʽ��   X = X0 + Vx * t + 1/2 * VX * t * t;
                             Y = Y0 + Vy * t;
                ����˼�룺  �����ѡ��ʱ����Ϊ�ƶ��ο�����ÿ�����ֵ����̫Զ
                            ����ʵ��������
                            �����ﷴ������������Ϊǰ�ᣬ�����ҳ�ÿ�ƶ�һ����λ
                            ��Ҫ����ʱ�䣬���������ҳ�һ�����������ߡ�

                �������⣺  c��������ֻ���������������ƶ�����ֻ�ܴ���ˮƽ����ֱ��
                            ���������˶�����ʵ����ĳ���ض��ĽǶ��ƶ�һ����λ��
                            ����Ҫ�ų��Ͻ����⣨����ӡ�����߶϶�������

                ���������  �����ƶ������ƶ���λ�ֽ⵽X��Y�ϡ�
                            �ֱ���� X ����һ����λ���� Ӧ�����ӵ� Y �ľ��� s1  <=> flag == 1
                                     Y ����һ����λ���� Ӧ�����ӵ� X �ľ��� s2  <=> flag == 2

                            ����ѡ����̵�min��s1,s2),Ȼ����flag��Ӧ��ͬ��ģʽ��Ϊ��һ���ƶ��Ļ�׼��
                            ���������ܱ�֤�߶ν���ֻ��ˮƽ����ֱ�����ƶ�ʱ�߶���������

                            ����ȷ���һ��б��Ϊ2��ֱ��
                            x����1 Y����2�㿴������Y�ѽ��˻�һ������Y���ƶ���2��
                            ��ʵ�������ǿ�
                            Y����1 Xʵ����ֻ����0.5.
                            ����һ�����ߣ�����΢Ԫ���ɵ�ֱ�߲���б�ʶ�ƫƧ������������ӡ��
                            �����Ϊʲôȡmin��s1,s2�������ƶ�ģʽ��ԭ��
                            �����ܱ�֤����ֻ�����ƶ�һ����λint��Y������int��X���ǲ����ӵģ������͵�X�ְ����ۼƵ���һ�����жϡ�

                ���ʵ�֣�
                            X��Y��double���棬��֤ʵ�ʵ�����������
                            ��ʵ�ʴ�ӡ���ǲ���˵��5,6.28�������ĸ���������c�����ϴ�ӡ���������ǲ���int���͵�old_x,old_y���н�X��Y�Ա��ڴ�ӡ����Ļ�ϡ�

                            ���ǰ���ʱ��Ϊѭ��ֻ������Ļ�ϴ�ӡһ���϶��������������ߵĵ㡣
                            �����ǰ�����һ��������λ����������������Ǿ��ܵõ�һ���������ߡ�

                ���ʵ�֣�  ���ڣ��㷨ƫ���Ͻ������ܻ����С���ֿ��ֶϽ�bug��������ѭ���Ƴ٣�������100%��������

                            ������Ϊ����

                            ������С��Χ��������������ӡ�����������ߣ�����
        ------------------------------------------------------------*/

    x1_t1 = (-Vx + sqrt(Vx * Vx + 20)) / 10;
    x2_t1 = (-Vx - sqrt(Vx * Vx + 20)) / 10;
    x3_t1 = (-Vx + sqrt(Vx * Vx - 20)) / 10;
    x4_t1 = (-Vx - sqrt(Vx * Vx - 20)) / 10;
    if (x1_t1 > 0 && x2_t1 > 0)
        t1 = x1_t1 < x2_t1 ? x1_t1 : x2_t1;
    else
        t1 = x1_t1 >= 0 ? x1_t1 : x2_t1;
    if (x3_t1 > 0 && x4_t1 > 0)
        temp = x3_t1 < x4_t1 ? x3_t1 : x4_t1;
    else if (x3_t1 * x4_t1 < 0)
        temp = x3_t1 >= 0 ? x3_t1 : x4_t1;
    else
        temp = 10;
    t1 = t1 < temp ? t1 : temp;
    s1 = t1 * Vy;
    //��Y2����һ����λ����ʱ
    t2 = 1.0 / fabs(Vy);
    s2 = Vx * t2 + 0.5 * g * t2 * t2;
    if ((int)s1 == 0)
        flag = 1;
    else if ((int)s2 == 0)
        flag = 2;
    else
        flag = s1 < s2 ? 1 : 2;

    //ѡ�����Ž��д���
    if (flag == 1)
    {
        X2 = X2 + Vx * t1 + 5 * t1 * t1;
        Y2 = Y2 + s1;
        Vx = Vx + g * t1;
    }
    else if (flag == 2)
    {
        Y2 = Y2 + Vy * t2;
        X2 = X2 + s2;
        Vx = Vx + g * t2;
    }
    /*else{
            for(  i = 0; i < 4; i++)
                �����ж϶Խ���ѡ��������ʽ�������ϸ����ͷע�ͣ�
            }
        } */
        //---------------------------------
    old_x2 = (int)X2;
    old_y2 = (int)Y2;

    //������ж���ײ
    if (map2[old_x2 + 1][old_y2] == wall && Vx >= 0 && map2[old_x2][old_y2 + 1] != wall && map2[old_x2][old_y2 - 1] != wall)
    {
        color = (color + 1) % 5;
        Vx = -Vx;
    }
    else if (map2[old_x2 - 1][old_y2] == wall && Vx <= 0 && map2[old_x2][old_y2 + 1] != wall && map2[old_x2][old_y2 - 1] != wall)
    {
        color = (color + 1) % 5;
        Vx = -Vx;
    }
    else if (map2[old_x2][old_y2 - 1] == wall && Vy <= 0 && map2[old_x2 - 1][old_y2] != wall && map2[old_x2 + 1][old_y2] != wall)
    {
        color = (color + 1) % 5;
        Vy = -Vy;
    }
    else if (map2[old_x2][old_y2 + 1] == wall && Vy >= 0 && map2[old_x2 - 1][old_y2] != wall && map2[old_x2 + 1][old_y2] != wall)
    {
        color = (color + 1) % 5;
        Vy = -Vy;
    }
    else if (map2[old_x2 + 1][old_y2 + 1] == wall && Vx > 0 && Vy > 0 || map2[old_x2 + 1][old_y2 - 1] == wall && Vx > 0 && Vy < 0 || map2[old_x2 - 1][old_y2 + 1] == wall && Vx < 0 && Vy > 0 || map2[old_x2 - 1][old_y2 - 1] == wall && Vx < 0 && Vy < 0)
    {
        color = (color + 1) % 5;
        Vy = -Vy;
        Vx = -Vx;
    }
    if (map2[old_x2 + 1][old_y2] == brick && Vx >= 0 && map2[old_x2][old_y2 + 1] != brick && map2[old_x2][old_y2 - 1] != brick)
    {
        //color = (color + 1) % 5;
        Vx = -Vx;
        map2[old_x2 + 1][old_y2] = air;
        gotoxy(old_y2, old_x2 + 1);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 07);
        printf(" ");
        goal++;
        gotoxy(5, 2);
        printf("goal:%5d", goal);
    }
    else if (map2[old_x2 - 1][old_y2] == brick && Vx <= 0 && map2[old_x2][old_y2 + 1] != brick && map2[old_x2][old_y2 - 1] != brick)
    {
        //color = (color + 1) % 5;
        Vx = -Vx;
        map2[old_x2 - 1][old_y2] = air;
        gotoxy(old_y2, old_x2 - 1);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 07);
        printf(" ");
        goal++;
        gotoxy(5, 2);
        printf("goal:%5d", goal);
    }
    else if (map2[old_x2][old_y2 - 1] == brick && Vy <= 0 && map2[old_x2 - 1][old_y2] != brick && map2[old_x2 + 1][old_y2] != brick)
    {
        //color = (color + 1) % 5;
        Vy = -Vy;
        map2[old_x2][old_y2 - 1] = air;
        gotoxy(old_y2 - 1, old_x2);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 07);
        printf(" ");
        goal++;
        gotoxy(5, 2);
        printf("goal:%5d", goal);
    }
    else if (map2[old_x2][old_y2 + 1] == brick && Vy >= 0 && map2[old_x2 - 1][old_y2] != brick && map2[old_x2 + 1][old_y2] != brick)
    {
        //color = (color + 1) % 5;
        Vy = -Vy;
        map2[old_x2][old_y2 + 1] = air;
        gotoxy(old_y2 + 1, old_x2);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 07);
        printf(" ");
        goal++;
        gotoxy(5, 2);
        printf("goal:%5d", goal);
    }
    else if (map2[old_x2 + 1][old_y2 + 1] == brick && Vx > 0 && Vy > 0 || map2[old_x2 + 1][old_y2 - 1] == brick && Vx > 0 && Vy < 0 || map2[old_x2 - 1][old_y2 + 1] == brick && Vx < 0 && Vy > 0 || map2[old_x2 - 1][old_y2 - 1] == brick && Vx < 0 && Vy < 0)
    {
        color = (color + 1) % 5; //�Խ����ı���ɫ��������
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 07);
        if (Vx > 0 && Vy > 0)
        {
            if (map2[old_x2 + 1][old_y2] == brick && map2[old_x2][old_y2 + 1] == brick)
            {
                map2[old_x2 + 1][old_y2] = air, gotoxy(old_y2, old_x2 + 1), printf(" ");
                map2[old_x2][old_y2 + 1] = air, gotoxy(old_y2 + 1, old_x2), printf(" ");
            }
            else
                map2[old_x2 + 1][old_y2 + 1] = air, gotoxy(old_y2 + 1, old_x2 + 1), printf(" ");
        }
        else if (Vx > 0 && Vy < 0)
        {
            if (map2[old_x2 + 1][old_y2] == brick && map2[old_x2][old_y2 - 1] == brick)
            {
                map2[old_x2 + 1][old_y2] = air, gotoxy(old_y2, old_x2 + 1), printf(" ");
                map2[old_x2][old_y2 - 1] = air, gotoxy(old_y2 - 1, old_x2), printf(" ");
            }
            else
                map2[old_x2 + 1][old_y2 - 1] = air, gotoxy(old_y2 - 1, old_x2 + 1), printf(" ");
        }
        else if (Vx < 0 && Vy > 0)
        {
            if (map2[old_x2 - 1][old_y2] == brick && map2[old_x2][old_y2 + 1] == brick)
            {
                map2[old_x2 - 1][old_y2] = air, gotoxy(old_y2, old_x2 - 1), printf(" ");
                map2[old_x2][old_y2 + 1] = air, gotoxy(old_y2 + 1, old_x2), printf(" ");
            }
            else
                map2[old_x2 - 1][old_y2 + 1] = air, gotoxy(old_y2 + 1, old_x2 - 1), printf(" ");
        }
        else if (Vx < 0 && Vy < 0)
        {
            if (map2[old_x2 - 1][old_y2] == brick && map2[old_x2][old_y2 - 1] == brick)
            {
                map2[old_x2 - 1][old_y2] = air, gotoxy(old_y2, old_x2 - 1), printf(" ");
                map2[old_x2][old_y2 - 1] = air, gotoxy(old_y2 - 1, old_x2), printf(" ");
            }
            else
                map2[old_x2 - 1][old_y2 - 1] = air, gotoxy(old_y2 - 1, old_x2 - 1), printf(" ");
        }
        Vx = -Vx;
        Vy = -Vy;
        goal++;
        gotoxy(5, 2);
        printf("goal:%5d", goal);
    }
    if (if_miss == 1)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 07);
        gotoxy(s[step2].y2, s[step2].x2);
        map2[s[step2].x2][s[step2].y2]--;
        if (map2[s[step2].x2][s[step2].y2] == air && !(s[step2].x2 == 0 && s[step2].y2 == 0)) //��ֹ�Լ����Լ�
            printf("%c", air);
    }
    s[step2].x2 = old_x2;
    s[step2].y2 = old_y2;
    if (map2[s[step2].x2][s[step2].y2] == food)
    {
        map2[s[step2].x2][s[step2].y2] = air;
        max2++;
    }
    switch (color)
    {
    case 0:
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 60);
        break; //��ɫ
    case 1:
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 70);
        break; //��ɫ
    case 2:
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 40);
        break; //��ɫ
    case 3:
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 30);
        break; //����ɫ
    case 4:
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 128);
        break; //��ɫ
    }
    gotoxy(s[step2].y2, s[step2].x2);
    if (map2[s[step2].x2][s[step2].y2] == brick)
    {
        map2[s[step2].x2][s[step2].y2] = air;
    }
    map2[s[step2].x2][s[step2].y2]++;
    if (debug == 0 && !(s[step2].x2 == 0 && s[step2].y2 == 0))
        printf("%c", air);
    else
        printf("%d", step2 % 10); //debugģʽ
    step2++;
    if (step2 >= max2)
    {
        if_miss = 1;
    }
    if (step2 >= max2)
    {
        cnt++;
    }
    step2 = step2 % max2;
    if (cnt > 2)
    {
        cnt = 0;
        color = (color + 1) % 5;
    }
    Sleep(150 - 2 * old_x2); //ģ����׹��ʱ���ٶȼӿ�--��Ӧ������¸���
    if (map[old_x2][old_y2] == wall)
    {
        Vx = -Vx;
        Vy = -Vy;
    }
    if (old_x2 == width2 - 1)
    {
        gotoxy(7 + 2 * life, 1);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 07);
        printf("  ");
        life--;
        if (life == 0)
            end_brick();
    }
}