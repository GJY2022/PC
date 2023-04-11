void move_hnt(int a, int b, int c, char aa, char bb, char cc, int n)
{ //正常的汉诺塔递归程序
    if (n == 1)
    {
        //printf("from %c to %c",aa,cc);
        play(a, c);
        return;
    }
    move_hnt(a, c, b, aa, cc, bb, n - 1);
    /*	gotoxy(0,width+1);
    printf("from %c to %c",aa,cc);*/
    play(a, c);
    move_hnt(b, a, c, bb, aa, cc, n - 1);
}