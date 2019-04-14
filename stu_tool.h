#ifndef STU_TOOL_H_
#define STU_TOOL_H_
extern void save(STUDENT *head);//此函数为支持存盘功能实现的函数，隐式调用，用户不参与显式命令
extern void destroy(STUDENT *head);//可以说该函数为存盘的善后，对链表销毁
extern STUDENT* copy();//用于将硬文件拷贝到链表，修改模块启用
extern void create_class_info(STUDENT *head,CLASS &clas);//通过链表班级信息产生班级信息，并存在clas内
extern void my_sort(STUDENT *head);//算出链表学生的总分和排名
#endif