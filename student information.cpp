/*
 *班级全体学生成绩及班级总体情况信息
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
	printf("学号\t姓名\t班号\t性别\t专业\t数学成绩\t英语成绩\t总分\t名次\n");
	while(p!=NULL){
		printf("%s\t%s\t%s\t%s\t%s\t%4.1f\t%4.1f\t%4.1f\t%d\n",p->stu_num,p->name,p->class_num,p->sex,p->major,p->math_poin,p->eng_poin,p->total_poin,p->rank);
		p=p->next;
	}
	printf("\n\t\t\t\t班级信息\n");
	printf("班号：%s\t",cls.class_num);
	printf("专业：%s\t",cls.major);
	printf("数学均分：%4.1f\t",cls.math_ave_poin);
	printf("英语均分：%4.1f\t",cls.eng_ave_poin);
	printf("总人数：%d\n",cls.total_peo);
	puts("\n数学最高学生信息：\n");
	printf("数学：%4.1f\t英语：%4.1f\t总分：%4.1f\t名次：%d\t学号：%s\t姓名：%s\t性别：%s\t专业：%s\t班号：%s\n",cls.math_hest.math_poin,cls.math_hest.eng_poin,cls.math_hest.total_poin,cls.math_hest.rank,cls.math_hest.stu_num,cls.math_hest.name,cls.math_hest.sex,cls.math_hest.major,cls.math_hest.class_num);
	puts("\n英语最高学生信息：\n");
	printf("英语：%4.1f\t数学：%4.1f\t总分：%4.1f\t名次：%d\t学号：%s\t姓名：%s\t性别：%s\t专业：%s\t班号：%s\n",cls.eng_hest.eng_poin,cls.eng_hest.math_poin,cls.eng_hest.total_poin,cls.eng_hest.rank,cls.eng_hest.stu_num,cls.eng_hest.name,cls.eng_hest.sex,cls.eng_hest.major,cls.eng_hest.class_num);
	destroy(head);
	printf("按任意键返回开始菜单\n");
	getch();
}

