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
		default:printf("输入不符合条件，请重新输入。\n");
		}
		firstprint();
		scanf("%d", &move);
		system("cls");
	}
	printf("\n\n谢谢使用，有缘再见!\n");
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
		default:printf("输入不符合条件，请重新输入。\n");
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
		default:printf("输入不符合条件，请重新输入。\n");
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
		default:printf("输入不符合条件，请重新输入。\n");
		}
		chooseprint();
		scanf("%d", &move);
		system("cls");
	}
}

void firstprint(void)
{
	printf("**************************欢迎您使用学生信息管理系统***********************\n\n"
		"				1、学生相关操作\n"
		"				2、课程相关操作\n"
		"				3、选课相关操作\n"
		"				4、退出系统\n\n"
		"***************************************************************************\n"
		"请输入您的选择："
	);
}
void studentprint(void)
{
	printf("************************************学生操作*******************************\n\n"
		"				1、添加学生信息\n"
		"				2、删除学生信息\n"
		"				3、更改学生信息\n"
		"				4、查看学生信息\n"
		"				5、返回上一级\n\n"
		"***************************************************************************\n"
		"请输入您的选择："

	);
}
void courseprint(void)
{
	printf("***********************************课程操作********************************\n\n"
		"				1、添加课程信息\n"
		"				2、删除课程信息\n"
		"				3、更改课程信息\n"
		"				4、查看课程信息\n"
		"				5、返回上一级\n\n"
		"***************************************************************************\n"
		"请输入您的选择："

	);
}
void chooseprint(void)
{
	printf("*********************************选课信息操作******************************\n\n"
		"				1、选课\n"
		"				2、退选\n"
		"				3、成绩录入\n"
		"				4、查看选课信息\n"
		"				5、返回上一级\n\n"
		"***************************************************************************\n"
		"请输入您的选择："

	);
}

void addstudent(void)
{
	int n,i;
	FILE *fp;
	if ((fp = fopen("student.txt", "a")) == NULL)
	{
		printf("无法打开student.txt文件\n");
		exit(0);
	}
	printf("请输入要追加学生信息的学生个数：");
	scanf("%d", &n);
	system("cls");
	for (i = 0; i < n; i++)
	{
		printf("请先后输入该学生的学号、姓名、性别(M/F)，中间分别用空格隔开:\n");
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
		printf("无法打开student1.txt文件\n");
		exit(0);
	}
	fclose(fp1);
	if ((fp2 = fopen("student.txt", "r")) == NULL)
	{
		printf("暂无学生信息！\n");
	}
	else
	{
		ch = fgetc(fp2);
		if (ch == EOF)
		{
			printf("暂无学生信息！\n");
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
			printf("请输入删除学生信息的方式：\n1.学号\n2.姓名\n3.返回上一级\n请输入您的选择：");
			scanf("%d", &choice);
			printf("***************************************************************************\n");
			system("cls");
			while (choice != 3)
			{
				if ((fp1 = fopen("student1.txt", "w")) == NULL)
				{
					printf("无法打开student1.txt文件\n");
					exit(0);
				}
				if ((fp2 = fopen("student.txt", "r")) == NULL)
				{
					printf("无法打开student.txt文件\n");
					exit(0);
				}
				jud = 1;
				switch (choice)
				{
				case 1:printf("***************************************************************************\n");
					printf("请输入删除学生的学号：");
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
							printf("删除成功!\n");
						}
					}
					if (jud == 1)
					{
						printf("***************************************************************************\n");
						printf("没有找到要删除的学生.\n");
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
				case 2:printf("请输入删除学生的姓名：");
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
							printf("删除成功!\n");
						}
					}
					if (jud == 1)
					{
						printf("***************************************************************************\n");
						printf("没有找到要删除的学生.\n");
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
				default:printf("输入不符合条件，请重新输入。\n");
				}
				printf("***************************************************************************\n");
				printf("请输入删除学生信息的方式：\n1.学号\n2.姓名\n3.返回上一级\n请输入您的选择：");
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
		printf("无法打开student1.txt文件\n");
		exit(0);
	}
	fclose(fp1);
	if ((fp2 = fopen("student.txt", "r")) == NULL)
	{
		printf("暂无学生信息！\n");
	}
	else
	{
		ch = fgetc(fp2);
		if (ch == EOF)
		{
			printf("暂无学生信息！\n");
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
			printf("请输入改变学生信息的方式：\n1.学号\n2.姓名\n3.返回上一级\n请输入您的选择：");
			scanf("%d", &choice);
			printf("***************************************************************************\n");
			system("cls");
			while (choice != 3)
			{
				if ((fp1 = fopen("student1.txt", "w")) == NULL)
				{
					printf("无法打开student1.txt文件\n");
					exit(0);
				}
				if ((fp2 = fopen("student.txt", "r")) == NULL)
				{
					printf("无法打开student.txt文件\n");
					exit(0);
				}
				jud = 1;
				switch (choice)
				{
				case 1:printf("***************************************************************************\n");
					printf("请输入需要改变信息的学生的学号：");
					scanf("%s", id);
					printf("***************************************************************************\n");
					system("cls");
					for (j = 0; j < i; j++)
					{
						if (!strcmp(id, stu2[j].stuId))
						{
							printf("请输入该生的姓名：");
							scanf("%s", stu2[j].stuName);
							printf("请输入该生的性别：");
							scanf("%s", stu2[j].stuSex);
							printf("请输入该生的学号：");
							scanf("%s", stu2[j].stuId);
							jud = 0;

							printf("更改信息成功!\n");
						}
					}
					if (jud == 1)
					{
						printf("没有找到要更改的学生.\n");
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
				case 2:printf("请输入更改信息的学生的姓名：");
					scanf("%s", name);
					for (j = 0; j < i; j++)
					{
						if (!strcmp(name, stu2[j].stuName))
						{
							jud = 0;
							printf("请输入该生的姓名：");
							scanf("%s", stu2[j].stuName);
							printf("请输入该生的性别：");
							scanf("%s", stu2[j].stuSex);
							printf("请输入该生的学号：");
							scanf("%s", stu2[j].stuId);
							printf("更改信息成功!\n");
						}
					}
					if (jud == 1)
					{
						printf("没有找到要更改信息的学生.\n");
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
				default:printf("输入不符合条件，请重新输入。\n");
				}
				printf("***************************************************************************\n");
				printf("请输入改变学生信息的方式：\n1.学号\n2.姓名\n3.返回上一级\n请输入您的选择：");
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
		printf("暂无学生信息！\n");
	}
	else
	{
		ch = fgetc(fp2);
		if (ch == EOF)
		{
			printf("***************************************************************************\n");
			printf("暂无学生信息！\n");
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
			printf("请输入查看学生信息的方式：\n1.全部\n2.个人\n3.返回上一级\n请输入您的选择：");
			scanf("%d", &choice);
			printf("***************************************************************************\n");
			system("cls");
			while (choice != 3)
			{
				jud = 1;
				switch (choice)
				{
				case 1:printf("\t学号\t\t姓名\t\t性别\n");
					for (j = 0; j < i; j++)
					{
						printf("\t%s\t\t%s\t\t%s\n", stu3[j].stuId, stu3[j].stuName, stu3[j].stuSex);
					}
					break;
				case 2:printf("***************************************************************************\n");
					printf("请输入查看学生信息的方法：\n1.姓名\n2.学号\n3.返回上一级\n请输入您的选择：");
					scanf("%d", &choice1);
					printf("***************************************************************************\n");
					system("cls");
					switch (choice1)
					{
					case 1:printf("请输入需要查看信息的学生的姓名：");
						scanf("%s", name);
						for (j = 0; j < i; j++)
						{
							if (!strcmp(name, stu3[j].stuName))
							{
								jud = 0;
								printf("\t学号\t\t姓名\t\t性别\n");
								printf("\t%s\t\t%s\t\t%s\n", stu3[j].stuId, stu3[j].stuName, stu3[j].stuSex);
							}
						}
						if (jud == 1)
						{
							printf("***************************************************************************\n");
							printf("没有找到该学生.\n");
						}
						break;
					case 2:printf("***************************************************************************\n");
						printf("请输入需要查看信息的学生的学号：");
						scanf("%s", id);
						printf("***************************************************************************\n");
						system("cls");
						for (j = 0; j < i; j++)
						{
							if (!strcmp(id, stu3[j].stuId))
							{
								printf("\t学号\t\t姓名\t\t性别\n");
								printf("\t%s\t\t%s\t\t%s\n", stu3[j].stuId, stu3[j].stuName, stu3[j].stuSex);

								jud = 0;
							}
						}
						if (jud == 1)
						{
							printf("***************************************************************************\n");
							printf("没有找到要该学生.\n");
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
				printf("请输入查看学生信息的方式：\n1.全部\n2.个人\n3.返回上一级\n请输入您的选择：");
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
		printf("无法打开course.txt文件\n");
		exit(0);
	}
	printf("请输入要追加课程信息的课程个数：");
	scanf("%d", &n);
	system("cls");
	for (i = 0; i < n; i++)
	{
		printf("请先后输入该课程的编号、名称、课程人数、选课人数(默认为0)、平均分(默认为0)，中间分别用空格隔开:\n");
		scanf("%s %s %d %d %f",cour[i].couId,cour[i].couName,&cour[i].stuNum,&cour[i].curStuNum,&cour[i].aveScore);
		system("cls");
		strcpy(name, cour[i].couName);
		strcat(name, ".txt");
		if ((fpp = fopen(name, "w")) == NULL)
		{
			printf("无法创建%s文件\n",cour[i].couName);
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
		printf("无法打开course1.txt文件\n");
		exit(0);
	}
	fclose(fp1);
	if ((fp2 = fopen("course.txt", "r")) == NULL)
	{
		printf("目前无课程信息\n");
	}
	else
	{
		ch = fgetc(fp2);
		if (ch == EOF)
		{
			printf("暂无课程信息！\n");
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
			printf("请输入删除课程信息的方式：\n1.编号\n2.名称\n3.返回上一级\n请输入您的选择：");
			scanf("%d", &choice);
			printf("***************************************************************************\n");
			system("cls");
			while (choice != 3)
			{
				if ((fp1 = fopen("course1.txt", "w")) == NULL)
				{
					printf("无法打开course1.txt文件\n");
					exit(0);
				}
				if ((fp2 = fopen("course.txt", "r")) == NULL)
				{
					printf("无法打开course.txt文件\n");
					exit(0);
				}
				jud = 1;
				switch (choice)
				{
				case 1:printf("***************************************************************************\n");
					printf("请输入删除课程的编号：");
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
								printf("删除成功!\n");
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
						printf("没有找到要删除的课程.\n");
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
				case 2:printf("请输入删除课程的名称：");
					scanf("%s", name);
					for (j = 0; j < i; j++)
					{
						if (!strcmp(name, cour1[j].couName))
						{
							jud = 0;

							strcpy(name, cour1[j].couName);
							strcat(name, ".txt");
							if (remove(name) == 0)
								printf("删除成功!\n");
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
						printf("没有找到要删除的课程.\n");
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
				default:printf("输入不符合条件，请重新输入。\n");
				}
				printf("***************************************************************************\n");
				printf("请输入删除课程信息的方式：\n1.编号\n2.名称\n3.返回上一级\n请输入您的选择：");
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
		printf("无法打开course1.txt文件\n");
		exit(0);
	}
	fclose(fp1);
	if ((fp2 = fopen("course.txt", "r")) == NULL)
	{
		printf("目前无课程信息\n");
	}
	else
	{
		ch = fgetc(fp2);
		if (ch == EOF)
		{
			printf("暂无课程信息！\n");
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
			printf("请输入改变课程信息的方式：\n1.编号\n2.名称\n3.返回上一级\n请输入您的选择：");
			scanf("%d", &choice);
			printf("***************************************************************************\n");
			system("cls");
			while (choice != 3)
			{
				if ((fp1 = fopen("course1.txt", "w")) == NULL)
				{
					printf("无法打开course1.txt文件\n");
					exit(0);
				}
				if ((fp2 = fopen("course.txt", "r")) == NULL)
				{
					printf("无法打开course.txt文件\n");
					exit(0);
				}
				jud = 1;
				switch (choice)
				{
				case 1:printf("***************************************************************************\n");
					printf("请输入需要改变信息的课程的编号：");
					scanf("%s", id);
					printf("***************************************************************************\n");
					system("cls");
					for (j = 0; j < i; j++)
					{
						if (!strcmp(id, cour2[j].couId))
						{
							strcpy(name, cour2[j].couName);
							strcat(name, ".txt");

							printf("请输入该课程的名称：");
							scanf("%s", cour2[j].couName);
							printf("请输入该课程的课程人数：");
							scanf("%d", &cour2[j].stuNum);
							printf("请输入该课程的编号：");
							scanf("%s", cour2[j].couId);
							printf("请输入该课程的选课人数：");
							scanf("%d", &cour2[j].curStuNum);
							printf("请输入该课程的平均分：");
							scanf("%f", &cour2[j].aveScore);
							jud = 0;
							strcpy(filename, cour2[j].couName);
							strcat(filename, ".txt");
							rename(name, filename);

							printf("更改信息成功!\n");
						}
					}
					if (jud == 1)
					{
						printf("没有找到要更改的课程.\n");
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
				case 2:printf("请输入更改信息的课程的名称：");
					scanf("%s", name);
					for (j = 0; j < i; j++)
					{
						if (!strcmp(name, cour2[j].couName))
						{
							strcpy(name, cour2[j].couName);
							strcat(name, ".txt");

							jud = 0;
							printf("请输入该课程的名称：");
							scanf("%s", cour2[j].couName);
							printf("请输入该课程的课程人数：");
							scanf("%d", &cour2[j].stuNum);
							printf("请输入该课程的编号：");
							scanf("%s", cour2[j].couId);
							printf("请输入该课程的选课人数：");
							scanf("%d", &cour2[j].curStuNum);
							printf("请输入该课程的平均分：");
							scanf("%f", &cour2[j].aveScore);

							strcpy(filename, cour2[j].couName);
							strcat(filename, ".txt");
							rename(name, filename);
						}
					}
					if (jud == 1)
					{
						printf("没有找到要更改信息的课程.\n");
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
				default:printf("输入不符合条件，请重新输入。\n");
				}
				printf("***************************************************************************\n");
				printf("请输入改变课程信息的方式：\n1.编号\n2.名称\n3.返回上一级\n请输入您的选择：");
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
		printf("目前无课程信息\n");
	}
	else
	{
		ch = fgetc(fp2);
		if (ch == EOF)
		{
			printf("暂无课程信息！\n");
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
			printf("请输入查看课程信息的方式：\n1.全部\n2.单课程\n3.返回上一级\n请输入您的选择：");
			scanf("%d", &choice);
			printf("***************************************************************************\n");
			system("cls");
			while (choice != 3)
			{
				jud = 1;
				switch (choice)
				{
				case 1:printf("\t编号\t\t名称\t\t课程人数\t选课人数\t平均分\n");
					for (j = 0; j < i; j++)
					{
						printf("\t%s\t\t%s\t\t%d\t\t%d\t\t%f\n", cour2[j].couId, cour2[j].couName, cour2[j].stuNum, cour2[j].curStuNum, cour2[j].aveScore);
					}
					break;
				case 2:printf("***************************************************************************\n");
					printf("请输入查看课程信息的方法：\n1.名称\n2.编号\n3.返回上一级\n请输入您的选择：");
					scanf("%d", &choice1);
					printf("***************************************************************************\n");
					system("cls");
					while (choice1 != 3)
					{
						jud = 1;
						switch (choice1)
						{
							jud = 1;
						case 1:printf("请输入需要查看信息的课程的名称：");
							scanf("%s", name);
							for (j = 0; j < i; j++)
							{
								if (!strcmp(name, cour2[j].couName))
								{
									jud = 0;
									printf("\t编号\t\t名称\t\t课程人数\t选课人数\t平均分\n");
									printf("\t%s\t\t%s\t\t%d\t\t%d\t\t%f\n", cour2[j].couId, cour2[j].couName, cour2[j].stuNum, cour2[j].curStuNum, cour2[j].aveScore);
								}
							}
							if (jud == 1)
							{
								printf("没有找到该课程.\n");
							}
							break;
						case 2:printf("***************************************************************************\n");
							printf("请输入需要查看信息的课程的编号：");
							scanf("%s", id);
							printf("***************************************************************************\n");
							system("cls");
							for (j = 0; j < i; j++)
							{
								if (!strcmp(id, cour2[j].couId))
								{
									printf("\t编号\t\t名称\t\t课程人数\t选课人数\t平均分\n");
									printf("\t%s\t\t%s\t\t%d\t\t%d\t\t%f\n", cour2[j].couId, cour2[j].couName, cour2[j].stuNum, cour2[j].curStuNum, cour2[j].aveScore);

									jud = 0;
								}
							}
							if (jud == 1)
							{
								printf("没有找到要该课程.\n");
							}
							break;
						case 3:break;
						default:printf("输入不符合条件，请重新输入。\n");
						}
						printf("***************************************************************************\n");
						printf("请输入查看课程信息的方法：\n1.名称\n2.编号\n3.返回上一级\n请输入您的选择：");
						scanf("%d", &choice1);
						printf("***************************************************************************\n");
						system("cls");
					}
					break;
				case 3:break;
				default:printf("输入不符合条件，请重新输入。\n");
				}
				printf("***************************************************************************\n");
				printf("请输入查看课程信息的方式：\n1.全部\n2.单课程\n3.返回上一级\n请输入您的选择：");
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
		printf("无法打开student.txt文件\n");
		exit(0);
	}
	if ((fp2 = fopen("course.txt", "r")) == NULL)
	{
		printf("无法打开course.txt文件\n");
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
	printf("请输入要选课的学生的学号（编号可在学生页面查询）：");
	scanf("%s", id);
	printf("***************************************************************************\n");
	system("cls");
	for (j = 0; j < i; j++)
	{
		if (!strcmp(id, stu1[j].stuId))
		{
			printf("请确认该学生的信息：\n");
			printf("学号：%s\n姓名：%s\n性别:%s\n",stu1[j].stuId,stu1[j].stuName,stu1[j].stuSex);
			printf("确认请输入1，反之则输入2：");
			scanf("%d", &jud1);
			printf("***************************************************************************\n");
			system("cls");
			jud=(jud1 == 1) ? 0:1;
		}
		if (jud == 0)
		{
			printf("学生存在。\n");
			printf("***************************************************************************\n");
			break;
		}
	}

	if (jud == 0)
	{
		printf("***************************************************************************\n");
		printf("请输入要选的课程的编号（编号可在课程页面查询）：");
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
					printf("该课人数已满，不可再选\n");
					break;
				}
				printf("请确认该课程的信息：\n");
				printf("编号：%s\n名称：%s\n课程人数:%d\n已报人数:%d\n", cour1[m].couId, cour1[m].couName, cour1[m].stuNum, cour1[m].curStuNum);
				printf("确认请输入1，反之则输入2：");
				scanf("%d", &jud2);
				printf("***************************************************************************\n");
				system("cls");
				JUD = (jud2 == 1) ? 0 : 1;
			}
			if (JUD == 0)
			{
				printf("课程存在。\n");
				printf("***************************************************************************\n");
				printf("正在添加!\n");
				break;
			}
			if (m == k - 1)
			{
				printf("该课程不存在！\n");
			}
		}
		if (JUD == 0)
		{
			strcpy(coursename, cour1[m].couName);
			strcat(coursename, ".txt");
			if ((fp = fopen(coursename, "a")) == NULL)
			{
				printf("无法打开%s文件\n", coursename);
				exit(0);
			}
			fprintf(fp, "%s %f\n", stu1[j].stuId, grade);
			fclose(fp);

			cour1[m].curStuNum++;
			
			if ((fp1 = fopen("course1.txt", "w")) == NULL)
			{
				printf("无法打开course1.txt文件\n");
				exit(0);
			}
			for (i = 0; i < k; i++)
			{
				fprintf(fp1, "%s %s %d %d %f\n", cour1[i].couId, cour1[i].couName, cour1[i].stuNum, cour1[i].curStuNum, cour1[i].aveScore);
			}
			fclose(fp1);
			remove("course.txt");
			rename("course1.txt", "course.txt");
			printf("选课成功!\n");
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
	printf("请输入要退选的准确课程名称（名称可在课程页面查询）：");
	scanf("%s", courname);
	printf("***************************************************************************\n");
	system("cls");
	strcpy(csname, courname);
	strcat(courname, ".txt");
	if ((fp = fopen(courname, "r")) == NULL)
	{
		printf("无法打开%s文件\n", courname);
		printf("%s课程不存在\n", csname);
		jud = 1;
	}
	else
	{
		if ((fp1 = fopen("副本.txt", "w")) == NULL)
		{
			printf("无法打开副本.txt文件\n");
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
		printf("请输入要退选的学生的学号（可在学生页面查询）：");
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
				printf("正在退选!\n");
			}
		}
		if (jud == 1)
		{
			printf("没有找到要退选的学生.\n");
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
		rename("副本.txt", courname);
	}
	if (jud == 0)
	{
		if ((fp1 = fopen("course.txt", "r")) == NULL)
		{
			printf("无法打开course.txt文件\n");
			exit(0);
		}
		if ((fp = fopen("course1.txt", "w")) == NULL)
		{
			printf("无法打开course1.txt文件\n");
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
				printf("退选成功！\n");
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
	printf("请输入要录入成绩的课程的准确名称（名称可在课程页面查询）：");
	scanf("%s", courname);
	printf("***************************************************************************\n");
	system("cls");
	strcpy(csname, courname);
	strcat(courname, ".txt");
	if ((fp = fopen(courname, "r")) == NULL)
	{
		printf("无法打开%s文件\n", courname);
		printf("%s课程不存在\n", csname);
		jud = 1;
	}
	else
	{
		if ((fp1 = fopen("one.txt", "w")) == NULL)
		{
			printf("无法打开one.txt文件\n");
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
		printf("请输入要录入成绩的学生的学号（可在学生页面查询,输入exit退出）：");
		scanf("%s", stuid);
		printf("***************************************************************************\n");
		system("cls");
		while (strcmp(stuid, "exit"))
		{
			for (j = 0; j < i; j++)
			{
				if (!strcmp(stuid, chostu1[j].choid))
				{
					printf("请输入该生的成绩\n");
					scanf("%f", &chostu1[j].grade);
					printf("***************************************************************************\n");
					printf("录入成功！\n");
					printf("***************************************************************************\n");
					break;
				}
				if (j == i - 1)
				{
					printf("该学生并没有选此课程！\n");
					printf("***************************************************************************\n");
				}
			}
			printf("***************************************************************************\n");
			printf("请输入要录入成绩的学生的学号（可在学生页面查询,输入exit退出）：");
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
			printf("无法打开course.txt文件\n");
			exit(0);
		}
		if ((fp1 = fopen("course1.txt", "w")) == NULL)
		{
			printf("无法打开course1.txt文件\n");
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
		printf("录入更新成功！\n");

	}
}
void choose_check(void)
{
	struct CHOOSESTUDENT chostu1[10000];
	char courname[20], csname[20],ch;
	int i = 0, j,jud = 1;
	FILE *fp, *fp1;
	printf("***************************************************************************\n");
	printf("请输入要查询的课程的准确名称（可在课程页面查询,输入exit退出）：");
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
			printf("%s课程不存在\n", csname);
			jud = 0;
		}
		else
		{
			ch = fgetc(fp);
			if (ch == EOF)
			{
				printf("暂无选该课的学生！\n");
				fclose(fp);
			}
			else
			{
				fclose(fp);
				fp = fopen(courname, "r");
				i = 0;
				printf("课程：%s\n", csname);
				while (1)
				{
					fscanf(fp, "%s", chostu1[i].choid);
					fscanf(fp, " %f\n", &chostu1[i].grade);
					i++;
					if (feof(fp)) break;
				}
				for (j = 0; j < i; j++)
				{
					printf("学号:%s  分数:%f\n", chostu1[j].choid, chostu1[j].grade);
				}
				fclose(fp);
				printf("***************************************************************************\n");
				printf("请输入要查询的课程的准确名称（可在课程页面查询,输入exit退出）：");
				scanf("%s", courname);
				printf("***************************************************************************\n");
				system("cls");
			}
		}
	}
}
