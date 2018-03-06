/*
Input:
S
W
Output:
a1 a2 a3...
S text to be serached
W query text
ai position

Complexity: O(k + n)
*/

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void KMP(char S[], char W[]){
    int M = strlen(S);
    int N = strlen(W);
    int lps[N];

    cout << "Pattern(s) are found at: ";
    //Construct LPS
    int index = 1;
    lps[0] = 0;
    int len = 0;
    while(index < N){
        if(W[index] == W[len]){
            len++;
            lps[index] = len;
            index++;
        }
        else if(len > 0) len--;
        else {
            lps[index] = 0;
            index++;
        }
    }

    //Start algorithm
    int i = 0, j = 0;
    while(i < M){
        if(j == N){
            j = lps[j-1];
            cout << i - N << " ";
        }
        if(S[i] == W[j]){
            i++;j++;
        }
        else{
            if(j > 0) j = lps[j-1];
            else i++;
        }
    }
    cout << "\n";
}

int main(){
    char S[100], W[100];
    cin >> S >> W;
    KMP(S,W);
}
