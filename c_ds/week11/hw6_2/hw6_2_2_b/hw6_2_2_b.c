// hw6_2_2_b  ���� �켱 Ž��, ��������Ʈ �̿�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include "queue.h"
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50
int visited[MAX_VERTICES];
typedef struct GraphNode {
    int vertex;
    struct GraphNode* link;
} GraphNode;
typedef struct GraphType {
    int n; // ������ ����
    GraphNode* adj_list[MAX_VERTICES];
} GraphType;
void init_graph(GraphType* g) {
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
void insert_edge(GraphType* g, int u, int v) {
    GraphNode* node;
    if (u >= g->n || v >= g->n) {
        fprintf(stderr, "�׷��� : ���� ��ȣ ����");
        return;
    }
    node = (GraphNode*)malloc(sizeof(GraphNode));
    node->vertex = v;
    node->link = g->adj_list[u];
    g->adj_list[u] = node;

    node = (GraphNode*)malloc(sizeof(GraphNode));
    node->vertex = u;
    node->link = g->adj_list[v];
    g->adj_list[v] = node;
}
void bfs_list(GraphType* g, int v) {
    GraphNode* w;
    QueueType q;
    init(&q);
    visited[v] = TRUE;
    enqueue(&q, v);

    while (!is_empty(&q)) {
        v = dequeue(&q);

        for (w = g->adj_list[v]; w; w = w->link) {
            if (!visited[w->vertex]) {
                visited[w->vertex] = TRUE;
                enqueue(&q, w->vertex);
                printf("<%d %d>\n", v, w->vertex);  // ť���� ������ dequeue�� �Ŀ� ���
            }
        }
    }
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
int main(void) {
    GraphType* g = (GraphType*)malloc(sizeof(GraphType));
    init_graph(g);
    int vertex;

    printf("Enter ����: ");
    scanf("%d", &vertex);
    read_graph(g, "input.txt");
    bfs_list(g, vertex);

    return 0;
}