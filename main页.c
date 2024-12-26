#include"header.h"

int main()
{
	FILE *stu = NULL, *tea = NULL, *que = NULL;
	student* head_stu; teacher* head_tea; question* head_que;//各个链表的头指针
	int sign_in_mark;//定义登录标记变量
	int n_stu=0, n_tea=0, n_que=0;//记录文件中记录的数据节点个数
	//打开文件rb+
//	getchar();
	stu = fopen("student.dat", "rb+");
	if (stu == NULL) {
		perror("student.dat文件打开失败");
		return 0;
	}
	tea = fopen("teacher.dat", "rb+");
	if (tea == NULL) {
		perror("teacher.dat文件打开失败");
		return 0;
	}
	que = fopen("question.dat", "rb+");
	if (que == NULL) {
		perror("question.dat文件打开失败");
		return 0;
	}
	//记录各个文件的存储节点数
	//n_stu = count_stu(pp);
	n_stu = count_stu(stu);
	n_tea = count_tea(tea);
	n_que = count_que(que);
	//创建链表(第一个为空表头，不存储数据)
	head_stu=chain_stu(n_stu+2);
	head_tea=chain_tea(n_tea+2);
	head_que=chain_que(n_que+2);
	//将文件中的数据写入链表
	read_stu(head_stu,stu,n_stu);
	read_tea(head_tea,tea,n_tea);
	read_que(head_que,que,n_que);
	//关闭
	close(stu, tea, que);
	//欢迎语！！
	menu_of_welcome();
	//输入登入端口功能标志序号
	scanf("%d", &sign_in_mark);
	

	//学生端
	while(1==sign_in_mark)
	{
		int select_mark;//功能选择标记变量
		student* p;
		p = sign_in_stu(head_stu);//登录成功返回对应节点的地址
		while (p == NULL)
		{
			printf("学号或密码错误！请重新登陆！\n");
			p = sign_in_stu(head_stu);
		}
		printf("登录成功！\n");
		//功能选择   1 答题\t2 查看信息\t3 更改学生信息\n
		menu_of_student();
		scanf("%d", &select_mark);
		//1 答题
	
		if (select_mark == 1)
		{
			int arr[11] = {0};
			rondom_s(arr);//生成随机数
			da_ti(head_que,p,arr);
			printf("答题结束！\n");
			printf("最终得分:%.2lf\n",p->score);
			///将链表信息存回文件
			/*stu = fopen("student.dat", "wb+");
			if (stu == NULL) {
				perror("student.dat文件打开失败");
				return 0;
			}*/
			/*write_stu(head_stu,stu);
			fclose(stu);*/
			out(&sign_in_mark);
			////////
			getchar();
		}
		//2 查看信息
		else if (select_mark == 2)
		{
			printf("--------------------------------------------------------------------------------------------\n");
			printf("您的详细信息如下：\n");
			output_stu(p);
			printf("--------------------------------------------------------------------------------------------\n");
			out(&sign_in_mark);
			getchar();
		}
		//3 更改学生信息
		else if (select_mark == 3)
		{
			printf("--------------------------------------------------------------------------------------------\n");
			printf("原学生信息：\n");
			output_stu(p);
			printf("请输入更改后的信息：\n");
			input_stu(p,2);//不改变分数
			/*stu = fopen("student.dat", "wb+");
			if (stu == NULL) {
				perror("student.dat文件打开失败");
				return 0;
			}*/
			/*write_stu(head_stu, stu);
			fclose(stu);*/
			printf("--------------------------------------------------------------------------------------------\n");
			out(&sign_in_mark);
			getchar();
		}

	
	}


	//////////////////////////////////////////////////////////////////////////////////////
	//教师端
	while(2==sign_in_mark)
	{
		int select_mark;//功能选择标记变量
		teacher* p;
		p = sign_in_tea(head_tea);//登录成功返回对应节点的地址
		while (p == NULL)
		{
			printf("学号或密码错误！请重新登陆！\n");
			p = sign_in_tea(head_tea);
		}
		printf("登录成功！\n");
		//功能选择  1 打印所有题目\t 2  打印学生成绩\n3 管理题库\t4 学生管理\n
		menu_of_teacher();
		//1 打印所有题目
		scanf("%d", &select_mark);
		if (select_mark == 1)
		{
			question* p_que=head_que->next;
			int i = 0;
			printf("--------------------------------------------------------------------------------------------\n");
			while (p != NULL)
			{
				if (i > 22)
					break;
				output_que(p_que);
				p_que = p_que->next;
				i++;
			}
			printf("--------------------------------------------------------------------------------------------\n");
			out2(&sign_in_mark);
			getchar();
		}
		//2 打印学生成绩
		else if (select_mark == 2)
		{
			student* p_s=head_stu;//到达第二位，既是有效位
			printf("--------------------------------------------------------------------------------------------\n");
			if (sort_stu_score(head_stu) == 1)
			{
				p_s = p_s->next;
				while (p_s != NULL)
				{
					output_stu(p_s);
					p_s = p_s->next;
				}
				
			}
			else
			{
				printf("打印失败！！！\n");
			}
			sort_stu_score(head_stu);//将列表恢复原本排序（学号排序）
			printf("--------------------------------------------------------------------------------------------\n");
			out2(&sign_in_mark);
			getchar();
		}
		//3 管理题库
		else if (select_mark == 3)
		{
			int mark;
			printf("--------------------------------------------------------------------------------------------\n");
			//1 根据题目编号编辑题目\t 2  根据题目编号删除该题目\n3 插入题目\n
			menu_of_manage_que();
			scanf("%d",&mark);
			//1 根据题目编号编辑题目
			if (mark == 1)
			{
				question* ptemp = head_que->next;
				int id_que;
				printf("请输入题目编号：\n");
				scanf("%d",&id_que);
				while (ptemp != NULL)
				{
					if (ptemp->id == id_que)
					{
						printf("原题：\n");
						output_que(ptemp);
						printf("请输入更改后的题目：\n");
						input_que(ptemp);
						//输出更改后的数据
						output_que(ptemp);
						break;
					}
					ptemp = ptemp->next;
				}
				/*que = fopen("question.dat", "wb+");
				if (que == NULL) {
					perror("question.dat文件打开失败");
					return 0;
				}*/
				/*write_stu(head_que, que);
				fclose(que);*/
				getchar();
				printf("--------------------------------------------------------------------------------------------\n");
				out2(&sign_in_mark);
				getchar();
			}
			//2 根据题目编号删除该题目
			else if (mark == 2)
			{/////////////////
				question* p_que = head_que->next;
				////////////////
				int id_que;
				printf("请输入题目编号：\n");
				scanf("%d", &id_que);
				delete_que(head_que,id_que);
				printf("删除成功！\n");

				///////////////////////
				while (p != NULL)
				{
					output_que(p_que);
					p_que = p_que->next;
				}
				/////////////////////
				/*que = fopen("question.dat", "wb+");
				if (que == NULL) {
					perror("question.dat文件打开失败");
					return 0;
				}*/
				/*write_stu(head_que, que);
				fclose(que);*/
				out2(&sign_in_mark);
				getchar();
			}
			//3 插入题目
			else if (mark == 3)
			{//////////////////////////
				question* p_que = head_que->next;
				///////////////////////
				question* ptemp;
				ptemp = insert_que(head_que, 1);
				if (ptemp != NULL)
				{
					input_que(ptemp);
					printf("插入成功！\n");
				}
				sort_que(head_que);//按题号排序

				//////////////////////////////////
				while (p != NULL)
				{
					output_que(p_que);
					p_que = p_que->next;
				}
				///////////////////////////////
				/*que = fopen("question.dat", "wb+");
				if (que == NULL) {
					perror("question.dat文件打开失败");
					return 0;
				}*/
				/*write_stu(head_que, que);
				fclose(que);*/
				printf("--------------------------------------------------------------------------------------------\n");
				out2(&sign_in_mark);
				getchar();
			}

		}
		//4 学生管理
		else if (select_mark==4)
		{
			int mark=0;
			printf("--------------------------------------------------------------------------------------------\n");
			//1 学生添加\t2 学生删除
			menu_of_manage_stu();
			scanf("%d", &mark);
			//1 学生添加
			if (mark == 1)
			{///////////////////////
				student* p_stu = head_stu->next;
				////////////////////////
				student* ptemp;
				ptemp = insert_stu(head_stu,1);
				if (ptemp != NULL)
				{
					input_stu(ptemp,1);
					printf("插入成功！\n");
					printf("--------------------------------------------------------------------------------------------\n");
				}
				/////////按学号排序
				sort_stu(head_stu);
				//////////////////////
				int i=0;
				while (p != NULL)
				{
					if (i > 22)
						break;
					output_stu(p_stu);
					p_stu = p_stu->next;
					i++;
				}
				///////////////////////////
				/*stu = fopen("student.dat", "wb+");
				if (stu == NULL) {
					perror("student.dat文件打开失败");
					return 0;
				}*/
				/*write_stu(head_stu, stu);
				fclose(stu);*/
				out2(&sign_in_mark);
				getchar();
			}
			//2 学生删除
			else if (mark == 2)
			{///////////////////////
				student* p_stu = head_stu->next;
				////////////////////////
				int id;
				printf("请输入学生id:\n");
				scanf("%d",&id);
				delete_stu(head_stu,id);
				printf("删除成功！\n");
				//////////////////////
				while (p != NULL)
				{
					output_stu(p_stu);
					p_stu = p_stu->next;
				}
				/*stu = fopen("student.dat", "wb+");
				if (stu == NULL) {
					perror("student.dat文件打开失败");
					return 0;
				}*/
			/*	write_stu(head_stu, stu);
				fclose(stu);*/
				//////////////////////////////
				printf("--------------------------------------------------------------------------------------------\n");
				out2(&sign_in_mark);
				getchar();
			}
		}
	}
	//关闭文件
	//close(stu,tea,que);
	return 0;
}

//int main()
//{
//	FILE* stu, * tea, * que;
//	student* head_stu=(student*)malloc(sizeof(student));
//	teacher* head_tea = (teacher*)malloc(sizeof(teacher));
//	question* head_que = (question*)malloc(sizeof(question));
//	student* p;
//	teacher* pp;
//	question* ppp;
//	
//	int n, n2, n3;
//	stu = fopen("student.dat", "rb+");
//		if (stu == NULL) {
//			perror("student.dat文件打开失败");
//			return 0;
//		}
//		tea = fopen("teacher.dat", "rb+");
//		if (tea == NULL) {
//			perror("teacher.dat文件打开失败");
//			return 0;
//		}
//		que = fopen("question.dat", "rb+");
//		if (que == NULL) {
//			perror("question.dat文件打开失败");
//			return 0;
//		}
//		/*n=count_stu(stu);
//		n2=count_tea(tea);
//		n3=count_que(que);*/
//
//
//
//		head_stu = chain_stu(20);
//		head_tea = chain_tea(1);
//		head_que = chain_que(20);
//
//
//	/*	read_stu(head_stu,stu,n);
//		read_tea(head_tea,tea,n2);
//		read_que(head_que,que,n3);*/
//
//
//		p = head_stu->next;
//		pp = head_tea->next;
//		ppp = head_que->next;
//		while (p != NULL)
//		{
//			input_stu(p,1);
//			output_stu(p);
//			p = p->next;
//		}
//
//		while (pp != NULL)
//		{
//			input_tea(pp);
//			output_tea(pp);
//			pp = pp->next;
//		}
//
//		while (ppp != NULL)
//		{
//			input_que(ppp);
//			output_que(ppp);
//			ppp = ppp->next;
//		}
//		///////////////////
//
//		p = head_stu->next;
//		pp = head_tea->next;
//		ppp = head_que->next;
//		while (p != NULL)
//		{
//			//input_stu(p, 1);
//			output_stu(p);
//			p = p->next;
//		}
//
//		while (pp != NULL)
//		{
//			//input_tea(pp);
//			output_tea(pp);
//			pp = pp->next;
//		}
//
//		while (ppp != NULL)
//		{
//			//input_que(ppp);
//			output_que(ppp);
//			ppp = ppp->next;
//		}
//		/*ppp = head_stu;
//		for (int j = 0; j < 20; j++) {
//			ppp = ppp->next;
//			input_stu(head_stu, 1);
//		}
//		input_tea(head_tea->next);
//		pp = head_que;
//		for (int i = 0; i < 20; i++)
//		{
//			pp = pp->next;
//			input_que(pp);
//		}*/
//
//		write_stu(head_stu,stu);
//		write_tea(head_tea,tea);
//		write_que(head_que,que);
//
//		close(stu,tea,que);
//}