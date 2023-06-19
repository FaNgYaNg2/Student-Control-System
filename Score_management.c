//
//  Score_management.c
//  _
//
// Created by 方杨 on 2023/5/28.
//

#include "Student_control.h"

void Add_score_information() { //添加选课信息，使用结构体数组
    int i = 0;
    while (1) {
        int StudentID_input, LessonID_input, flag = 0;
        char Name_input[50];
        scanf("%d", &StudentID_input);
        if (StudentID_input == -1)
            break;
        if(StudentID_input==-2){
            FILE *fp;
            fp=fopen("Data/Score.txt","r");
            if(fp==NULL){
                printf("文件打开失败\n");
                sleep(2);
                return;
            }
            while(fscanf(fp,"%d %s %d %d %d",&Sel[i].StudentID,Sel[i].StudentName,&Sel[i].LessonID,&Sel[i].Term,&Sel[i].Score)!=EOF){
                i++;
                Select_present++;
            }
            fclose(fp);
            return;
        }
        for (int j = 0; j < Select_present; j++) {
            if (Sel[j].StudentID == StudentID_input) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            printf("该学号不存在,无法输入\n");
            sleep(1);
            break;
        }
        scanf("%s", Name_input);
        scanf("%d", &LessonID_input);
        flag = 0;
        for (int j = 0; j < Select_present; j++) {
            if (Sel[j].LessonID == LessonID_input) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            printf("该课程号不存在,无法输入\n");
            break;
        }
        scanf("%d", &Sel[i].Term);
        scanf("%d", &Sel[i].Score);
        i++;
    }
}

void Delete_score_information(int StudentID, int LessonID) { //删除选课信息
    int flag = 0;
    for (int j = 0; j < Student_present; j++) {
        if (Sel[j].StudentID == StudentID && Sel[j].LessonID == LessonID) {
            Sel[j].Score = -1;
            flag = 1;
            printf("删除成功！\n");
            break;
        }
    }
    if (flag == 0) {
        printf("不存在,无法删除\n");
    }
    sleep(2);
}

void Change_score_information(int StudentID, int LessonID) { //修改选课信息
    int flag = 0;
    for (int j = 0; j < Student_present; j++) {
        if (Sel[j].StudentID == StudentID && Sel[j].LessonID == LessonID) {
            scanf("%d",&Sel[j].Score);
            flag = 1;
            printf("修改成功！\n");
            break;
        }
    }
    if (flag == 0) {
        printf("不存在,无法删除\n");
    }
    sleep(2);
}
