#include"header.h"

////////////////////////////////////////////////////////////////////////////////////�ļ��ٿأ�����

//������ʹ���ļ�
int open(FILE *student,FILE *teacher,FILE *question)
{
	student=fopen("student.dat","rb+");
	if (student == NULL) {
		perror("student.dat�ļ���ʧ��");
		return 0;
	}
	teacher=fopen("teacher.dat","rb+");
	if (teacher == NULL) {
		perror("teacher.dat�ļ���ʧ��");
		return 0;
	}
	question=fopen("question.dat","rb+");
	if (question == NULL) {
		perror("question.dat�ļ���ʧ��");
		return 0;
	}
	return 1;
}

//�ر������ļ�
int close(FILE* student, FILE* teacher, FILE* question)
{
	fclose(student);
	fclose(teacher);
	fclose(question);
	return 1;
}

////////////////////////////////////////////////////////////////////////////////////�ļ����ݶ�ȡ������

//��ȡѧ���ļ�������
int read_stu(student* head, FILE* stu,int sum_stu)
{
	//int sum_stu,i;
	int i;
	student* p = head;
	//sum_stu=count_stu(stu);
	for (i = 0; i < sum_stu; i++)
	{
		p = p->next;//������һ���հױ�ͷ
		fread(p, sizeof(student) - sizeof(student*), 1, stu);
	}
	return 1;
}

//��ȡ��ʦ�ļ�������
int read_tea(teacher* head, FILE* tea,int sum_tea)
{
	//int sum_tea, i;
	int i;
	teacher* p = head;
	//sum_tea = count_stu(tea);
	for (i = 0; i < sum_tea; i++)
	{
		p = p->next;//������һ���հױ�ͷ
		fread(p, sizeof(teacher) - sizeof(teacher*), 1, tea);
	}
	return 1;
}

//��ȡ��Ŀ�ļ�������
int read_que(question* head, FILE* que,int sum_que)
{
	//int sum_que, i;
	int i;
	question* p = head;
	//sum_que = count_stu(que);
	for (i = 0; i < sum_que; i++)
	{
		p = p->next;//������һ���հױ�ͷ
		fread(p, sizeof(question) - sizeof(question*), 1, que);
	}
	return 1;
}

////////////////////////////////////////////////////////////////////////////////////��������д�����ļ�������

//��ѧ�����������ݴ����ļ�
int write_stu(student* head,FILE *stu)
{
	int i,count=0;
	student* p = head->next;//��һ����Ч�ڵ㣬���ǵڶ����ڵ�
	while (p != NULL)//������Ч�ڵ��Ǹ���
	{
		count++;
		p = p->next;
	}
	//д��
	p = head;
	for (i = 0; i < count; i++)
	{
		p = p->next;
		fwrite(p, sizeof(student) - sizeof(student*), 1, stu);
	}
	return 1;
}

//����ʦ���������ݴ����ļ�
int write_tea(teacher* head, FILE* tea)
{
	int i, count = 0;
	teacher* p = head->next;//��һ����Ч�ڵ㣬���ǵڶ����ڵ�
	while (p != NULL)//������Ч�ڵ��Ǹ���
	{
		count++;
		p = p->next;
	}
	//д��
	p = head;
	for (i = 0; i < count; i++)
	{
		p = p->next;
		fwrite(p, sizeof(teacher) - sizeof(teacher*), 1, tea);
	}
	return 1;
}

//���������������ݴ����ļ�
int write_que(question* head, FILE* que)
{
	int i, count = 0;
	question* p = head->next;//��һ����Ч�ڵ㣬���ǵڶ����ڵ�
	while (p != NULL)//������Ч�ڵ��Ǹ���
	{
		count++;
		p = p->next;
	}
	//д��
	p = head;
	for (i = 0; i < count; i++)
	{
		p = p->next;
		fwrite(p, sizeof(question) - sizeof(question*), 1, que);
	}
	return 1;
}

/////////////////////////////////////////////////////////////////////////////////////�ڵ����������

//����ѧ���ļ������ݵĽڵ���
int count_stu(FILE *fofstu)
{
	int bytes,count;
	fseek(fofstu,0,SEEK_END);
	bytes = ftell(fofstu);
	count = bytes / (sizeof(student) - sizeof(student*));//�õ��洢�Ľڵ���
	fseek(fofstu,0,SEEK_SET);//���ļ�ָ���������ڿ�ʼλ��
	return count;
}

//�����ʦ�ļ������ݵĽڵ���
int count_tea(FILE* foftea)
{
	int bytes, count;
	fseek(foftea, 0, SEEK_END);
	bytes = ftell(foftea);
	count = bytes / (sizeof(teacher) - sizeof(teacher*));//�õ��洢�Ľڵ���
	fseek(foftea, 0, SEEK_SET);//���ļ�ָ���������ڿ�ʼλ��
	return count;
}

//���������ļ������ݵĽڵ���
int count_que(FILE* fofque)
{
	int bytes, count;
	fseek(fofque, 0, SEEK_END);
	bytes = ftell(fofque);
	count = bytes / (sizeof(question) - sizeof(question*));//�õ��洢�Ľڵ���
	fseek(fofque, 0, SEEK_SET);//���ļ�ָ���������ڿ�ʼλ��
	return count;
}

////////////////////////////////////////////////////////////////////////////////////////��¼������

//ѧ�������¼
student* sign_in_stu(student *head)
{
	student* p;
	int id, passward;//�������������
	printf("������id��");
	scanf("%d", &id);
	printf("���������룺");
	scanf("%d",&passward);
	//��¼�Ա�
	p = head->next;
	while (p != NULL) 
	{
		//��ͨ��ѧ���ҵ���Ӧѧ��
		if (p->id == id)
		{
			if (p->passward == passward)
				return p;//��½�ɹ����ض�Ӧѧ����ָ��
			else
				return NULL;
		}
		p = p->next;
	}
	return NULL;
}

//��ʦ�����¼
teacher* sign_in_tea(teacher* head)
{
	teacher* p;
	int id, passward;//�������������
	printf("������id��");
	scanf("%d", &id);
	printf("���������룺");
	scanf("%d", &passward);
	//��¼�Ա�
	 p= head->next;
	while (p != NULL)
	{
		//��ͨ��ѧ���ҵ���Ӧѧ��
		if (p->id == id)
		{
			if (p->passward == passward)
				return p;//��½�ɹ����ض�Ӧѧ����ָ��
			else
				return NULL;
		}
		p = p->next;
	}
	return NULL;
}

///////////////////////////////////////////////////////////////////////////////////////////��������������

//��Сд��ĸת����д
void convert(char* str)
{
	if (*str >= 97 && *str <= 122)
	{
		*str -= 32;
	}
}

//stdin���������������
void clear_buffer()
{
	char ch='0';
	while (ch = getchar() != '\n' && ch != EOF)
	{
		//�ѷǻ��з������в���ȥ��ֱ��ĩβ��'\n',���һ��������һ��'\n'Ҳȥ��
	}
}

////////////////////////////////////////////////////////////////////////////////////////////�������ɣ�����

//ѧ����������
student* chain_stu(int n)//����n���ڵ�
{
	//�����һ���ڵ�
	student* head = NULL, * pnew = NULL, *pend = NULL;
	int i = 1;
	head = (student*)malloc(sizeof(student));
	pend = head;
	//����n���ڵ�
	for (; i < n; i++)
	{ 
		pnew = (student*)malloc(sizeof(student));
		pend->next = pnew;
		pend = pnew;
		pend->next = NULL;
	}
	return head;
}

//��ʦ��������
teacher* chain_tea(int n)//����n���ڵ�
{
	//�����һ���ڵ�
	teacher* head = NULL, * pnew = NULL, * pend = NULL;
	int i = 1;
	head = (teacher*)malloc(sizeof(teacher));
	pend = head;
	//����n���ڵ�
	for (; i < n; i++)
	{
		pnew = (teacher*)malloc(sizeof(teacher));
		pend->next = pnew;
		pend = pnew;
		pend->next = NULL;
	}
	return head;
}

//��Ŀ��������
question* chain_que(int n)//����n���ڵ�
{
	//�����һ���ڵ�
	question* head = NULL, * pnew = NULL, * pend = NULL;
	int i = 1;
	head = (question*)malloc(sizeof(question));
	pend = head;
	//����n���ڵ�
	for (; i < n; i++)
	{
		pnew = (question*)malloc(sizeof(question));
		pend->next = pnew;
		pend = pnew;
		pend->next = NULL;
	}
	return head;
}

////////////////////////////////////////////////////////////////////////////////////////////�����������룡����

//ѧ����������
void input_stu(student* p,int mark)
{
	printf("������ѧ������:");
	scanf("%s", &p->name);
	clear_buffer();
	printf("ע��ѧ����λ��Ϊ0\n");
	printf("������ѧ��:");
	scanf("%d", &p->id);
	clear_buffer();
	printf("ע��������λ��Ϊ0\n");
	printf("����������:");
	scanf("%d", &p->passward);
	clear_buffer();
	if (mark == 1) {
		p->score = 0;//������0
	}
}

//��ʦ��������
void input_tea(teacher* p)
{
	printf("�������ʦ����:");
	scanf("%s", &p->name);
	clear_buffer();
	printf("ע����ʦ�����λ��Ϊ0\n");
	printf("�������ʦ���:");
	scanf("%d", &p->id);
	clear_buffer();
	printf("ע��������λ��Ϊ0\n");
	printf("����������:");
	scanf("%d", &p->passward);
	clear_buffer();
}

//������Ŀ��������
void input_que(question* p)
{
	printf("��������Ŀ��ţ�");
	scanf("%d", &p->id);

	printf("��������ɣ�");
	clear_buffer();
	fgets(p->stem, 299, stdin);
	remove_newline(p->stem);
	printf("������Aѡ�");
	//clear_buffer();
	fgets(p->A, 99, stdin);
	remove_newline(p->A);
	printf("������Bѡ�");
	//clear_buffer();
	fgets(p->B, 99, stdin);
	remove_newline(p->B);
	printf("������Cѡ�");
	//clear_buffer();
	fgets(p->C, 99, stdin);
	remove_newline(p->C);
	printf("������Dѡ�");
	//clear_buffer();
	fgets(p->D, 99, stdin);
	remove_newline(p->D);
	printf("��������ȷѡ�");
	//clear_buffer();
	p->answer=getchar();
}

// ȥ�� fgets ����� '\n' �ַ�
void remove_newline(char* str) 
{
	size_t len = strlen(str);
	if (len > 0 && str[len - 1] == '\n') {
		str[len - 1] = '\0';
	}
}

////////////////////////////////////////////////////////////////////////////////////////////�����������������

//����ѧ���������
void output_stu(student* p)
{
	printf("name:%s\nid:%d\nscore:%.2f\n",p->name,p->id,p->score);
}

//������ʦ�������
void output_tea(teacher* p)
{
	printf("name:%s\nid:%d\n", p->name, p->id);
}

//������Ŀ���
void output_que(question* p)
{
	printf("id:%d\nstem:%s\nA:%s\tB:%s\tC:%s\tD:%s\n", p->id, p->stem, p->A, p->B, p->C, p->D);
	printf("��ȷ�𰸣�%c\n\n",p->answer);
}

////////////////////////////////////////////////////////////////////////////////////////////////�������򣡣���

//����ָ�뷨��������(id)ѧ��
int sort_stu(student* head)
{
	student* current, * before, * after;
	int i,j;
	int count_i;
	int count = 0;
	current = head->next;
	//ȡ��������(��Ч����)
	while (current != NULL)
	{
		count++;//�õ�����ĳ���(��Ч����)
		current = current->next;
	}
	//����ð������
	count_i = count - 1;

	for (i = 0; i < count - 1; i++, count_i--)
	{
		before = head;
		current = head->next;
		after = current->next;
		for (j = 0; j < count_i; j++)
		{

			if (current->id > after->id)
			{
				student* after_after, * temp_current = current;
				before->next = after;
				after_after = after->next;//��after���һ���ڵ��ַ������
				after->next = current;
				current->next = after_after;

				//������ԭ����ָ������������ã����и���
				current = after;
				after = temp_current;
			}
			before = current;
			current = after;
			after = after->next;
		}
	}
	return 1;
}

//����ָ�뷨��������(score)ѧ��
int sort_stu_score(student* head)
{
	student* current, * before, * after;
	int i, j, count_i;
	int count = 0;
	current = head->next;
	//ȡ��������(��Ч����)
	while (current != NULL)
	{
		count++;//�õ�����ĳ���(��Ч����)
		current = current->next;
	}
	//����ð������
	count_i = count - 1;

	for (i = 0; i < count - 1; i++, count_i--)
	{
		before = head;
		current = head->next;
		after = current->next;
		for (j = 0; j < count_i; j++)
		{

			if (current->score < after->score)
			{
				student* after_after, * temp_current = current;
				before->next = after;
				after_after = after->next;//��after���һ���ڵ��ַ������
				after->next = current;
				current->next = after_after;

				//������ԭ����ָ������������ã����и���
				current = after;
				after = temp_current;
			}
			before = current;
			current = after;
			after = after->next;
		}
	}
	return 1;

}

//����ָ�뷨��������(id)��ʦ
int sort_tea(teacher* head)
{
	teacher* current, * before, * after;
	int i, j, count_i;
	int count = 0;
	current = head->next;
	//ȡ��������(��Ч����)
	while (current != NULL)
	{
		count++;//�õ�����ĳ���(��Ч����)
		current = current->next;
	}
	//����ð������
	count_i = count - 1;

	for (i = 0; i < count - 1; i++, count_i--)
	{
		before = head;
		current = head->next;
		after = current->next;
		for (j = 0; j < count_i; j++)
		{

			if (current->id > after->id)
			{
				teacher* after_after, * temp_current = current;
				before->next = after;
				after_after = after->next;//��after���һ���ڵ��ַ������
				after->next = current;
				current->next = after_after;

				//������ԭ����ָ������������ã����и���
				current = after;
				after = temp_current;
			}
			before = current;
			current = after;
			after = after->next;
		}
	}
	return 1;
}

////����ָ�뷨��������(id)��Ŀ
int sort_que(question* head)
{
	question* current, * before, * after;
	int i, j, count_i;
	int count = 0;
	current = head->next;
	//ȡ��������(��Ч����)
	while (current != NULL)
	{
		count++;//�õ�����ĳ���(��Ч����)
		current = current->next;
	}
	//����ð������
	count_i = count - 1;

	for (i = 0; i < count - 1; i++, count_i--)
	{
		before = head;
		current = head->next;
		after = current->next;
		for (j = 0; j < count_i; j++)
		{

			if (current->id > after->id)
			{
				question* after_after, * temp_current = current;
				before->next = after;
				after_after = after->next;//��after���һ���ڵ��ַ������
				after->next = current;
				current->next = after_after;

				//������ԭ����ָ������������ã����и���
				current = after;
				after = temp_current;
			}
			before = current;
			current = after;
			after = after->next;
		}
	}
	return 1;
}

//////////////////////////////////////////////////////////////////////////////////////////////////����༭������
//�ڵ�site���ڵ�֮�󴦲���һ���½ڵ�(�ӵڶ�λ��ʼ��ȡ)
student* insert_stu(student* head, int site)
{
	int count = 0;
	student* p = head->next;

	while (p != NULL)
	{
		count++;
		if (count == site)
		{
			student* p_old = NULL, * pnew = NULL;
			pnew = (student*)malloc(sizeof(student));//����һ���½ڵ�
			p_old = p->next;
			p->next = pnew;
			pnew->next = p_old;
			return pnew;
		}
		p = p->next;
	}
	return NULL;//ʧ�ܷ���NULL
}

//������Ŀ���ɾ����Ŀ
void delete_stu(student* head, int id)
{
	student* before = head, * current = head->next;
	while (current != NULL)
	{
		if (current->id == id)
		{
			before->next = current->next;
			free(current);//�ͷŸýڵ��ڴ�
			return;
		}
		before = before->next;
		current = current->next;
	}
}

//�ڵ�site���ڵ�֮�󴦲���һ���½ڵ�(�ӵڶ�λ��ʼ��ȡ)
teacher* insert_tea(teacher* head, int site)
{
	int count = 0;
	teacher* p = head->next;

	while (p != NULL)
	{
		count++;
		if (count == site)
		{
			teacher* p_old = NULL, * pnew = NULL;
			pnew = (teacher*)malloc(sizeof(teacher));//����һ���½ڵ�
			p_old = p->next;
			p->next = pnew;
			pnew->next = p_old;
			return pnew;
		}
		p = p->next;
	}
	return NULL;//ʧ�ܷ���NULL
}

//������Ŀ���ɾ����Ŀ
void delete_tea(teacher* head, int id)
{
	teacher* before = head, * current = head->next;
	while (current != NULL)
	{
		if (current->id == id)
		{
			before->next = current->next;
			free(current);//�ͷŸýڵ��ڴ�
			return;
		}
		before = before->next;
		current = current->next;
	}
}

//�ڵ�site���ڵ�֮�󴦲���һ���½ڵ�(�ӵڶ�λ��ʼ��ȡ)
question* insert_que(question* head, int site)
{
	int count = 0;
	question* p = head->next;

	while (p != NULL)
	{
		count++;
		if (count == site)
		{
			question* p_old = NULL, * pnew = NULL;
			pnew = (question*)malloc(sizeof(question));//����һ���½ڵ�
			p_old = p->next;
			p->next = pnew;
			pnew->next = p_old;
			return pnew;
		}
		p = p->next;
	}
	sort_que(head);
	return NULL;//ʧ�ܷ���NULL
}

//������Ŀ���ɾ����Ŀ
void delete_que(question* head, int id)
{
	question *before=head, *current = head->next;
	while (current->next != NULL)
	{
		if (current->id == id)
		{
			before->next = current->next;
			free(current);//�ͷŸýڵ��ڴ�
			return;
		}
		before = before->next;
		current = current->next;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////ѧ�����⣡����
int rondom_s(int array[11])
{
	int i, j;
	// �������������
	srand((unsigned int)time(NULL));
	// ���ɵ�һ�����������������
	array[0] = rand() % 20 + 1;
	for (i = 1; i < 10; i++) {
		int new_num;
		do {
			new_num = rand() % 20 + 1;
			// ��������ɵ����Ƿ��Ѿ���������
			for (j = 0; j < i; j++) {
				if (array[j] == new_num) {
					break;
				}
			}
		} while (j < i);
		array[i] = new_num;
	}
	return 1;
}

////����
//void da_ti(question* head,student* current, int array[])
//{
//	int i = 0;
//	question* p = head->next;
//	for (; i < 10; i++)
//	{
//		while (p != NULL)
//		{
//			p = head->next;
//			if (p->id == array[i])
//			{
//				char c;
//				printf("��ش��%d��\n",i+1);
//				printf("��Ŀ:%d\n%s\nA:%s \tB:%s \tC:%s \tD:%s\n",p->id,p->stem,p->A,p->B,p->C,p->D);
//				printf("��������Ĵ𰸣�");
//				scanf("%c", &c);
//				if (c == p->answer)
//				{
//					current->score += 10;
//					printf("�����ˣ�\n");
//				}
//				else
//				{
//					printf("���ź��������ˣ�\n");
//					printf("��ȷ�𰸣�%c\n",p->answer);
//				}
//				break;
//			}
//		}
//	}
//
//}
// ����
void da_ti(question* head, student* current, int array[])
{
	int i = 0;
	question* p = head->next;
	printf("********************************************************************************************\n");
	printf("��ʼ���⣡����\n");
	for (; i < 10; i++)
	{
		// �����������ƥ�����Ŀ
		p = head->next;
		while (p != NULL)
		{
			if (p->id == array[i])
			{
				char c;
				printf("��ش��%d��\n", i + 1);
				printf("��Ŀ���:%d\n%s\nA:%s\tB:%s\tC:%s\tD:%s\n", p->id, p->stem, p->A, p->B, p->C, p->D);
				// ���� '\n' �ַ�
				getchar();
				printf("��������Ĵ𰸣�");
				scanf("%c", &c);
				if (c == p->answer)
				{
					current->score += 10;
					printf("�����ˣ�\n\n");
				}
				else
				{
					printf("���ź��������ˣ�\n");
					printf("��ȷ�𰸣�%c\n\n", p->answer);
				}
				break;
			}
			p = p->next;
		}
		if (p == NULL) {
			printf("δ�ҵ����Ϊ %d ����Ŀ\n", array[i]);
		}
	}
	printf("********************************************************************************************\n");
}

//////////////////////////////////////////////////////////////////////////////////////////////////////�˳�������
void out(int* sign_in_mark)
{
	printf("��ѡ���Ƿ��˳�ϵͳ\n");
	printf("0 ��\t 1 ��\n");
	scanf("%d", sign_in_mark);
}

void out2(int* sign_in_mark)
{
	printf("��ѡ���Ƿ��˳�ϵͳ\n");
	printf("1 ��\t 2 ��\n");
	scanf("%d", sign_in_mark);
}