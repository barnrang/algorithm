/*
Input:
N
x1 x2 x3 ....
Output:
Num of inversion
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int* construct_bit(int N, int data[]);
int inversion_bit(int N, int norm_data[]);
void update_tree(int N, int tree[], int change, int index);
int get_sum(int tree[], int index);


int main(){
    int N;
    cin >> N;
    int data[N];
    int copy[N];
    int norm_data[N];
    for(int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        data[i] = tmp;
        copy[i] = tmp;
        norm_data[i] = 0;
    }
    sort(copy, copy + N);
    cout << copy[0] << "\n";
    for(int i = 0; i < N; i++){
        int index = lower_bound(copy, copy + N, data[i]) - copy;
        norm_data[i] = index + 1;
    }
    cout << "num of inversion" << inversion_bit(N, norm_data) << "\n";
}

int inversion_bit(int N, int norm_data[]){
    int *tree = (int*) malloc(sizeof(int) * (N+1));
    for(int i = 0; i < N+1; i++) tree[i] = 0;
    int count = 0;
    for(int i = N-1; i >= 0; i--){
        update_tree(N, tree, 1, norm_data[i]);
        count += get_sum(tree, norm_data[i]-1);
    }
    free(tree);
    return count;
}

void update_tree(int N, int tree[], int change, int in){
    int index = in;
    while(index <= N){
        tree[index] += change;
        index += index & (-index);
    }
}

int get_sum(int tree[], int in){
    int index = in;
    int sum = 0;
    while(index > 0){
        sum += tree[index];
        index -= index & (-index);
    }
    return sum;
}
//Classical Binary Index Tree
int* construct_bit(int N, int data[]){
    int tree[N+1];
    for(int i = 0; i < N+1; i++) tree[i] = 0;
    for(int i = 0; i < N; i++){
        int index = i;
        while(index <= N){
            tree[index] += data[index];
            index += index & (-index);
        }
    }
    return tree;
}
