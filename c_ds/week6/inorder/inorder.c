// �ݺ��� ������ȸ
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;
// ������ ���� typedef
typedef TreeNode* element;
typedef struct StackNode {
	element item;
	struct StackNode* link;
}StackNode;
typedef struct {
	StackNode* top;
}LinkedStackType;
void init(LinkedStackType* s) {
	s->top = NULL;
}
element is_empty(LinkedStackType* s) {
	return s->top == NULL;
}
int is_full(LinkedStackType* s) {
	return 0;
}
void push(LinkedStackType* s, element item) {
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	if (temp == NULL) {
		fprintf(stderr, "�޸� �Ҵ翡��\n");
		return;
	}
	else {
		temp->item = item;
		temp->link = s->top;
		s->top = temp;
	}
}
element pop(LinkedStackType* s) {
	StackNode* temp;
	element item;
	if (is_empty(s)) {
		fprintf(stderr, "������ �������\n");
		exit(1);
	}
	else {
		temp = s->top;
		item = temp->item;
		s->top = temp->link;
		free(temp);
		return item;
	}
}
void stack_print(LinkedStackType* s) {
	LinkedStackType* temp = s->top;
	if (is_empty(s)) {
		printf("<empty>\n--\n");
		return;
	}
	else {
		printf("%d <-top\n", s->top->item);
		s->top = s->top->link;
		while (s->top != NULL) {
			printf("%d\n", s->top->item);
			s->top = s->top->link;
		}
	}
	printf("--\n");
	s->top = temp;
}
void inorder_iter(LinkedStackType *s, TreeNode* root) { // ������ȸ
	for (; root ; root = root->left) // for(int i = 0; i < arraySize; i++) 
		push(s, root);
	while (!is_empty(s)) {
		root = pop(s);
		printf("[%d]", root->data);
		root = root->right;

		for (; root; root = root->left) {
			push(s, root);
		}
	}
}
void postorder_iter(LinkedStackType* s, TreeNode* root) { // ���� ��ȸ
	if (!root) return;

	LinkedStackType* outputStack;
	init(outputStack);

	push(s, root);

	while (!is_empty(s)) {
		root = pop(s);
		push(outputStack, root);

		if (root->left) push(s, root->left);
		if (root->right) push(s, root->right);
	}

	while (!is_empty(outputStack)) {
		root = pop(outputStack);
		printf("[%d]", root->data);
	}
}
void preorder_iter(LinkedStackType* s, TreeNode* root) { // ������ȸ
	if (!root) return;

	push(s, root);

	while (!is_empty(s)) {
		root = pop(s);
		printf("[%d]", root->data);

		if (root->right) push(s, root->right);
		if (root->left) push(s, root->left);
	}
// for ������ �̿��ؼ� ���� ��ȸ ������ ���
/*void inorder_iter(TreeNode* root) {
    TreeNode* stack[100]; // �ִ� ���� ũ��
    int indexStack[100]; // �ε��� ����
    int top = -1;

    TreeNode* current = root;
    
    while (current || top >= 0) {
        while (current) {
            stack[++top] = current;
            indexStack[top] = 0; // ���� ����Ʈ���� �ִ� ���� ��Ÿ���� �ε��� 0
            current = current->left;
        }
        
        current = stack[top];
        
        printf("[%d]", current->data);
        
        if (++indexStack[top] == 1) {
            current = current->right;
        } else {
            current = NULL;
            top--;
        }
    }
}
*/