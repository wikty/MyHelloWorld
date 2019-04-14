/*
 ****************************************************************
 *版权归属于肖文斌，版本1.0
 *创建时间 2012-7-26
 *调试时间 2012-8-12
 ****************************************************************
 *程序简介：该程序可以用来管理任意个班级学生信息，功能有创建班级，
 *查询，删改
 */
#include"student.h"
#include"stu_main_fn.h"
static int mainmenu();	//开始菜单返回功能选择序号
int main(void){
	for(;;){			//for循环保证了，每一个功能函数的结束，都再次回到开始菜单
		switch(mainmenu()){
		case 1: buil_class();break;		//创建一个新的班级信息
		case 2: modification();break;		//修改菜单，通过该菜单你可以修改已经创建保存的班级或学生信息
		case 3: information();break;	//班级信息查询
		case 4: sear_menu();break;		//信息查询菜单
		case 5: printf("谢谢使用！请按任意键退出程序\n\n\n");		//退出程序，这是正常退出程序的唯一出口
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
	printf("\n\n\n				欢迎进入学生信息管理平台！\n");
	printf("			此平台为您提供记录，删改，查看学生信息的功能\n");
	printf("			输入以下目录对应的数字序号以选择相应功能(按enter键确认)\n\n\n");
	printf("					1.创建-班级信息文件\n");
	printf("					2.修改-班级信息文件\n");
	printf("					3.查看-班级信息\n");
	printf("					4.查询-学生信息\n");
	printf("					5.退出平台\n");
	printf("			请输入：");
	scanf("%d%*c",&chioce);
	while(!(chioce<=5&&chioce>=1)){
		printf("			输入有误，请准确输入菜单序号:");
		scanf("%d%*c",&chioce);
	}
	system("cls");
	return chioce;
}
