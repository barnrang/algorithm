/*
Input:
V
x1 x2 ... x_(V^2) <square shape>

Expected Out:
y1 y2 ... y_(V^2) <square shape>

V - vertices
Complexity: O(V^3)
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define INF 0x3f3f3f3f
int V;
long graph[1000][1000];

void floyd();

int main(){
    cin >> V;
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            cin >> graph[i][j];
        }
    }
    floyd();
    return 0;
}


/*
Return:
2-D Matrix
*/

void floyd(){
    for(int k = 0; k < V; k++){
        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }
}
