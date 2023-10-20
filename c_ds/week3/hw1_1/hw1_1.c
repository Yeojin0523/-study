#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // exit(1)
#define MAX_LIST_SIZE 5
typedef int element;
typedef struct {
	element array[MAX_LIST_SIZE];
	int size;
}ArrayListType;
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}
void init(ArrayListType* L) {
	L->size = 0;
}
int is_empty(ArrayListType* L) {
	return L->size == 0;
}
int is_full(ArrayListType* L) {
	return L->size == MAX_LIST_SIZE;
}
element get_entry(ArrayListType* L, int pos) {
	if (pos < 0 || pos >= L->size)
		error("��ġ ����");
	return L->array[pos];
}
void print_list(ArrayListType* L) {
	int i;
	for (i = 0; i < L->size; i++) {
		printf("%d->", L->array[i]);
	}
	printf("����Ʈ ��\n");
}
void insert_last(ArrayListType* L, element item) {
	if (is_full(L)) {
		printf("����Ʈ �����÷ο�\n");
		return;
	}
	L->array[L->size++] = item;
}
void insert_first(ArrayListType* L, element item) {
	if (is_full(L)) {
		printf("����Ʈ �����÷ο�\n");
		return;
	}
	L->size++;
	
	for (int i = L->size - 1; i >= 0; i--)
		L->array[i + 1] = L->array[i];
	L->array[0] = item;
}
void insert(ArrayListType* L, int pos, element item) {
	if (!is_full(L) && pos >= 0 && pos <= L->size) {
		for (int i = (L->size - 1); i >= pos; i--)
			L->array[i + 1] = L->array[i];
		L->array[pos] = item;
		L->size++;
	}
}
element delete(ArrayListType* L, int pos) {
	element item;

	if (pos < 0 || pos >= L->size)
		error("��ġ ����");
	item = L->array[pos];

	for (int i = pos; i < (L->size - 1); i++)
		L->array[i] = L->array[i + 1];
	L->size--;

	return item;
}
void clear_list(ArrayListType* L) {
	for (int i = 0; i < L->size; i++) {
		// ������ ��Ҹ� ����
		free(L->array[i]);
	}
	L->size = 0; 
}
int get_length(ArrayListType* L) {
	int count = 0;
	
	for (int i = 0; i < L->size; i++)
		count++;
	return count;
}
element replace(ArrayListType* L, int pos, int item) {
	int temp = 0;

	temp = L->array[pos];
	L->array[pos] = item;
	item = temp;

	return L->array[pos];
}
int is_in_list(ArrayListType* L, int item) {
	for (int i = 0; i < L->size; i++) {
		if (item == L->array[i])
			return 1;
	}
	return 0;
}
void delete_by_key(ArrayListType *L, int item) {
	for (int i = 0; i < L->size; i++) {
		if (item == L->array[i]) {
			delete(L, i);
			return; // �� �̻� ó���� �ʿ� �����Ƿ� �Լ��� �����Ѵ�.
		}
	}
	printf("�����Ϸ��� key�� %d�� ����Ʈ�� �����ϴ�.\n", item);
}
int main(void) {

	ArrayListType list1;

	init(&list1);
	insert(&list1, 0, 20);
	insert(&list1, 0, 10);
	print_list(&list1);
	clear_list(&list1);
	print_list(&list1);

	insert_last(&list1, 90);
	print_list(&list1);

	insert(&list1, 0, 30);
	insert(&list1, 0, 20);
	insert(&list1, 0, 10);
	print_list(&list1);

	delete(&list1, 2);
	print_list(&list1);

	printf("\n-�� ���Ĵ� hw1_1���� �߰��� �Լ��� �׽�Ʈ-\n");
	insert_first(&list1, 9);
	print_list(&list1);
	insert_last(&list1, 99);
	print_list(&list1);

	insert_first(&list1, 1); // ����Ʈ �����÷ο� ����ؾߵ� -> �ٷ� ���������� -> exit(1) �������� ������ ����(100����)
	print_list(&list1);
	
	printf("���̴� %d\n", get_length(&list1));
	printf("3��° �����ʹ� %d\n", get_entry(&list1, 2));
	
	replace(&list1, 3, 40);
	print_list(&list1);
	printf("20�� ����Ʈ�� %s\n", is_in_list(&list1, 20) ? "�ֽ��ϴ�" : "�����ϴ�");
	printf("22�� ����Ʈ�� %s\n", is_in_list(&list1, 22) ? "�ֽ��ϴ�" : "�����ϴ�");

	delete_by_key(&list1, 20);
	print_list(&list1);
	delete_by_key(&list1, 22);
	print_list(&list1);
	
	return 0;
}
