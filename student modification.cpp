/*
 *�޸��Ѿ�Ӳ�����ѧ����Ϣ�ļ�
 */
#include"student.h"
#include"stu_tool.h"
static void add();//�������
static void cut();//ɾ������
static void mod_o();//�޸�����
static void mod_c();//�޸İ༶��
static void mod_m();//�޸İ༶רҵ
//����������޸ĺ����Ĺ���ģ�麯��
static int modif_menu(){
	int chioce;
	printf("		��������Ҫ�����޸�ѧ����Ϣ\n		�������Ӧ���\n");
	printf("	1.��������\n");
	printf("	2.ɾ������\n");
	printf("	3.�޸�����\n");
	printf("	4.�޸İ༶��\n");
    printf("	5.�޸İ༶רҵ\n");
	printf("	6.������һ��\n");
	printf("	�����룺");
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
	default:printf("ִ��Ĭ�ϲ������������˵�\n");break;
	}
	printf("\n����������ؿ�ʼ�˵�\n");
	getch();
}

void add(){
	STUDENT *head,*p,*q,now,*ntail;
	head=copy();
	printf("��������������ѧ�ţ��������Ա���ѧ�ɼ���Ӣ��ɼ�\nֹͣ����ʱ���һ��ѧ��ѧ��Ϊ-1\n");
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
	printf("��ӳɹ��������������󷵻����˵�\n");
	save(head);
	getch();
}
void cut(){
	char chioce;
	STUDENT *head,*p,*q,now;
	head=copy();
	p=q=head;
	printf("������Ҫɾ����ѧ��������ѧ�ţ�\n");
	scanf(" %s%s",now.name,now.stu_num);
	while(p!=NULL){
		if(strcmp(p->stu_num,now.stu_num)==0&&strcmp(p->name,now.name)==0)break;
		q=p;
		p=p->next;
	}
	if(p==NULL){
		printf("�п���������������Ϣ�����⣬ϵͳδ�ҵ�������\n���������ϵͳ���Զ���ת����ʼ��ɾ�����棬�Ա����ٴ�����ѧ����Ϣ\n��ܰ��ʾ�����鰴��ǰ�˶���Ϣ\n");
        getch();
		system("cls");
		cut();
	}
	else{
		if(p==head){
			printf("ȷ��ɾ��%s%s���밴y,����n:\n",p->name,p->stu_num);
			scanf(" %c%*c",&chioce);
			if(chioce=='y'){
				head=p->next;
				delete p;
				printf("ɾ���ɹ�������������б���\n");
				getch();
			}
			else
				printf("����ɾ��������ȡ�����Զ�Ϊ������");
		}
		else if(p->next==NULL){
				printf("ȷ��ɾ��%s%s���밴y,����n:\n",p->name,p->stu_num);
				scanf(" %c%*c",&chioce);
				if(chioce=='y'){
					q->next=NULL;
					delete p;
					printf("ɾ���ɹ�������������б���\n");
				    getch();
				}
				else
                    printf("����ɾ��������ȡ�����Զ�Ϊ������");
			}
		else  {
					printf("ȷ��ɾ��%s%s���밴y,����n\n",p->name,p->stu_num);
					scanf(" %c%*c",&chioce);
					if(chioce=='y'){
						q->next=p->next;
						delete p;
                         printf("ɾ���ɹ�������������б���\n");
				         getch();
					}
					else
						printf("����ɾ��������ȡ�����Զ�Ϊ������");
		}
	}
	save(head);
}
void mod_o(){
	char chioce;
	STUDENT *head,*p,now;
	head=copy();
	p=head;
	printf("������Ҫ�޸ĵ�ѧ��������ѧ�ţ�\n");
	scanf(" %s%s",now.name,now.stu_num);
	while(p!=NULL){
		if(strcmp(p->stu_num,now.stu_num)==0&&strcmp(p->name,now.name)==0)break;
		p=p->next;
	}
	if(p==NULL){
		printf("�п���������������Ϣ�����⣬ϵͳδ�ҵ�������\n���������ϵͳ���Զ���ת����ʼ���޸Ľ��棬�Ա����ٴ�����ѧ����Ϣ\n��ܰ��ʾ�����鰴��ǰ�˶���Ϣ\n");
        getch();
		mod_o();
	}
	else{
			printf("ȷ���޸�%s%s���밴y,����n:\n",p->name,p->stu_num);
		    scanf(" %c%*c",&chioce);
		    if(chioce=='y'){
				printf("�������������Ϣ��ѧ�ţ��������Ա�רҵ����ѧ�ɼ���Ӣ��ɼ�\n");
				scanf("%s%s%s%s%lf%lf",p->stu_num,p->name,p->sex,p->major,p->math_poin,p->eng_poin);
			    printf("����������б���\n");
				getch();
			}
			else
				printf("�����޸Ĳ����ѱ�ȡ�����Զ�����\n");
	}
	save(head);

}
void mod_c(){
	char class_num_[NUM_MAX];
	char chioce;
	STUDENT *head,*p;
	head=copy();
	p=head;
	printf("�������°�ţ�������\n");
	scanf(" %s",class_num_);
	printf("ȷ���޸İ�y,����n\n");
	scanf(" %c%*c",&chioce);
	if(chioce=='y'){
		while(p!=NULL){
		      strcpy(p->class_num,class_num_);
			  p=p->next;
		}
	}
	else 
		printf("�����޸Ĳ����ѱ�ȡ�����Զ�����\n");
	save(head);
}
				
void mod_m(){
	char major[MAJOR_MAX];
	char chioce;
	STUDENT *head,*p;
	head=copy();
	p=head;
	printf("������༶�µ�רҵ��\n");
	scanf(" %s%*c",major);
	printf("ȷ���޸İ�y,����n\n");
	scanf(" %c%*c",&chioce);
	if(chioce=='y'){
		while(p!=NULL){
		      strcpy(p->major,major);
			  p=p->next;
		}
	}
	else 
		printf("�����޸Ĳ����ѱ�ȡ�����Զ�����\n");
	save(head);
}
				













