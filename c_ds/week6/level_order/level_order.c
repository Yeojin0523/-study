// ���� ��ȸ(ť�� �̿�)
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;
// ���� ť ����
#define MAX_QUEUE_SIZE 100
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
	if (is_empty(q))
		error("ť�� ��������Դϴ�.");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return (q->queue[q->front]);
}
void level_order(TreeNode* ptr) {
	QueueType q;
	init(&q);

	if (ptr == NULL)
		return;

	enqueue(&q, ptr);
	
	while(!is_empty(&q)){
		ptr = dequeue(&q); // ť���� �ϳ��� ���� ptr��. ��� ��ü�� ����Ű�� ���ؼ� ptr->data�� �ƴ϶� ptr
		printf("[%d]", ptr->data);
		if (ptr->left) // �����Ͱ� ������ ����Ų�ٸ�
			enqueue(&q, ptr->left);
		if(ptr->right)
			enqueue(&q, ptr->right);
	}
}