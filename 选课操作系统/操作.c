#include <stdio.h>
#include<string.h>


void firstprint(void);
void studentprint(void);
void courseprint(void);
void chooseprint(void);

void studentmove(void);
void addstudent(void);
void deletestudent(void);
void changestudent(void);
void checkstudent(void);

void coursemove(void);
void course_add(void);
void course_delete(void);
void course_change(void);
void course_check(void);

void choosemove(void);
void course_choose(void);
void course_choosedelete(void);
void grade_get(void);
void choose_check(void);

int N=0;
struct STUDENT
{
	char stuId[10];
	char stuName[10];
	char stuSex[2];
}stu[10000];

struct COURSE
{
	char couId[10], couName[20];
	int stuNum, curStuNum;
	float aveScore;
}cour[1000];

struct CHOOSESTUDENT
{
	char choid[10];
	float grade;
};
int main()
{
	//FILE *fp = fopen("student.txt", "w");
	//fclose(fp);
	int move;
	firstprint();
	scanf("%d", &move);
	system("cls");
	while (move!=4)
	{
		switch (move)
		{
		case 1:studentmove();  break;
		case 2:coursemove(); break;
		case 3:choosemove(); break;
		default:printf("���벻�������������������롣\n");
		}
		firstprint();
		scanf("%d", &move);
		system("cls");
	}
	printf("\n\nллʹ�ã���Ե�ټ�!\n");
	system("pause");
	return 0;
}

void studentmove(void)
{
	int move;
	studentprint();
	scanf("%d", &move);
	system("cls");
	while (move!=5)
	{
		switch (move)
		{
		case 1:addstudent(); break;
		case 2:deletestudent(); break;
		case 3:changestudent(); break;
		case 4:checkstudent(); break;
		default:printf("���벻�������������������롣\n");
		}
		studentprint();
		scanf("%d", &move);
		system("cls");
	}
	
}
void coursemove(void)
{
	int move;
	courseprint();
	scanf("%d", &move);
	system("cls");
	while (move != 5)
	{
		switch (move)
		{
		case 1:course_add(); break;
		case 2:course_delete(); break;
		case 3:course_change(); break;
		case 4:course_check(); break;
		case 5:break;
		default:printf("���벻�������������������롣\n");
		}
		courseprint();
		scanf("%d", &move);
		system("cls");
	}
}
void choosemove(void)
{
	int move;
	chooseprint();
	scanf("%d", &move);
	system("cls");
	while (move!=5)
	{
		switch (move)
		{
		case 1:course_choose(); break;
		case 2:course_choosedelete(); break;
		case 3:grade_get(); break;
		case 4:choose_check(); break;
		case 5:break;
		default:printf("���벻�������������������롣\n");
		}
		chooseprint();
		scanf("%d", &move);
		system("cls");
	}
}

void firstprint(void)
{
	printf("**************************��ӭ��ʹ��ѧ����Ϣ����ϵͳ***********************\n\n"
		"				1��ѧ����ز���\n"
		"				2���γ���ز���\n"
		"				3��ѡ����ز���\n"
		"				4���˳�ϵͳ\n\n"
		"***************************************************************************\n"
		"����������ѡ��"
	);
}
void studentprint(void)
{
	printf("************************************ѧ������*******************************\n\n"
		"				1�����ѧ����Ϣ\n"
		"				2��ɾ��ѧ����Ϣ\n"
		"				3������ѧ����Ϣ\n"
		"				4���鿴ѧ����Ϣ\n"
		"				5��������һ��\n\n"
		"***************************************************************************\n"
		"����������ѡ��"

	);
}
void courseprint(void)
{
	printf("***********************************�γ̲���********************************\n\n"
		"				1����ӿγ���Ϣ\n"
		"				2��ɾ���γ���Ϣ\n"
		"				3�����Ŀγ���Ϣ\n"
		"				4���鿴�γ���Ϣ\n"
		"				5��������һ��\n\n"
		"***************************************************************************\n"
		"����������ѡ��"

	);
}
void chooseprint(void)
{
	printf("*********************************ѡ����Ϣ����******************************\n\n"
		"				1��ѡ��\n"
		"				2����ѡ\n"
		"				3���ɼ�¼��\n"
		"				4���鿴ѡ����Ϣ\n"
		"				5��������һ��\n\n"
		"***************************************************************************\n"
		"����������ѡ��"

	);
}

void addstudent(void)
{
	int n,i;
	FILE *fp;
	if ((fp = fopen("student.txt", "a")) == NULL)
	{
		printf("�޷���student.txt�ļ�\n");
		exit(0);
	}
	printf("������Ҫ׷��ѧ����Ϣ��ѧ��������");
	scanf("%d", &n);
	system("cls");
	for (i = 0; i < n; i++)
	{
		printf("���Ⱥ������ѧ����ѧ�š��������Ա�(M/F)���м�ֱ��ÿո����:\n");
		scanf("%s %s %s", stu[N].stuId, stu[N].stuName, stu[N].stuSex);
		fprintf(fp, "%s %s %s\n", stu[N].stuId, stu[N].stuName, stu[N].stuSex);
		//printf("%s,%s,%s\n" ,stu[N].stuId, stu[N].stuName, stu[N].stuSex);
		N++;
	}
	system("cls");
	fclose(fp);
}
void deletestudent(void)
{
	struct STUDENT stu1[10000];
	int i = 0, j, jud = 1, choice;
	char c,name[10],id[10],ch;
	FILE *fp1,*fp2;
	if ((fp1 = fopen("student1.txt", "w")) == NULL)
	{
		printf("�޷���student1.txt�ļ�\n");
		exit(0);
	}
	fclose(fp1);
	if ((fp2 = fopen("student.txt", "r")) == NULL)
	{
		printf("����ѧ����Ϣ��\n");
	}
	else
	{
		ch = fgetc(fp2);
		if (ch == EOF)
		{
			printf("����ѧ����Ϣ��\n");
			fclose(fp2);
		}
		else
		{
			fclose(fp2);
			fp2 = fopen("student.txt", "r");
			while (1)
			{
				fscanf(fp2, "%s", stu1[i].stuId);
				fscanf(fp2, " %s", stu1[i].stuName);
				fscanf(fp2, " %s\n", stu1[i].stuSex);
				i++;
				//c = fgetc(fp2);
				if (feof(fp2)) break;
			}
			fclose(fp1);
			fclose(fp2);
			printf("***************************************************************************\n");
			printf("������ɾ��ѧ����Ϣ�ķ�ʽ��\n1.ѧ��\n2.����\n3.������һ��\n����������ѡ��");
			scanf("%d", &choice);
			printf("***************************************************************************\n");
			system("cls");
			while (choice != 3)
			{
				if ((fp1 = fopen("student1.txt", "w")) == NULL)
				{
					printf("�޷���student1.txt�ļ�\n");
					exit(0);
				}
				if ((fp2 = fopen("student.txt", "r")) == NULL)
				{
					printf("�޷���student.txt�ļ�\n");
					exit(0);
				}
				jud = 1;
				switch (choice)
				{
				case 1:printf("***************************************************************************\n");
					printf("������ɾ��ѧ����ѧ�ţ�");
					scanf("%s", id);
					printf("***************************************************************************\n");
					system("cls");
					for (j = 0; j < i; j++)
					{
						if (!strcmp(id, stu1[j].stuId))
						{
							jud = 0;
							for (; j < i - 1; j++)
							{
								stu1[j] = stu1[j + 1];
							}
							printf("***************************************************************************\n");
							printf("ɾ���ɹ�!\n");
						}
					}
					if (jud == 1)
					{
						printf("***************************************************************************\n");
						printf("û���ҵ�Ҫɾ����ѧ��.\n");
					}
					else
					{
						i--;
					}
					for (j = 0; j < i; j++)
					{
						fprintf(fp1, "%s %s %s\n", stu1[j].stuId, stu1[j].stuName, stu1[j].stuSex);
					}
					fclose(fp1);
					fclose(fp2);
					remove("student.txt");
					rename("student1.txt", "student.txt");
					break;
				case 2:printf("������ɾ��ѧ����������");
					scanf("%s", name);
					for (j = 0; j < i; j++)
					{
						if (!strcmp(name, stu1[j].stuName))
						{
							jud = 0;
							for (; j < i - 1; j++)
							{
								stu1[j] = stu1[j + 1];
							}
							printf("***************************************************************************\n");
							printf("ɾ���ɹ�!\n");
						}
					}
					if (jud == 1)
					{
						printf("***************************************************************************\n");
						printf("û���ҵ�Ҫɾ����ѧ��.\n");
					}
					else
					{
						i--;
					}
					for (j = 0; j < i; j++)
					{
						fprintf(fp1, "%s %s %s\n", stu1[j].stuId, stu1[j].stuName, stu1[j].stuSex);
					}
					fclose(fp1);
					fclose(fp2);
					remove("student.txt");
					rename("student1.txt", "student.txt");
					break;
				case 3:break;
				default:printf("���벻�������������������롣\n");
				}
				printf("***************************************************************************\n");
				printf("������ɾ��ѧ����Ϣ�ķ�ʽ��\n1.ѧ��\n2.����\n3.������һ��\n����������ѡ��");
				scanf("%d", &choice);
				printf("***************************************************************************\n");
				system("cls");
			}
		}
	}
	
	
}
void changestudent(void)
{
	struct STUDENT stu2[10000];
	int i = 0, j, jud = 1, choice;
	char c, name[10],id[10],ch;
	FILE *fp1, *fp2;
	if ((fp1 = fopen("student1.txt", "w")) == NULL)
	{
		printf("�޷���student1.txt�ļ�\n");
		exit(0);
	}
	fclose(fp1);
	if ((fp2 = fopen("student.txt", "r")) == NULL)
	{
		printf("����ѧ����Ϣ��\n");
	}
	else
	{
		ch = fgetc(fp2);
		if (ch == EOF)
		{
			printf("����ѧ����Ϣ��\n");
			fclose(fp2);
		}
		else
		{
			fclose(fp2);
			fp2 = fopen("student.txt", "r");
			while (1)
			{
				fscanf(fp2, "%s", stu2[i].stuId);
				fscanf(fp2, " %s", stu2[i].stuName);
				fscanf(fp2, " %s\n", stu2[i].stuSex);
				i++;
				//c = fgetc(fp2);
				if (feof(fp2)) break;
			}
			
			fclose(fp2);
			printf("***************************************************************************\n");
			printf("������ı�ѧ����Ϣ�ķ�ʽ��\n1.ѧ��\n2.����\n3.������һ��\n����������ѡ��");
			scanf("%d", &choice);
			printf("***************************************************************************\n");
			system("cls");
			while (choice != 3)
			{
				if ((fp1 = fopen("student1.txt", "w")) == NULL)
				{
					printf("�޷���student1.txt�ļ�\n");
					exit(0);
				}
				if ((fp2 = fopen("student.txt", "r")) == NULL)
				{
					printf("�޷���student.txt�ļ�\n");
					exit(0);
				}
				jud = 1;
				switch (choice)
				{
				case 1:printf("***************************************************************************\n");
					printf("��������Ҫ�ı���Ϣ��ѧ����ѧ�ţ�");
					scanf("%s", id);
					printf("***************************************************************************\n");
					system("cls");
					for (j = 0; j < i; j++)
					{
						if (!strcmp(id, stu2[j].stuId))
						{
							printf("�����������������");
							scanf("%s", stu2[j].stuName);
							printf("������������Ա�");
							scanf("%s", stu2[j].stuSex);
							printf("�����������ѧ�ţ�");
							scanf("%s", stu2[j].stuId);
							jud = 0;

							printf("������Ϣ�ɹ�!\n");
						}
					}
					if (jud == 1)
					{
						printf("û���ҵ�Ҫ���ĵ�ѧ��.\n");
					}
					for (j = 0; j < i; j++)
					{
						fprintf(fp1, "%s %s %s\n", stu2[j].stuId, stu2[j].stuName, stu2[j].stuSex);
					}
					fclose(fp1);
					fclose(fp2);
					remove("student.txt");
					rename("student1.txt", "student.txt");
					break;
				case 2:printf("�����������Ϣ��ѧ����������");
					scanf("%s", name);
					for (j = 0; j < i; j++)
					{
						if (!strcmp(name, stu2[j].stuName))
						{
							jud = 0;
							printf("�����������������");
							scanf("%s", stu2[j].stuName);
							printf("������������Ա�");
							scanf("%s", stu2[j].stuSex);
							printf("�����������ѧ�ţ�");
							scanf("%s", stu2[j].stuId);
							printf("������Ϣ�ɹ�!\n");
						}
					}
					if (jud == 1)
					{
						printf("û���ҵ�Ҫ������Ϣ��ѧ��.\n");
					}
					for (j = 0; j < i; j++)
					{
						fprintf(fp1, "%s %s %s\n", stu2[j].stuId, stu2[j].stuName, stu2[j].stuSex);
					}
					fclose(fp1);
					fclose(fp2);
					remove("student.txt");
					rename("student1.txt", "student.txt");
					break;
				case 3:break;
				default:printf("���벻�������������������롣\n");
				}
				printf("***************************************************************************\n");
				printf("������ı�ѧ����Ϣ�ķ�ʽ��\n1.ѧ��\n2.����\n3.������һ��\n����������ѡ��");
				scanf("%d", &choice);
				printf("***************************************************************************\n");
				system("cls");
			}
		}
	}
	
	
}
void checkstudent(void)
{
	struct STUDENT stu3[10000];
	int i = 0, j, jud = 1, choice,choice1;
	char c, name[10],id[10],ch;
	FILE  *fp2;
	if ((fp2 = fopen("student.txt", "r")) == NULL)
	{
		printf("***************************************************************************\n");
		printf("����ѧ����Ϣ��\n");
	}
	else
	{
		ch = fgetc(fp2);
		if (ch == EOF)
		{
			printf("***************************************************************************\n");
			printf("����ѧ����Ϣ��\n");
			fclose(fp2);
		}
		else
		{
			while (1)
			{
				fclose(fp2);
				fp2 = fopen("student.txt", "r");
				fscanf(fp2, "%s", stu3[i].stuId);
				fscanf(fp2, " %s", stu3[i].stuName);
				fscanf(fp2, " %s\n", stu3[i].stuSex);
				i++;
				//c = fgetc(fp2);
				if (feof(fp2)) break;
			}
			printf("***************************************************************************\n");
			printf("������鿴ѧ����Ϣ�ķ�ʽ��\n1.ȫ��\n2.����\n3.������һ��\n����������ѡ��");
			scanf("%d", &choice);
			printf("***************************************************************************\n");
			system("cls");
			while (choice != 3)
			{
				jud = 1;
				switch (choice)
				{
				case 1:printf("\tѧ��\t\t����\t\t�Ա�\n");
					for (j = 0; j < i; j++)
					{
						printf("\t%s\t\t%s\t\t%s\n", stu3[j].stuId, stu3[j].stuName, stu3[j].stuSex);
					}
					break;
				case 2:printf("***************************************************************************\n");
					printf("������鿴ѧ����Ϣ�ķ�����\n1.����\n2.ѧ��\n3.������һ��\n����������ѡ��");
					scanf("%d", &choice1);
					printf("***************************************************************************\n");
					system("cls");
					switch (choice1)
					{
					case 1:printf("��������Ҫ�鿴��Ϣ��ѧ����������");
						scanf("%s", name);
						for (j = 0; j < i; j++)
						{
							if (!strcmp(name, stu3[j].stuName))
							{
								jud = 0;
								printf("\tѧ��\t\t����\t\t�Ա�\n");
								printf("\t%s\t\t%s\t\t%s\n", stu3[j].stuId, stu3[j].stuName, stu3[j].stuSex);
							}
						}
						if (jud == 1)
						{
							printf("***************************************************************************\n");
							printf("û���ҵ���ѧ��.\n");
						}
						break;
					case 2:printf("***************************************************************************\n");
						printf("��������Ҫ�鿴��Ϣ��ѧ����ѧ�ţ�");
						scanf("%s", id);
						printf("***************************************************************************\n");
						system("cls");
						for (j = 0; j < i; j++)
						{
							if (!strcmp(id, stu3[j].stuId))
							{
								printf("\tѧ��\t\t����\t\t�Ա�\n");
								printf("\t%s\t\t%s\t\t%s\n", stu3[j].stuId, stu3[j].stuName, stu3[j].stuSex);

								jud = 0;
							}
						}
						if (jud == 1)
						{
							printf("***************************************************************************\n");
							printf("û���ҵ�Ҫ��ѧ��.\n");
						}
						break;
					case 3:break;
					default:
						break;
					}
					break;
				default:
					break;
				}
				printf("***************************************************************************\n");
				printf("������鿴ѧ����Ϣ�ķ�ʽ��\n1.ȫ��\n2.����\n3.������һ��\n����������ѡ��");
				scanf("%d", &choice);
				printf("***************************************************************************\n");
				system("cls");
			}

			fclose(fp2);
		}
		
	}
	
}

void course_add(void)
{
	int n, i;
	char name[20];
	FILE *fp,*fpp;
	if ((fp = fopen("course.txt", "a")) == NULL)
	{
		printf("�޷���course.txt�ļ�\n");
		exit(0);
	}
	printf("������Ҫ׷�ӿγ���Ϣ�Ŀγ̸�����");
	scanf("%d", &n);
	system("cls");
	for (i = 0; i < n; i++)
	{
		printf("���Ⱥ�����ÿγ̵ı�š����ơ��γ�������ѡ������(Ĭ��Ϊ0)��ƽ����(Ĭ��Ϊ0)���м�ֱ��ÿո����:\n");
		scanf("%s %s %d %d %f",cour[i].couId,cour[i].couName,&cour[i].stuNum,&cour[i].curStuNum,&cour[i].aveScore);
		system("cls");
		strcpy(name, cour[i].couName);
		strcat(name, ".txt");
		if ((fpp = fopen(name, "w")) == NULL)
		{
			printf("�޷�����%s�ļ�\n",cour[i].couName);
			exit(0);
		}
		fclose(fpp);
		fprintf(fp, "%s %s %d %d %f\n", cour[i].couId, cour[i].couName, cour[i].stuNum, cour[i].curStuNum, cour[i].aveScore);
		//printf("%s,%s,%s\n" ,stu[N].stuId, stu[N].stuName, stu[N].stuSex);
	}
	fclose(fp);
}
void course_delete(void)
{
	struct COURSE cour1[1000];
	int i = 0, j, jud = 1, choice;
	char c, name[20], id[10],ch;
	FILE *fp1, *fp2,*fpp;
	if ((fp1 = fopen("course1.txt", "w")) == NULL)
	{
		printf("�޷���course1.txt�ļ�\n");
		exit(0);
	}
	fclose(fp1);
	if ((fp2 = fopen("course.txt", "r")) == NULL)
	{
		printf("Ŀǰ�޿γ���Ϣ\n");
	}
	else
	{
		ch = fgetc(fp2);
		if (ch == EOF)
		{
			printf("���޿γ���Ϣ��\n");
			fclose(fp2);
		}
		else
		{
			fclose(fp2);
			fp2 = fopen("course.txt", "r");
			while (1)
			{
				fscanf(fp2, "%s", cour1[i].couId);
				fscanf(fp2, " %s", cour1[i].couName);
				fscanf(fp2, " %d", &cour1[i].stuNum);
				fscanf(fp2, " %d", &cour1[i].curStuNum);
				fscanf(fp2, " %f\n", &cour1[i].aveScore);
				i++;
				//c = fgetc(fp2);
				if (feof(fp2)) break;
			}
			fclose(fp2);
			printf("***************************************************************************\n");
			printf("������ɾ���γ���Ϣ�ķ�ʽ��\n1.���\n2.����\n3.������һ��\n����������ѡ��");
			scanf("%d", &choice);
			printf("***************************************************************************\n");
			system("cls");
			while (choice != 3)
			{
				if ((fp1 = fopen("course1.txt", "w")) == NULL)
				{
					printf("�޷���course1.txt�ļ�\n");
					exit(0);
				}
				if ((fp2 = fopen("course.txt", "r")) == NULL)
				{
					printf("�޷���course.txt�ļ�\n");
					exit(0);
				}
				jud = 1;
				switch (choice)
				{
				case 1:printf("***************************************************************************\n");
					printf("������ɾ���γ̵ı�ţ�");
					scanf("%s", id);
					printf("***************************************************************************\n");
					system("cls");
					for (j = 0; j < i; j++)
					{
						if (!strcmp(id, cour1[j].couId))
						{
							jud = 0;

							strcpy(name, cour1[j].couName);
							strcat(name, ".txt");

							if (remove(name) == 0)
								printf("ɾ���ɹ�!\n");
							else
							{
								perror("remove");
							}

							for (; j < i - 1; j++)
							{
								cour1[j] = cour1[j + 1];
							}

						}
					}
					if (jud == 1)
					{
						printf("û���ҵ�Ҫɾ���Ŀγ�.\n");
					}
					else
					{
						i--;
					}
					for (j = 0; j < i; j++)
					{
						fprintf(fp1, "%s %s %d %d %f\n", cour1[j].couId, cour1[j].couName, cour1[j].stuNum, cour1[j].curStuNum, cour1[j].aveScore);
					}
					fclose(fp1);
					fclose(fp2);
					remove("course.txt");
					rename("course1.txt", "course.txt");
					break;
				case 2:printf("������ɾ���γ̵����ƣ�");
					scanf("%s", name);
					for (j = 0; j < i; j++)
					{
						if (!strcmp(name, cour1[j].couName))
						{
							jud = 0;

							strcpy(name, cour1[j].couName);
							strcat(name, ".txt");
							if (remove(name) == 0)
								printf("ɾ���ɹ�!\n");
							else
							{
								perror("remove");
							}

							for (; j < i - 1; j++)
							{
								cour1[j] = cour1[j + 1];
							}
						}
					}
					if (jud == 1)
					{
						printf("û���ҵ�Ҫɾ���Ŀγ�.\n");
					}
					else
					{
						i--;
					}
					for (j = 0; j < i; j++)
					{
						fprintf(fp1, "%s %s %d %d %f\n", cour1[j].couId, cour1[j].couName, cour1[j].stuNum, cour1[j].curStuNum, cour1[j].aveScore);
					}
					fclose(fp1);
					fclose(fp2);
					remove("course.txt");
					rename("course1.txt", "course.txt");
					break;
				case 3:break;
				default:printf("���벻�������������������롣\n");
				}
				printf("***************************************************************************\n");
				printf("������ɾ���γ���Ϣ�ķ�ʽ��\n1.���\n2.����\n3.������һ��\n����������ѡ��");
				scanf("%d", &choice);
				printf("***************************************************************************\n");
				system("cls");
			}
		}
	}
	
	
}
void course_change(void)
{
	struct COURSE cour2[1000];
	int i = 0, j, jud = 1, choice;
	char c, name[20],filename[20], id[10],ch;
	FILE *fp1, *fp2,*fpp;
	if ((fp1 = fopen("course1.txt", "w")) == NULL)
	{
		printf("�޷���course1.txt�ļ�\n");
		exit(0);
	}
	fclose(fp1);
	if ((fp2 = fopen("course.txt", "r")) == NULL)
	{
		printf("Ŀǰ�޿γ���Ϣ\n");
	}
	else
	{
		ch = fgetc(fp2);
		if (ch == EOF)
		{
			printf("���޿γ���Ϣ��\n");
			fclose(fp2);
		}
		else
		{
			fclose(fp2);
			fp2 = fopen("course.txt", "r");

			while (1)
			{
				fscanf(fp2, "%s", cour2[i].couId);
				fscanf(fp2, " %s", cour2[i].couName);
				fscanf(fp2, " %d", &cour2[i].stuNum);
				fscanf(fp2, " %d", &cour2[i].curStuNum);
				fscanf(fp2, " %f\n", &cour2[i].aveScore);
				i++;
				//c = fgetc(fp2);
				if (feof(fp2)) break;
			}
			fclose(fp2);
			printf("***************************************************************************\n");
			printf("������ı�γ���Ϣ�ķ�ʽ��\n1.���\n2.����\n3.������һ��\n����������ѡ��");
			scanf("%d", &choice);
			printf("***************************************************************************\n");
			system("cls");
			while (choice != 3)
			{
				if ((fp1 = fopen("course1.txt", "w")) == NULL)
				{
					printf("�޷���course1.txt�ļ�\n");
					exit(0);
				}
				if ((fp2 = fopen("course.txt", "r")) == NULL)
				{
					printf("�޷���course.txt�ļ�\n");
					exit(0);
				}
				jud = 1;
				switch (choice)
				{
				case 1:printf("***************************************************************************\n");
					printf("��������Ҫ�ı���Ϣ�Ŀγ̵ı�ţ�");
					scanf("%s", id);
					printf("***************************************************************************\n");
					system("cls");
					for (j = 0; j < i; j++)
					{
						if (!strcmp(id, cour2[j].couId))
						{
							strcpy(name, cour2[j].couName);
							strcat(name, ".txt");

							printf("������ÿγ̵����ƣ�");
							scanf("%s", cour2[j].couName);
							printf("������ÿγ̵Ŀγ�������");
							scanf("%d", &cour2[j].stuNum);
							printf("������ÿγ̵ı�ţ�");
							scanf("%s", cour2[j].couId);
							printf("������ÿγ̵�ѡ��������");
							scanf("%d", &cour2[j].curStuNum);
							printf("������ÿγ̵�ƽ���֣�");
							scanf("%f", &cour2[j].aveScore);
							jud = 0;
							strcpy(filename, cour2[j].couName);
							strcat(filename, ".txt");
							rename(name, filename);

							printf("������Ϣ�ɹ�!\n");
						}
					}
					if (jud == 1)
					{
						printf("û���ҵ�Ҫ���ĵĿγ�.\n");
					}
					for (j = 0; j < i; j++)
					{
						fprintf(fp1, "%s %s %d %d %f\n", cour2[j].couId, cour2[j].couName, cour2[j].stuNum, cour2[j].curStuNum, cour2[j].aveScore);
					}
					fclose(fp1);
					fclose(fp2);
					remove("course.txt");
					rename("course1.txt", "course.txt");
					break;
				case 2:printf("�����������Ϣ�Ŀγ̵����ƣ�");
					scanf("%s", name);
					for (j = 0; j < i; j++)
					{
						if (!strcmp(name, cour2[j].couName))
						{
							strcpy(name, cour2[j].couName);
							strcat(name, ".txt");

							jud = 0;
							printf("������ÿγ̵����ƣ�");
							scanf("%s", cour2[j].couName);
							printf("������ÿγ̵Ŀγ�������");
							scanf("%d", &cour2[j].stuNum);
							printf("������ÿγ̵ı�ţ�");
							scanf("%s", cour2[j].couId);
							printf("������ÿγ̵�ѡ��������");
							scanf("%d", &cour2[j].curStuNum);
							printf("������ÿγ̵�ƽ���֣�");
							scanf("%f", &cour2[j].aveScore);

							strcpy(filename, cour2[j].couName);
							strcat(filename, ".txt");
							rename(name, filename);
						}
					}
					if (jud == 1)
					{
						printf("û���ҵ�Ҫ������Ϣ�Ŀγ�.\n");
					}
					for (j = 0; j < i; j++)
					{
						fprintf(fp1, "%s %s %d %d %f\n", cour2[j].couId, cour2[j].couName, cour2[j].stuNum, cour2[j].curStuNum, cour2[j].aveScore);
					}
					fclose(fp1);
					fclose(fp2);
					remove("course.txt");
					rename("course1.txt", "course.txt");
					break;
				case 3:break;
				default:printf("���벻�������������������롣\n");
				}
				printf("***************************************************************************\n");
				printf("������ı�γ���Ϣ�ķ�ʽ��\n1.���\n2.����\n3.������һ��\n����������ѡ��");
				scanf("%d", &choice);
				printf("***************************************************************************\n");
				system("cls");
			}
		}

	}
	
	
}
void course_check(void)
{
	struct COURSE cour2[1000];
	int i = 0, j, jud = 1, choice,choice1;
	char c, name[20], id[10],ch;
	FILE *fp2;
	if ((fp2 = fopen("course.txt", "r")) == NULL)
	{
		printf("Ŀǰ�޿γ���Ϣ\n");
	}
	else
	{
		ch = fgetc(fp2);
		if (ch == EOF)
		{
			printf("���޿γ���Ϣ��\n");
			fclose(fp2);
		}
		else
		{
			fclose(fp2);
			fp2 = fopen("course.txt", "r");
			while (1)
			{
				fscanf(fp2, "%s", cour2[i].couId);
				fscanf(fp2, " %s", cour2[i].couName);
				fscanf(fp2, " %d", &cour2[i].stuNum);
				fscanf(fp2, " %d", &cour2[i].curStuNum);
				fscanf(fp2, " %f\n", &cour2[i].aveScore);
				i++;
				//c = fgetc(fp2);
				if (feof(fp2)) break;
			}
			printf("***************************************************************************\n");
			printf("������鿴�γ���Ϣ�ķ�ʽ��\n1.ȫ��\n2.���γ�\n3.������һ��\n����������ѡ��");
			scanf("%d", &choice);
			printf("***************************************************************************\n");
			system("cls");
			while (choice != 3)
			{
				jud = 1;
				switch (choice)
				{
				case 1:printf("\t���\t\t����\t\t�γ�����\tѡ������\tƽ����\n");
					for (j = 0; j < i; j++)
					{
						printf("\t%s\t\t%s\t\t%d\t\t%d\t\t%f\n", cour2[j].couId, cour2[j].couName, cour2[j].stuNum, cour2[j].curStuNum, cour2[j].aveScore);
					}
					break;
				case 2:printf("***************************************************************************\n");
					printf("������鿴�γ���Ϣ�ķ�����\n1.����\n2.���\n3.������һ��\n����������ѡ��");
					scanf("%d", &choice1);
					printf("***************************************************************************\n");
					system("cls");
					while (choice1 != 3)
					{
						jud = 1;
						switch (choice1)
						{
							jud = 1;
						case 1:printf("��������Ҫ�鿴��Ϣ�Ŀγ̵����ƣ�");
							scanf("%s", name);
							for (j = 0; j < i; j++)
							{
								if (!strcmp(name, cour2[j].couName))
								{
									jud = 0;
									printf("\t���\t\t����\t\t�γ�����\tѡ������\tƽ����\n");
									printf("\t%s\t\t%s\t\t%d\t\t%d\t\t%f\n", cour2[j].couId, cour2[j].couName, cour2[j].stuNum, cour2[j].curStuNum, cour2[j].aveScore);
								}
							}
							if (jud == 1)
							{
								printf("û���ҵ��ÿγ�.\n");
							}
							break;
						case 2:printf("***************************************************************************\n");
							printf("��������Ҫ�鿴��Ϣ�Ŀγ̵ı�ţ�");
							scanf("%s", id);
							printf("***************************************************************************\n");
							system("cls");
							for (j = 0; j < i; j++)
							{
								if (!strcmp(id, cour2[j].couId))
								{
									printf("\t���\t\t����\t\t�γ�����\tѡ������\tƽ����\n");
									printf("\t%s\t\t%s\t\t%d\t\t%d\t\t%f\n", cour2[j].couId, cour2[j].couName, cour2[j].stuNum, cour2[j].curStuNum, cour2[j].aveScore);

									jud = 0;
								}
							}
							if (jud == 1)
							{
								printf("û���ҵ�Ҫ�ÿγ�.\n");
							}
							break;
						case 3:break;
						default:printf("���벻�������������������롣\n");
						}
						printf("***************************************************************************\n");
						printf("������鿴�γ���Ϣ�ķ�����\n1.����\n2.���\n3.������һ��\n����������ѡ��");
						scanf("%d", &choice1);
						printf("***************************************************************************\n");
						system("cls");
					}
					break;
				case 3:break;
				default:printf("���벻�������������������롣\n");
				}
				printf("***************************************************************************\n");
				printf("������鿴�γ���Ϣ�ķ�ʽ��\n1.ȫ��\n2.���γ�\n3.������һ��\n����������ѡ��");
				scanf("%d", &choice);
				printf("***************************************************************************\n");
				system("cls");
			}
		}
		

		fclose(fp2);
	}
	
}

void course_choose(void)
{
	struct STUDENT stu1[10000];
	struct COURSE cour1[1000];
	int i = 0, k = 0, j, m, jud = 1, JUD = 1, jud1 = 1, jud2 = 1;
	float grade = 0.0;
	char id[10],courseid[10],coursename[20];
	FILE *fp, *fp1, *fp2;
	if ((fp1 = fopen("student.txt", "r")) == NULL)
	{
		printf("�޷���student.txt�ļ�\n");
		exit(0);
	}
	if ((fp2 = fopen("course.txt", "r")) == NULL)
	{
		printf("�޷���course.txt�ļ�\n");
		exit(0);
	}
	while (1)
	{
		fscanf(fp1, "%s", stu1[i].stuId);
		fscanf(fp1, " %s", stu1[i].stuName);
		fscanf(fp1, " %s\n", stu1[i].stuSex);
		i++;
		//c = fgetc(fp2);
		if (feof(fp1)) break;
	}
	while (1)
	{
		fscanf(fp2, "%s", cour1[k].couId);
		fscanf(fp2, " %s", cour1[k].couName);
		fscanf(fp2, " %d", &cour1[k].stuNum);
		fscanf(fp2, " %d", &cour1[k].curStuNum);
		fscanf(fp2, " %f\n", &cour1[k].aveScore);
		k++;
		//c = fgetc(fp2);
		if (feof(fp2)) break;
	}
	fclose(fp1);
	fclose(fp2);
	printf("***************************************************************************\n");
	printf("������Ҫѡ�ε�ѧ����ѧ�ţ���ſ���ѧ��ҳ���ѯ����");
	scanf("%s", id);
	printf("***************************************************************************\n");
	system("cls");
	for (j = 0; j < i; j++)
	{
		if (!strcmp(id, stu1[j].stuId))
		{
			printf("��ȷ�ϸ�ѧ������Ϣ��\n");
			printf("ѧ�ţ�%s\n������%s\n�Ա�:%s\n",stu1[j].stuId,stu1[j].stuName,stu1[j].stuSex);
			printf("ȷ��������1����֮������2��");
			scanf("%d", &jud1);
			printf("***************************************************************************\n");
			system("cls");
			jud=(jud1 == 1) ? 0:1;
		}
		if (jud == 0)
		{
			printf("ѧ�����ڡ�\n");
			printf("***************************************************************************\n");
			break;
		}
	}

	if (jud == 0)
	{
		printf("***************************************************************************\n");
		printf("������Ҫѡ�Ŀγ̵ı�ţ���ſ��ڿγ�ҳ���ѯ����");
		scanf("%s", courseid);
		printf("***************************************************************************\n");
		system("cls");
		for (m = 0; m < k; m++)
		{
			if (!strcmp(courseid, cour1[m].couId))
			{
				if (cour1[m].stuNum <= cour1[m].curStuNum)
				{
					JUD = 1;
					printf("�ÿ�����������������ѡ\n");
					break;
				}
				printf("��ȷ�ϸÿγ̵���Ϣ��\n");
				printf("��ţ�%s\n���ƣ�%s\n�γ�����:%d\n�ѱ�����:%d\n", cour1[m].couId, cour1[m].couName, cour1[m].stuNum, cour1[m].curStuNum);
				printf("ȷ��������1����֮������2��");
				scanf("%d", &jud2);
				printf("***************************************************************************\n");
				system("cls");
				JUD = (jud2 == 1) ? 0 : 1;
			}
			if (JUD == 0)
			{
				printf("�γ̴��ڡ�\n");
				printf("***************************************************************************\n");
				printf("�������!\n");
				break;
			}
			if (m == k - 1)
			{
				printf("�ÿγ̲����ڣ�\n");
			}
		}
		if (JUD == 0)
		{
			strcpy(coursename, cour1[m].couName);
			strcat(coursename, ".txt");
			if ((fp = fopen(coursename, "a")) == NULL)
			{
				printf("�޷���%s�ļ�\n", coursename);
				exit(0);
			}
			fprintf(fp, "%s %f\n", stu1[j].stuId, grade);
			fclose(fp);

			cour1[m].curStuNum++;
			
			if ((fp1 = fopen("course1.txt", "w")) == NULL)
			{
				printf("�޷���course1.txt�ļ�\n");
				exit(0);
			}
			for (i = 0; i < k; i++)
			{
				fprintf(fp1, "%s %s %d %d %f\n", cour1[i].couId, cour1[i].couName, cour1[i].stuNum, cour1[i].curStuNum, cour1[i].aveScore);
			}
			fclose(fp1);
			remove("course.txt");
			rename("course1.txt", "course.txt");
			printf("ѡ�γɹ�!\n");
		}
	}
}
void course_choosedelete(void)
{
	struct CHOOSESTUDENT chostu1[10000];
	struct COURSE cour1[1000];
	FILE *fp,*fp1;
	int i=0, j, m, k=0,jud=1;
	char courname[20],csname[20],stuid[10];
	printf("***************************************************************************\n");
	printf("������Ҫ��ѡ��׼ȷ�γ����ƣ����ƿ��ڿγ�ҳ���ѯ����");
	scanf("%s", courname);
	printf("***************************************************************************\n");
	system("cls");
	strcpy(csname, courname);
	strcat(courname, ".txt");
	if ((fp = fopen(courname, "r")) == NULL)
	{
		printf("�޷���%s�ļ�\n", courname);
		printf("%s�γ̲�����\n", csname);
		jud = 1;
	}
	else
	{
		if ((fp1 = fopen("����.txt", "w")) == NULL)
		{
			printf("�޷��򿪸���.txt�ļ�\n");
			exit(0);
		}
		while (1)
		{
			fscanf(fp, "%s", chostu1[i].choid);
			fscanf(fp, " %f\n", &chostu1[i].grade);
			i++;
			if (feof(fp)) break;
		}
		fclose(fp);
		printf("***************************************************************************\n");
		printf("������Ҫ��ѡ��ѧ����ѧ�ţ�����ѧ��ҳ���ѯ����");
		scanf("%s", stuid);
		printf("***************************************************************************\n");
		system("cls");
		for (j = 0; j < i; j++)
		{
			if (!strcmp(stuid, chostu1[j].choid))
			{
				jud = 0;
				for (; j < i - 1; j++)
				{
					chostu1[j] = chostu1[j + 1];
				}
				printf("������ѡ!\n");
			}
		}
		if (jud == 1)
		{
			printf("û���ҵ�Ҫ��ѡ��ѧ��.\n");
		}
		else
		{
			i--;
		}
		for (j = 0; j < i; j++)
		{
			fprintf(fp1, "%s %f\n", chostu1[j].choid,chostu1[j].grade);
		}
		fclose(fp1);
		fclose(fp);
		remove(courname);
		rename("����.txt", courname);
	}
	if (jud == 0)
	{
		if ((fp1 = fopen("course.txt", "r")) == NULL)
		{
			printf("�޷���course.txt�ļ�\n");
			exit(0);
		}
		if ((fp = fopen("course1.txt", "w")) == NULL)
		{
			printf("�޷���course1.txt�ļ�\n");
			exit(0);
		}
		while (1)
		{
			fscanf(fp1, "%s", cour1[k].couId);
			fscanf(fp1, " %s", cour1[k].couName);
			fscanf(fp1, " %d", &cour1[k].stuNum);
			fscanf(fp1, " %d", &cour1[k].curStuNum);
			fscanf(fp1, " %f\n", &cour1[k].aveScore);
			k++;
			//c = fgetc(fp1);
			if (feof(fp1)) break;
		}
		for (j = 0; j < k; j++)
		{
			if (!strcmp(csname, cour1[j].couName))
			{
				cour1[j].curStuNum--;
				printf("��ѡ�ɹ���\n");
				break;
			}
		}
		for (j = 0; j < k; j++)
		{
			fprintf(fp, "%s %s %d %d %f\n", cour1[j].couId, cour1[j].couName, cour1[j].stuNum, cour1[j].curStuNum, cour1[j].aveScore);
		}

		fclose(fp);
		fclose(fp1);
		remove("course.txt");
		rename("course1.txt", "course.txt");
	}
}
void grade_get(void)
{
	struct CHOOSESTUDENT chostu1[10000];
	struct COURSE cour1[1000];
	char courname[20], csname[20], stuid[10];
	FILE *fp, *fp1;
	int i = 0, j, m, k = 0, jud = 1,jud1=1;
	float sum = 0.0;
	printf("***************************************************************************\n");
	printf("������Ҫ¼��ɼ��Ŀγ̵�׼ȷ���ƣ����ƿ��ڿγ�ҳ���ѯ����");
	scanf("%s", courname);
	printf("***************************************************************************\n");
	system("cls");
	strcpy(csname, courname);
	strcat(courname, ".txt");
	if ((fp = fopen(courname, "r")) == NULL)
	{
		printf("�޷���%s�ļ�\n", courname);
		printf("%s�γ̲�����\n", csname);
		jud = 1;
	}
	else
	{
		if ((fp1 = fopen("one.txt", "w")) == NULL)
		{
			printf("�޷���one.txt�ļ�\n");
			exit(0);
		}
		while (1)
		{
			fscanf(fp, "%s", chostu1[i].choid);
			fscanf(fp, " %f\n", &chostu1[i].grade);
			i++;
			if (feof(fp)) break;
		}
		fclose(fp);
		printf("***************************************************************************\n");
		printf("������Ҫ¼��ɼ���ѧ����ѧ�ţ�����ѧ��ҳ���ѯ,����exit�˳�����");
		scanf("%s", stuid);
		printf("***************************************************************************\n");
		system("cls");
		while (strcmp(stuid, "exit"))
		{
			for (j = 0; j < i; j++)
			{
				if (!strcmp(stuid, chostu1[j].choid))
				{
					printf("����������ĳɼ�\n");
					scanf("%f", &chostu1[j].grade);
					printf("***************************************************************************\n");
					printf("¼��ɹ���\n");
					printf("***************************************************************************\n");
					break;
				}
				if (j == i - 1)
				{
					printf("��ѧ����û��ѡ�˿γ̣�\n");
					printf("***************************************************************************\n");
				}
			}
			printf("***************************************************************************\n");
			printf("������Ҫ¼��ɼ���ѧ����ѧ�ţ�����ѧ��ҳ���ѯ,����exit�˳�����");
			scanf("%s", stuid);
			printf("***************************************************************************\n");
			system("cls");
		}
		for (j = 0; j < i; j++)
		{
			fprintf(fp1, "%s %f\n", chostu1[j].choid, chostu1[j].grade);
		}
		fclose(fp1);
		remove(courname);
		rename("one.txt", courname);


		if ((fp = fopen("course.txt", "r")) == NULL)
		{
			printf("�޷���course.txt�ļ�\n");
			exit(0);
		}
		if ((fp1 = fopen("course1.txt", "w")) == NULL)
		{
			printf("�޷���course1.txt�ļ�\n");
			exit(0);
		}
		while (1)
		{
			fscanf(fp, "%s", cour1[k].couId);
			fscanf(fp, " %s", cour1[k].couName);
			fscanf(fp, " %d", &cour1[k].stuNum);
			fscanf(fp, " %d", &cour1[k].curStuNum);
			fscanf(fp, " %f\n", &cour1[k].aveScore);
			k++;
			//c = fgetc(fp);
			if (feof(fp)) break;
		}
		fclose(fp);


		for (m = 0; m < i; m++)
		{
			sum += chostu1[m].grade;
		}
		sum = sum / m;

		for (j = 0; j < k; j++)
		{
			if (!strcmp(csname, cour1[j].couName))
			{
				cour1[j].aveScore = sum;
				break;
			}
		}
		for (i = 0; i < k; i++)
		{
			fprintf(fp1, "%s %s %d %d %f\n", cour1[i].couId, cour1[i].couName, cour1[i].stuNum, cour1[i].curStuNum, cour1[i].aveScore);
		}
		fclose(fp1);
		remove("course.txt");
		rename("course1.txt", "course.txt");
		printf("¼����³ɹ���\n");

	}
}
void choose_check(void)
{
	struct CHOOSESTUDENT chostu1[10000];
	char courname[20], csname[20],ch;
	int i = 0, j,jud = 1;
	FILE *fp, *fp1;
	printf("***************************************************************************\n");
	printf("������Ҫ��ѯ�Ŀγ̵�׼ȷ���ƣ����ڿγ�ҳ���ѯ,����exit�˳�����");
	scanf("%s", courname);
	printf("***************************************************************************\n");
	system("cls");
	while (strcmp(courname, "exit")&& jud == 1)
	{
		jud = 1;
		strcpy(csname, courname);
		strcat(courname, ".txt");
		if ((fp = fopen(courname, "r")) == NULL)
		{
			printf("%s�γ̲�����\n", csname);
			jud = 0;
		}
		else
		{
			ch = fgetc(fp);
			if (ch == EOF)
			{
				printf("����ѡ�ÿε�ѧ����\n");
				fclose(fp);
			}
			else
			{
				fclose(fp);
				fp = fopen(courname, "r");
				i = 0;
				printf("�γ̣�%s\n", csname);
				while (1)
				{
					fscanf(fp, "%s", chostu1[i].choid);
					fscanf(fp, " %f\n", &chostu1[i].grade);
					i++;
					if (feof(fp)) break;
				}
				for (j = 0; j < i; j++)
				{
					printf("ѧ��:%s  ����:%f\n", chostu1[j].choid, chostu1[j].grade);
				}
				fclose(fp);
				printf("***************************************************************************\n");
				printf("������Ҫ��ѯ�Ŀγ̵�׼ȷ���ƣ����ڿγ�ҳ���ѯ,����exit�˳�����");
				scanf("%s", courname);
				printf("***************************************************************************\n");
				system("cls");
			}
		}
	}
}
