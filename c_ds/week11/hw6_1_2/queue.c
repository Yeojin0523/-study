// ���Ḯ��Ʈ�� �̿��� ť
#include "queue.h"
#include <stdio.h>
#include <malloc.h>
void error(char* message) {
	fprintf(stderr, "error");
	exit(1);
}
void init(QueueType* q) {
	q->front = q->rear = NULL;
}
int is_empty(QueueType* q) {
	return q->front == NULL;
}
int is_full(QueueType* q) {
	return 0;
}
void enqueue(QueueType* q, element item) {
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	if (temp == NULL)
		error("�޸𸮸� �Ҵ��� �� �����ϴ�.");
	else {
		temp->item = item;
		temp->link = NULL;
		if (is_empty(q)) {
			q->rear = temp;
			q->front = temp;
		}
		else {
			q->rear->link = temp;
			q->rear = temp;
		}
	}
}
element dequeue(QueueType* q) {
	QueueNode* temp = q->front;
	element item;
	if (is_empty(q))
		error("ť�� ����ֽ��ϴ�.");
	else {
		item = temp->item;
		q->front = temp->link;
		if (q->front == NULL)
			q->rear = NULL;
		free(temp);
		return item;
	}
}