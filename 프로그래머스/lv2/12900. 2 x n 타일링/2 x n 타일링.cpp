#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int solution(int n) {
    int a = 1, b = 2;
    while (--n) {(a += b) %= MOD; swap(a, b);}
    return a;
}