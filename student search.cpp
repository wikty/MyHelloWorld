#include"student.h"
#include"stu_tool.h"
static void search(STUDENT *head,int select);
void sear_menu(){
	STUDENT *head;
	int chioce;
	printf("�밴��Ӧ�Ĺ�����Ž��в�ѯ\n");
	printf("\n\n\t1.��ѯĳѧ����Ϣ\n");
	printf("\t2.��ĳ����ߵ��Ƴɼ���ѯ\n");
	printf("�����룺");
	scanf(" %d%*c",&chioce);
	head=copy();
	search(head,chioce);
	destroy(head);
	printf("����������ؿ�ʼ�˵�\n");
	getch();
}
void search(STUDENT *head,int select){
	system("cls");
	char temp[NAM_MAX];
	double h_math,h_eng;
	STUDENT *p,*mark1,*mark2;
	p=head;
	switch(select){
	case 1:printf("�����������ѧ�Ż�����\n");
		   scanf(" %s",temp);
		   while(p!=NULL){
			   if(strcmp(p->stu_num,temp)==0||strcmp(p->name,temp)==0)break;
			   p=p->next;
		   }
		   system("cls");
		   if(p!=NULL){
		   printf("��ѯ��Ϣ���£�\n");
		   printf("ѧ��    ����    ���    �Ա� רҵ        ��ѧ�ɼ� Ӣ��ɼ� �ܷ� ����\n");
		   printf("%s\t%s\t%s\t%s\t%s\t%4.1f\t%4.1f\t%4.1f\t%d\n",p->stu_num,p->name,p->class_num,p->sex,p->major,p->math_poin,p->eng_poin,p->total_poin,p->rank);
		   }
		   else{
			   printf("δ�ҵ��������п�����������Ϣ���󣬰���������ز�ѯ����\n");
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
		   printf("���Ϊ%s�İ༶��\n",mark1->class_num);
		   printf("Ӣ����߷�Ϊ��%4.1f\n",mark1->eng_poin);
		   printf("ѧ��    ����    ���    �Ա� רҵ        ��ѧ�ɼ� Ӣ��ɼ� �ܷ� ����\n");
		   printf("%s\t%s\t%s\t%s\t%s\t%4.1f\t%4.1f\t%4.1f\t%d\n\n",mark1->stu_num,mark1->name,mark1->class_num,mark1->sex,mark1->major,mark1->math_poin,mark1->eng_poin,mark1->total_poin,mark1->rank);
		   printf("��ѧ��߷�Ϊ��%4.1f\n",mark1->eng_poin);
		   printf("%s\t%s\t%s\t%s\t%s\t%4.1f\t%4.1f\t%4.1f\t%d\n",mark2->stu_num,mark2->name,mark2->class_num,mark2->sex,mark2->major,mark2->math_poin,mark2->eng_poin,mark2->total_poin,mark2->rank);
		   mark1=NULL;
		   mark2=NULL;
		   break;
	default:break;
	}
}
