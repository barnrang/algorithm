/*
Rank & Path Union and Find data structure
Complexity for find and Union is O(log(n))
Testing input will be:
M, N
a1 b1
a2 b2
a3 b3
.
.
which refer to graph vertices (Used later in MST)
M - vertices number
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct node{
    int rank;
    int parent;
};

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

int main(){
    int M,N;
    cin >> M >> N;
    struct node *nodes = (struct node*) malloc(M * sizeof(struct node));
    for(int i = 0; i < M; i++){
        nodes[i].rank = 0;
        nodes[i].parent = -1;
    }
    int a, b;
    int state = 0;
    for(int i = 0; i < N; i++){
        cin >> a >> b;
        state += Union(a, b, nodes);
    }
    if(state) cout << "Cycle";
    else cout << "No cycle";
    free(nodes);
    return 0;
}
