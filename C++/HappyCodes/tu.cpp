#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTEX_NUM 100
typedef struct ArcNode{
	int adjvex;//该边的另一个顶点的位置 
	struct ArcNode *nextarc; //指向下一条边 
}ArcNode;

typedef struct VNode{
	int data;//顶点的值 
	ArcNode *firstarc;//指向第一条依附该顶点的边的指针 
}VNode,AdjList[MAX_VERTEX_NUM];

typedef struct{
	AdjList vertices;//顶点数组 
	int vexnum,arcnum;
}ALGraph;

int LocateVex(ALGraph G,int v){//定位函数 
	for(int i=0;i<G.vexnum;i++){
		if(v==G.vertices[i].data)return i;
	} 
}
void CreateUDG(ALGraph &G){
	ArcNode *p,*q;
	int i,j,k,v1,v2;
	printf("分别输入顶点个数和边的数目：\n");
	scanf("%d%d",&G.vexnum,&G.arcnum);
	printf("分别输入各个顶点值：\n");
	for(i=0;i<G.vexnum;i++){
	scanf("%d",&G.vertices[i].data);
	G.vertices[i].firstarc=NULL;//初始化 
	} 
	printf("分别输入各条边的两个顶点：\n");
	for(k=0;k<G.arcnum;k++){
		scanf("%d%d",&v1,&v2);
		i=LocateVex(G,v1);j=LocateVex(G,v2);//定位 
		p=(ArcNode*)malloc(sizeof(ArcNode));//申请一个结点 
		p->adjvex=j;p->nextarc=NULL;//赋值 
		p->nextarc=G.vertices[i].firstarc;//连接结点 
		G.vertices[i].firstarc=p;//连接结点 
		q=(ArcNode*)malloc(sizeof(ArcNode));
		q->adjvex=i;q->nextarc=NULL;
		q->nextarc=G.vertices[j].firstarc;
		G.vertices[j].firstarc=q;
	}
}
void PrintUDG(ALGraph G){//输出邻接表 
    int i,j;
	for(i=0;i<G.vexnum;i++){
		printf("%d:",i+1);
		ArcNode *p;
		p=G.vertices[i].firstarc;
		while(p!=NULL){
			printf("->%d",p->adjvex+1);
			p=p->nextarc;
		}
		printf("\n");
	}
}
static void DFS(ALGraph G, int i, int *visited)
{
    int w;
    ArcNode *node;

    visited[i] = 1;
    printf("%d ", G.vertices[i].data);
    node = G.vertices[i].firstarc;
    while (node != NULL)
    {
        if (!visited[node->adjvex])
            DFS(G, node->adjvex, visited);
        node = node->nextarc;
    }
}
void DFSTraverse(ALGraph G)
{
    int i;
    int visited[MAX_VERTEX_NUM];       // 顶点访问标记

    // 初始化所有顶点都没有被访问
    for (i = 0; i < G.vexnum; i++)
        visited[i] = 0;

    printf("DFS: ");
    for (i = 0; i < G.vexnum; i++)
    {
        if (!visited[i])
            DFS(G, i, visited);
    }
    printf("\n");
}
void BFS(ALGraph G)
{
    int head = 0;
    int rear = 0;
    int queue[MAX_VERTEX_NUM];     // 辅组队列
    int visited[MAX_VERTEX_NUM];   // 顶点访问标记
    int i, j, k;
    ArcNode *node;

    for (i = 0; i < G.vexnum; i++)
        visited[i] = 0;

    printf("BFS: ");
    for (i = 0; i < G.vexnum; i++)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            printf("%d ", G.vertices[i].data);
            queue[rear++] = i;  // 入队列
        }
        while (head != rear) 
        {
            j = queue[head++];  // 出队列
            node = G.vertices[j].firstarc;
            while (node != NULL)
            {
                k = node->adjvex;
                if (!visited[k])
                {
                    visited[k] = 1;
                    printf("%d ", G.vertices[k].data);
                    queue[rear++] = k;
                }
                node = node->nextarc;
            }
        }
    }
    printf("\n");
}
int main(){
	ALGraph G;
	CreateUDG(G);
    DFSTraverse(G);
    BFS(G);
	//PrintUDG(G);
	return 0;
}
