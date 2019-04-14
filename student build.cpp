/*
 *创建班级信息模块，连续按顺序输入，自动保存为班级名（即班级号）.txt，
 *自认为优点是：提供了，输入完成后的审核功能
 */
#include"student.h"
#include"stu_tool.h"
static void show(STUDENT *head);  //供输入完成后审核时用的显示函数
static void modif_(STUDENT *head);	//供输入完成后审核时的修改函数
void buil_class(){	//创建班级函数
	
	char chioce;
	STUDENT *head,*otail,*ntail;
	char class_num_[NUM_MAX],stu_num_[NUM_MAX],major[MAJOR_MAX];
	printf("		您要创建一个新的班级信息文件，\n		这是一个麻烦的事情，请慢慢来！\n\n\n");
	printf("注意：班级号可以数字夹带汉字，但不要太长哦！太长了系统会被撑死\n请输入您要创建的班级号（名）:");
	scanf(" %s%*c",class_num_);
	printf("\n请输入您要创建班级学习的专业:");
	scanf(" %s%*c",major);
	head=new(STUDENT);
	otail=ntail=head;
	system("cls");
	printf("		班号输入完毕，现在请您按以下方式输入学生信息\n");
	printf("			注意：当学号输入为-1时表示录入完成\n\n");
	printf("请输入学生的：学号  姓名 性别  数学成绩  英语成绩\n");//考虑到用户不可能一条信息也不输入，故对第一条信息不做结束检验，这是一个缺陷
	scanf(" %s%s%s%lf%lf",ntail->stu_num,ntail->name,ntail->sex,&ntail->math_poin,&ntail->eng_poin);
	strcpy(ntail->major,major);
	strcpy(ntail->class_num,class_num_);
	ntail->next=NULL;
	while(1){
		scanf(" %s",stu_num_);
		if(strcmp(stu_num_,"-1")==0)break;
		ntail=new(STUDENT);
		scanf(" %s%s%lf%lf",ntail->name,ntail->sex,&ntail->math_poin,&ntail->eng_poin);
		strcpy(ntail->stu_num,stu_num_);
		strcpy(ntail->major,major);
		strcpy(ntail->class_num,class_num_);
		otail->next=ntail;
		ntail->next=NULL;
		otail=ntail;
	}
	printf("\n输入结束！按任意键转到确认输入信息环节\n");
	getch();
	system("cls");
	printf("您已经完成输入，以下是您输入的信息，请做确认\n");//这里是对刚才输入信息的审核环节，提供修改功能，正确则予以保存
    show(head);
	printf("\n确认无误，就按y，想要修改就按n\n");
	scanf(" %c%*c",&chioce);
	while(chioce!='y'&&chioce!='n'){
		printf("输入错误，确认无误，就按y，想要修改就按n");
		scanf(" %c%*c",&chioce);
	}
	system("cls");
	if(chioce=='y') save(head);
	else  modif_(head);

}




void show(STUDENT *head){
	STUDENT  *p;
	p=head;
	while(p!=NULL){
		printf("%s  %s  %s  %s  %s  %.1f  %.1f\n",p->stu_num,p->name,p->class_num,p->sex,p->major,p->math_poin,p->eng_poin);
		p=p->next;
	}
}



void modif_(STUDENT* head){
	STUDENT *p;
	p=head;
	char stu_num_[NUM_MAX],name_[NAM_MAX],class_num_[NUM_MAX];
	char chioce;
	printf("您要修改的若是班号就按y,否则按n\n");
	scanf(" %c%*c",&chioce);
	while(chioce!='y'&&chioce!='n'){
		printf("输入错误，您要修改的若是班号就按y,否则按n\n");
		scanf(" %c%*c",&chioce);
	}
	if(chioce=='y'){
		system("cls");
		printf("请输入修改后的班级号（名）\n");
		scanf(" %s",class_num_);
		while(p!=NULL){
			strcpy(p->class_num,class_num_);
			p=p->next;
		}
		printf("班号已经修改成功，是否还要修改别的信息\n是按y否按n\n");
		scanf(" %c%*c",&chioce);
		while(chioce!='y'&&chioce!='n'){
			printf("输入错误，班号已经修改成功，是否还要修改别的信息\n是按y否按n\n");
			scanf(" %c%*c",&chioce);
		}
		if(chioce=='n')save(head);
		else goto loop1;
	}
	else{ 		
loop1:	system("cls");
		printf("请输入要修改的学生学号和姓名:");
		scanf(" %s%s",stu_num_,name_);
		p=head;
		while(!(p==NULL||strcmp(p->stu_num,stu_num_)==0&&strcmp(p->name,name_)==0)){
			p=p->next;
		}
		if(p==NULL){
			printf("未找到你输入的学生，请检查您输入的信息是否错了？\n接下来按任意键将返回，请您重新输入要修改的学生\n");
			getch();
			system("cls");
			modif_(head);
		}
loop2:	printf("请重新输入该生的信息：学号    姓名    性别  专业       数学成绩 英语成绩\n");
		scanf("%s%s%s%s%lf%lf",p->stu_num,p->name,p->sex,p->major,&p->math_poin,&p->eng_poin);
		printf("您输入修改后的学生信息是：");
		printf("%s %s %s %s %s %f %f ，是么？是按y，否按n\n",p->stu_num,p->class_num,p->name,p->sex,p->major,p->math_poin,p->eng_poin);
		scanf(" %c%*c",&chioce);
		while(chioce!='y'&&chioce!='n'){
			printf("请确认你输入的修改信息，正确按y,否则按n\n");
			scanf(" %c%*c",&chioce);
		}
		if(chioce=='y') {
			p=NULL;
			save(head);
		}
		else{
			system("cls");
			goto loop2;
		}
	}
}