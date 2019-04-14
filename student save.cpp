/*
 *对链表中的学生信息及班级信息进行硬拷贝,调用了stu_tool工具包中的create_class_info()班级信息创建函数
 */
#include"student.h"
#include"stu_tool.h"//用了工具销毁函数和班级信息创建函数
static void sort(STUDENT *head);//按总分排序，在文件保存之前调用，使得保存的文件中学生信息以总成绩排序
void save(STUDENT *head){
	CLASS cls;
	char file_name[NUM_MAX+3];
	STUDENT *p;
	p=head;
	my_sort(head);
	FILE *fp;
	//创建班级里的学生的信息文件
	strcpy(file_name,p->class_num);
    strcat(file_name,".student.txt");
	if((fp=fopen(file_name,"w"))==NULL){
		printf("文件保存中系统出错，保存失败，程序终止\n");
		destroy(head);
		exit(0);
	}
    fputs("学号\t姓名\t班号\t性别\t专业\t数学\t英语\t总分\t名次\n",fp);
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
	//创建班级整体情况信息文件
	p=head;
	strcpy(file_name,p->class_num);
    strcat(file_name,".class.txt");
	if((fp=fopen(file_name,"w"))==NULL){
		printf("文件保存中系统出错，保存失败，程序终止\n");
		destroy(head);
		exit(0);
	}
	create_class_info(head,cls);
	fputs("\t\t\t\t班级总体情况\n",fp);
	fputs("班号: ",fp);
	fputs(cls.class_num,fp);
	fputs("\t专业:",fp);
	fputs(cls.major,fp);
	fputs("\t数学均分: ",fp);
	fprintf(fp,"%4.1f",cls.math_ave_poin);
	fputs("\t英语均分: ",fp);
	fprintf(fp,"%4.1f",cls.eng_ave_poin);
	fputs("\t总人数: ",fp);
	fprintf(fp,"%d\n",cls.total_peo);
	fputs("数学最高分学生信息：\n",fp);
	fprintf(fp,"数学：%4.1f\t英语：%4.1f\t总分：%4.1f\t名次：%d\t学号：%s\t姓名：%s\t性别：%s\t专业：%s\t班号：%s\n",cls.math_hest.math_poin,cls.math_hest.eng_poin,cls.math_hest.total_poin,cls.math_hest.rank,cls.math_hest.stu_num,cls.math_hest.name,cls.math_hest.sex,cls.math_hest.major,cls.math_hest.class_num);
	fputs("英语最高分学生信息：\n",fp);
	fprintf(fp,"英语：%4.1f\t数学：%4.1f\t总分：%4.1f\t名次：%d\t学号：%s\t姓名：%s\t性别：%s\t专业：%s\t班号：%s\n",cls.eng_hest.eng_poin,cls.eng_hest.math_poin,cls.eng_hest.total_poin,cls.eng_hest.rank,cls.eng_hest.stu_num,cls.eng_hest.name,cls.eng_hest.sex,cls.eng_hest.major,cls.eng_hest.class_num);
	destroy(head);
	fclose(fp);
	printf("保存成功！按任意键返回主菜单");
	getch();
}





void my_sort(STUDENT *head){
	STUDENT *p,*q,temp,*tp,*max,*hhead;
	p=head;
	while(p!=NULL){
		p->total_poin=p->math_poin+p->eng_poin;//计算总成绩添加科目时在此处修改程序
		p=p->next;
	}
	p=head;
	for(hhead=head;hhead->next!=NULL;hhead=p){//根据总成绩排序（冒泡法）
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
	while(p!=NULL){  //添加名次
		p->rank=i;
		i++;
		p=p->next;
	}
	max=NULL;
	hhead=NULL;
}






      





	



	