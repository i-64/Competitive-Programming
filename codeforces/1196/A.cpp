#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

int main() {
  int t;
  cin >> t;
  while (t--) {
    i64 a, b, c;
    cin >> a >> b >> c;
    i64 ans = (a+b+c)/2ll;
    cout << ans << endl;
  }
  return 0;
}
