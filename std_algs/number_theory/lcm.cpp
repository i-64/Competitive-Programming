#include <bits/stdc++.h>
using namespace std;
// ALL THESE ALGS RUN IN O(LOG(MIN(A,B))) TIME

// division first, avoids integer overflow
int lcm(int a, int b) {
  return a / gcd(a, b) * b;
}

int main() {
  return 0;
}
