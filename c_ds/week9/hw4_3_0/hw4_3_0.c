#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_STRING 100
typedef struct {
	int id;
	char name[MAX_STRING];
	char tel[MAX_STRING];
	char dept[MAX_STRING];
} element;
typedef struct TreeNode {
	element data;
	struct TreeNode* left, * right;
} TreeNode;
TreeNode* new_node(int key, element e) {
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->data.id = key;
	strcpy(temp->data.name, e.name);
	strcpy(temp->data.tel, e.tel);
	strcpy(temp->data.dept, e.dept);
	temp->left = temp->right = NULL;
	return temp;
}
TreeNode* insert_node(TreeNode* root, element e) {
	
	if (root == NULL)
		return new_node(e.id, e);
	if (e.id < root->data.id)
		root->left = insert_node(root->left, e);
	else if (e.id > root->data.id)
		root->right = insert_node(root->right, e);
	return root;
}
int get_minimum(TreeNode* node) {
	TreeNode* current = node;
	while (current->left != NULL)
		current = current->left;
	return current->data.id;
}
TreeNode* delete_node(TreeNode* root, int key) {
	TreeNode* temp;
	if (root == NULL)
		return root;

	if (key < root->data.id)
		root->left = delete_node(root->left, key);
	else if (key > root->data.id)
		root->right = delete_node(root->right, key);
	else {
		if (root->left == NULL) {
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}
		temp = get_minimum(root->right);

		root->data.id = temp->data.id; // ���� ��ȸ�� �İ� ��带 �����Ѵ�.

		root->right = delete_node(root->right, temp->data.id); // ���� ��ȸ�� �İ� ��带 �����Ѵ�.
	}
	return root;
}
void inorder(TreeNode* root) {
	if (root) {
		inorder(root->left);
		printf("�л� ���� �й� �� ���\n--------------------\n");
		printf("�й�: %d\n�̸�: %s\n��ȭ��ȣ: %s\n�а�: %s\n", root->data.id, root->data.name, root->data.tel, root->data.dept);
		inorder(root->right);
	}
}
TreeNode* search(TreeNode* node, int key) {
	if (node == NULL)
		return NULL;
	if (key == node->data.id)
		return node;
	else if (key < node->data.id)
		return search(node->left, key);
	else
		return search(node->right, key);

	return NULL;
}
int get_count(TreeNode* root) {
	if (root == NULL)
		return 0;

	int left_count = get_count(root->left);
	int right_count = get_count(root->right);

	return 1 + left_count + right_count;
}
int main(void) {

	TreeNode* tree = NULL;
	char input;
	
	element e;

	printf("Enter i<nsert>, d<elete>, s<earch>, p<rint>, c<ount>, q<uit>:");
	scanf(" %c", &input);
	while (getchar() != '\n');
	
	while (input != 'q') {
		switch (input) {
		case 'i':
			printf("�й� �Է�: ");
			scanf("%d", &e.id);
			while (getchar() != '\n');
			printf("�̸� �Է�: ");
			scanf("%s", e.name);
			getchar();
			printf("��ȭ��ȣ �Է�: ");
			scanf("%s", e.tel);
			getchar();
			printf("���� �Է�: ");
			scanf("%s", e.dept);
			getchar();
			tree = insert_node(tree, e);
			break;

		case 'd':
			printf("������ �й� �Է�:");
			scanf("%d", &e.id);
			tree = delete_node(tree, e.id);
			while (getchar() != '\n');
			break;
		case 's':
			printf("Ž���� �й� �Է�:");
			scanf("%d", &e.id);
			tree = search(tree, e.id);
			if (tree)
				inorder(tree);
			else
				printf("id�� %d�� �л��� �����ϴ�.\n", e.id);
			while (getchar() != '\n');
			break;
		case 'p':
			inorder(tree);
			break;
		case 'c':
			printf("���� ����� �л��� �� ���� %d", get_count(tree));
			break;
		default:
			break;
		}
		printf("Enter i<nsert>, d<elete>, s<earch>, p<rint>, c<ount>, q<uit>:");
		scanf("%c", &input);
		while (getchar() != '\n');
	}
	return 0;
}