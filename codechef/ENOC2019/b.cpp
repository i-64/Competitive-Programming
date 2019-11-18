#include <bits/stdc++.h>
using namespace std;

int main () {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <int> g[n];
    for (int i = 0; i < n-1; i++) {
      cin >> u >> v;
      if (u > v)
        g[v].push_back(u);
      else
        g[u].push_back(v);
    }
    int s = 1;
    while ()
  }
  return 0;
}
