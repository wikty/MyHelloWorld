/*
 *�����༶��Ϣģ�飬������˳�����룬�Զ�����Ϊ�༶�������༶�ţ�.txt��
 *����Ϊ�ŵ��ǣ��ṩ�ˣ�������ɺ����˹���
 */
#include"student.h"
#include"stu_tool.h"
static void show(STUDENT *head);  //��������ɺ����ʱ�õ���ʾ����
static void modif_(STUDENT *head);	//��������ɺ����ʱ���޸ĺ���
void buil_class(){	//�����༶����
	
	char chioce;
	STUDENT *head,*otail,*ntail;
	char class_num_[NUM_MAX],stu_num_[NUM_MAX],major[MAJOR_MAX];
	printf("		��Ҫ����һ���µİ༶��Ϣ�ļ���\n		����һ���鷳�����飬����������\n\n\n");
	printf("ע�⣺�༶�ſ������ּд����֣�����Ҫ̫��Ŷ��̫����ϵͳ�ᱻ����\n��������Ҫ�����İ༶�ţ�����:");
	scanf(" %s%*c",class_num_);
	printf("\n��������Ҫ�����༶ѧϰ��רҵ:");
	scanf(" %s%*c",major);
	head=new(STUDENT);
	otail=ntail=head;
	system("cls");
	printf("		���������ϣ��������������·�ʽ����ѧ����Ϣ\n");
	printf("			ע�⣺��ѧ������Ϊ-1ʱ��ʾ¼�����\n\n");
	printf("������ѧ���ģ�ѧ��  ���� �Ա�  ��ѧ�ɼ�  Ӣ��ɼ�\n");//���ǵ��û�������һ����ϢҲ�����룬�ʶԵ�һ����Ϣ�����������飬����һ��ȱ��
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
	printf("\n����������������ת��ȷ��������Ϣ����\n");
	getch();
	system("cls");
	printf("���Ѿ�������룬���������������Ϣ������ȷ��\n");//�����ǶԸղ�������Ϣ����˻��ڣ��ṩ�޸Ĺ��ܣ���ȷ�����Ա���
    show(head);
	printf("\nȷ�����󣬾Ͱ�y����Ҫ�޸ľͰ�n\n");
	scanf(" %c%*c",&chioce);
	while(chioce!='y'&&chioce!='n'){
		printf("�������ȷ�����󣬾Ͱ�y����Ҫ�޸ľͰ�n");
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
	printf("��Ҫ�޸ĵ����ǰ�žͰ�y,����n\n");
	scanf(" %c%*c",&chioce);
	while(chioce!='y'&&chioce!='n'){
		printf("���������Ҫ�޸ĵ����ǰ�žͰ�y,����n\n");
		scanf(" %c%*c",&chioce);
	}
	if(chioce=='y'){
		system("cls");
		printf("�������޸ĺ�İ༶�ţ�����\n");
		scanf(" %s",class_num_);
		while(p!=NULL){
			strcpy(p->class_num,class_num_);
			p=p->next;
		}
		printf("����Ѿ��޸ĳɹ����Ƿ�Ҫ�޸ı����Ϣ\n�ǰ�y��n\n");
		scanf(" %c%*c",&chioce);
		while(chioce!='y'&&chioce!='n'){
			printf("������󣬰���Ѿ��޸ĳɹ����Ƿ�Ҫ�޸ı����Ϣ\n�ǰ�y��n\n");
			scanf(" %c%*c",&chioce);
		}
		if(chioce=='n')save(head);
		else goto loop1;
	}
	else{ 		
loop1:	system("cls");
		printf("������Ҫ�޸ĵ�ѧ��ѧ�ź�����:");
		scanf(" %s%s",stu_num_,name_);
		p=head;
		while(!(p==NULL||strcmp(p->stu_num,stu_num_)==0&&strcmp(p->name,name_)==0)){
			p=p->next;
		}
		if(p==NULL){
			printf("δ�ҵ��������ѧ�����������������Ϣ�Ƿ���ˣ�\n������������������أ�������������Ҫ�޸ĵ�ѧ��\n");
			getch();
			system("cls");
			modif_(head);
		}
loop2:	printf("�����������������Ϣ��ѧ��    ����    �Ա�  רҵ       ��ѧ�ɼ� Ӣ��ɼ�\n");
		scanf("%s%s%s%s%lf%lf",p->stu_num,p->name,p->sex,p->major,&p->math_poin,&p->eng_poin);
		printf("�������޸ĺ��ѧ����Ϣ�ǣ�");
		printf("%s %s %s %s %s %f %f ����ô���ǰ�y����n\n",p->stu_num,p->class_num,p->name,p->sex,p->major,p->math_poin,p->eng_poin);
		scanf(" %c%*c",&chioce);
		while(chioce!='y'&&chioce!='n'){
			printf("��ȷ����������޸���Ϣ����ȷ��y,����n\n");
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