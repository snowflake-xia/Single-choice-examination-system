#include"header.h"

int main()
{
	FILE *stu = NULL, *tea = NULL, *que = NULL;
	student* head_stu; teacher* head_tea; question* head_que;//���������ͷָ��
	int sign_in_mark;//�����¼��Ǳ���
	int n_stu=0, n_tea=0, n_que=0;//��¼�ļ��м�¼�����ݽڵ����
	//���ļ�rb+
//	getchar();
	stu = fopen("student.dat", "rb+");
	if (stu == NULL) {
		perror("student.dat�ļ���ʧ��");
		return 0;
	}
	tea = fopen("teacher.dat", "rb+");
	if (tea == NULL) {
		perror("teacher.dat�ļ���ʧ��");
		return 0;
	}
	que = fopen("question.dat", "rb+");
	if (que == NULL) {
		perror("question.dat�ļ���ʧ��");
		return 0;
	}
	//��¼�����ļ��Ĵ洢�ڵ���
	//n_stu = count_stu(pp);
	n_stu = count_stu(stu);
	n_tea = count_tea(tea);
	n_que = count_que(que);
	//��������(��һ��Ϊ�ձ�ͷ�����洢����)
	head_stu=chain_stu(n_stu+2);
	head_tea=chain_tea(n_tea+2);
	head_que=chain_que(n_que+2);
	//���ļ��е�����д������
	read_stu(head_stu,stu,n_stu);
	read_tea(head_tea,tea,n_tea);
	read_que(head_que,que,n_que);
	//�ر�
	close(stu, tea, que);
	//��ӭ���
	menu_of_welcome();
	//�������˿ڹ��ܱ�־���
	scanf("%d", &sign_in_mark);
	

	//ѧ����
	while(1==sign_in_mark)
	{
		int select_mark;//����ѡ���Ǳ���
		student* p;
		p = sign_in_stu(head_stu);//��¼�ɹ����ض�Ӧ�ڵ�ĵ�ַ
		while (p == NULL)
		{
			printf("ѧ�Ż�������������µ�½��\n");
			p = sign_in_stu(head_stu);
		}
		printf("��¼�ɹ���\n");
		//����ѡ��   1 ����\t2 �鿴��Ϣ\t3 ����ѧ����Ϣ\n
		menu_of_student();
		scanf("%d", &select_mark);
		//1 ����
	
		if (select_mark == 1)
		{
			int arr[11] = {0};
			rondom_s(arr);//���������
			da_ti(head_que,p,arr);
			printf("���������\n");
			printf("���յ÷�:%.2lf\n",p->score);
			///��������Ϣ����ļ�
			/*stu = fopen("student.dat", "wb+");
			if (stu == NULL) {
				perror("student.dat�ļ���ʧ��");
				return 0;
			}*/
			/*write_stu(head_stu,stu);
			fclose(stu);*/
			out(&sign_in_mark);
			////////
			getchar();
		}
		//2 �鿴��Ϣ
		else if (select_mark == 2)
		{
			printf("--------------------------------------------------------------------------------------------\n");
			printf("������ϸ��Ϣ���£�\n");
			output_stu(p);
			printf("--------------------------------------------------------------------------------------------\n");
			out(&sign_in_mark);
			getchar();
		}
		//3 ����ѧ����Ϣ
		else if (select_mark == 3)
		{
			printf("--------------------------------------------------------------------------------------------\n");
			printf("ԭѧ����Ϣ��\n");
			output_stu(p);
			printf("��������ĺ����Ϣ��\n");
			input_stu(p,2);//���ı����
			/*stu = fopen("student.dat", "wb+");
			if (stu == NULL) {
				perror("student.dat�ļ���ʧ��");
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
	//��ʦ��
	while(2==sign_in_mark)
	{
		int select_mark;//����ѡ���Ǳ���
		teacher* p;
		p = sign_in_tea(head_tea);//��¼�ɹ����ض�Ӧ�ڵ�ĵ�ַ
		while (p == NULL)
		{
			printf("ѧ�Ż�������������µ�½��\n");
			p = sign_in_tea(head_tea);
		}
		printf("��¼�ɹ���\n");
		//����ѡ��  1 ��ӡ������Ŀ\t 2  ��ӡѧ���ɼ�\n3 �������\t4 ѧ������\n
		menu_of_teacher();
		//1 ��ӡ������Ŀ
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
		//2 ��ӡѧ���ɼ�
		else if (select_mark == 2)
		{
			student* p_s=head_stu;//����ڶ�λ��������Чλ
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
				printf("��ӡʧ�ܣ�����\n");
			}
			sort_stu_score(head_stu);//���б�ָ�ԭ������ѧ������
			printf("--------------------------------------------------------------------------------------------\n");
			out2(&sign_in_mark);
			getchar();
		}
		//3 �������
		else if (select_mark == 3)
		{
			int mark;
			printf("--------------------------------------------------------------------------------------------\n");
			//1 ������Ŀ��ű༭��Ŀ\t 2  ������Ŀ���ɾ������Ŀ\n3 ������Ŀ\n
			menu_of_manage_que();
			scanf("%d",&mark);
			//1 ������Ŀ��ű༭��Ŀ
			if (mark == 1)
			{
				question* ptemp = head_que->next;
				int id_que;
				printf("��������Ŀ��ţ�\n");
				scanf("%d",&id_que);
				while (ptemp != NULL)
				{
					if (ptemp->id == id_que)
					{
						printf("ԭ�⣺\n");
						output_que(ptemp);
						printf("��������ĺ����Ŀ��\n");
						input_que(ptemp);
						//������ĺ������
						output_que(ptemp);
						break;
					}
					ptemp = ptemp->next;
				}
				/*que = fopen("question.dat", "wb+");
				if (que == NULL) {
					perror("question.dat�ļ���ʧ��");
					return 0;
				}*/
				/*write_stu(head_que, que);
				fclose(que);*/
				getchar();
				printf("--------------------------------------------------------------------------------------------\n");
				out2(&sign_in_mark);
				getchar();
			}
			//2 ������Ŀ���ɾ������Ŀ
			else if (mark == 2)
			{/////////////////
				question* p_que = head_que->next;
				////////////////
				int id_que;
				printf("��������Ŀ��ţ�\n");
				scanf("%d", &id_que);
				delete_que(head_que,id_que);
				printf("ɾ���ɹ���\n");

				///////////////////////
				while (p != NULL)
				{
					output_que(p_que);
					p_que = p_que->next;
				}
				/////////////////////
				/*que = fopen("question.dat", "wb+");
				if (que == NULL) {
					perror("question.dat�ļ���ʧ��");
					return 0;
				}*/
				/*write_stu(head_que, que);
				fclose(que);*/
				out2(&sign_in_mark);
				getchar();
			}
			//3 ������Ŀ
			else if (mark == 3)
			{//////////////////////////
				question* p_que = head_que->next;
				///////////////////////
				question* ptemp;
				ptemp = insert_que(head_que, 1);
				if (ptemp != NULL)
				{
					input_que(ptemp);
					printf("����ɹ���\n");
				}
				sort_que(head_que);//���������

				//////////////////////////////////
				while (p != NULL)
				{
					output_que(p_que);
					p_que = p_que->next;
				}
				///////////////////////////////
				/*que = fopen("question.dat", "wb+");
				if (que == NULL) {
					perror("question.dat�ļ���ʧ��");
					return 0;
				}*/
				/*write_stu(head_que, que);
				fclose(que);*/
				printf("--------------------------------------------------------------------------------------------\n");
				out2(&sign_in_mark);
				getchar();
			}

		}
		//4 ѧ������
		else if (select_mark==4)
		{
			int mark=0;
			printf("--------------------------------------------------------------------------------------------\n");
			//1 ѧ�����\t2 ѧ��ɾ��
			menu_of_manage_stu();
			scanf("%d", &mark);
			//1 ѧ�����
			if (mark == 1)
			{///////////////////////
				student* p_stu = head_stu->next;
				////////////////////////
				student* ptemp;
				ptemp = insert_stu(head_stu,1);
				if (ptemp != NULL)
				{
					input_stu(ptemp,1);
					printf("����ɹ���\n");
					printf("--------------------------------------------------------------------------------------------\n");
				}
				/////////��ѧ������
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
					perror("student.dat�ļ���ʧ��");
					return 0;
				}*/
				/*write_stu(head_stu, stu);
				fclose(stu);*/
				out2(&sign_in_mark);
				getchar();
			}
			//2 ѧ��ɾ��
			else if (mark == 2)
			{///////////////////////
				student* p_stu = head_stu->next;
				////////////////////////
				int id;
				printf("������ѧ��id:\n");
				scanf("%d",&id);
				delete_stu(head_stu,id);
				printf("ɾ���ɹ���\n");
				//////////////////////
				while (p != NULL)
				{
					output_stu(p_stu);
					p_stu = p_stu->next;
				}
				/*stu = fopen("student.dat", "wb+");
				if (stu == NULL) {
					perror("student.dat�ļ���ʧ��");
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
	//�ر��ļ�
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
//			perror("student.dat�ļ���ʧ��");
//			return 0;
//		}
//		tea = fopen("teacher.dat", "rb+");
//		if (tea == NULL) {
//			perror("teacher.dat�ļ���ʧ��");
//			return 0;
//		}
//		que = fopen("question.dat", "rb+");
//		if (que == NULL) {
//			perror("question.dat�ļ���ʧ��");
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