/*
This program is for demonstrating Heap for data from 0 - 999 (No Input)
*/

#include <iostream>
#include <cmath>
using namespace std;
#define N 100
int heap[N];
int vacant = N - 1;

void fall(int pos);

void insert(int x, int pos){
	heap[pos] = x;
	int parent = (pos - 1)/2;
	if(heap[parent] < x){
		heap[pos] = heap[parent];
		insert(x, parent);
	}
}

void heapify(int pos){
	int parent = heap[pos];
	int child1 = 2 * pos + 1, child2 = 2 * pos + 2;
	if(child1 <= vacant) heapify(child1);
	else return;
	if(child2 <= vacant) heapify(child2);
	else{
		if(heap[child1] > parent){
			heap[pos] = heap[child1];
			heap[child1] = parent;
		}
		return;
	}
	fall(pos);
}

void fall(int pos){
	int parent = heap[pos];
	int child1 = 2 * pos + 1, child2 = 2 * pos + 2;
	int child = 0;
	if(child1 > vacant) return;
	else if(child2 > vacant) child = child1;
	else child = heap[child1] > heap[child2] ? child1:child2;
	if(heap[child] > heap[pos]){
		heap[pos] = heap[child];
		heap[child] = parent;
		fall(child);
	}
}

int pop(){
	int max = heap[0];
	heap[0] = heap[vacant];
	vacant--;
	fall(0);
	return max;
}

void show_heap(){
	int i = 0,j;
	int max_n = log2(N);
	for(i = 0; i < max_n + 1; i++){
		for(j = pow(2,i)-1; j < pow(2,i+1) - 1; j++){
			if(j > vacant) return;
			cout << heap[j] << " ";
		}
		cout << "\n";
		for(j = pow(2,i)-1; j < pow(2,i+1) - 1; j++){
			cout << "|\\";
		}
		cout << "\n";
	}
}

int main(){
	int i;
	for(i=0;i < N;i++){
		heap[i] = i;
	}
	heapify(0);
	for(i=0;i < N; i++){
		cout << heap[i] << "\n";
	}
	show_heap();
	return 0;
}
