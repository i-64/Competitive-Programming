#include <bits/stdc++.h>
using namespace std;
// TIME DEPENDS ON THE GCD USED

inline void red(int &a, int &b) {
  int div = __gcd(a, b);
  a /= div;
  b /= div;
}

int main() {
  int a=10, b=30;
  red(a, b);
  cout<<a<<endl<<b;
  return 0;
}
