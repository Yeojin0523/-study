#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_LIST_SIZE 100

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
	if (is_full(L))
		error("����Ʈ �����÷ο�");
	L->array[L->size++] = item;
}
void insert_first(ArrayListType* L, element item) {
	if (is_full(L))
		error("����Ʈ �����÷ο�");
	L->size++;
	for (int i = 0; i <= L->size; i++) 
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
	
	L->size = 0; // !!
}
int main(void) {

	ArrayListType list1;

	init(&list1);
	insert(&list1, 0, 20);
	insert(&list1, 0, 10);
	print_list(&list1);
	clear_list(&list1);
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

	insert_first(&list1, 1);
	print_list(&list1);
	
	return 0;
}
