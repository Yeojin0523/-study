#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define TRUE 1 
#define FALSE 0 
#define MAX_VERTICES 100 
#define INF 1000000 /* ���Ѵ� (������ ���� ���) */
typedef struct GraphType {
	int n; // ������ ����
	int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;
int distance[MAX_VERTICES];/* �����������κ����� �ִܰ�� �Ÿ� */
int found[MAX_VERTICES]; /* �湮�� ���� ǥ�� */
int previous[MAX_VERTICES]; /* �ִ� ��� �� �ִ� �� ������ �ٷ� �� ���� ���� */
int choose(int distance[], int n, int found[])
{ // ���� s�� ���Ե��� ����, distance[]�� ���� ���� ���� ��ȯ
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for (i = 0; i < n; i++) {
		if (distance[i] < min && !found[i]) {
			min = distance[i];
			minpos = i;
		}
	}
	return minpos;
}
void print_path(int start, int end)
{
	int u = end;
	if (start == end) {
		printf("%d ", start);
		return;
	}
	else {
		print_path(start, previous[u]);
		printf("-> %d ", u);
	}
}
void shortest_path(GraphType* g, int start)
{
	int i, u, w;
	for (i = 0; i < g->n; i++) /* �ʱ�ȭ */
	{
		distance[i] = g->weight[start][i];
		found[i] = FALSE;
		previous[i] = start;
	}
	found[start] = TRUE; /* ���� ���� �湮 ǥ�� */
	distance[start] = 0;
	previous[start] = 0;
	for (i = 0; i < g->n - 1; i++) {
		u = choose(distance, g->n, found);
		found[u] = TRUE;

		for (w = 0; w < g->n; w++)
			if (!found[w])
				if (distance[u] + g->weight[u][w] < distance[w]) {
					distance[w] = distance[u] + g->weight[u][w];
					previous[w] = u;
				}
				
		print_path(start, u);
		printf("<%d>\n", distance[u]);
	}	
}
void insert_edge(GraphType* g, int start, int end, int value)
{
	if (start >= g->n || end >= g->n) {
		fprintf(stderr, "�׷��� : ���� ��ȣ ����");
		return;
	}
	g->weight[start][end] = value;
	g->weight[end][start] = value;
}
void read_graph(GraphType* g, char* filename)
{
	// ����
	int numOfVer, start, end, weight;
	FILE* fp = fopen(filename, "r");
	if (fp == NULL) {
		fprintf(stderr, "���� %s�� �� �� ����\n", filename);
		return;
	}
	fscanf(fp, "%d", &numOfVer);
	g->n = numOfVer;

	while (fscanf(fp, "%d %d %d", &start, &end, &weight) != EOF) {
		insert_edge(g, start, end, weight);
	}

	fclose(fp);
}
void graph_init(GraphType* g)
{
	// ����
	g->n = 0;
	for (int i = 0; i < MAX_VERTICES; i++) {
		for (int j = 0; j < MAX_VERTICES; j++) {
			g->weight[i][j] = INF;
		}
	}
}
int main(void)
{
	GraphType g;

	graph_init(&g);
	
	read_graph(&g, "input.txt");

	shortest_path(&g, 0); // 0�� ������
}