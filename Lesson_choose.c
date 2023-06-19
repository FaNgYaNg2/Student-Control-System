//
//  Lesson_choose.c
//  _
//
// Created by 方杨 on 2023/5/28.
//

#include "Student_control.h"

void Add_Select_information() { //添加选课信息
    int i = 0;
    while (1) {
        int StudentID_input, LessonID_input, flag = 0;
        char Name_input[50];
        Lesson *p = head;
        scanf("%d", &StudentID_input);
        if (StudentID_input == -1)
            break;
        if (StudentID_input == -2) {
            FILE *fp;
            fp = fopen("Data/Select.txt", "r");
            if (fp == NULL) {
                printf("文件打开失败\n");
                sleep(2);
                return;
            }
            while (fscanf(fp, "%d %s %d %s %d", &Sel[i].StudentID,Sel[i].StudentName,&Sel[i].LessonID,Sel[i].LessonName,&Sel[i].Term) != EOF) {
                i++;
                Select_present++;
            }
            fclose(fp);
            return;
        }
        for (int j = 0; j < Student_present; j++) {
            if (Stu[j].ID == StudentID_input) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) { //通过flag判定输入的选课的学生学号是否在库
            printf("该学号不存在,无法输入\n");
            sleep(1);
            break;
        }
        scanf("%s", Name_input);
        scanf("%d", &LessonID_input);
        flag = 0;
        while (p != NULL) {
            if (p->ID == LessonID_input) {
                flag = 1;
                break;
            }
            p = p->next;
        }
        if (flag == 0) {
            printf("该课程号不存在,无法输入\n");
            break;
        } //课程号在库则可以输入
        scanf("%s %d", Sel[i].LessonName, &Sel[i].Term);
        Sel[i].Score = -1;
        Sel[i].StudentID = StudentID_input;
        strcpy(Sel[i].StudentName, Name_input);
        Sel[i].LessonID = LessonID_input;
        Select_present++;
        i++;
    }
}

void Delete_Select_information(int ID, int Kind) {
    int flag = 0; //通过flag判定是否有删除行为
    for (int i = 0; i < Select_present; i++) {
        if (Kind == 1) { //按学号删除选课信息
            if (Sel[i].StudentID == ID) {
                flag = 1;
                for (int j = i; j < Select_present - 1; j++) {
                    Sel[j] = Sel[j + 1];
                }
                Select_present--;
            }
        } else if (Kind == 2) { //按课号删除选课信息
            if (Sel[i].LessonID == ID) {
                flag = 1;
                for (int j = i; j < Select_present - 1; j++) {
                    Sel[j] = Sel[j + 1];
                }
                Select_present--;
            }
        }
    }
    if (flag == 0) {
        printf("该学号或课程号不存在\n");
        sleep(2);
    } else {
        printf("删除成功\n");
        sleep(2);
    }
}

void Search_Select_information(int ID, int Kind) {
    int flag = 0;
    printf("若成绩为-1，则表示该科目成绩尚未录入。\n");
    setlocale(LC_ALL, ""); // 设置本地化环境，以支持中文字符输出
    wprintf(L"学号\t姓名\t课程号\t课程名\t\t\t学期\t成绩\n");
    if (Kind == 2) { //显示所有选课信息
        flag = 1;
        for (int i = 0; i < Select_present; i++) {
            wprintf(L"%d\t%s\t%d\t%-20s\t%d\t%d\n", Sel[i].StudentID, Sel[i].StudentName, Sel[i].LessonID,
                    Sel[i].LessonName,
                    Sel[i].Term, Sel[i].Score);
        }
    } else {
        for (int i = 0; i < Select_present; i++) {
            if (Kind == 0) { //按学号查询选课信息
                if (Sel[i].StudentID == ID) {
                    flag = 1;
                    wprintf(L"%d\t%s\t%d\t%-20s\t%d\t%d\n", Sel[i].StudentID, Sel[i].StudentName, Sel[i].LessonID,
                            Sel[i].LessonName, Sel[i].Term, Sel[i].Score);
                }
            } else if (Kind == 1) { //按课号查询选课信息
                if (Sel[i].LessonID == ID) {
                    flag = 1;
                    wprintf(L"%d\t%s\t%d\t%-20s\t%d\t%d\n", Sel[i].StudentID, Sel[i].StudentName, Sel[i].LessonID,
                            Sel[i].LessonName, Sel[i].Term, Sel[i].Score);
                }
            }
        }
    }
    if (flag == 0) {
        printf("该学号或课程号不存在\n");
    }
    AnyKeyToReturn();
    manu();
}

