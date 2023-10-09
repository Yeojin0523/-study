#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHAR_PER_LINE 100
typedef struct {
	char line[MAX_CHAR_PER_LINE];
} element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}
ListNode* insert_last(ListNode* head, element data) {
	ListNode* temp = head;
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = data;
	p->link = NULL;

	if (head == NULL) {
		head = p;
		return head;
	}
	else {
		while (temp->link != NULL)
			temp = temp->link;
		temp->link = p;
	}
	return head;
}
ListNode* insert_pos(ListNode* head, int pos, element value) {
	if (pos < 0 || get_length(head) < pos)
		error("pos error");

	ListNode* temp = head;
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;

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
element get_entry(ListNode* head, int pos) {
	ListNode* p = head;
	for (int i = 0; i < pos; i++)
		p = p->link;
	return p->data;
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
void print_list(ListNode* head) {
	ListNode* p;
	for (p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("\n");
}
void display_te(ListNode* head) {
	ListNode* p;
	p = head;
	int pos = 1;
	printf("\n-----------text edited---------\n");
	while (p != NULL) {
		printf("(%d) %s", pos, p->data);
		p = p->link;
		pos++;
	}
}
char askChoice(void) {
	char choice;
	printf("------------------------------\n");
	printf("a: �ؽ�Ʈ ���� ���� �߰�\n");
	printf("i: ���� ��ȣ�� ���� �߰�\n");
	printf("d: ���� ��ȣ�� ���� ����\n");
	printf("v: ���� ��ȣ�� �ش� ���� ���\n");
	printf("p: ��ü �ؽ�Ʈ ���\n");
	printf("q: ��\n");
	printf("�޴� ����:");
	scanf(" %c", &choice); // Use a space before %c to skip leading whitespace.
	return choice;
}
int main(void){

	ListNode* list = NULL;
	char choice;
	int lineNb;
	element newElement;
	while ((choice = askChoice()) != 'q') {
		switch (choice) {
		case 'a':
			printf("�ؽ�Ʈ ���� ������ ����: ");
			while (getchar() != '\n');
			fgets(newElement.line, MAX_CHAR_PER_LINE, stdin);
			list = insert_last(list, newElement);
			display_te(list);
			break;
		case 'i':
			printf("������ ���� ��ȣ: ");
			scanf("%d", &lineNb);
			if (lineNb < 0 || lineNb > get_length(list) + 1)
				error("���� ��ȣ ����");

			printf("������ ����: ");
			while (getchar() != '\n');
			fgets(newElement.line, MAX_CHAR_PER_LINE, stdin);
			list = insert_pos(list, lineNb -1, newElement);
			display_te(list);
			break;
		case 'd':
			printf("������ ���� ��ȣ: ");
			scanf("%d", &lineNb);
			if (lineNb < 0 || lineNb > get_length(list))
				error("���� ��ȣ ����");
			list = delete_pos(list, lineNb - 1);
			display_te(list);
			//�ڵ�
			break;
		case 'v':
			printf("����� ���� ��ȣ: ");
			scanf("%d", &lineNb);
			if (lineNb < 0 || lineNb > get_length(list))
				error("���� ��ȣ ����");

			element lineData = get_entry(list, lineNb - 1);
			printf("(%d) %s ", lineNb,lineData);
			break;
		case 'p':
			print_list(list);
			display_te(list);
		}
		// while (getchar() != '\n');
	}
}
