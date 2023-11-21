// hw6_2_1_a ���� �켱 Ž��, ���� ��� �̿�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// #include "queue.h"
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50
int visited[MAX_VERTICES]; // ���������� �ڵ� 0���� �ʱ�ȭ
typedef struct GraphType {
	int n; // ������ ����
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;
void graph_init(GraphType* g) {
	int r, c;
	g->n = 0;
	for (r = 0; r < MAX_VERTICES; r++)
		for (c = 0; c < MAX_VERTICES; c++)
			g->adj_mat[r][c] = 0;
}
void insert_edge(GraphType* g, int start, int end) { // ���� ����
	if (start >= g->n || end >= g->n) {
		fprintf(stderr, "�׷��� ���� ��ȣ ����");
		return;
	}
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;
}
void dfs_mat(GraphType* g, int v) {
	int w;
	visited[v] = TRUE;

	for (w = 0; w < g->n; w++)
		if (g->adj_mat[v][w] && !visited[w]){
			printf("<%d %d>\n", v, w);
			dfs_mat(g, w);
		}
}
void read_graph(GraphType* g, char* filename) {
	int numOfVer, start, end, vertex;
	FILE* fp = fopen(filename, "r");
	if (fp == NULL) {
		fprintf(stderr, "���� %s�� �� �� ����\n", filename);
		return;
	}
	fscanf(fp, "%d", &numOfVer);
	g->n = numOfVer;

	while (fscanf(fp, "%d %d", &start, &end) != EOF) {
		insert_edge(g, start, end);
	}
	fclose(fp);
}
int main(void) {
	GraphType g;
	int vertex;
	graph_init(&g);
	printf("Enter ����: ");
	scanf("%d", &vertex);
	read_graph(&g, "input.txt");
	
	dfs_mat(&g, vertex);
		
	return 0;
}