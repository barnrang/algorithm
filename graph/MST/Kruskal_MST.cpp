/*
This is the optimized algorithm for searching
the minimum spanning tree

Input data's shape is
M, N
a1 b1 c1
a2 b2 c2
.
.
.
M vertices/ N edges
where a, b are nodes and c is distance.
Complexity O(Elog(V)) or O(Elog(E))
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int find(int pos, struct node tree[]);
int Union(int x, int y, struct node tree[]);
int MST(struct edge graph[], struct node nodes[]);
int M,N;

struct edge{
    int v1;
    int v2;
    int dist;
};

struct node{
    int rank;
    int parent;
};

bool for_sorting(edge a, edge b){
    return a.dist < b.dist;
}

int main(){
    cin >> M >> N;
    struct edge *graph = (struct edge*) malloc( N * sizeof(struct edge));
    struct node *nodes = (struct node*) malloc( M * sizeof(struct node));
    for(int i = 0; i < M; i++){
        nodes[i].rank = 0;
        nodes[i].parent = -1;
    }
    for(int i = 0; i < N; i++){
        cin >> graph[i].v1 >> graph[i].v2 >> graph[i].dist;
    }
    cout << "Shortest sum(dist) is " << MST(graph, nodes) << "\n";
    free(graph);
    free(nodes);
    return 0;
}


/*
MAX is an upper  limit on number of vertices.
g[u] represents adjacency list of vertex u,  Every element of this list
is a pair<w,v>  where v is another vertex and w is weight of edge (u, v)
*/

int MST(struct edge graph[], struct node nodes[]){
    sort(graph, graph + N, for_sorting);
    int count = 0;
    int index = 0;
    int all_dist = 0;
    int pos1, pos2, dist;
    int cycle; //Bool
    while(count < M - 1){
        if(index == N) return -1;
        pos1 = graph[index].v1;
        pos2 = graph[index].v2;
        dist = graph[index].dist;
        cycle = Union(pos1, pos2, nodes);
        if(cycle == 0){
            count++;
            all_dist += dist;
        }
        index++;
    }
    return all_dist;
}

/*
From Union and Find
*/

int find(int pos, struct node tree[]){
    if(tree[pos].parent == -1) return pos;
    else return find(tree[pos].parent, tree);
}


//Union also return cycle existing
int Union(int x, int y, struct node tree[]){
    int lead1 = find(x, tree);
    int lead2 = find(y, tree);
    if(lead1 == lead2) return 1;
    if(tree[lead1].rank > tree[lead2].rank) tree[lead2].parent = lead1;
    else if(tree[lead1].rank < tree[lead2].rank) tree[lead1].parent = lead2;
    else{
        tree[lead1].rank++;
        tree[lead2].parent = lead1;
    }
    return 0;
}
