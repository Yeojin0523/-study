// kruscal �ּҺ�� ����Ʈ��, ������ķ�
#include <stdio.h>
#define MAX_VERTICES 100
#define INF 1000L
typedef struct GraphType {
	int n;
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
}GraphType;
void graph_init(GraphType* g){
	int r, c;
	g->n = 0;
	for (r = 0; r < MAX_VERTICES; r++)
		for (c = 0; c < MAX_VERTICES; c++)
			g->adj_mat[r][c] = INF;
}
void insert_edge(GraphType* g, int start, int end) { // ���� ����
	if (start >= g->n || end >= g->n) {
		fprintf(stderr, "�׷��� ���� ��ȣ ����");
		return;
	}
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;
}
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void kruscal(GraphType* g, GraphType* t) { // �Է±׷��� g, ��±׷��� t
	int edge_accepted = 0; // ������� ���õ� ������ ��
	int uset, vset;

	set_init(g->n);
	// ������ ������������ ����
	
	// ���� u�� ���� ��ȣ
	// v�� ���� ��ȣ
	// ���� ���� ������ �ٸ���
	// ����
	// �ΰ��� ������ ��ģ��.

}
void readGraph(GraphType *g, char *filename) {
	int numOfVer, start, end, weight;
	FILE* fp = fopen(filename, "r");
	if (fp == NULL) {
		fprintf(stderr, "���� %s�� �� �� ����\n", filename);
		return;
	}
	fscanf(fp, "%d", &numOfVer);
	g->n = numOfVer;

	while (fscanf(fp, "%d %d %d", &start, &end, &weight) != EOF)
		insert_edge(g, start, end, weight);

	fclose(fp);
}
main()
{
	GraphType g, t; // �Է� �׷���, ��� Ʈ�� 
	graph_init(&g);
	read_graph(&g, "input.txt");
	graph_init(&t);
	t.n = g.n;
	kruskal(&g, &t);
	printf("���Ϸ� ���:\n");
	write_graph(&t, "output.txt");
	write_graph(&t, NULL); // to stdout 
}
