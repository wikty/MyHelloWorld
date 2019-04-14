#ifndef STUDENT_H_H_
#define STUDENT_H_H_
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#define NUM_MAX 21
#define NAM_MAX 21
#define MAJOR_MAX 21
typedef struct student
{
	char stu_num[NUM_MAX];
	char class_num[NUM_MAX];
	char name[NAM_MAX];
	char sex[3];
	char major[MAJOR_MAX];
	double math_poin;
	double eng_poin;
	double total_poin;
	int rank;
	student *next;
}STUDENT;
typedef struct
{
	char class_num[NUM_MAX];
	char major[MAJOR_MAX];
	double math_ave_poin;
	double eng_ave_poin;
	STUDENT math_hest;
    STUDENT eng_hest;
	int total_peo;
}CLASS;

#endif