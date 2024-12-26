#include"header.h"

 void menu_of_student()
{
	 printf("1 答题\t2 查看信息\t3 更改学生信息\n");
}

 void menu_of_teacher()
 {
	 printf("1 打印所有题目\t 2  打印学生成绩\n3 管理题库\t4 学生管理\n");
 }

 void menu_of_manage_que()
 {
	 printf("1 根据题目编号编辑题目\t 2  根据题目编号删除该题目\n3 插入题目\n");
 }

 void menu_of_manage_stu()
 {
	 printf("1 学生添加\t2 学生删除\n");
 }

 void menu_of_welcome()
 {
	 printf("--------------------------------------------------------------------------------------------\n");
	 printf("欢迎使用山颠单选题标准化考试系统! \n");
	 printf("无人扶我青云志，我自踏雪至山颠!\n");
	 printf("--------------------------------------------------------------------------------------------\n请登录：");
	 printf("1 学生端\t2 教师端\n");
 }