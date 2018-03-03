/*
Dijkstra implemented with min-heap
Input:
M, N
X, Y
a1 ,b1 ,c1
.
.
M vertices/ N edges
a1,b1 vertices c1 weight(positive)
Complexity O(Elog(V))
*/

#include <iostream>
#include <algorithm>
#include <vector>
#define INF 10e+18;
int M,N;
int X,Y;
int weight[1000][1000];

struct node{
    vector <node> *adj;
    int no;
    int weight;
};

int for_heap(node a, node b){
    return a.weight > b.weight;
}

int main(){
    cin >> M >> N;
    cin >> X >> Y;
    struct node *graph = (struct node*) malloc( M * sizeof(struct node));
    int a,b,c;
    for(int i = 0; i < N; i++){
        cin >> a >> b >> c;
        graph[a].weight = INF;
        graph[b].weight = INF;
        graph[a].adj.push_back(&graph[b]);
        graph[b].adj.push_back(&graph[a]);
    }
    cout << "The shortest distance is " << dj(graph) << "\n";
}

int dj(struct node graph[]){
    int used_node[M];

    for(int i = 0; i < M; i++){
        graph[i].no = i
        used_node[i] = 0;
    }
    graph[X].weight = 0;
    make_heap(graph, graph + N, for_heap);
    struct node chosen;
    while(chosen != Y){
        chosen = graph.front();
        used_node[chosen.no] = 1;
        graph.pop();
        for(int i = 0; i < chosen.adj.size(); i++){
            if(chosen.adj[i] != NULL){
                chosen.adj[i] -> weight = min(chosen.weight + )
            }
        }
    }
}
