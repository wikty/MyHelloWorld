/*
 *�༶ȫ��ѧ���ɼ����༶���������Ϣ
 */
#include"student.h"
#include"stu_tool.h"
void information(){
	CLASS cls;
	STUDENT *head,*p;
	head=copy();
	p=head;
	create_class_info(head,cls);
	system("cls");
	printf("\n\n\n");
	printf("ѧ��\t����\t���\t�Ա�\tרҵ\t��ѧ�ɼ�\tӢ��ɼ�\t�ܷ�\t����\n");
	while(p!=NULL){
		printf("%s\t%s\t%s\t%s\t%s\t%4.1f\t%4.1f\t%4.1f\t%d\n",p->stu_num,p->name,p->class_num,p->sex,p->major,p->math_poin,p->eng_poin,p->total_poin,p->rank);
		p=p->next;
	}
	printf("\n\t\t\t\t�༶��Ϣ\n");
	printf("��ţ�%s\t",cls.class_num);
	printf("רҵ��%s\t",cls.major);
	printf("��ѧ���֣�%4.1f\t",cls.math_ave_poin);
	printf("Ӣ����֣�%4.1f\t",cls.eng_ave_poin);
	printf("��������%d\n",cls.total_peo);
	puts("\n��ѧ���ѧ����Ϣ��\n");
	printf("��ѧ��%4.1f\tӢ�%4.1f\t�ܷ֣�%4.1f\t���Σ�%d\tѧ�ţ�%s\t������%s\t�Ա�%s\tרҵ��%s\t��ţ�%s\n",cls.math_hest.math_poin,cls.math_hest.eng_poin,cls.math_hest.total_poin,cls.math_hest.rank,cls.math_hest.stu_num,cls.math_hest.name,cls.math_hest.sex,cls.math_hest.major,cls.math_hest.class_num);
	puts("\nӢ�����ѧ����Ϣ��\n");
	printf("Ӣ�%4.1f\t��ѧ��%4.1f\t�ܷ֣�%4.1f\t���Σ�%d\tѧ�ţ�%s\t������%s\t�Ա�%s\tרҵ��%s\t��ţ�%s\n",cls.eng_hest.eng_poin,cls.eng_hest.math_poin,cls.eng_hest.total_poin,cls.eng_hest.rank,cls.eng_hest.stu_num,cls.eng_hest.name,cls.eng_hest.sex,cls.eng_hest.major,cls.eng_hest.class_num);
	destroy(head);
	printf("����������ؿ�ʼ�˵�\n");
	getch();
}

