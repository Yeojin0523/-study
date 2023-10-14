#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct ListNode { 	// ��� Ÿ��
	element data;
	struct ListNode* link;
} ListNode;

// ���� ó�� �Լ�
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListNode* insert_first(ListNode* head, int value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));	//(1)
	p->data = value;					// (2)
	p->link = head;	// ��� �������� ���� ����	//(3)
	head = p;	// ��� ������ ����		//(4)
	return head;	// ����� ��� ������ ��ȯ
}

// ��� pre �ڿ� ���ο� ��� ����
ListNode* insert(ListNode* head, ListNode* pre, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));	//(1)
	p->data = value;		//(2)
	p->link = pre->link;	//(3)	
	pre->link = p;		//(4)	
	return head;		//(5)	
}

ListNode* delete_first(ListNode* head)
{
	ListNode* removed;
	if (head == NULL) return NULL;
	removed = head;	// (1)
	head = removed->link;	// (2)
	free(removed);		// (3)
	return head;		// (4)
}
// pre�� ����Ű�� ����� ���� ��带 �����Ѵ�. 
ListNode* delete(ListNode* head, ListNode* pre)
{
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;		// (2)
	free(removed);			// (3)
	return head;			// (4)
}

void print_list(ListNode* head) // ����Ʈ�� ���� end�� ����ϰ� �����϶�
{
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("end\n");
}
//-----------------------------------------
int is_in_list(ListNode* head, element item) // item �� ����Ʈ�� ������ 1 �� �ƴϸ� 0 �� ��ȯ
{
	for (ListNode* p = head; p != NULL; p = p->link)
		if (p->data == item)
			return 1;
	return 0;
}
int get_length(ListNode* head) // �ܼ� ���� ����Ʈ�� �����ϴ� ����� ���� ��ȯ
{
	int length = 0;
	for (ListNode* p = head; p != NULL; p = p->link)
		length++;
	return length;
}

ListNode* delete_by_key(ListNode* head, int key)
{
	ListNode* temp = head;
	ListNode* prev = NULL;
	while (temp->link != NULL) {
		if (head->data == key) {
			head = head->link;
			free(temp);
			return head;
		} // ù��° ���
		
		// �ι�° ������
		if (temp->data == key) {
			prev->link = temp->link;
			free(temp);
			return head;
		}
		prev = temp;
		temp = temp->link;
	}

	return head;
}
int main(void)
{
	ListNode* list = NULL;
	int n, key;

	scanf("%d", &n);
	while (n != -1) {
		list = insert_first(list, n);
		scanf("%d", &n);
	}
	print_list(list);
	scanf("%d", &key);
	list = delete_by_key(list, key);
	print_list(list);
	// �ڵ� ����
}