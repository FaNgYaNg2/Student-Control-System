//
//  Search.c
//  _
//
// Created by 方杨 on 2023/5/28.
//
#include "Student_control.h"

void Search_student_information(Searching *a, int Kind) { //搜索学生信息，通过共用体a传入搜索信息，Kind为0时为按学号查询，为1时为按姓名查询，为2时为按住址查询
    printf("学号\t姓名\t性别\t住址\n");
    if (Kind == 0) {
        for (int i = 0; i < Student_present; i++) {
            if (Stu[i].ID == a->StudentID) {
                printf("%d\t%s\t%c\t%s\n", Stu[i].ID, Stu[i].Name, Stu[i].Gender, Stu[i].Adress);
            }
        }
    } else if (Kind == 1) {
        for (int i = 0; i < Student_present; i++) {
            if (strcmp(Stu[i].Name, a->StudentName) == 0) {
                printf("%d\t%s\t%c\t%s\n", Stu[i].ID, Stu[i].Name, Stu[i].Gender, Stu[i].Adress);
            }
        }
    } else if (Kind == 2) {
        for (int i = 0; i < Student_present; i++) {
            if (strcmp(Stu[i].Adress, a->Adress) == 0) {
                printf("%d\t%s\t%c\t%s\n", Stu[i].ID, Stu[i].Name, Stu[i].Gender, Stu[i].Adress);
            }
        }
    }
    AnyKeyToReturn();
    manu();
}

void Search_lesson_information(Searching *a, int Kind) { //搜索课程信息，通过共用体a传入搜索信息，Kind为0时为按课程号查询，为1时为按课程名查询
    Lesson *p;
    p = head;
    setlocale(LC_ALL, ""); // 设置本地化环境，支持中文字符输出
    wprintf(L"课程号\t课程名\t\t\t\t学分\t学时\n");
    while (p->next != NULL) {
        if (Kind == 0 && p->next->ID == a->LessonID) {
            wprintf(L"%d\t%-20s\t%d\t%d\n", p->next->ID, p->next->Name, p->next->Credit, p->next->Time);
        } else if (Kind == 1 && strcmp(p->next->Name, a->LessonName) == 0) {
            wprintf(L"%d\t%-20s\t%d\t%d\n", p->next->ID, p->next->Name, p->next->Credit, p->next->Time);
        }
        p = p->next;
    }
    AnyKeyToReturn();
    manu();
}

void Search_score_information(Searching *a, int Kind) { //搜索成绩信息，通过共用体a传入搜索信息，Kind为0时为按学号查询，为1时为按课程号查询
    int p = 0, score[MAXLESSON][2], *tmp[MAXLESSON], term_now;
    printf("请输入要查询的学期\n");
    scanf("%d", &term_now);
    if (Kind == 0) {
        for (int j = 0; j < Select_present; j++) {
            if (Sel[j].StudentID == a->StudentID && Sel[j].Score != -1 && Sel[j].Term == term_now) {
                score[p][0] = Sel[j].Score;
                score[p][1] = j;
                p++;
            }
        }
    } else {
        for (int j = 0; j < Select_present; j++) {
            if (Sel[j].LessonID == a->LessonID && Sel[j].Score != -1 && Sel[j].Term == term_now) {
                score[p][0] = Sel[j].Score;
                score[p][1] = j;
                p++;
            }
        }
    }
    for (int i = 0; i < p; i++) {
        tmp[i] = score[i];
    }
    qsort(tmp, p, sizeof(int *), compare);
    setlocale(LC_ALL, ""); // 设置本地化环境
    wprintf(L"学号\t姓名\t课程号\t课程名\t\t\t\t学期\t成绩\n");
    for (int i = 0; i < p; i++) {
        int j = tmp[i][1];
        wprintf(L"%d\t%s\t%d\t%-20s\t%d\t%d\n", Sel[j].StudentID, Sel[j].StudentName, Sel[j].LessonID,
                Sel[j].LessonName,
                Sel[j].Term, Sel[j].Score);
    }
    AnyKeyToReturn();
}
