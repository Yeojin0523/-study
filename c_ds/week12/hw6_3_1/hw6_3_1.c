#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "minheap.h"
#include "unionfind.h"
#define MAX_VERTICES 100
#define INF 9999
typedef struct GraphType {
	int n;					// ������ ����
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

// �׷��� �ʱ�ȭ 
void graph_init(GraphType* g)
{
	// ����
	g->n = 0;
	for (int i = 0; i < MAX_VERTICES; i++) {
		for (int j = 0; j < MAX_VERTICES; j++) {
			g->adj_mat[i][j] = INF;
		}
	}
}
void insert_edge(GraphType* g, int start, int end, int weight)
{
	if (start >= g->n || end >= g->n) {
		fprintf(stderr, "�׷��� : ���� ��ȣ ����");
		return;
	}
	g->adj_mat[start][end] = weight;
	g->adj_mat[end][start] = weight;
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

/*  */
void write_graph(GraphType* g, char* filename)
{
	// ����
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
	fprintf(fp, "%d\n", g->n);
	for (int i = 0; i < g->n; i++)
		for (int j = 0; j < g->n; j++) // ��Ī�̴ϱ� �ݸ� ����ϵ���
			if (g->adj_mat[i][j] != INF)
				fprintf(fp, "%d %d %d\n", i, j, g->adj_mat[i][j]);

	fclose(fp);
}

// ���� ����̳� ���� ����Ʈ���� �������� �о �ּ� ������ ���� 
// ����� ���� �׷����� �������� �����Ѵ�.
void insert_all_edges(HeapType* h, GraphType* g)
{
	// ����

	for (int i = 0; i < g->n; i++) {
		for (int j = i; j < g->n; j++) {
			if (g->adj_mat[i][j] != INF) {
				element e;
				e.u = i;
				e.v = j;
				e.key = g->adj_mat[i][j];
				insert_min_heap(h, e);
			}
		}
	}


}

// kruskal�� �ּ� ��� ���� Ʈ�� ���α׷�
void kruskal(GraphType* g, GraphType* t)
{
	int edge_accepted = 0;
	int uset, vset;
	HeapType h;
	init(&h);
	insert_all_edges(&h, g);
	set_init(g->n);
	element e; // �� ���
	
	while (edge_accepted < (g->n - 1)) {
		e = delete_min_heap(&h);
		uset = set_find(e.u);
		vset = set_find(e.v);
		if (uset != vset) {
			edge_accepted++;
			t->adj_mat[e.u][e.v] = e.key;
			set_union(uset, vset);
		}
	}
}

int main(void)
{
	GraphType g, t;		// �Է� �׷���, ��� Ʈ��

	graph_init(&g);
	read_graph(&g, "input2.txt");
	//read_graph(&g, "input.txt");

	graph_init(&t);
	t.n = g.n;

	kruskal(&g, &t);

	printf("���Ϸ� ���:\n");
	write_graph(&t, "output.txt");
	write_graph(&t, NULL);	// to stdout
}
