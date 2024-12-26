#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

//ѧ���ṹ��
typedef struct student
{
	char name[16];
	int id;
	int passward;
	double score;
	struct student* next;
}student;

//��ʦ�ṹ��
typedef struct teacher
{
	char name[16];
	int id;
	int passward;
	struct teacher* next;
}teacher;

//��Ŀ�ṹ��
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

//////////////////////////////////////////////////////////////////�˵�������

//��ӭ�˵�
void menu_of_welcome();

//ѧ���˵�
void menu_of_student();

//��ʦ�˵�
void menu_of_teacher();

//������
void menu_of_manage_que();

//ѧ������
void menu_of_manage_stu();

/////////////////////////////////////////////////////////////////������������

//ѧ������������
student* chain_stu(int n);//����n���ڵ�

// ��ʦ��������
teacher* chain_tea(int n);//����n���ڵ�

//��Ŀ��������
question* chain_que(int n);//����n���ڵ�

////////////////////////////////////////////////////////////////�ļ��ٿأ�����

//������ʹ���ļ�
int open(FILE* student, FILE* teacher, FILE* question);

//�ر������ļ�
int close(FILE* student, FILE* teacher, FILE* question);


//////////////////////////////////////////////////////////////��¼������

//ѧ�������¼
student* sign_in_stu(student* head);

//��ʦ�����¼
teacher* sign_in_tea(teacher* head);

//////////////////////////////////////////////////////////////�����������ݣ�����

//������Ŀ��������
void input_que(question* p);

//ѧ����������
void input_stu(student* p,int mark);

//��ʦ��������
void input_tea(teacher* p);

// ȥ�� fgets ����� '\n' �ַ�
void remove_newline(char* str);

/////////////////////////////////////////////////////////////�������������

//������Ŀ���
void output_que(question* p);

//����ѧ���������
void output_stu(student* p);

//������ʦ�������
void output_tea(teacher* p);

///////////////////////////////////////////////////////////////�ڵ����������

//����ѧ���ļ������ݵĽڵ���
int count_stu(FILE* fofstu);

//�����ʦ�ļ������ݵĽڵ���
int count_tea(FILE* foftea);

//���������ļ������ݵĽڵ���
int count_que(FILE* fofque);

////////////////////////////////////////////////////////////////��ȡ�ļ�������

//��ȡѧ���ļ�������
int read_stu(student* head, FILE* stu, int sum_stu);

//��ȡ��ʦ�ļ�������
int read_tea(teacher* head, FILE* tea, int sum_tea);

//��ȡ��Ŀ�ļ�������
int read_que(question* head, FILE* que, int sum_que);

/////////////////////////////////////////////////////////////////////////�������浽�ļ�������

//��ѧ�����������ݴ����ļ�
int write_stu(student* head, FILE* stu);

//����ʦ���������ݴ����ļ�
int write_tea(teacher* head, FILE* tea);

//���������������ݴ����ļ�
int write_que(question* head, FILE* que);

/////////////////////////////////////////////////////////////////���򣡣���

//����ָ�뷨��������(id)ѧ��
int sort_stu(student* head);

//����ָ�뷨��������()ѧ��
int sort_stu_score(student* head);

//����ָ�뷨��������(id)��ʦ
int sort_tea(teacher* head);

////����ָ�뷨��������(id)��Ŀ
int sort_que(question* head);

//////////////////////////////////////////////////////////////////////����༭������
//�ڵ�site���ڵ�֮�󴦲���һ���½ڵ�(�ӵڶ�λ��ʼ��ȡ)
student* insert_stu(student* head, int site);

//������Ŀ���ɾ����Ŀ
void delete_stu(student* head, int id);

//�ڵ�site���ڵ�֮�󴦲���һ���½ڵ�(�ӵڶ�λ��ʼ��ȡ)
teacher* insert_tea(teacher* head, int site);

//������Ŀ���ɾ����Ŀ
void delete_tea(teacher* head, int id);

//�ڵ�site���ڵ�֮�󴦲���һ���½ڵ�(�ӵڶ�λ��ʼ��ȡ)
question* insert_que(question* head, int site);

// ������Ŀ���ɾ����Ŀ
void delete_que(question * head, int id);

/////////////////////////////////////////////////////////////////////��������
//��Сд��ĸת����д
void convert(char* str);

//stdin���������������
void clear_buffer();

///////////////////////////////////////////////////////////////////////////ѧ�����⣡����
//�������������
int rondom_s(int array[11]);

//����
void da_ti(question* head, student* current, int array[]);

/////////////////////////////////////////////////////////////////////////////////////�˳�
//�˳�
void out(int* sign_in_mark);

void out2(int* sign_in_mark);