#ifndef STU_TOOL_H_
#define STU_TOOL_H_
extern void save(STUDENT *head);//�˺���Ϊ֧�ִ��̹���ʵ�ֵĺ�������ʽ���ã��û���������ʽ����
extern void destroy(STUDENT *head);//����˵�ú���Ϊ���̵��ƺ󣬶���������
extern STUDENT* copy();//���ڽ�Ӳ�ļ������������޸�ģ������
extern void create_class_info(STUDENT *head,CLASS &clas);//ͨ������༶��Ϣ�����༶��Ϣ��������clas��
extern void my_sort(STUDENT *head);//�������ѧ�����ֺܷ�����
#endif