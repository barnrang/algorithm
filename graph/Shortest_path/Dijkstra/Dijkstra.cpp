/*
Dijkstra implemented with C++ STL
Input:
M, N
X, Y
a1 ,b1 ,c1
.
.
M vertices/ N edges
X source/ Y target
a1,b1 vertices c1 weight(positive)
Complexity O(Elog(V))
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define INF 0x3f3f3f3f
using namespace std;

long M,N;
long X,Y;
long dj(struct node graph[]);

struct node{
    vector <pair<long,long> > adj;
    long weight;
};

bool for_heap(node a, node b){
    return a.weight > b.weight;
}

int main(){
    cin >> M >> N;
    cin >> X >> Y;
    struct node *graph = (struct node*) malloc( M * sizeof(struct node));
    long a,b,c;
    for(long i = 0; i < N; i++){
        cin >> a >> b >> c;
        graph[a].adj.push_back(make_pair(b, c));
        graph[b].adj.push_back(make_pair(a, c));
    }
    for(int i = 0; i < M; i++) graph[i].weight = (long)INF;
    cout << "The shortest distance is " << dj(graph) << "\n";
}

long dj(struct node graph[]){
    set<pair<long,long> > node_set;
    long used_node[M];
    for(long i = 0; i < M; i++) used_node[i] = 0;
    node_set.insert(make_pair(0, X));
    graph[X].weight = 0;
    while(!node_set.empty()){
        pair<long, long> use = *(node_set.begin());
        node_set.erase(node_set.begin());

        //Check if the minimum reach target
        long no = use.second;
        if(no == Y) return use.first;

        //Continue if not yet reach
        used_node[no] = 1;
        long w = use.first;
        vector <pair<long,long> > :: iterator i;
        for (i = graph[no].adj.begin(); i != graph[no].adj.end(); ++i){
            long v = i->first;
            if (used_node[v] == 1) continue;
            long weight = i->second;
            if (graph[v].weight > (weight + w)){
                if(graph[v].weight != INF){
                    node_set.erase(node_set.find(make_pair(graph[v].weight, v)));
                }
                graph[v].weight = weight + w;
                node_set.insert(make_pair(graph[v].weight, v));
            }
        }
    }
    //In case
    return -1;
}
