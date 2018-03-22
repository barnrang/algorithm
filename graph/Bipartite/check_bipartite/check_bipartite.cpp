/*
This program is for checking whether the graph can be
bipartite or not

INPUT:
V
a1 a2 a3 ... aV^2
where ai = 0, 1

OUTPUT:
boolean
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<vector<int> > graph;
bool isBipartite(int *used, int index, int V, int color);

int main(){
    int V;
    cin >> V;
    int used[V];
    for(int i = 0; i < V; i++){
        vector<int> vertex;
        for(int j = 0; j < V; j++){
            int tmp;
            cin >> tmp;
            vertex.push_back(tmp);
        }
        graph.push_back(vertex);
        used[i] = -1;
    }
    cout << "This graph is bipartite " << isBipartite(used, 0, V, 0) << "\n";
}

bool isBipartite(int *used, int index, int V, int color){
    used[index] = color;
    int next_color = color ^ 1;
    for (int i = 0; i < V; i++){
        if(graph[index][i] == 1){
            if(used[i] == -1){
                return isBipartite(used, i, V, next_color);
            }
            else if(used[i] == color){
                return false;
            }
        }
    }
    return true;
}
