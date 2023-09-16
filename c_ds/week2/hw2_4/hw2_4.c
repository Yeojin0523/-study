#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define MAX_STRING 100
#define MAX_STACK_SIZE 100

typedef char element;

typedef struct {
	int top;
	element word[MAX_STRING];
}StackType;

void init_stack(StackType* s) {
	s->top = -1;
}

int is_empty(StackType* s) {
    return (s->top == -1);
}

int is_full(StackType* s) {
    return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType* s, element word) {
    if (is_full(s)) {
        fprintf(stderr, "���� ��ȭ ����\n");
        return;
    }
    else {
        s->word[++(s->top)] = word;
    }
}

element pop(StackType* s) {
    if (is_empty(s)) {
        fprintf(stderr, "���� ���� ����\n");
        exit(1);
    }
    return s->word[s->top--];
}

element peek(StackType* s) {
    if (is_empty(s)) {
        fprintf(stderr, "���� ���� ����\n");
        exit(1);
    }
    return s->word[s->top];
}

int palindrome(char str[]) {
	StackType s;	
    init_stack(&s);

    int count = 0, i, j;

    //str�� ���ڿ��� ���ÿ� �ֱ�
    for (i = 0; str[i] != '\0'; i++) {
        push(&s, str[i]);
        count++;
    }

    // ���ÿ��� �ϳ��� ���鼭 ���ڵ�� ���ʷ� ��
    for (j = 0; j < count / 2; j++) {
        if (str[j] == pop(&s))
            continue;
        else
            return 0;
    }
    return 1;
}
int main(void) {

    char word[MAX_STRING];

	printf("Enter a word to check palindrome:");
	scanf("%s", word);

	if (palindrome(word))
		printf("palindrome �Դϴ�.\n");
	else
		printf("palindrome�� �ƴմϴ�.\n");
	
	return 0;
}