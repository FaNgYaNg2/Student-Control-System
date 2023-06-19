//
//  manu.c
//  _
//
// Created by 方杨 on 2023/5/28.
//

#include "Student_control.h"

void Init() {
    Student_present = 0;
    Select_present = 0;
    Lesson_present = 0;
    head = (Lesson *) malloc(sizeof(Lesson));
    head->next = NULL;
}

void manu() { //主菜单
    system("clear"); //清屏，linux下，windows下为system("cls")；
    printf("1.学生信息管理\n");
    printf("2.课程信息管理\n");
    printf("3.选课信息管理\n");
    printf("4.成绩管理\n");
    printf("5.查询\n");
    printf("6.退出\n");
    printf("请输入你的选择：");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            Student_information_manu();
            break;
        case 2:
            Lesson_information_manu();
            break;
        case 3:
            Select_information_manu();
            break;
        case 4:
            Score_management_manu();
            break;
        case 5:
            Search_manu();
            break;
        case 6:
            printf("感谢使用，再见！\n");
            exit(0);
            break;
        default:
            printf("输入错误，请重新输入\n");
            manu();
            break;
    }
}

void Student_information_manu() { //学生信息管理菜单
    system("clear"); //清屏，linux下，windows下为system("cls")；
    printf("1.添加学生信息\n");
    printf("2.删除学生信息\n");
    printf("3.修改学生信息\n");
    printf("4.显示所有学生信息\n");
    printf("5.按学号排序所有学生信息\n");
    printf("6.返回上一级\n");
    printf("请输入你的选择：");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            Add_student_manu();
            break;
        case 2:
            Delete_student_manu();
            break;
        case 3:
            Change_student_manu();
            break;
        case 4:
            Show_student_information();
            break;
        case 5:
            Sort_student_information();
            break;
        case 6:
            manu();
            break;
        default:
            printf("输入错误，请重新输入\n");
            Student_information_manu();
            break;
    }
}

void Add_student_manu() { //添加学生信息菜单
    system("clear"); //清屏，linux下，windows下为system("cls")；
    printf("输入学生信息按照以下顺序：学号；姓名；性别(F/M)；地址\n输入-1来结束输入\n输入-2从文件./Data/Student.txt输入\n");
    Add_student_information();
    manu();
}

void Delete_student_manu() { //删除学生信息菜单
    system("clear"); //清屏，linux下，windows下为system("cls")；
    printf("请输入要删除的学生的学号\n输入0返回上一级\n");
    int ID;
    scanf("%d", &ID);
    if (ID == 0) {
        Student_information_manu();
    } else {
        Delete_student_information(ID);
        manu();
    }
}

void Change_student_manu() { //修改学生信息菜单
    system("clear"); //清屏，linux下，windows下为system("cls")；
    printf("请输入要修改的学生的学号\n然后给出修改后的完整信息。(包括ID)\n输入0返回上一级\n");
    int ID;
    scanf("%d", &ID);
    if (ID == 0) {
        Student_information_manu();
    } else {
        Change_student_information(ID);
        manu();
    }
}

void Lesson_information_manu() { //课程信息管理菜单
    system("clear"); //清屏，linux下，windows下为system("cls")；
    printf("1.添加课程信息\n");
    printf("2.删除课程信息\n");
    printf("3.修改课程信息\n");
    printf("4.显示所有课程信息\n");
    printf("5.按课号排序所有课程信息\n");
    printf("6.返回上一级\n");
    printf("请输入你的选择：");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            Add_lesson_manu();
            break;
        case 2:
            Delete_lesson_manu();
            break;
        case 3:
            Change_lesson_manu();
            break;
        case 4:
            Show_lesson_information();
            break;
        case 5:
            Sort_lesson_information();
            break;
        case 6:
            manu();
            break;
        default:
            printf("输入错误，请重新输入\n");
            Lesson_information_manu();
            break;
    }
}

void Add_lesson_manu() { //添加课程信息菜单
    system("clear"); //清屏，linux下，windows下为system("cls")；
    printf("输入课程信息按照以下顺序：课号；课程名；学分；学时\n输入-1来结束输入数据\n输入-2来从文件./Data/Lesson.txt读取(仅支持在没有数据时)\n");
    if (head->next == NULL)
        head = Create_lesson_information();
    else
        Add_lesson_information();
    manu();
}

void Delete_lesson_manu() { //删除课程信息菜单
    system("clear"); //清屏，linux下，windows下为system("cls")；
    printf("请输入要删除的课程的课号\n输入0返回上一级\n");
    int ID;
    scanf("%d", &ID);
    if (ID == 0) {
        Lesson_information_manu();
    } else {
        Delete_lesson_information(ID);
        manu();
    }
}

void Change_lesson_manu() { //修改课程信息菜单
    system("clear"); //清屏，linux下，windows下为system("cls")；
    printf("请输入要修改的课程的课号\n然后给出修改后的完整信息。(包括ID)\n输入0返回上一级\n");
    int ID;
    scanf("%d", &ID);
    if (ID == 0) {
        Lesson_information_manu();
    } else {
        Change_lesson_information(ID);
        manu();
    }
}

void Select_information_manu() { //选课信息管理菜单
    system("clear"); //清屏，linux下，windows下为system("cls")；
    printf("1.添加选课信息\n");
    printf("2.按学号删除选课信息\n");
    printf("3.按课号删除选课信息\n");
    printf("4.按学号查看选课信息\n");
    printf("5.按课号查看选课信息\n");
    printf("6.显示所有选课信息\n");
    printf("7.返回上一级\n");
    printf("请输入你的选择：");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            Add_Select_manu();
            break;
        case 2:
            Delete_Select_manu(0);
            break;
        case 3:
            Delete_Select_manu(1);
            break;
        case 4:
            Search_Select_manu(0);
            break;
        case 5:
            Search_Select_manu(1);
            break;
        case 6:
            Search_Select_information(-617, 2);
            break;
        case 7:
            manu();
            break;
        default:
            printf("输入错误，请重新输入\n");
            Select_information_manu();
            break;
    }
}

void Add_Select_manu() { //添加选课信息菜单
    system("clear"); //清屏，linux下，windows下为system("cls")；
    printf("输入选课信息按照以下顺序：学号；姓名；课号；课名;学期\n输入-1来结束输入数据\n输入-2从文件./Data/Select.txt读取数据\n");
    Add_Select_information();
    manu();
}

void Delete_Select_manu(int Kind) { //删除选课信息菜单
    system("clear"); //清屏，linux下，windows下为system("cls")；
    if (Kind == 0) {
        printf("请输入要删除的学生的学号\n输入0返回上一级\n");
    } else if (Kind == 1) {
        printf("请输入要删除的课程的课号\n输入0返回上一级\n");
    }
    int ID;
    scanf("%d", &ID);
    if (ID == 0) {
        Select_information_manu();
    } else {
        Delete_Select_information(ID, Kind);
        manu();
    }
}

void Search_Select_manu(int Kind) { //查看选课信息菜单
    system("clear"); //清屏，linux下，windows下为system("cls")；
    if (Kind == 0) {
        printf("请输入要查看的学生的学号\n输入0返回上一级\n");
    } else if (Kind == 1) {
        printf("请输入要查看的课程的课号\n输入0返回上一级\n");
    }
    int ID;
    scanf("%d", &ID);
    if (ID == 0) {
        Select_information_manu();
    } else {
        Search_Select_information(ID, Kind);
        manu();
    }
}

void Score_management_manu() { //成绩管理菜单
    system("clear"); //清屏，linux下，windows下为system("cls")；
    printf("1.添加成绩\n");
    printf("2.删除成绩\n");
    printf("3.修改成绩\n");
    printf("4.返回上一级\n");
    printf("请输入你的选择：");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            Add_score_manu();
            break;
        case 2:
            Delete_score_manu();
            break;
        case 3:
            Change_score_manu();
            break;
        case 4:
            manu();
            break;
        default:
            printf("输入错误，请重新输入\n");
            Score_management_manu();
            break;
    }
}

void Add_score_manu() { //添加成绩菜单
    system("clear"); //清屏，linux下，windows下为system("cls")；
    printf("输入成绩信息按照以下顺序：学号；姓名；课号; 学期；成绩\n输入-1来结束输入数据\n输入-2来从文件./Data/Score.txt读取数据\n");
    Add_score_information();
    manu();
}

void Delete_score_manu() { //删除成绩菜单
    system("clear"); //清屏，linux下，windows下为system("cls")；
    printf("请输入要删除成绩的学生的学号和课程的课程号\n输入0返回上一级\n");
    int StudentID, LessonID;
    scanf("%d", &StudentID);
    if (StudentID == 0) {
        Score_management_manu();
    } else {
        scanf("%d", &LessonID);
        Delete_score_information(StudentID, LessonID);
        manu();
    }
}

void Change_score_manu() { //修改成绩菜单
    system("clear"); //清屏，linux下，windows下为system("cls")；
    printf("请输入要修改成绩的学生的学号和课程号\n然后给出修改后的成绩。\n输入0返回上一级\n");
    int StudentID, LessonID;
    scanf("%d", &StudentID);
    if (StudentID == 0) {
        Score_management_manu();
    } else {
        scanf("%d", &LessonID);
        Change_score_information(StudentID, LessonID);
        manu();
    }
}

void Search_manu() { //查询菜单
    system("clear"); //清屏，linux下，windows下为system("cls")；
    printf("注意：选课查询请前往主菜单功能三\n");
    printf("1.学生信息查询\n");
    printf("2.课程信息查询\n");
    printf("3.成绩查询\n");
    printf("4.返回上一级\n");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            Search_student_manu();
            break;
        case 2:
            Search_lesson_manu();
            break;
        case 3:
            Search_score_manu();
            break;
        case 4:
            manu();
            break;
        default:
            printf("输入错误，请重新输入\n");
            Search_manu();
            break;
    }
}

void Search_student_manu() { //学生信息查询菜单
    system("clear"); //清屏，linux下，windows下为system("cls")；
    printf("1.按学号查询\n");
    printf("2.按姓名查询\n");
    printf("3.按地址查询\n");
    printf("4.返回上一级\n");
    int choice;
    Searching Input;
    scanf("%d", &choice);
    system("clear"); //清屏，linux下，windows下为system("cls")；
    switch (choice) {
        case 1:
            system("clear"); //清屏，linux下，windows下为system("cls")；
            printf("请输入学号\n");
            scanf("%d", &Input.StudentID);
            Search_student_information(&Input, 0);
            break;
        case 2:
            system("clear"); //清屏，linux下，windows下为system("cls")；
            printf("请输入姓名\n");
            scanf("%s", Input.StudentName);
            Search_student_information(&Input, 1);
            break;
        case 3:
            system("clear"); //清屏，linux下，windows下为system("cls")；
            printf("请输入地址\n");
            scanf("%s", Input.Adress);
            Search_student_information(&Input, 2);
            break;
        case 4:
            manu();
            break;
        default:
            printf("输入错误，请重新输入\n");
            Search_manu();
            break;
    }
}

void Search_lesson_manu() { //课程信息查询菜单
    system("clear"); //清屏，linux下，windows下为system("cls")；
    printf("1.按课号查询\n");
    printf("2.按课名查询\n");
    printf("3.返回上一级\n");
    int choice;
    Searching Input;
    scanf("%d", &choice);
    system("clear"); //清屏，linux下，windows下为system("cls")；
    switch (choice) {
        case 1:
            system("clear"); //清屏，linux下，windows下为system("cls")；
            printf("请输入课号\n");
            scanf("%d", &Input.LessonID);
            Search_lesson_information(&Input, 0);
            break;
        case 2:
            system("clear"); //清屏，linux下，windows下为system("cls")；
            printf("请输入课名\n");
            scanf("%s", Input.LessonName);
            Search_lesson_information(&Input, 1);
            break;
        case 3:
            manu();
            break;
        default:
            printf("输入错误，请重新输入\n");
            Search_manu();
            break;
    }
}

void Search_score_manu() { //成绩查询菜单
    system("clear"); //清屏，linux下，windows下为system("cls")；
    printf("1.按学号查询\n");
    printf("2.按课号查询\n");
    printf("3.返回上一级\n");
    int choice;
    Searching Input;
    scanf("%d", &choice);
    system("clear"); //清屏，linux下，windows下为system("cls")；
    switch (choice) {
        case 1:
            system("clear"); //清屏，linux下，windows下为system("cls")；
            printf("请输入学号\n");
            scanf("%d", &Input.StudentID);
            Search_score_information(&Input, 0);
            manu();
            break;
        case 2:
            system("clear"); //清屏，linux下，windows下为system("cls")；
            printf("请输入课号\n");
            scanf("%d", &Input.LessonID);
            Search_score_information(&Input, 1);
            manu();
            break;
        case 3:
            manu();
            break;
        default:
            printf("输入错误，请重新输入\n");
            Search_manu();
            break;
    }
}