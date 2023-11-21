#include <stdio.h>
#define MAX_VERTICES 50
typedef struct GraphNode {
	int vertex;
	struct GraphNode* link;
}GraphNode;
typedef struct GraphType {
	int n; // ������ ����
	GraphNode* adj_list[MAX_VERTICES];
} GraphType;
void graph_init(GraphType* g) {
	int v;
	g->n = 0;
	for (v = 0; v < MAX_VERTICES; v++)
		g->adj_list[v] = NULL;
}
void insert_vertex(GraphType* g, int v) {
	if ((g->n + 1) > MAX_VERTICES) {
		fprintf(stderr, "�׷��� : ������ ���� �ʰ�");
		return;
	}
	g->n++;
}
void insert_edge(GraphType* g, int u, int v) { // ���� �׷����� ����
	GraphNode* node;
	if (u >= g->n || v >= g->n) {
		fprintf(stderr, "�׷��� : ���� ��ȣ ����");
		return;
	}
	node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = v;
	node->link = g->adj_list[u];
	g->adj_list[u] = node;
}
void print_adj_list(GraphType* g) {
	for (int i = 0; i < g->n; i++) {
		GraphNode* p = g->adj_list[i];
		printf("���� %d�� ���� ����Ʈ", i);
		while (p != NULL) {
			printf("->%d ", p->vertex);
			p = p->link;
		}
	}
}
int edgeCount(GraphType* g) {
	int totalEdges = 0;

	for (int v = 0; v < g->n; ++v) {
		GraphNode* current = g->adj_list[v];

		while (current != NULL) {
			totalEdges++;
			current = current->link;
		}
	}
	return totalEdges / 2;
}
int inDegree(GraphType* g, int vertex) {
	int degree = 0;
	int v;
	for (v = 0; v < g->n; v++) {
		GraphNode* current = g->adj_list[v];
		while (current != NULL) {
			if (current->vertex == vertex) {
				degree++;
			}
			current = current->link;
		}
	}
	return degree;
}
int outDegree(GraphType* g, int vertex) {
	int degree = 0;
	GraphNode* current = g->adj_list[vertex];

	while (current != NULL) {
		degree++;
		current = current->link;
	}
	return degree;
}
int main(void) {
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	init(g);

	for (int i = 0; i < 4; i++)
		insert_vertex(g, i);
	insert_edge(g, 0, 1);
	insert_edge(g, 1, 0);
	insert_edge(g, 0, 2);
	insert_edge(g, 2, 0);
	insert_edge(g, 0, 3);
	insert_edge(g, 3, 0);
	insert_edge(g, 1, 2);
	insert_edge(g, 2, 1);
	insert_edge(g, 2, 3);
	insert_edge(g, 3, 2);
	print_adj_list(g);
	free(g);
	return 0;
}