// �迭�� �̿��� ���� ť
#define MAX_QUEUE_SIZE 100
#include<stdio.h>
#include<stdlib.h>
typedef int element;
typedef struct {
	element queue[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;
void error(char* message) {
	fprintf(stderr, "%s\n", message);
}
void init(QueueType* q) {
	q->front = q->rear = 0;
}
int is_empty(QueueType* q) {
	return (q->front == q->rear);
}
int is_full(QueueType* q) {
	return (q->front == (q->rear + 1) % MAX_QUEUE_SIZE);
}
void enqueue(QueueType* q, element item) {
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�.");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}
element dequeue(QueueType* q) {
	if(is_empty(q))
		error("ť�� ��ȭ�����Դϴ�.");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return (q->queue[q->front]);
}
element peek(QueueType* q) {
	if (is_empty(q))
		error("ť�� ��ȭ�����Դϴ�.");
	return (q->queue[(q->front + 1) % MAX_QUEUE_SIZE]);
}