//
//  Lesson_information.c
//  _
//
// Created by 方杨 on 2023/5/28.
//

#include "Student_control.h"

Lesson *Create_lesson_information(){ //创建课程信息，返回头指针，链表，头指针不存储数据
    Lesson *p,*q,*head;
    head=(Lesson *)malloc(sizeof(Lesson));
    head->next=NULL;
    q=NULL;
    while(1){
        p=(Lesson *)malloc(sizeof(Lesson));
        scanf("%d",&p->ID);
        if(p->ID==-1) {
            free(p);
            break;
        }
        if (p->ID == -2) { //输入-2时从文件中读取
            FILE *fp;
            fp = fopen("Data/Lesson.txt", "r");
            if (fp == NULL) {
                printf("文件打开失败\n");
                sleep(2);
                return NULL;
            }
            Lesson *q = NULL;
            while (fscanf(fp, "%d %s %d %d", &p->ID, p->Name, &p->Credit, &p->Time) != EOF) {
                Lesson_present++;
                Lesson *new_lesson = (Lesson *)malloc(sizeof(Lesson));
                new_lesson->ID = p->ID;
                strcpy(new_lesson->Name, p->Name);
                new_lesson->Credit = p->Credit;
                new_lesson->Time = p->Time;
                new_lesson->next = NULL;
                if (q == NULL) {
                    head->next = new_lesson;
                    q = new_lesson;
                }
                else {
                    q->next = new_lesson;
                    q = new_lesson;
                }
            }
            fclose(fp);
            return head;
        }
        if(p->ID<0){
            printf("课程号不能为负数\n");
            free(p);
            continue;
        }
        //检查ID是否重复
        Lesson *test=head;
        int flag=0;
        while (test!=NULL){
            if(test->ID==p->ID){
                flag=1;
                printf("课程号重复\n");
                sleep(1);
                free(p);
                break;
            }
            test=test->next;
        }
        if(flag==1)
            continue;
        scanf("%s %d %d",p->Name,&p->Credit,&p->Time);
        Lesson_present++;
        if(q==NULL){ //头指针为空，即第一次输入，头指针指向第一个节点。
            head->next=p;
            p->next=NULL;
            q=p;
        }
        else {
            q->next = p;
            q = p;
        }
    }
    return head;
}

void Add_lesson_information(){ //添加课程信息，在链表已经建立完成的情况下调用
    Lesson *p,*q;
    p=head;
    while (p->next!=NULL){
        p=p->next;
    }
    q=(Lesson *)malloc(sizeof(Lesson));
    scanf("%d",&q->ID);
    while(q->ID!=-1) {
        if (q->ID < 0) {
            printf("课程号不能为负数\n");
            sleep(1);
            free(q);
            continue;
        }
        //检查ID是否重复
        Lesson *test = head;
        int flag = 0;
        while (test != NULL) {
            if (test->ID == q->ID) {
                flag = 1;
                printf("课程号重复\n");
                free(q);
                break;
            }
            test = test->next;
        }
        if (flag == 1)
            continue;
        scanf("%s %d %d", q->Name, &q->Credit, &q->Time);
        Lesson_present++;
        p->next = q;
        q->next = NULL;
    }
}

void Delete_lesson_information(int ID){ //删除课程信息，ID为课程号
    Lesson *p,*q;
    int flag=0;
    p=head;
    while (p->next!=NULL){
        if(p->next->ID==ID){
            flag=1;
            q=p->next;
            p->next=q->next;
            free(q);
            break;
        }
        p=p->next;
    }
    if(flag==0){
        printf("该课程号不存在\n");
        sleep(2);
    }
    else{
        printf("删除成功\n");
        sleep(2);
    }
}

void Change_lesson_information(int ID){ //修改课程信息，ID为课程号
    Lesson *p;
    int flag=0;
    p=head;
    while (p->next!=NULL){
        if(p->next->ID==ID){
            flag=1;
            scanf("%d %s %d %d",&p->next->ID,p->next->Name,&p->next->Credit,&p->next->Time);
            break;
        }
        p=p->next;
    }
    if(flag==0){
        printf("该课程号不存在\n");
        sleep(2);
    }
    else{
        printf("修改成功\n");
        sleep(2);
    }
}

void Show_lesson_information(){ //显示课程信息
    Lesson *p;
    p=head;
    if(p==NULL || p->next==NULL){
        printf("无课程信息\n");
        sleep(2);
        manu();
        return;
    }
    setlocale(LC_ALL, ""); // 设置本地化环境，支持中文字符输出
    wprintf(L"课程号\t课程名\t\t\t\t学分\t学时\n");
    while (p->next!=NULL){
        wprintf(L"%d\t%-20s\t%d\t%d\n",p->next->ID,p->next->Name,p->next->Credit,p->next->Time);
        p=p->next;
    }
    AnyKeyToReturn();
    manu();
}
void Sort_lesson_information(){ //排序课程信息，按照课程号从小到大排序，使用快速排序
    if (head == NULL || head->next == NULL) {
        printf("无需排序\n");
        sleep(2);
        manu();
        return;
    }
    Lesson *p,*q;
    p=head->next;
    while (p!=NULL){
        q=head->next;
        while (q->next!=NULL){
            if(q->ID>q->next->ID){
                int temp;
                char temp1[50];
                temp=q->ID;
                q->ID=q->next->ID;
                q->next->ID=temp;
                strcpy(temp1,q->Name);
                strcpy(q->Name,q->next->Name);
                strcpy(q->next->Name,temp1);
                temp=q->Credit;
                q->Credit=q->next->Credit;
                q->next->Credit=temp;
                temp=q->Time;
                q->Time=q->next->Time;
                q->next->Time=temp;
            }
            q=q->next;
        }
        p=p->next;
    }
    printf("排序成功\n");
    sleep(2);
    manu();
}
