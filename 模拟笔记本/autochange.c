void autochange() //自动更新
{
    int flag = 1, i;
    double t1, t2;
    double s1, s2;
    double temp;
    double x1_t1;
    double x2_t1;
    double x3_t1;
    double x4_t1;
    //更具体请前往https://github.com/404name/winter   打砖块子目录下下载demo文件参考抛物线原理
    //这里的“轨迹”是存在“循环队列”的结构体中的
    //map数组一开始只打印一次，随后在原数组上的改变不会作用显示。
    //显示轨迹的其实还是打印空格，但不同的是颜色
    //消去轨迹也打印白色的空格：SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 07);
    /*-------------------------------------------------------
                核心公式：   X = X0 + Vx * t + 1/2 * VX * t * t;
                             Y = Y0 + Vy * t;
                核心思想：  ·如果选择时间作为移动参考，则每秒会出现点相差太远
                            难以实现连续。
                            ·这里反过来，以连续为前提，尝试找出每移动一个单位
                            需要多少时间，则能依次找出一个连续的曲线。

                出现问题：  c语言数组只能是整数，所以移动方向只能存在水平和竖直，
                            不能依照运动方向实现往某个特定的角度移动一个单位。
                            并且要排除断节问题（即打印的曲线断断续续）

                解决方法：  把特移动方向移动单位分解到X，Y上。
                            分别算出 X 增加一个单位长度 应该增加的 Y 的距离 s1  <=> flag == 1
                                     Y 增加一个单位长度 应该增加的 X 的距离 s2  <=> flag == 2

                            优先选择更短的min（s1,s2),然后以flag对应不同的模式作为下一次移动的基准。
                            这样操作能保证线段仅仅只在水平与竖直方向移动时线段仍能连续

                            打个比方：一段斜率为2的直线
                            x增加1 Y增加2你看，这里Y脱节了会一下子在Y上移动了2格。
                            但实际上我们看
                            Y增加1 X实际上只增加0.5.
                            所以一段曲线，他的微元构成的直线不管斜率多偏僻，都能连续打印。
                            这就是为什么取min（s1,s2）决定移动模式的原因。
                            这样能保证仅仅只在上移动一个单位int（Y），而int（X）是不增加的，浮点型的X又把量累计到下一次在判断。

                最后实现：
                            X，Y用double储存，保证实际叠加能连续；
                            而实际打印，是不能说（5,6.28）这样的浮点型能在c语言上打印，所以我们采用int整型的old_x,old_y来承接X，Y以便于打印在屏幕上。

                            我们按照时间为循环只能在屏幕上打印一串断断续续的类抛物线的点。
                            但我们按照走一个“方向单位”，依次类叠，我们就能得到一串连续的线。

                结果实现：  由于，算法偏向不严谨，可能会出现小部分开局断节bug，但随着循环推迟，后期能100%连续！！

                            加入人为修正

                            经测试小范围的数据能完美打印出物理抛物线！！！
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
    //当Y2增加一个单位方向时
    t2 = 1.0 / fabs(Vy);
    s2 = Vx * t2 + 0.5 * g * t2 * t2;
    if ((int)s1 == 0)
        flag = 1;
    else if ((int)s2 == 0)
        flag = 2;
    else
        flag = s1 < s2 ? 1 : 2;

    //选择最优进行处理
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
                放弃判断对角了选择其他方式解决（详细见开头注释）
            }
        } */
        //---------------------------------
    old_x2 = (int)X2;
    old_y2 = (int)Y2;

    //常规的判断碰撞
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
        color = (color + 1) % 5; //对角碰改变颜色方便区分
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
        if (map2[s[step2].x2][s[step2].y2] == air && !(s[step2].x2 == 0 && s[step2].y2 == 0)) //防止自己吃自己
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
        break; //蓝色
    case 1:
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 70);
        break; //红色
    case 2:
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 40);
        break; //绿色
    case 3:
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 30);
        break; //深蓝色
    case 4:
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 128);
        break; //紫色
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
        printf("%d", step2 % 10); //debug模式
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
    Sleep(150 - 2 * old_x2); //模拟下坠的时候速度加快--对应画面更新更快
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