#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h> // malloc �� �� �ʼ���

typedef int element;
typedef struct ListNode {
	element number;
	struct ListNode* link;
}ListNode;
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}
ListNode* insert_first(ListNode* head, element data) {

	ListNode* list = (ListNode*)malloc(sizeof(ListNode));

	list->number = data;
	list->link = head;
	head = list;

	return head;
}
ListNode* insert_last(ListNode* head, element data) {
	ListNode* temp = head;
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->number = data;
	p->link = NULL;

	if (head == NULL) {
		head = p;
	}
	else {
		while (temp->link != NULL)
			temp = temp->link;
		temp->link = p;
	}
	return head;
}
ListNode* delete_first(ListNode* head) {
	ListNode* removed;
	if (head == NULL)
		error("������ �׸��� ����");
	else {
		removed = head;
		head = removed->link;
		free(removed);
	}
	return head;
}
ListNode* delete_last(ListNode* head) {
	ListNode* temp = head;
	ListNode* prevTemp = NULL;
	ListNode* removed;

	if (head == NULL)
		error("������ �׸��� ����\n");
	if (head->link == NULL) {
		free(temp);
		head = NULL;
	}
	else {
		while (temp->link != NULL) {
			prevTemp = temp;
			temp = temp->link;
		}
		prevTemp->link = NULL;
		free(temp);
	}
	return head;
}
ListNode* reverse(ListNode* head) {
	ListNode* p, * q, * r;
	p = head;
	q = NULL;

	while (p != NULL) {
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}
	return q;
}
ListNode* concat(ListNode* head1, ListNode* head2) {
	ListNode* p;
	if (head1 == NULL)
		return head2;
	else if (head2 == NULL)
		return head1;
	else {
		p = head1;
		while (p->link != NULL)
			p = p->link;
		p->link = head2;
	}
	return head1;
}
int is_in_list(ListNode* head, element item) {
	ListNode* p;
	p = head;
	if (head == NULL)
		error("item�� �ִ��� Ȯ���� ����Ʈ�� ����");

	while (p->link != NULL) {
		if (p->number == item)
			return 1;
		else
			p = p->link;
	}
	return 0;
}
int get_length(ListNode* head) {
	ListNode* p = head;
	int count = 0;

	while (p != NULL) {
		p = p->link;
		count++;
	}
	return count;
}
int get_total(ListNode* head) {
	ListNode* p = head;
	int total = 0;
	while (p != NULL) {
		total += p->number;
		p = p->link;
	}
	return total;
}
element get_entry(ListNode* head, int pos) {
	ListNode* p = head;
	for (int i = 0; i < pos; i++)
		p = p->link;
	return p->number;
}
ListNode* delete_by_key(ListNode* head, int key) {
	ListNode* p = head;
	ListNode* prev = NULL;

	if (head == NULL)
		error("������ �׸��� ����");
	
	while (p != NULL) {
		if (p->number == key) {
			if (prev == NULL) {
				head = p->link;
				free(p);
				return head;
			}
			else {
				prev->link = p->link;
				free(p);
				return head;
			}
		}
		else
			printf("key�� node�� ����");
		prev = p;
		p = p->link;
	}
	return head;
}
ListNode* insert_pos(ListNode* head, int pos, element value) {
	ListNode* temp = head;
	
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->number = value;
	
	if (pos == 0) 
		head = insert_first(head, value);
	else if(pos == get_length(head) - 1) 
		head = insert_last(head, value);
	else {
		for (int i = 0; i < pos - 1; i++) 
			temp = temp->link;
		p->link = temp->link;
		temp->link = p;
	}
	return head;
}
ListNode* delete_pos(ListNode* head, int pos) {
	ListNode* temp = head;
	ListNode* prevTemp = NULL;
	ListNode* removed;
	
	if (pos == 0)
		head = delete_first(head);
	else if (pos == get_length(head) - 1)
		head = delete_last(head);
	else {
		for (int i = 0; i < pos - 1; i++) {
			prevTemp = temp;
			temp = temp->link;
		}
		prevTemp->link = temp->link;
		free(temp);
	}
	return head;
}
void print_list(ListNode* head) {
	ListNode* p;
	for (p = head; p != NULL; p = p->link)
		printf("%d->", p->number);
	printf("\n");
}
int main(void) {
	
	ListNode *list1 = NULL, *list2 = NULL, *list3;

	// list1 = 30 -> 20 -> 10�� �����.
	list1 = insert_first(list1, 10);
	list1 = insert_first(list1, 20);
	list1 = insert_first(list1, 30);

	// list1 ���
	printf("list1 = "); 
	print_list(list1);

	// list1�� �� �� ��带 �����Ѵ�. ��, list1 = 20 -> 30
	list1 = delete_first(list1);
	printf("list1 = ");
	print_list(list1);

	// list2�� �����. 11 22 33 44
	list2 = insert_last(list2, 11);
	list2 = insert_last(list2, 22);
	list2 = insert_last(list2, 33);
	list2 = insert_last(list2, 44);

	printf("list2 = ");
	print_list(list2);

	list2 = delete_last(list2);
	printf("list2 = ");
	print_list(list2);

	list3 = reverse(list2);
	printf("list3 = ");
	print_list(list3);

	list1 = concat(list1, list3);
	printf("list1 = ");
	print_list(list1);
	printf("\n");

	printf("20�� ����Ʈ�� ������ 1, ������ 0 ��� : %d\n", is_in_list(list1, 20));
	printf("50�� ����Ʈ�� ������ 1, ������ 0 ��� : %d\n", is_in_list(list1, 50));
	printf("��� ���� ��� : %d\n", get_length(list1));
	printf("������ ���� ���� �� : %d\n", get_total(list1));
	printf("pos = 2�� �ִ� data �� : %d\n", get_entry(list1, 2));
	
	printf("key = 20�϶� list? : ");
	list1 = delete_by_key(list1, 20);
	print_list(list1);
	printf("\n");
	
	printf("insert_pos�Լ�, pos = 2���? "); 
	list1 = insert_pos(list1, 2, 60);
	print_list(list1);
	
	printf("\ndelete_pos�Լ�, pos = 0? ");
	list1 = delete_pos(list1, 0);
	print_list(list1);
	return 0;
}