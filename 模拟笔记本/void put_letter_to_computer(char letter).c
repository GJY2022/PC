//-----------------------------------------------------------------------------打砖块/-----------------------------------------------------------------------------

void put_letter_to_computer(char letter)
{ //把字符传输给电脑屏幕，如果电脑if_input为零就禁止显示
    int i;
    if (if_input == 1 && put_in_num < input_max)
    {
        put_in_computer[put_in_num] = letter;
        put_in_num++;
        put_in_computer[put_in_num] = '\0';
    }
    gotoxy(input_y, input_x);
    if (if_input_password == 1)
        for (i = 0; i < put_in_num; i++)
        {
            if (i < put_in_num - 1)
            {
                printf("*");
            }
            else
                printf("%c", put_in_computer[i]);
        }
    else
        printf("%s", put_in_computer);
}