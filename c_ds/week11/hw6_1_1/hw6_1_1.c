// �׷��� �߻� Ÿ���� ����(���� ��� �̿�)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
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
void delete_edge(GraphType* g, int start, int end) { // ���� ����
	if (start >= g->n || end >= g->n) {
		fprintf(stderr, "�׷��� ���� ��ȣ ����");
		return;
	}
	g->adj_mat[start][end] = 0;
	g->adj_mat[end][start] = 0;
}
void insert_vertex(GraphType* g) { // ���� ����
	if ((g->n) + 1 > MAX_VERTICES) {
		fprintf(stderr, "�׷��� ������ ���� �ʰ�");
		return;
	}
	g->n++;
}
void dfs_mat(GraphType* g, int v) {
	int w;
	visited[v] = TRUE;
	printf("����%d ->", v);
	for (w = 0; w < g->n; w++)
		if (g->adj_mat[v][w] && !visited[w])
			dfs_mat(g, w);
}
void bfs_mat(GraphType* g, int v) {
	int w;
	QueueType q;
	init(&q);
	visited[v] = TRUE;
	printf("%d", v);
	enqueue(&q, v);
	while (!is_empty(&q)) {
		v = dequeue(&q);
		for (w = 0; w < g->n; w++)
			if (g->adj_mat[v][w] && !visited[w]) {
				visited[w] = TRUE;
				printf("%d", w);
				enqueue(&q, w);
			}
	}
}
void visited_init() {
	int i;
	for (i = 0; i < MAX_VERTICES; i++)
		visited[i] = 0;
}
void read_graph(GraphType* g, char* filename) {
	int numOfVer, start, end;
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
void write_graph(GraphType* g, char* filename) {
	FILE* fp;

	if (filename == NULL)
		fp = stdout;
	else {
		fp = fopen(filename, "w");
		if (fp == NULL) {
			fprintf(stderr, "���� %s�� �� �� ����\n", filename);
			return;
		}
	}
	for (int i = 0; i < g->n; i++) {
		for (int j = 0; j < g->n; j++)
			fprintf(fp, "%d", g->adj_mat[i][j]);
		fprintf(fp, "\n");
	}
	fclose(fp);
}
void print_adj_mat(GraphType* g) {
	for (int i = 0; i < g->n; i++) {
		for (int j = 0; j < g->n; j++) {
			printf("%d", g->adj_mat[i][j]);
		}
		printf("\n");
	}
}
int main(void) {
	GraphType g;
	graph_init(&g);

	read_graph(&g, "input.txt");
	write_graph(&g, "output.txt");

	return 0;
}
