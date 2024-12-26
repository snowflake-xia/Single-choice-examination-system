#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

//学生结构体
typedef struct student
{
	char name[16];
	int id;
	int passward;
	double score;
	struct student* next;
}student;

//教师结构体
typedef struct teacher
{
	char name[16];
	int id;
	int passward;
	struct teacher* next;
}teacher;

//题目结构体
typedef struct question
{
	int id;
	char stem[300];
	char A[200];
	char B[200];
	char C[200];
	char D[200];
	char answer;
	struct question* next;
}question;

//////////////////////////////////////////////////////////////////菜单！！！

//欢迎菜单
void menu_of_welcome();

//学生菜单
void menu_of_student();

//教师菜单
void menu_of_teacher();

//题库管理
void menu_of_manage_que();

//学生管理
void menu_of_manage_stu();

/////////////////////////////////////////////////////////////////生成链表！！！

//学生单链表生成
student* chain_stu(int n);//生成n个节点

// 教师链表生成
teacher* chain_tea(int n);//生成n个节点

//题目链表生成
question* chain_que(int n);//生成n个节点

////////////////////////////////////////////////////////////////文件操控！！！

//打开所有使用文件
int open(FILE* student, FILE* teacher, FILE* question);

//关闭所有文件
int close(FILE* student, FILE* teacher, FILE* question);


//////////////////////////////////////////////////////////////登录！！！

//学生密码登录
student* sign_in_stu(student* head);

//教师密码登录
teacher* sign_in_tea(teacher* head);

//////////////////////////////////////////////////////////////输入链表数据！！！

//单个题目数据输入
void input_que(question* p);

//学生数据输入
void input_stu(student* p,int mark);

//教师数据输入
void input_tea(teacher* p);

// 去除 fgets 读入的 '\n' 字符
void remove_newline(char* str);

/////////////////////////////////////////////////////////////链表输出！！！

//单个题目输出
void output_que(question* p);

//单个学生数据输出
void output_stu(student* p);

//单个教师数据输出
void output_tea(teacher* p);

///////////////////////////////////////////////////////////////节点计数！！！

//计算学生文件中数据的节点数
int count_stu(FILE* fofstu);

//计算教师文件中数据的节点数
int count_tea(FILE* foftea);

//计算问题文件中数据的节点数
int count_que(FILE* fofque);

////////////////////////////////////////////////////////////////读取文件！！！

//读取学生文件到链表
int read_stu(student* head, FILE* stu, int sum_stu);

//读取教师文件到链表
int read_tea(teacher* head, FILE* tea, int sum_tea);

//读取题目文件到链表
int read_que(question* head, FILE* que, int sum_que);

/////////////////////////////////////////////////////////////////////////将链表保存到文件！！！

//将学生链表中数据存入文件
int write_stu(student* head, FILE* stu);

//将教师链表中数据存入文件
int write_tea(teacher* head, FILE* tea);

//将问题链表中数据存入文件
int write_que(question* head, FILE* que);

/////////////////////////////////////////////////////////////////排序！！！

//交换指针法进行排序(id)学生
int sort_stu(student* head);

//交换指针法进行排序()学生
int sort_stu_score(student* head);

//交换指针法进行排序(id)教师
int sort_tea(teacher* head);

////交换指针法进行排序(id)题目
int sort_que(question* head);

//////////////////////////////////////////////////////////////////////链表编辑！！！
//在第site个节点之后处插入一个新节点(从第二位开始读取)
student* insert_stu(student* head, int site);

//根据题目编号删除题目
void delete_stu(student* head, int id);

//在第site个节点之后处插入一个新节点(从第二位开始读取)
teacher* insert_tea(teacher* head, int site);

//根据题目编号删除题目
void delete_tea(teacher* head, int id);

//在第site个节点之后处插入一个新节点(从第二位开始读取)
question* insert_que(question* head, int site);

// 根据题目编号删除题目
void delete_que(question * head, int id);

/////////////////////////////////////////////////////////////////////辅助函数
//大小写字母转换大写
void convert(char* str);

//stdin输入流缓冲区清除
void clear_buffer();

///////////////////////////////////////////////////////////////////////////学生答题！！！
//生成随机数数列
int rondom_s(int array[11]);

//答题
void da_ti(question* head, student* current, int array[]);

/////////////////////////////////////////////////////////////////////////////////////退出
//退出
void out(int* sign_in_mark);

void out2(int* sign_in_mark);