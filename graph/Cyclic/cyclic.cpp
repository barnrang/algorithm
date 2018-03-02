#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int is_cyclic(vector <int> g[], int MAX);

/*
Input
N M
a1 b1 a2 b2
N,M are no of vertices and edge
a1, b1 are the vertices that are connected to each other, 2 * M pairs in total
*/

int main(){
    int N, M;
    cin >> N >> M;
    vector <int> g[N];
    for(int i = 0; i < M; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        g[tmp1].push_back(tmp2);
    }
    if(is_cyclic(g, N)){
        cout << "Cycle Exist";
    }
    else{
        cout << "No Cycle";
    }
    return 0;
}

/*
MAX is an upper  limit on number of vertices.
g[u] represents adjacency list of vertex u,  Every element of this list
is a <x>  where x is the adjacency
*/

int is_cyclic(vector <int> g[], int MAX){
    //Initialize
    queue <int> nodes;
    int used_vex[MAX];
    for(int i = 0; i < MAX; i++){
        used_vex[i] = 0;
    }
    int st_index = 0;
    int now_index = 0;
    while(st_index < MAX){
        if(!used_vex[st_index]){
            now_index = st_index;
            nodes.push(now_index);
            while(true){
                if(nodes.empty()) break;
                now_index = nodes.front();
                nodes.pop();
                if(used_vex[now_index] == 1) return 1;
                used_vex[now_index] = 1;
                for(int i = 0; i < g[now_index].size(); i++){
                    nodes.push(g[now_index][i]);
                }
            }
        }
        st_index++;
    }
    return 0;
}
