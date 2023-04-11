void init()
{
    int i, j, k; //初始化整个程序
    char ch;
    HideCursor(); //决定是否开启光标隐藏
    cx = 1, cy = 1;
    lcx = cx, lcy = cy;
    mid_x = 7, mid_y = 60;
    tcx = computer_map_place[computer_map[cx][cy]][0], tcy = computer_map_place[computer_map[cx][cy]][1];
    flag = 0, function, if_shift = 0, if_start = 0, if_input_password = 0, if_into_desktop = 0, if_game = 0;
    put_in_num = 0, if_input = 0;
    system("mode con cols=125 lines=60");
    printf("【程序信息】：\n");
    printf("        程序名称：模拟笔记本电脑\n");
    printf("        程序作者：404name\n");
    printf("        完成时间：2020.2.01\n");
    printf("        最后更新：2020.4.07\n");
    printf("        项目地址：https://github.com/404name/winter （有问题可以去联系我）\n\n");
    printf("【更新记录】（2020）\n");
    printf("        3.10 修复bug：不同平台显示乱码\n");
    printf("        3.15 修复bug：关机仍能输入密码\n");
    printf("        3.15 优化体验：加入光标隐藏（关闭前往init函数第一行）\n");
    printf("        3.19 完善功能：加入可移动游戏简洁版，可自制地图，方法前往源程序my_map数组处查看\n");
    printf("        4.07 完善功能：（桌面软件全部更新，功能完善，更加贴近xp系统。）\n");
    printf("            ·密码输入优化，输入的密码会在下一次输入变成不可视。\n");
    printf("            ·优化打砖块对角碰撞算法，更加真实。\n");
    printf("            ·新增“此电脑”可查看电脑配置.\n");
    printf("            ·新增关机画面。\n");
    printf("            ·加入蓝屏，更加快乐（点击浏览器触发）\n");
    printf("            ·优化更多细节.\n\n");
    printf("【程序补充】\n");
    printf("        ·这里差不多把坑填完了，之前反应的要有能操控的游戏，输入密码可见不真实，关机画面没模拟等等\n");
    printf("        ·都弄完了，至于网上冲浪，打lol，写编译器就有生之年吧。对了，因此我还特意加入了蓝屏（滑稽）。\n\n");
    printf("【程序说明】\n");
    printf("        ·有问题，有bug，不兼容，欢迎去git反馈交流\n");
    printf("        ·操作方法：↑ ↓ ← → 空格 控制光标即可。\n");
    printf("        ·进入程序电源键处按一次空格||输入密码WHJY即可登录||请在虚拟键盘上开启大写再输入||\n");
    printf("        ·欢迎使用XP模拟笔记本电脑！\n");
    printf("            1.按两下回车进入（未能解决bug:移动时周围可能会有蓝色的闪频）\n");
    printf("            2.按1再按回车进入 （开启清除闪频，但光标背景变成透明，不好鉴别）\n");
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