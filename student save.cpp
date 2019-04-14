/*
 *�������е�ѧ����Ϣ���༶��Ϣ����Ӳ����,������stu_tool���߰��е�create_class_info()�༶��Ϣ��������
 */
#include"student.h"
#include"stu_tool.h"//���˹������ٺ����Ͱ༶��Ϣ��������
static void sort(STUDENT *head);//���ܷ��������ļ�����֮ǰ���ã�ʹ�ñ�����ļ���ѧ����Ϣ���ܳɼ�����
void save(STUDENT *head){
	CLASS cls;
	char file_name[NUM_MAX+3];
	STUDENT *p;
	p=head;
	my_sort(head);
	FILE *fp;
	//�����༶���ѧ������Ϣ�ļ�
	strcpy(file_name,p->class_num);
    strcat(file_name,".student.txt");
	if((fp=fopen(file_name,"w"))==NULL){
		printf("�ļ�������ϵͳ��������ʧ�ܣ�������ֹ\n");
		destroy(head);
		exit(0);
	}
    fputs("ѧ��\t����\t���\t�Ա�\tרҵ\t��ѧ\tӢ��\t�ܷ�\t����\n",fp);
	while(p!=NULL){
		fputs(p->stu_num,fp);
		fputs("\t",fp);
		fputs(p->name,fp);
		fputs("\t",fp);
		fputs(p->class_num,fp);
		fputs("\t",fp);
		fputs(p->sex,fp);
		fputs("\t",fp);
		fputs(p->major,fp);
		fputs("\t",fp);
		fprintf(fp,"%4.1f",p->math_poin);
		fputs("\t",fp);
		fprintf(fp,"%4.1f",p->eng_poin);
		fputs("\t",fp);
		fprintf(fp,"%4.1f",p->total_poin);
		fputs("\t",fp);
		if(p->next!=NULL)
		{
			fprintf(fp,"%d\n",p->rank);
		}
		else
		{
			fprintf(fp,"%d",p->rank);
		}
		p=p->next;
	}
	fclose(fp);
	//�����༶���������Ϣ�ļ�
	p=head;
	strcpy(file_name,p->class_num);
    strcat(file_name,".class.txt");
	if((fp=fopen(file_name,"w"))==NULL){
		printf("�ļ�������ϵͳ��������ʧ�ܣ�������ֹ\n");
		destroy(head);
		exit(0);
	}
	create_class_info(head,cls);
	fputs("\t\t\t\t�༶�������\n",fp);
	fputs("���: ",fp);
	fputs(cls.class_num,fp);
	fputs("\tרҵ:",fp);
	fputs(cls.major,fp);
	fputs("\t��ѧ����: ",fp);
	fprintf(fp,"%4.1f",cls.math_ave_poin);
	fputs("\tӢ�����: ",fp);
	fprintf(fp,"%4.1f",cls.eng_ave_poin);
	fputs("\t������: ",fp);
	fprintf(fp,"%d\n",cls.total_peo);
	fputs("��ѧ��߷�ѧ����Ϣ��\n",fp);
	fprintf(fp,"��ѧ��%4.1f\tӢ�%4.1f\t�ܷ֣�%4.1f\t���Σ�%d\tѧ�ţ�%s\t������%s\t�Ա�%s\tרҵ��%s\t��ţ�%s\n",cls.math_hest.math_poin,cls.math_hest.eng_poin,cls.math_hest.total_poin,cls.math_hest.rank,cls.math_hest.stu_num,cls.math_hest.name,cls.math_hest.sex,cls.math_hest.major,cls.math_hest.class_num);
	fputs("Ӣ����߷�ѧ����Ϣ��\n",fp);
	fprintf(fp,"Ӣ�%4.1f\t��ѧ��%4.1f\t�ܷ֣�%4.1f\t���Σ�%d\tѧ�ţ�%s\t������%s\t�Ա�%s\tרҵ��%s\t��ţ�%s\n",cls.eng_hest.eng_poin,cls.eng_hest.math_poin,cls.eng_hest.total_poin,cls.eng_hest.rank,cls.eng_hest.stu_num,cls.eng_hest.name,cls.eng_hest.sex,cls.eng_hest.major,cls.eng_hest.class_num);
	destroy(head);
	fclose(fp);
	printf("����ɹ�����������������˵�");
	getch();
}





void my_sort(STUDENT *head){
	STUDENT *p,*q,temp,*tp,*max,*hhead;
	p=head;
	while(p!=NULL){
		p->total_poin=p->math_poin+p->eng_poin;//�����ܳɼ���ӿ�Ŀʱ�ڴ˴��޸ĳ���
		p=p->next;
	}
	p=head;
	for(hhead=head;hhead->next!=NULL;hhead=p){//�����ܳɼ�����ð�ݷ���
		max=hhead;
        for(q=hhead;q!=NULL;q=q->next)
			if((q->total_poin)>(max->total_poin)) max=q;
		temp=*hhead;
		*hhead=*max;
		*max=temp;
		tp=hhead->next;
		hhead->next=max->next;
		max->next=tp;
		p=p->next;
	}
	int i=1;
	p=head;
	while(p!=NULL){  //�������
		p->rank=i;
		i++;
		p=p->next;
	}
	max=NULL;
	hhead=NULL;
}






      





	



	