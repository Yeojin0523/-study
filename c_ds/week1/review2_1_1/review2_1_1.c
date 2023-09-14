#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
typedef struct score {
	int midterm;
	int final;
}Score;
void printScore(Score* p) {
	printf("�߰����� ������ %d\n", p->midterm);
	printf("�⸻���� ������ %d\n", p->final);
}
Score* biggerScore(Score* p1, Score* p2) {
	Score* bigger = (Score*)malloc(sizeof(Score));

	if (p1->midterm > p2->midterm)
		bigger->midterm = p1->midterm;
	else
		bigger->midterm = p2->midterm;

	if (p1->final > p2->final)
		bigger->final = p1->final;
	else
		bigger->final = p2->final;

	return bigger;
}
Score* totalScore(Score* p1, Score* p2) {
	Score* total = (Score*)malloc(sizeof(Score));

	total->midterm = p1->midterm + p2->midterm;
	total->final = p1->final + p2->final;

	return total;
}
Score* createScore(int midterm, int final) {
	Score* create = (Score*)malloc(sizeof(Score));

	create->midterm = midterm;
	create->final = final;

	return create;
}
int main(void) {

	Score *p1, *p2, *p3;
	
	p1 = (Score*)malloc(sizeof(Score));
	p2 = (Score*)malloc(sizeof(Score));

	p1->midterm = 50;
	p1->final = 100;
	p2->midterm = 70;
	p2->final = 70;

	printScore(p1);
	printScore(p2);

	printf("----------------------\n");
	printf("���� ������ ���� ����:\n");
	printScore(biggerScore(p1, p2));

	printf("----------------------\n");
	printf("�� ������ �� ��:\n");
	printScore(totalScore(p1, p2));

	printf("----------------------\n");
	p3 = createScore(100, 100);
	printScore(p3);

	free(p1);
	free(p2);

	return 0;
}