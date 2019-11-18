#include <bits/stdc++.h>
using namespace std;
// ALL THESE ALGS RUN IN O(LOG(MIN(A,B))) TIME

// builtin __gcd(int &a, int &b)

// recursive
int gcd(int a, int b) {
  return b ? gcd(b, a%b) : a;
}

// iterative
int gcdi() {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}

int main(){
  return 0;
}
