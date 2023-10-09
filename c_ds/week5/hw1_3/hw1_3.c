#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h> 
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
	if (head == NULL)
		error("item�� �ִ��� Ȯ���� ����Ʈ�� ����");

	while (head != NULL) {
		if (head->number == item)
			return 1;
		head = head->link;
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
	int idx = 0;

	if (pos < 0 || get_length(head) <= pos)
		error("pos error");
	while (p != NULL) {
		if (pos == idx)
			return p->number;
		p = p->link;
		idx++;
	}
	if (head == NULL)
		error("Ȯ���� ����Ʈ�� ����\n");
}
ListNode* delete_by_key(ListNode* head, int key) {
	ListNode* temp = head;
	ListNode* prev = NULL;
	if (head == NULL)
		error("������ �׸��� ����");

	if (head->number == key) {
		head = head->link;
		free(temp);
		return head;
	}
	while (head != NULL) {
		if (temp->number == key) {
			prev->link = temp->link;
			free(temp);
		}
		prev = temp;
		temp = temp->link;
	}
	return head;
}
ListNode* insert_pos(ListNode* head, int pos, element value) {
	if (pos < 0 || get_length(head) < pos)
		error("pos error");

	ListNode* temp = head;
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->number = value;

	if (pos == 0) { // insert_first
		p->link = head;
		head = p;
		return head;
	}

	for (int i = 0; i < pos - 1; i++)
		temp = temp->link;
	p->link = temp->link;
	temp->link = p;
	return head;
}
ListNode* delete_pos(ListNode* head, int pos) {
	ListNode* temp = head;
	ListNode* prevTemp = NULL;

	if (pos < 0 || get_length(head) <= pos)
		error("pos error");

	if (pos == 0) {
		if (head == NULL)
			error("������ �׸��� ����\n");
		else {
			temp = head;
			head = temp->link;
			free(temp);
			return head;
		}
	}
	for (int i = 0; i < pos - 1; i++) {
		prevTemp = temp;
		temp = temp->link;
	}
	prevTemp->link = temp->link;
	free(temp);
	return head;
}
void display(ListNode* head) {
	ListNode* p = head;
	printf("< ");
	while (p != NULL) {
		printf("%d ", p->number); // ���� ������ ����
		p = p->link;
	}
	printf(" >\n");
}
void add_item(ListNode** phead, int new_item) {
	ListNode* p = *phead;
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));

	int total = 0;
	if (*phead == NULL) 
		total = 0; // ?? �����ϸ� ���ڴ�.
	else {
		while (p->link != NULL) {
			total += p->number;
			p = p->link;
		}
	}
	if (total + new_item < 100) {
		newNode->number = new_item; // ���ο� ������ ����
		newNode->link = *phead;
		*phead = newNode;
	}
	else {
		printf("�ִ� ���� <100kg> �ʰ��� ������ %d�� �߰��� �� ����\n", new_item);
		free(newNode); // �Ҵ��� ��� �޸� ����!!!!
	}
}
char askChoice(ListNode *head) {
	char choice;

	printf("enter a<dd>, d<elete>, or q<uit>: ");
	scanf(" %c", &choice);
	return choice;
}
int main(void) {
	ListNode* list = NULL;
	char choice;
	int weight;

	while ((choice = askChoice(list)) != 'q') {
		switch (choice) {
		case 'a':
			printf("enter the weight of the item: ");
			scanf("%d", &weight);
			add_item(&list, weight);
			display(list);
			break;
		case 'd':
			printf("enter the weight of the item: ");
			scanf("%d", &weight);
			delete_by_key(&list, weight);
			display(list);
			break;
		}
		while (getchar() != '\n');
	}
}

