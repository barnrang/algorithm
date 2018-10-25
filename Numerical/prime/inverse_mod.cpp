/*
 * The following code is the algorithm to determine the modulo inverse.
 * independently looking up O(logN)
 * For a range of number 1-N, by using memory, it can be performed in O(N)
 */
#include<iostream>
#include<cmath>
#define ll long long
const ll Mod = 11;

template<typename T, typename T1>
T mod(T x, T1 p){
    x %= p;
    x = x < 0 ? x + p : x;
    return x;
}

template<typename T>
T inverse(T x,T p){
    x = mod(x, p);
    if (x == 1) return x;
    return mod(1LL * (-p/x) * inverse(p % x, p), p);
}


int main(){
    ll test[] = {1,2,3,4,5,7};
    ll inv[6];
    for (int i = 0; i < 6; i++){
        inv[i] = inverse(test[i], Mod);
        std::cout << test[i] << " " << inv[i] << std::endl;
    }

}

