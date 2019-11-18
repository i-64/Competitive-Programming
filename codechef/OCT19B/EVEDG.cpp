#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

void solve (i64 n, i64 e) {
  vector <i64> g[n+1];
  map <i64,i64> deg;
  i64 u, v;
  for (i64 i = 1; i <= e; i++) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
    deg[u]++;deg[v]++;
  }
  if (e % 2 == 0) {
    cout << 1 << endl;
    for (i64 i = 1; i <= n; i++) {
      cout << 1 << " ";
    }
    cout << endl;

    return ;
  }
  else {
    bool flag = false;
    i64 iso = -1;
    for (auto p: deg) {
      if (p.second % 2 == 1) {
        iso = p.first;
        break;
      }
    }
    if (iso != -1) {
      cout << 2 << endl;
      for (i64 i = 1; i <= n; i++) {
        if (i == iso) { cout << 2 << " "; continue;}
        cout << 1 << " ";
      }
      cout << endl;

      return ;
    }
    else {
      // assert (false);
      i64 otherend, iso1;
      for (i64 i = 1; i <= n; i++) {
        if (deg[i] != 0) {
          iso1 = i;
          break;
        }
      }
      otherend = g[iso1].front();
      cout << 3 << endl;
      for (i64 i = 1; i <= n; i++) {
        if (i == iso1) {
          cout << 2 << " ";
          continue;
        }
        if (i == otherend) {
          cout << 3 << " ";
          continue;
        }
        cout << 1 << " ";
      }
      cout << endl;
      return ;
    }
  }
  assert (false);
}

int main () {
  ios_base :: sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  i64 t;
  cin >> t;
  while (t--) {
    i64 n, e;
    cin >> n >> e;
    solve(n, e);
  }
  return 0;
}
