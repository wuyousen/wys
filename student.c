#include "student.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>

 //初始化学生信息链表
void init_student_info_list()
{
     //学生信息链表头结点
      student_list = (student_info*)malloc(sizeof(student_info));
      student_list->next = NULL;
  }
  //判断学生信息链表是否为空
  int student_list_empty()
  {
      return student_list->next == NULL;
  }
  //操作函数实现
  //向学校信息表中添加学生信息记录
  int add_student_info()
  {
      student_info *pstu = (student_info*)malloc(sizeof(student_info));
      if(pstu == NULL)
      {
          printf("内存分配失败.\n");
          return 0;
      }
      printf("请按要求一次输入学生的信息.\n");
      printf("请输入学号: ");
      scanf("%d",&pstu->num);
      //判断该学号是否已经存在
      if(search_student_info(pstu->num) != NULL)
      {
          printf("该学号已经存在学生信息表中.\n");
          return 0;
      }
      printf("请输入姓名: ");
      getchar();
      gets(pstu->name);
      printf("请输入性别: ");
      scanf("%s",pstu->sex);
      printf("请输入年龄: ");
      scanf("%d",&pstu->age);
      printf("请输入英语成绩: ");
      scanf("%d",&pstu->english);
      printf("请输入数学成绩: ");
      scanf("%d",&pstu->math);
      printf("请输入计算机成绩: ");
      scanf("%d",&pstu->computer);
      pstu->average = (pstu->english + pstu->math + pstu->computer)/3;
      //每次从学生信息链表的头部插入;
      pstu->next = student_list->next;
      student_list->next = pstu;
      return 1;
  }
  //根据学号删除学生信息
  int delete_student_info(int num)
  {
      student_info *pstu;
      student_info *qstu;
      if(search_student_info(num) == NULL)
      {
          printf("不存在该学好为%d的学生信息.\n",num);
          return 0;
      }
      pstu = student_list->next;
      qstu = student_list;
      while(pstu->num != num)
      {
          qstu = pstu;
          pstu = pstu->next;
      }
      qstu->next = pstu->next;
      free(pstu);
      return 1;
  }
  //根据学号修改学生信息
  int modify_student_info(int num)
  {
      int choice;
      student_info *pstu = search_student_info(num);
      if(pstu == NULL)
      {
          printf("不存在该学号为%d的学生信息.\n",num);
          return 0;
      }
      printf("1.姓名 2.性别 3.年龄 4.英语成绩 5.数学成绩 6.计算机成绩.\n");
      printf("请选择修改的信息: ");
      scanf("%d",&choice);
      switch(choice)
      {
      case 1:
          printf("请输入新的姓名: ");
          getchar();
          gets(pstu->name);
          break;
      case 2:
          printf("请输入新的性别: ");
          scanf("%s",pstu->sex);
         break;
     case 3:
         printf("请输入新的年龄: ");
         scanf("%d",&pstu->age);
         break;
     case 4:
         printf("请输入新的英语成绩: ");
         scanf("%d",&pstu->english);
         break;
     case 5:
         printf("请输入新的数学成绩: ");
         scanf("%d",&pstu->math);
         break;
     case 6:
         printf("请输入新的计算机成绩: ");
         scanf("%d",&pstu->computer);
         break;
     default:
         printf("请按提示要求操作.\n");
     }
     return 1;
 }
 //根据学号查找学生信息
 student_info* search_student_info(int num)
 {
     student_info *pstu;
     pstu = student_list->next;
     while(pstu  && pstu->num != num)
     {
 
         pstu = pstu->next;
    }
     return pstu;
 }
 //输出每个学生的平均成绩
 void display_average()
 {
     student_info *pstu;
     pstu = student_list->next;
     while(pstu)
     {
         printf("学号为%d，姓名为%s的学生平均成绩为: %d\n",pstu->num,pstu->name,pstu->average);
         pstu = pstu->next;
     }
 }
 //显示所有学生信息
 void display_student_info()
 {
     student_info *pstu;
     pstu = student_list->next;
     printf("所有学生信息如下所示.\n");
     printf("学号\t姓名\t性别\t年龄\t英语\t数学\t计算机\t平均成绩.\n");
     while(pstu)
     {
         printf("%d\t",pstu->num);
         printf("%s\t",pstu->name);
         printf("%s\t",pstu->sex);
         printf("%d  \t",pstu->age);
         printf("%d   \t",pstu->english);
         printf("%d  \t",pstu->math);
         printf("%d    \t",pstu->computer);
         printf("%d\n",pstu->average);
         pstu = pstu->next;
     }
 }
 //将学生信息保存到文件
 int save_file()
 {
     FILE *pfile;
     student_info *pstu;
     pfile = fopen("student.txt","w");
     if(pfile == NULL)
     {
         printf("打开文件失败.\n");
         return 0;
     }
     pstu = student_list->next;
     while(pstu)
     {
         fprintf(pfile,"%5d%15s%9s%3d%4d%4d%4d%4d",pstu->num,pstu->name,pstu->sex,pstu->age,
             pstu->english,pstu->math,pstu->computer,pstu->average);
         pstu = pstu->next;
     }
     fclose(pfile);
     return 1;
 }
 
 //从文件中读取学生信息
 int read_file()
 {
     FILE *pfile;
     student_info *pstu;
     pfile = fopen("student.txt","r");
     if(pfile == NULL)
     {
         printf("打开文件失败.\n");
         return 0;
     }
     while(!feof(pfile))
     {
         pstu = (student_info*)malloc(sizeof(student_info));
         fscanf(pfile,"%5d%15s%9s%4d%4d%4d%4d%4d",&pstu->num,pstu->name,pstu->sex,&pstu->age,
             &pstu->english,&pstu->math,&pstu->computer,&pstu->average);
         pstu->average = (pstu->english + pstu->math + pstu->computer)/3;
         //每次从学生信息链表的头部插入;
         pstu->next = student_list->next;
         student_list->next = pstu;
     }
     fclose(pfile);
     return 1;
 }
