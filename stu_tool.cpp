//Ӳ�������ߣ����ļ����ݴ�������
#include"student.h"
#include"stu_tool.h"
STUDENT* copy(){
	char class_num_[NUM_MAX+3];
	char buff[100];
	system("cls");
	printf("������Ҫ����İ༶�ļ��������\n");
	scanf(" %s%*c",class_num_);
	strcat(class_num_,".student.txt");
	STUDENT *head,*otail,*ntail;
	char ch,temp[80];
	FILE *fp;
	if((fp=fopen(class_num_,"r"))==NULL){
		printf("Ӧ����������İ༶������ϵͳδ���������ļ�����������ֹ\n");
		exit(0);
	}
	head=new(STUDENT);
	ntail=otail=head;
	for(int i=0;i<9;i++)//�����ڴ˴���Ϊ��С���⣬ʹ�ó����󲻱���ά��
		fscanf(fp,"%s",buff);
	//ch=fgetc(fp);
	fscanf(fp,"%s%s%s%s%s%lf%lf%lf%d",ntail->stu_num,ntail->name,ntail->class_num,ntail->sex,ntail->major,&ntail->math_poin,&ntail->eng_poin,&ntail->rank);
	while(!feof(fp)){
		fscanf(fp,"%s",temp);
		//if(strcmp(temp,"								�༶�������								\n")==0)break;
	
		ntail=new(STUDENT); 
		strcpy(ntail->stu_num,temp);
		fscanf(fp,"%s%s%s%s%lf%lf%lf%d",ntail->name,ntail->class_num,ntail->sex,ntail->major,&ntail->math_poin,&ntail->eng_poin,&ntail->rank);
		otail->next=ntail;
		ntail->next=NULL;
		otail=ntail;
		
	}
	fclose(fp);
	my_sort(head);
	return head;
}


//�����༶��Ϣ�������ú���������һ��ѧ����Ϣ����clas�ǽ�����İ༶���������Ϊ�������ʹ��
void create_class_info(STUDENT *head,CLASS &clas){
	double h_math,h_eng;
	STUDENT *p,*q,*mark1=head,*mark2=head;
	p=head;
	strcpy(clas.class_num,p->class_num);
	strcpy(clas.major,p->major);
	while(p!=NULL){
		q=p;
		p=p->next;
	}
	clas.total_peo=q->rank;
	p=head;
	double math_total=0,eng_total=0;
	while(p!=NULL){
		math_total+=p->math_poin;
		eng_total+=p->eng_poin;
		p=p->next;
	}
	clas.math_ave_poin=math_total/clas.total_peo;
	clas.eng_ave_poin=eng_total/clas.total_peo;
	p=head;
	h_math=p->math_poin;
    h_eng=p->eng_poin;
    while(p!=NULL){
	   if(p->math_poin>h_math) mark1=p;
	   if(p->eng_poin>h_eng) mark2=p;//©�����ڵ�����߷�ֻ����ʾһ�������ܷ�������ǰ�����պ�Ľ�
	   p=p->next;
	}
	clas.math_hest=*mark1;
	clas.eng_hest=*mark2;
}



//����������
void destroy(STUDENT *head){
	STUDENT *p,*q;
	p=head;
	while(p!=NULL){
		q=p;
		p=p->next;
		delete q;
	}
	head=NULL;
	q=NULL;
}