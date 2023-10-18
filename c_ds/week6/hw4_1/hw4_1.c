#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#define TRUE 1
#define FALSE 0
#define MAX_TREE_SIZE 20
typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right; 
}TreeNode;
TreeNode n1 = { 15, NULL, NULL };
TreeNode n2 = { 4, &n1, NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 15, &n3, &n4 };
TreeNode n6 = { 15, &n2, &n5 };
TreeNode* root = &n6;

TreeNode m1 = { 15, NULL, NULL };
TreeNode m2 = { 4, &n1, NULL };
TreeNode m3 = { 16, NULL, NULL };
TreeNode m7 = { 28, NULL, NULL }; // �߰�
TreeNode m4 = { 25, NULL, &m7 }; // ����
TreeNode m5 = { 15, &m3, &m4 };
TreeNode m6 = { 15, &m2, &m5 };
TreeNode* root2 = &m6;
int get_nonleaf_count(TreeNode* node) { // ����ü ������
	int count = 0;

	if (node != NULL) {
		if (node->left != NULL || node->right != NULL)
			count = 1 + get_nonleaf_count(node->left) + get_nonleaf_count(node->right);
		else
			return 0;
	}
	return count;
}
int get_oneleaf_count(TreeNode* node) { // ����
	int count = 0;

	if (node != NULL) {
		if ((node->left == NULL && node->right != NULL) || (node->right == NULL && node->left != NULL))
			count = 1 + get_oneleaf_count(node->right) + get_oneleaf_count(node->left);
		else
			count = get_oneleaf_count(node->right) + get_oneleaf_count(node->left);
	}
	return count;
}
int get_twoleaf_count(TreeNode* node) {
	int count = 0;

	if (node != NULL) {
		if (node->left != NULL && node->right != NULL)
			count = 1 + get_twoleaf_count(node->left) + get_twoleaf_count(node->right);
		else
			count = get_twoleaf_count(node->left) + get_twoleaf_count(node->right);
	}
	return count;
}
int get_max(TreeNode* node) {
	if (node == NULL) {
		return INT_MIN; 
	}

	int leftMax = get_max(node->left);
	int rightMax = get_max(node->right);
	int rootMax = node->data;

	int maxVal = (leftMax > rightMax) ? leftMax : rightMax;
	return (rootMax > maxVal) ? rootMax : maxVal;
}
int get_min(TreeNode* node) {
	if (node == NULL)
		return INT_MAX;
	
	int leftMin = get_min(node->left);
	int rightMin = get_min(node->right);
	int rootMin = node->data;

	int minVal = (leftMin < rightMin) ? leftMin : rightMin;
	return (rootMin < minVal) ? rootMin : minVal;
}
void node_increase(TreeNode* node) { // ���� Ʈ���� ������ ���� 1�� ����
	
	if (node == NULL)
		return;

	node->data = node->data + 1; 
	node_increase(node->left);
	node_increase(node->right);
}
void preorder(TreeNode* node) {
	if (node != NULL) {
		printf("[%d] ", node->data);
		preorder(node->left);
		preorder(node->right);
	}
}
int equal(TreeNode* node1, TreeNode* node2) {
	if (node1 == NULL && node2 == NULL) {
		return TRUE;
	}
	if ((node1 != NULL && node2 == NULL) || (node1 == NULL && node2 != NULL))
		return FALSE;
	
	if (node1->data == node2->data) {
		if (equal(node1->left, node2->left) && equal(node1->right, node2->right))
			return TRUE;
	}
	return FALSE;
}
TreeNode* copy(TreeNode* node) {
	if (node == NULL)
		return NULL;

	// TreeNode* copied = node; Ʋ�� �ڵ�
	TreeNode* copied = node;
	copied = (TreeNode*)malloc(sizeof(TreeNode));
	
	copied->data = node->data;
	copied->left = copy(node->left);
	copied->right = copy(node->right);

	return copied;
}
int main(void) {

	TreeNode* result[MAX_TREE_SIZE];
	TreeNode* clone;
	int i, num;


	printf("��)\n");
	printf("Ʈ�� root �� ��ܸ������ ������ %d.\n", get_nonleaf_count(root));
	printf("Ʈ�� root2 �� ��ܸ������ ������ %d.\n", get_nonleaf_count(root2));

	printf("Ʈ�� root �� �ڽ��� �ϳ��� �ִ� ����� ������ %d.\n", get_oneleaf_count(root));
	printf("Ʈ�� root2 �� �ڽ��� �ϳ��� �ִ� ����� ������ %d.\n", get_oneleaf_count(root2));
	printf("Ʈ�� root �� �ڽ��� ���� �ִ� ����� ������ %d.\n", get_twoleaf_count(root));
	printf("Ʈ�� root2 �� �ڽ��� ���� �ִ� ����� ������ %d.\n", get_twoleaf_count(root2));
	printf("Ʈ�� root ���� ���� ū ���� %d.\n", get_max(root));
	printf("Ʈ�� root2 ���� ���� ū ���� %d.\n", get_max(root2));
	printf("Ʈ�� root ���� ���� ���� ���� %d.\n", get_min(root));
	printf("Ʈ�� root2 ���� ���� ���� ���� %d.\n", get_min(root2));

	printf("\n ��)\n");
	preorder(root);
	node_increase(root);
	printf("\n");
	preorder(root);
	printf("\n");
	
	printf("%s\n", equal(root, root) ? "����" : "�ٸ���");
	printf("%s\n", equal(root2, root2) ? "����" : "�ٸ���");
	printf("%s\n", equal(root, root2) ? "����" : "�ٸ���");
	
	printf("\n ��)\n");
	clone = copy(root);
	preorder(root);
	printf("\n");
	preorder(clone);
	printf("\n");
}