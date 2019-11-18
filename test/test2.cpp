#include <bits/stdc++.h>
using namespace std;

void set_union (int u, int v, int* disjoint_set) {
  disjoint_set[u] = v;
}

bool check (int u, int v, int* disjoint_set) {
  int curr = u;
  while (true) {
    if (curr != disjoint_set[curr]) {
      curr = disjoint_set[curr];
    }
    else {
      return true;
    }
  }
}

int main () {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int disjoint_set[n+1];
    // memset(disjoint_set, -1, sizeof disjoint_set);
    for (int i = 0; i < n+1; i++) {
      disjoint_set[i] = i;;
    }
    while (k--) {
      int u, v;
      cin >> u;
      char ch;
      cin >> ch;
      if (ch == '!') {
        cin >> ch >> v;
        check(u, v, disjoint_set);
      }
      else {
        cin >> v;
        set_union(u, v, disjoint_set);
      }
    }
  }
  return 0;
}
