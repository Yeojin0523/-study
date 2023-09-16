#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAX_STACK_SIZE 100
typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
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
void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->data[++(s->top)] = item;
}
element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}
element peek(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[s->top];
}
void stack_print(StackType *s) {
	if (is_empty(s)) {
		printf("<empty>\n--\n");
		return; // 함수의 실행이 성공적으로 완료되었을 때
	}
	
	printf("%d ", pop(s));

	if (s->top > 0)
		printf("<- top\n");
	else
		printf("\n");
}
int main(void){

	StackType s; // 스택을 정적으로 생성

	init_stack(&s);
 
	push(&s, 10);
	push(&s, 20);	
	push(&s, 30);
	
	stack_print(&s);
	stack_print(&s);
	stack_print(&s);

	return 0;
} 