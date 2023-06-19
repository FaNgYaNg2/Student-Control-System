//
//  Student_information.c
//  _
//
// Created by 方杨 on 2023/5/28.
//

#include "Student_control.h"

void Add_student_information() { //添加学生信息，使用结构体数组
    int i = Student_present;
    while (1) {
        int ID_input, flag = 0;
        scanf("%d", &ID_input);
        if (ID_input == -1)
            break;
        if (ID_input == -2) {
            //从同目录下的Data文件夹中的Student.txt中读取学生信息
            FILE *fp;
            fp = fopen("Data/Student.txt", "r");
            if (fp == NULL) {
                printf("文件打开失败\n");
                sleep(2);
                return;
            }
            while (fscanf(fp, "%d %s %c %s", &Stu[i].ID, Stu[i].Name, &Stu[i].Gender, Stu[i].Adress) != EOF) {
                Student_present++;
                i++;
            }
            fclose(fp);
            return;
        }
        for (int j = 0; j < Student_present; j++) {
            if (Stu[j].ID == ID_input) {
                printf("该学号已存在,无法输入\n");
                sleep(1);
                flag = 1;
                break;
            }
        }
        if (flag == 1)
            break;
        else {
            Stu[i].ID = ID_input;
            scanf("%s %c %s", Stu[i].Name, &Stu[i].Gender, Stu[i].Adress);
            Student_present++;
        }
        i++;
    }
}

void Delete_student_information(int ID) { //删除学生信息
    int flag = 0;
    for (int i = 0; i < Student_present; i++) {
        if (Stu[i].ID == ID) {
            flag = 1;
            for (int j = i; j < Student_present - 1; j++) {
                Stu[j] = Stu[j + 1];
            }
            Student_present--;
            break;
        }
    }
    if (flag == 0) {
        printf("该学号不存在\n");
        sleep(2);
    } else {
        printf("删除成功\n");
        sleep(2);
    }
}

void Change_student_information(int ID) { //修改学生信息
    int flag = 0;
    for (int i = 0; i < Student_present; i++) {
        if (Stu[i].ID == ID) {
            flag = 1;
            scanf("%d %s %c %s", &Stu[i].ID, Stu[i].Name, &Stu[i].Gender, Stu[i].Adress);
            break;
        }
    }
    if (flag == 0) {
        printf("该学号不存在\n");
        sleep(2);
    } else {
        printf("修改成功\n");
        sleep(2);
    }
}

void Show_student_information() { //显示学生信息
    printf("学号\t姓名\t性别\t住址\n");
    for (int i = 0; i < Student_present; i++) {
        printf("%d\t%s\t%c\t%s\n", Stu[i].ID, Stu[i].Name, Stu[i].Gender, Stu[i].Adress);
    }
    AnyKeyToReturn();
    manu();
}

void Sort_student_information() { //排序学生信息
    for (int i = 0; i < Student_present; i++) {
        for (int j = 0; j < Student_present - i - 1; j++) {
            if (Stu[j].ID > Stu[j + 1].ID) {
                Student temp = Stu[j];
                Stu[j] = Stu[j + 1];
                Stu[j + 1] = temp;
            }
        }
    }
    printf("排序成功\n");
    sleep(2);
    manu();
}