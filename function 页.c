#include"header.h"

////////////////////////////////////////////////////////////////////////////////////文件操控！！！

//打开所有使用文件
int open(FILE *student,FILE *teacher,FILE *question)
{
	student=fopen("student.dat","rb+");
	if (student == NULL) {
		perror("student.dat文件打开失败");
		return 0;
	}
	teacher=fopen("teacher.dat","rb+");
	if (teacher == NULL) {
		perror("teacher.dat文件打开失败");
		return 0;
	}
	question=fopen("question.dat","rb+");
	if (question == NULL) {
		perror("question.dat文件打开失败");
		return 0;
	}
	return 1;
}

//关闭所有文件
int close(FILE* student, FILE* teacher, FILE* question)
{
	fclose(student);
	fclose(teacher);
	fclose(question);
	return 1;
}

////////////////////////////////////////////////////////////////////////////////////文件数据读取！！！

//读取学生文件到链表
int read_stu(student* head, FILE* stu,int sum_stu)
{
	//int sum_stu,i;
	int i;
	student* p = head;
	//sum_stu=count_stu(stu);
	for (i = 0; i < sum_stu; i++)
	{
		p = p->next;//跳过第一个空白表头
		fread(p, sizeof(student) - sizeof(student*), 1, stu);
	}
	return 1;
}

//读取教师文件到链表
int read_tea(teacher* head, FILE* tea,int sum_tea)
{
	//int sum_tea, i;
	int i;
	teacher* p = head;
	//sum_tea = count_stu(tea);
	for (i = 0; i < sum_tea; i++)
	{
		p = p->next;//跳过第一个空白表头
		fread(p, sizeof(teacher) - sizeof(teacher*), 1, tea);
	}
	return 1;
}

//读取题目文件到链表
int read_que(question* head, FILE* que,int sum_que)
{
	//int sum_que, i;
	int i;
	question* p = head;
	//sum_que = count_stu(que);
	for (i = 0; i < sum_que; i++)
	{
		p = p->next;//跳过第一个空白表头
		fread(p, sizeof(question) - sizeof(question*), 1, que);
	}
	return 1;
}

////////////////////////////////////////////////////////////////////////////////////链表数据写入入文件！！！

//将学生链表中数据存入文件
int write_stu(student* head,FILE *stu)
{
	int i,count=0;
	student* p = head->next;//第一个有效节点，既是第二个节点
	while (p != NULL)//计算有效节点是个数
	{
		count++;
		p = p->next;
	}
	//写入
	p = head;
	for (i = 0; i < count; i++)
	{
		p = p->next;
		fwrite(p, sizeof(student) - sizeof(student*), 1, stu);
	}
	return 1;
}

//将教师链表中数据存入文件
int write_tea(teacher* head, FILE* tea)
{
	int i, count = 0;
	teacher* p = head->next;//第一个有效节点，既是第二个节点
	while (p != NULL)//计算有效节点是个数
	{
		count++;
		p = p->next;
	}
	//写入
	p = head;
	for (i = 0; i < count; i++)
	{
		p = p->next;
		fwrite(p, sizeof(teacher) - sizeof(teacher*), 1, tea);
	}
	return 1;
}

//将问题链表中数据存入文件
int write_que(question* head, FILE* que)
{
	int i, count = 0;
	question* p = head->next;//第一个有效节点，既是第二个节点
	while (p != NULL)//计算有效节点是个数
	{
		count++;
		p = p->next;
	}
	//写入
	p = head;
	for (i = 0; i < count; i++)
	{
		p = p->next;
		fwrite(p, sizeof(question) - sizeof(question*), 1, que);
	}
	return 1;
}

/////////////////////////////////////////////////////////////////////////////////////节点计数！！！

//计算学生文件中数据的节点数
int count_stu(FILE *fofstu)
{
	int bytes,count;
	fseek(fofstu,0,SEEK_END);
	bytes = ftell(fofstu);
	count = bytes / (sizeof(student) - sizeof(student*));//得到存储的节点数
	fseek(fofstu,0,SEEK_SET);//将文件指针重新置于开始位置
	return count;
}

//计算教师文件中数据的节点数
int count_tea(FILE* foftea)
{
	int bytes, count;
	fseek(foftea, 0, SEEK_END);
	bytes = ftell(foftea);
	count = bytes / (sizeof(teacher) - sizeof(teacher*));//得到存储的节点数
	fseek(foftea, 0, SEEK_SET);//将文件指针重新置于开始位置
	return count;
}

//计算问题文件中数据的节点数
int count_que(FILE* fofque)
{
	int bytes, count;
	fseek(fofque, 0, SEEK_END);
	bytes = ftell(fofque);
	count = bytes / (sizeof(question) - sizeof(question*));//得到存储的节点数
	fseek(fofque, 0, SEEK_SET);//将文件指针重新置于开始位置
	return count;
}

////////////////////////////////////////////////////////////////////////////////////////登录！！！

//学生密码登录
student* sign_in_stu(student *head)
{
	student* p;
	int id, passward;//接受输入的密码
	printf("请输入id：");
	scanf("%d", &id);
	printf("请输入密码：");
	scanf("%d",&passward);
	//登录对比
	p = head->next;
	while (p != NULL) 
	{
		//先通过学号找到对应学生
		if (p->id == id)
		{
			if (p->passward == passward)
				return p;//登陆成功返回对应学生的指针
			else
				return NULL;
		}
		p = p->next;
	}
	return NULL;
}

//教师密码登录
teacher* sign_in_tea(teacher* head)
{
	teacher* p;
	int id, passward;//接受输入的密码
	printf("请输入id：");
	scanf("%d", &id);
	printf("请输入密码：");
	scanf("%d", &passward);
	//登录对比
	 p= head->next;
	while (p != NULL)
	{
		//先通过学号找到对应学生
		if (p->id == id)
		{
			if (p->passward == passward)
				return p;//登陆成功返回对应学生的指针
			else
				return NULL;
		}
		p = p->next;
	}
	return NULL;
}

///////////////////////////////////////////////////////////////////////////////////////////辅助函数！！！

//大小写字母转换大写
void convert(char* str)
{
	if (*str >= 97 && *str <= 122)
	{
		*str -= 32;
	}
}

//stdin输入流缓冲区清除
void clear_buffer()
{
	char ch='0';
	while (ch = getchar() != '\n' && ch != EOF)
	{
		//把非换行符的所有残留去除直到末尾或'\n',并且会把遇到第一个'\n'也去除
	}
}

////////////////////////////////////////////////////////////////////////////////////////////链表生成！！！

//学生链表生成
student* chain_stu(int n)//生成n个节点
{
	//定义第一个节点
	student* head = NULL, * pnew = NULL, *pend = NULL;
	int i = 1;
	head = (student*)malloc(sizeof(student));
	pend = head;
	//生成n个节点
	for (; i < n; i++)
	{ 
		pnew = (student*)malloc(sizeof(student));
		pend->next = pnew;
		pend = pnew;
		pend->next = NULL;
	}
	return head;
}

//教师链表生成
teacher* chain_tea(int n)//生成n个节点
{
	//定义第一个节点
	teacher* head = NULL, * pnew = NULL, * pend = NULL;
	int i = 1;
	head = (teacher*)malloc(sizeof(teacher));
	pend = head;
	//生成n个节点
	for (; i < n; i++)
	{
		pnew = (teacher*)malloc(sizeof(teacher));
		pend->next = pnew;
		pend = pnew;
		pend->next = NULL;
	}
	return head;
}

//题目链表生成
question* chain_que(int n)//生成n个节点
{
	//定义第一个节点
	question* head = NULL, * pnew = NULL, * pend = NULL;
	int i = 1;
	head = (question*)malloc(sizeof(question));
	pend = head;
	//生成n个节点
	for (; i < n; i++)
	{
		pnew = (question*)malloc(sizeof(question));
		pend->next = pnew;
		pend = pnew;
		pend->next = NULL;
	}
	return head;
}

////////////////////////////////////////////////////////////////////////////////////////////链表数据输入！！！

//学生数据输入
void input_stu(student* p,int mark)
{
	printf("请输入学生姓名:");
	scanf("%s", &p->name);
	clear_buffer();
	printf("注：学号首位不为0\n");
	printf("请输入学号:");
	scanf("%d", &p->id);
	clear_buffer();
	printf("注：密码首位不为0\n");
	printf("请设置密码:");
	scanf("%d", &p->passward);
	clear_buffer();
	if (mark == 1) {
		p->score = 0;//分数置0
	}
}

//教师数据输入
void input_tea(teacher* p)
{
	printf("请输入教师姓名:");
	scanf("%s", &p->name);
	clear_buffer();
	printf("注：教师编号首位不为0\n");
	printf("请输入教师编号:");
	scanf("%d", &p->id);
	clear_buffer();
	printf("注：密码首位不为0\n");
	printf("请设置密码:");
	scanf("%d", &p->passward);
	clear_buffer();
}

//单个题目数据输入
void input_que(question* p)
{
	printf("请输入题目编号：");
	scanf("%d", &p->id);

	printf("请输入题干：");
	clear_buffer();
	fgets(p->stem, 299, stdin);
	remove_newline(p->stem);
	printf("请输入A选项：");
	//clear_buffer();
	fgets(p->A, 99, stdin);
	remove_newline(p->A);
	printf("请输入B选项：");
	//clear_buffer();
	fgets(p->B, 99, stdin);
	remove_newline(p->B);
	printf("请输入C选项：");
	//clear_buffer();
	fgets(p->C, 99, stdin);
	remove_newline(p->C);
	printf("请输入D选项：");
	//clear_buffer();
	fgets(p->D, 99, stdin);
	remove_newline(p->D);
	printf("请输入正确选项；");
	//clear_buffer();
	p->answer=getchar();
}

// 去除 fgets 读入的 '\n' 字符
void remove_newline(char* str) 
{
	size_t len = strlen(str);
	if (len > 0 && str[len - 1] == '\n') {
		str[len - 1] = '\0';
	}
}

////////////////////////////////////////////////////////////////////////////////////////////链表数据输出！！！

//单个学生数据输出
void output_stu(student* p)
{
	printf("name:%s\nid:%d\nscore:%.2f\n",p->name,p->id,p->score);
}

//单个教师数据输出
void output_tea(teacher* p)
{
	printf("name:%s\nid:%d\n", p->name, p->id);
}

//单个题目输出
void output_que(question* p)
{
	printf("id:%d\nstem:%s\nA:%s\tB:%s\tC:%s\tD:%s\n", p->id, p->stem, p->A, p->B, p->C, p->D);
	printf("正确答案：%c\n\n",p->answer);
}

////////////////////////////////////////////////////////////////////////////////////////////////链表排序！！！

//交换指针法进行排序(id)学生
int sort_stu(student* head)
{
	student* current, * before, * after;
	int i,j;
	int count_i;
	int count = 0;
	current = head->next;
	//取到链表长度(有效长度)
	while (current != NULL)
	{
		count++;//得到链表的长度(有效长度)
		current = current->next;
	}
	//进行冒泡排序
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
				after_after = after->next;//将after后的一个节点地址存下来
				after->next = current;
				current->next = after_after;

				//交换后原来的指针变量名不适用，进行更改
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

//交换指针法进行排序(score)学生
int sort_stu_score(student* head)
{
	student* current, * before, * after;
	int i, j, count_i;
	int count = 0;
	current = head->next;
	//取到链表长度(有效长度)
	while (current != NULL)
	{
		count++;//得到链表的长度(有效长度)
		current = current->next;
	}
	//进行冒泡排序
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
				after_after = after->next;//将after后的一个节点地址存下来
				after->next = current;
				current->next = after_after;

				//交换后原来的指针变量名不适用，进行更改
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

//交换指针法进行排序(id)教师
int sort_tea(teacher* head)
{
	teacher* current, * before, * after;
	int i, j, count_i;
	int count = 0;
	current = head->next;
	//取到链表长度(有效长度)
	while (current != NULL)
	{
		count++;//得到链表的长度(有效长度)
		current = current->next;
	}
	//进行冒泡排序
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
				after_after = after->next;//将after后的一个节点地址存下来
				after->next = current;
				current->next = after_after;

				//交换后原来的指针变量名不适用，进行更改
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

////交换指针法进行排序(id)题目
int sort_que(question* head)
{
	question* current, * before, * after;
	int i, j, count_i;
	int count = 0;
	current = head->next;
	//取到链表长度(有效长度)
	while (current != NULL)
	{
		count++;//得到链表的长度(有效长度)
		current = current->next;
	}
	//进行冒泡排序
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
				after_after = after->next;//将after后的一个节点地址存下来
				after->next = current;
				current->next = after_after;

				//交换后原来的指针变量名不适用，进行更改
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

//////////////////////////////////////////////////////////////////////////////////////////////////链表编辑！！！
//在第site个节点之后处插入一个新节点(从第二位开始读取)
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
			pnew = (student*)malloc(sizeof(student));//创建一个新节点
			p_old = p->next;
			p->next = pnew;
			pnew->next = p_old;
			return pnew;
		}
		p = p->next;
	}
	return NULL;//失败返回NULL
}

//根据题目编号删除题目
void delete_stu(student* head, int id)
{
	student* before = head, * current = head->next;
	while (current != NULL)
	{
		if (current->id == id)
		{
			before->next = current->next;
			free(current);//释放该节点内存
			return;
		}
		before = before->next;
		current = current->next;
	}
}

//在第site个节点之后处插入一个新节点(从第二位开始读取)
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
			pnew = (teacher*)malloc(sizeof(teacher));//创建一个新节点
			p_old = p->next;
			p->next = pnew;
			pnew->next = p_old;
			return pnew;
		}
		p = p->next;
	}
	return NULL;//失败返回NULL
}

//根据题目编号删除题目
void delete_tea(teacher* head, int id)
{
	teacher* before = head, * current = head->next;
	while (current != NULL)
	{
		if (current->id == id)
		{
			before->next = current->next;
			free(current);//释放该节点内存
			return;
		}
		before = before->next;
		current = current->next;
	}
}

//在第site个节点之后处插入一个新节点(从第二位开始读取)
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
			pnew = (question*)malloc(sizeof(question));//创建一个新节点
			p_old = p->next;
			p->next = pnew;
			pnew->next = p_old;
			return pnew;
		}
		p = p->next;
	}
	sort_que(head);
	return NULL;//失败返回NULL
}

//根据题目编号删除题目
void delete_que(question* head, int id)
{
	question *before=head, *current = head->next;
	while (current->next != NULL)
	{
		if (current->id == id)
		{
			before->next = current->next;
			free(current);//释放该节点内存
			return;
		}
		before = before->next;
		current = current->next;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////学生答题！！！
int rondom_s(int array[11])
{
	int i, j;
	// 设置随机数种子
	srand((unsigned int)time(NULL));
	// 生成第一个随机数并放入数组
	array[0] = rand() % 20 + 1;
	for (i = 1; i < 10; i++) {
		int new_num;
		do {
			new_num = rand() % 20 + 1;
			// 检查新生成的数是否已经在数组中
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

////答题
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
//				printf("请回答第%d题\n",i+1);
//				printf("题目:%d\n%s\nA:%s \tB:%s \tC:%s \tD:%s\n",p->id,p->stem,p->A,p->B,p->C,p->D);
//				printf("请输入你的答案：");
//				scanf("%c", &c);
//				if (c == p->answer)
//				{
//					current->score += 10;
//					printf("你答对了！\n");
//				}
//				else
//				{
//					printf("很遗憾，你答错了！\n");
//					printf("正确答案：%c\n",p->answer);
//				}
//				break;
//			}
//		}
//	}
//
//}
// 答题
void da_ti(question* head, student* current, int array[])
{
	int i = 0;
	question* p = head->next;
	printf("********************************************************************************************\n");
	printf("开始答题！！！\n");
	for (; i < 10; i++)
	{
		// 遍历链表查找匹配的题目
		p = head->next;
		while (p != NULL)
		{
			if (p->id == array[i])
			{
				char c;
				printf("请回答第%d题\n", i + 1);
				printf("题目编号:%d\n%s\nA:%s\tB:%s\tC:%s\tD:%s\n", p->id, p->stem, p->A, p->B, p->C, p->D);
				// 跳过 '\n' 字符
				getchar();
				printf("请输入你的答案：");
				scanf("%c", &c);
				if (c == p->answer)
				{
					current->score += 10;
					printf("你答对了！\n\n");
				}
				else
				{
					printf("很遗憾，你答错了！\n");
					printf("正确答案：%c\n\n", p->answer);
				}
				break;
			}
			p = p->next;
		}
		if (p == NULL) {
			printf("未找到编号为 %d 的题目\n", array[i]);
		}
	}
	printf("********************************************************************************************\n");
}

//////////////////////////////////////////////////////////////////////////////////////////////////////退出！！！
void out(int* sign_in_mark)
{
	printf("请选择是否退出系统\n");
	printf("0 是\t 1 否\n");
	scanf("%d", sign_in_mark);
}

void out2(int* sign_in_mark)
{
	printf("请选择是否退出系统\n");
	printf("1 是\t 2 否\n");
	scanf("%d", sign_in_mark);
}