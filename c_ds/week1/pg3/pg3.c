#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
typedef struct student {
	char name[20];
	int midterm;
	int final;
}student;
int main(void) {
	
	student *sp;
	sp = (student*)malloc(sizeof(student));
	
	printf("Enter student name:");
	scanf("%s", &sp->name);
	
	printf("Enter midterm and final score:");
	scanf("%d %d", &sp->midterm, &sp->final);

	printf("\n이름\t중간\t학기말\n");
	printf("%s\t%d\t%d\n", sp->name, sp->midterm, sp->final);

	return 0;
}