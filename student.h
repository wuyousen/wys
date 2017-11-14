#ifndef STUDENT_HEAD
#define STUDENT_HEAD
 
typedef struct node /*定义结构体*/
{ 
     int num; //学号
     char name[15];//姓名
     char sex[9]; //性别
     int age;  //年龄
     int english; //英语成绩
     int math; //数学成绩
     int computer;//计算机成绩
     int average; //平均成绩
     struct node *next; //链表指针域
 }student_info;
 
 //学生信息链表
 extern student_info* student_list;  //全局变量声明
 
 
 //初始化函数声明
 //初始化学生信息链表
 void init_student_info_list();
 //判断学生信息链表是否为空
 int student_list_empty();
 
 //操作函数声明
 //向学校信息表中添加学生信息记录
 int add_student_info();
 //根据学号删除学生信息
 int delete_student_info(int num);
 //根据学号修改学生信息
 int modify_student_info(int num);
//根据学号查找学生信息
 student_info* search_student_info(int num);
 //输出每个学生的平均成绩
 void display_average();
 //显示所有学生信息
 void display_student_info();
 //将学生信息保存到文件
 int save_file();
 //从文件中读取学生信息
 int read_file();
 #endif















