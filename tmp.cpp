#include <iostream>
#include <limits.h>
#include <math.h>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

typedef char VertexType;
typedef int EdgeType;
#define MAX_VEX_NUM 100
#define INFINITY 65535
bool visited[MAX_VEX_NUM];

typedef struct {
    vector<VertexType> vertexes;  // 顶点表
    vector<vector<EdgeType>> arc; // 邻接矩阵，可视为边表
    int num_vertexes, num_edges;  // 图中顶点数和边数
} MGraph;

typedef struct EdgeNode {
    int adjvex;             // 邻接点域，存储该顶点对应的数组中的下标
    EdgeType weight;        // 存储权值
    struct EdgeNode *next_; // 指向下一个邻接点
} EdgeNode;

typedef struct VertexNode {
    VertexType data;
    EdgeNode *first_edge_; // 边表头指针
} VertexNode;

typedef struct {
    vector<VertexNode> adj_list;
    int num_vertexes, num_edges;
} GraphAdjList;

typedef struct Arc {
    int tailvex, headvex; // 存储弧起点，弧终点在顶点数组中的下标
    EdgeType weight;
    struct Arc *head_link_, *tail_link_;
} Arc;

typedef struct {
    VertexType data;
    Arc *firstin_, *firstout_;
} VertexOrthogonal;

typedef struct {
    vector<VertexOrthogonal> orthogonal_list;
    int arc_num, vertex_num;
} OLGraph;

// typedef struct EdgeNode {
//     int ivex, jvex;
//     struct EdgeNode *i_link_, *j_link_;
//     infoType *info_;
// }EdgeNode;

// typedef struct VertexNode {
//     VertexType data;
//     EdgeNode *first_edge_;
// }VertexNode;

// typedef struct {
//     vector<VertexNode> adj_multi_list;
//     int vex_num, edge_num;
// }AdjMlGraph;

// void dfs(GraphAdjList *gal, int i) {
//     EdgeNode *p;
//     visited[i] = true;
//     printf("%c", gal->adj_list[i].data); // 起点
//     p = gal->adj_list[i].first_edge_;
//     while (p) {
//         if (!visited[p->adjvex])
//             dfs(gal, p->adjvex);
//         p = p->next_;
//     }
// }
void MiniSpanTree_Prim(MGraph *g) {
    int min, i, j, k;
    vector<int> adjvex(MAX_VEX_NUM);
    vector<int> low_cost(MAX_VEX_NUM);
    low_cost[0] = 0;
    adjvex[0] = 0;
    for (i = 1; i < g->num_vertexes; i++) {
        low_cost[i] = g->arc[0][i];
        adjvex[i] = 0;
    }
    for (i = 1; i < g->num_vertexes; i++) {
        min = INFINITY;
        j = 1;
        k = 0;
        while (j < g->num_vertexes) {
            if (low_cost[j] != 0 && low_cost[j] < min) {
                min = low_cost[j];
                k = j;
            }
            j++;
        }
        printf("(%d, %d)", adjvex[k], k); // 打印当前顶点边中权值最小边
        low_cost[k] = 0;                  // 当前顶点的权值置零，表示此顶点已经完成任务
        for (j = 1; j < g->num_vertexes; j++) {
            if (low_cost[j] != 0 && g->arc[k][j] < low_cost[j]) {
                low_cost[j] = g->arc[k][j];
                adjvex[j] = k;
            }
        }
    }
}
typedef struct {
    int begin;
    int end;
    int weight;
}Edge;