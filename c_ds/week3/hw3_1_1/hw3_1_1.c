#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_QUEUE_SIZE 3
// typedef char element;
typedef struct {
	char name[10];
	char gender;
}element;
typedef struct {
	element man[MAX_QUEUE_SIZE];
	int front;
	int rear;
}QueueType;
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}
void init_queue(QueueType* p) {
	p->front = -1;
	p->rear = -1;
}
int is_empty(QueueType* p) {
	if (p->front == p->rear)
		return 1;
	else
		return 0;
}
int is_full(QueueType* p) {
	if (p->rear == MAX_QUEUE_SIZE - 1)
		return 1;
	else
		return 0;
}
void enqueue(QueueType* p, element item) {
	/*
	if (is_full(p)) {
		error("���� ����ڰ� �����ϴ�. ����ڰ� ��á���� �� ��ȸ�� �̿�");
	}
	*/
	p->man[++(p->rear)] = item;
}
element dequeue(QueueType* p) {
	if (is_empty(p)) {
		error("ť�� ��������Դϴ�.");
	}
	element item = p->man[++(p->front)];
	return item;
}
element peek(QueueType* q)
{
	if (is_empty(q))
	{
		printf("ť�� ��ȭ�����Դϴ�.");
	}
	else return q->man[(q->front) % MAX_QUEUE_SIZE];
}
int get_count(QueueType *p) {
	return p->rear - p->front;
}
void print_queue(QueueType* q) {
	int start = (q->front + 1) % MAX_QUEUE_SIZE;
	int end = (q->rear + 1) % MAX_QUEUE_SIZE;

	for (int i = start; i != end; i = (i + 1) % MAX_QUEUE_SIZE) {
		printf("%s ", q->man[i].name);
	}
}
void find_mate(QueueType *manQ, QueueType *womanQ, element item) {
	
	if(!is_empty(manQ) && !is_empty(womanQ)) {

		printf("Ŀ���� ź���߽��ϴ�!");
		printf("%s %s\n", manQ->man[manQ->front + 1].name, womanQ->man[womanQ->front + 1].name);
		dequeue(manQ);
		dequeue(womanQ);
	}
	else if (is_full(manQ) || is_full(womanQ)) {
		printf("���� ����ڰ� �����ϴ�. ����ڰ� �� á���� �� ��ȸ�� �̿�");
		if (is_full(manQ))
			dequeue(manQ);
		else if(is_full(womanQ))
			dequeue(womanQ);
	}
	else
		printf("���� ����ڰ� �����ϴ�. ��ٷ��ֽʽÿ�.\n");
}
void check_gender(char *gen, QueueType *manQ, QueueType *womanQ, element newPerson) {
	
	if (gen == 'm') {
		enqueue(manQ, newPerson); // enqueue(*manQ, newPerson); �̷��� �ϸ� �ݺ��� �ȵ��ư�
	}
	else {
		enqueue(womanQ, newPerson);
	}
}
int main(void) {

	QueueType manQ, womanQ;
	element newPerson;

	init_queue(&manQ);
	init_queue(&womanQ);

	char input = 0;
	char gender = 0;

	printf("���� �ּ� ���α׷��Դϴ�.");
	do {
		printf("\ni<nsert, ���Է�>, c<heck, ����� üũ>, q<uit>:");
		scanf(" %c", &input);
		
		if (input == 'i') {
			printf("�̸��� �Է�:");
			scanf("%s", newPerson.name);
			printf("������ �Է�<m or f>:");
			scanf(" %c", &newPerson.gender);

			check_gender(newPerson.gender, &manQ, &womanQ, newPerson); // ���⼭ ť�� ���Ա��� �ѹ���
			find_mate(&manQ, &womanQ, newPerson);
		}
		else if (input == 'c') {
			printf("���� ����� %d��: ", get_count(&manQ));
			print_queue(&manQ);
			printf("���� ����� %d��: ", get_count(&womanQ));
			print_queue(&womanQ);
		}
	} while (input != 'q');
	
	return 0;
}