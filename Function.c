//
//  Keyboard.c
//  _
//
// Created by 方杨 on 2023/5/28.
//

#include "Student_control.h"

//getch()函数用来获取键盘输入，不以回车结束且没有回显。适用于Linux。Windows下请改用conio.h
char getch()
{
    char c;
    system("stty -echo");  //不回显
    system("stty -icanon");//设置一次性读完操作，如使用getchar()读操作，不需要按enter
    c=getchar();
    system("stty icanon");//取消上面的设置
    system("stty echo");//回显
    return c;
}

//大小比较函数，在qsort（排序函数）中使用
int compare(const void *a, const void *b)
{
    int *pa = *(int **)a;
    int *pb = *(int **)b;
    return pa[0] - pb[0];
}

//按任意键返回主菜单
void AnyKeyToReturn()
{
    printf("按任意键返回主菜单\n");
    while (getchar() != '\n');
    getch();
}