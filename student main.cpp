/*
 ****************************************************************
 *��Ȩ������Ф�ı󣬰汾1.0
 *����ʱ�� 2012-7-26
 *����ʱ�� 2012-8-12
 ****************************************************************
 *�����飺�ó��������������������༶ѧ����Ϣ�������д����༶��
 *��ѯ��ɾ��
 */
#include"student.h"
#include"stu_main_fn.h"
static int mainmenu();	//��ʼ�˵����ع���ѡ�����
int main(void){
	for(;;){			//forѭ����֤�ˣ�ÿһ�����ܺ����Ľ��������ٴλص���ʼ�˵�
		switch(mainmenu()){
		case 1: buil_class();break;		//����һ���µİ༶��Ϣ
		case 2: modification();break;		//�޸Ĳ˵���ͨ���ò˵�������޸��Ѿ���������İ༶��ѧ����Ϣ
		case 3: information();break;	//�༶��Ϣ��ѯ
		case 4: sear_menu();break;		//��Ϣ��ѯ�˵�
		case 5: printf("ллʹ�ã��밴������˳�����\n\n\n");		//�˳��������������˳������Ψһ����
			    getch();
				exit(0);
				break;
		default: break;
		}
		system("cls");
	}
	return 0;
}
int mainmenu(){
	int chioce;
	printf("\n\n\n				��ӭ����ѧ����Ϣ����ƽ̨��\n");
	printf("			��ƽ̨Ϊ���ṩ��¼��ɾ�ģ��鿴ѧ����Ϣ�Ĺ���\n");
	printf("			��������Ŀ¼��Ӧ�����������ѡ����Ӧ����(��enter��ȷ��)\n\n\n");
	printf("					1.����-�༶��Ϣ�ļ�\n");
	printf("					2.�޸�-�༶��Ϣ�ļ�\n");
	printf("					3.�鿴-�༶��Ϣ\n");
	printf("					4.��ѯ-ѧ����Ϣ\n");
	printf("					5.�˳�ƽ̨\n");
	printf("			�����룺");
	scanf("%d%*c",&chioce);
	while(!(chioce<=5&&chioce>=1)){
		printf("			����������׼ȷ����˵����:");
		scanf("%d%*c",&chioce);
	}
	system("cls");
	return chioce;
}
