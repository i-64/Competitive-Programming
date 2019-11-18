#include <bits/stdc++.h>
using namespace std;
using i64 = long long int;

int main () {
  int t;
  cin >> t;
  while (t--) {
    int a, b, s, n;
    cin >> a >> b >> n >> s;
    if ((((i64)a) * n) + b >= s && s % n <= b)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
