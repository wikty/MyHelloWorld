/*
 *修改已经硬保存的学生信息文件
 */
#include"student.h"
#include"stu_tool.h"
static void add();//添加新生
static void cut();//删减老生
static void mod_o();//修改老生
static void mod_c();//修改班级号
static void mod_m();//修改班级专业
//以上五个是修改函数的功能模块函数
static int modif_menu(){
	int chioce;
	printf("		您现在是要进行修改学生信息\n		请输入对应序号\n");
	printf("	1.加入新生\n");
	printf("	2.删掉老生\n");
	printf("	3.修改老生\n");
	printf("	4.修改班级号\n");
    printf("	5.修改班级专业\n");
	printf("	6.返回上一层\n");
	printf("	请输入：");
	scanf(" %d%*c",&chioce);
	system("cls");
	return chioce;
}
void modification(){

	switch(modif_menu()){
	case 1:add();break;
	case 2:cut();break;
	case 3:mod_o();break;
	case 4:mod_c();break;
	case 5:mod_m();break;
	case 6:break;
	default:printf("执行默认操作，返回主菜单\n");break;
	}
	printf("\n按任意键返回开始菜单\n");
	getch();
}

void add(){
	STUDENT *head,*p,*q,now,*ntail;
	head=copy();
	printf("请输入新添生的学号，姓名，性别，数学成绩，英语成绩\n停止输入时最后一个学生学号为-1\n");
	while(1){
	p=q=head;
	scanf("%s%*c",now.stu_num);
	if(strcmp(now.stu_num,"-1")==0)break;
	scanf("%s%s%lf%lf",now.name,now.sex,&now.math_poin,&now.eng_poin);
	strcpy(now.class_num,head->class_num);
	now.next=NULL;
	while(p!=NULL){
		q=p;
		p=p->next;
	}
	ntail=new(STUDENT);
	*ntail=now;
	q->next=ntail;
	}
	printf("添加成功，按任意键保存后返回主菜单\n");
	save(head);
	getch();
}
void cut(){
	char chioce;
	STUDENT *head,*p,*q,now;
	head=copy();
	p=q=head;
	printf("请输入要删减的学生姓名和学号：\n");
	scanf(" %s%s",now.name,now.stu_num);
	while(p!=NULL){
		if(strcmp(p->stu_num,now.stu_num)==0&&strcmp(p->name,now.name)==0)break;
		q=p;
		p=p->next;
	}
	if(p==NULL){
		printf("有可能是您的输入信息有问题，系统未找到该生，\n按任意键，系统将自动跳转到初始的删除界面，以便您再次输入学生信息\n温馨提示：建议按键前核对信息\n");
        getch();
		system("cls");
		cut();
	}
	else{
		if(p==head){
			printf("确认删除%s%s，请按y,否则按n:\n",p->name,p->stu_num);
			scanf(" %c%*c",&chioce);
			if(chioce=='y'){
				head=p->next;
				delete p;
				printf("删除成功！按任意键进行保存\n");
				getch();
			}
			else
				printf("您的删除操作被取消，自动为您保存");
		}
		else if(p->next==NULL){
				printf("确认删除%s%s，请按y,否则按n:\n",p->name,p->stu_num);
				scanf(" %c%*c",&chioce);
				if(chioce=='y'){
					q->next=NULL;
					delete p;
					printf("删除成功！按任意键进行保存\n");
				    getch();
				}
				else
                    printf("您的删除操作被取消，自动为您保存");
			}
		else  {
					printf("确认删除%s%s，请按y,否则按n\n",p->name,p->stu_num);
					scanf(" %c%*c",&chioce);
					if(chioce=='y'){
						q->next=p->next;
						delete p;
                         printf("删除成功！按任意键进行保存\n");
				         getch();
					}
					else
						printf("您的删除操作被取消，自动为您保存");
		}
	}
	save(head);
}
void mod_o(){
	char chioce;
	STUDENT *head,*p,now;
	head=copy();
	p=head;
	printf("请输入要修改的学生姓名和学号：\n");
	scanf(" %s%s",now.name,now.stu_num);
	while(p!=NULL){
		if(strcmp(p->stu_num,now.stu_num)==0&&strcmp(p->name,now.name)==0)break;
		p=p->next;
	}
	if(p==NULL){
		printf("有可能是您的输入信息有问题，系统未找到该生，\n按任意键，系统将自动跳转到初始的修改界面，以便您再次输入学生信息\n温馨提示：建议按键前核对信息\n");
        getch();
		mod_o();
	}
	else{
			printf("确认修改%s%s，请按y,否则按n:\n",p->name,p->stu_num);
		    scanf(" %c%*c",&chioce);
		    if(chioce=='y'){
				printf("请输入该生的信息：学号，姓名，性别，专业，数学成绩，英语成绩\n");
				scanf("%s%s%s%s%lf%lf",p->stu_num,p->name,p->sex,p->major,p->math_poin,p->eng_poin);
			    printf("按任意键进行保存\n");
				getch();
			}
			else
				printf("您的修改操作已被取消，自动保存\n");
	}
	save(head);

}
void mod_c(){
	char class_num_[NUM_MAX];
	char chioce;
	STUDENT *head,*p;
	head=copy();
	p=head;
	printf("请输入新班号（名）：\n");
	scanf(" %s",class_num_);
	printf("确认修改按y,否则按n\n");
	scanf(" %c%*c",&chioce);
	if(chioce=='y'){
		while(p!=NULL){
		      strcpy(p->class_num,class_num_);
			  p=p->next;
		}
	}
	else 
		printf("您的修改操作已被取消，自动保存\n");
	save(head);
}
				
void mod_m(){
	char major[MAJOR_MAX];
	char chioce;
	STUDENT *head,*p;
	head=copy();
	p=head;
	printf("请输入班级新的专业：\n");
	scanf(" %s%*c",major);
	printf("确认修改按y,否则按n\n");
	scanf(" %c%*c",&chioce);
	if(chioce=='y'){
		while(p!=NULL){
		      strcpy(p->major,major);
			  p=p->next;
		}
	}
	else 
		printf("您的修改操作已被取消，自动保存\n");
	save(head);
}
				













