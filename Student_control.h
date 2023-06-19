//
// Created by 方杨 on 2023/5/28.
//

#ifndef __STUDENT_CONTROL_H
#define __STUDENT_CONTROL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <wchar.h>
#include <locale.h>


typedef struct student { //学生信息
    int ID;
    char Name[50];
    char Gender;
    char Adress[50];
} Student;
typedef struct lesson { //课程信息
    int ID;
    char Name[50];
    int Credit;
    int Time;
    struct lesson *next;
} Lesson;
typedef struct Select { //选课信息
    int StudentID;
    char StudentName[50];
    int LessonID;
    char LessonName[50];
    int Term;
    int Score;
} Select;
typedef union Searching { //搜索信息
    int StudentID, LessonID;
    char StudentName[50], LessonName[50], Adress[50];
} Searching;

void Init(); //初始化学生信息数组、课程信息链表、选课信息数组

void manu(); //主菜单

void Student_information_manu(); //学生信息菜单
void Add_student_manu(); //添加学生信息菜单
void Delete_student_manu(); //删除学生信息菜单
void Change_student_manu(); //修改学生信息菜单

void Lesson_information_manu(); //课程信息菜单
void Add_lesson_manu(); //添加课程信息菜单
void Delete_lesson_manu(); //删除课程信息菜单
void Change_lesson_manu(); //修改课程信息菜单

void Select_information_manu(); //选课信息菜单
void Add_Select_manu(); //添加选课信息菜单
void Delete_Select_manu(int Kind); //删除选课信息菜单,Kind为0时为按学号删除，为1时为按课程号删除
void Search_Select_manu(int Kind); //查询选课信息菜单,Kind为0时为按学号查询，为1时为按课程号查询

void Score_management_manu(); //成绩管理菜单
void Add_score_manu(); //添加成绩菜单
void Delete_score_manu(); //删除成绩菜单
void Change_score_manu(); //修改成绩菜单

void Search_manu(); //查询菜单
void Search_student_manu(); //查询学生信息菜单
void Search_lesson_manu(); //查询课程信息菜单
void Search_score_manu();  //查询成绩信息菜单

void Add_student_information(); //添加学生信息
void Delete_student_information(int ID); //删除学生信息,按学号删除
void Change_student_information(int ID); //修改学生信息,按学号修改
void Show_student_information(); //显示学生信息
void Sort_student_information(); //排序学生信息

Lesson *Create_lesson_information(); //创建课程信息链表
void Add_lesson_information(); //添加课程信息
void Delete_lesson_information(int ID); //删除课程信息,按课程号删除
void Change_lesson_information(int ID); //修改课程信息,按课程号修改
void Show_lesson_information(); //显示课程信息
void Sort_lesson_information(); //排序课程信息

void Add_Select_information(); //添加选课信息
void Delete_Select_information(int ID, int Kind); //删除选课信息,Kind为0时为按学号删除，为1时为按课程号删除
void Search_Select_information(int ID, int Kind); //查询选课信息,Kind为0时为按学号查询，为1时为按课程号查询

void Add_score_information(); //添加成绩信息
void Delete_score_information(int StudentID, int LessonID); //删除成绩信息,按学号和课程号删除
void Change_score_information(int StudentID, int LessonID); //修改成绩信息,按学号和课程号修改

void Search_student_information(Searching *a, int Kind); //查询学生信息,Kind为0时为按学号查询，为1时为按姓名查询，为2时为按地址查询
void Search_lesson_information(Searching *a, int Kind); //查询课程信息,Kind为0时为按课程号查询，为1时为按课程名查询
void Search_score_information(Searching *a,int Kind); //查询成绩信息,Kind为0时为按学号查询，为1时为按课程号查询

char getch(); //获取键盘输入,不显示在屏幕上
int compare(const void *a, const void *b); //比较函数
void AnyKeyToReturn(); //任意键返回

#define MAXSTUDENT 100
#define MAXLESSON 100

Student Stu[MAXSTUDENT];
Select Sel[MAXSTUDENT * MAXLESSON];
Lesson *head;

int Student_present, Lesson_present, Select_present;

#endif //__STUDENT_CONTROL_H
