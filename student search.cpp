#include"student.h"
#include"stu_tool.h"
static void search(STUDENT *head,int select);
void sear_menu(){
	STUDENT *head;
	int chioce;
	printf("请按对应的功能序号进行查询\n");
	printf("\n\n\t1.查询某学生信息\n");
	printf("\t2.对某班最高单科成绩查询\n");
	printf("请输入：");
	scanf(" %d%*c",&chioce);
	head=copy();
	search(head,chioce);
	destroy(head);
	printf("按任意键返回开始菜单\n");
	getch();
}
void search(STUDENT *head,int select){
	system("cls");
	char temp[NAM_MAX];
	double h_math,h_eng;
	STUDENT *p,*mark1,*mark2;
	p=head;
	switch(select){
	case 1:printf("请输入该生的学号或姓名\n");
		   scanf(" %s",temp);
		   while(p!=NULL){
			   if(strcmp(p->stu_num,temp)==0||strcmp(p->name,temp)==0)break;
			   p=p->next;
		   }
		   system("cls");
		   if(p!=NULL){
		   printf("查询信息如下：\n");
		   printf("学号    姓名    班号    性别 专业        数学成绩 英语成绩 总分 名次\n");
		   printf("%s\t%s\t%s\t%s\t%s\t%4.1f\t%4.1f\t%4.1f\t%d\n",p->stu_num,p->name,p->class_num,p->sex,p->major,p->math_poin,p->eng_poin,p->total_poin,p->rank);
		   }
		   else{
			   printf("未找到该生，有可能是输入信息有误，按任意键返回查询界面\n");
			   getch();
			   search(head,select);
		   }
		   break;
	case 2:system("cls");
		   h_math=p->math_poin;
		   h_eng=p->eng_poin;
		   while(p!=NULL){
			   if(p->math_poin>h_math){
				   h_math=p->math_poin;
				   mark1=p;
			   }   
			   if(p->eng_poin>h_eng){
				   h_eng=p->eng_poin;
				   mark2=p;
			   }
			   p=p->next;
		   }
		   printf("班号为%s的班级中\n",mark1->class_num);
		   printf("英语最高分为：%4.1f\n",mark1->eng_poin);
		   printf("学号    姓名    班号    性别 专业        数学成绩 英语成绩 总分 名次\n");
		   printf("%s\t%s\t%s\t%s\t%s\t%4.1f\t%4.1f\t%4.1f\t%d\n\n",mark1->stu_num,mark1->name,mark1->class_num,mark1->sex,mark1->major,mark1->math_poin,mark1->eng_poin,mark1->total_poin,mark1->rank);
		   printf("数学最高分为：%4.1f\n",mark1->eng_poin);
		   printf("%s\t%s\t%s\t%s\t%s\t%4.1f\t%4.1f\t%4.1f\t%d\n",mark2->stu_num,mark2->name,mark2->class_num,mark2->sex,mark2->major,mark2->math_poin,mark2->eng_poin,mark2->total_poin,mark2->rank);
		   mark1=NULL;
		   mark2=NULL;
		   break;
	default:break;
	}
}
