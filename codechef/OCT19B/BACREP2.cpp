#include <bits/stdc++.h>
using namespace std;
typedef long long i64;

void simulate (vector <i64>* g, i64 n, i64* old, i64* _new, bool* flagesh) {
  queue <i64> q;
  bool vis[n+1];
  memset(vis, false, sizeof(vis));
  q.push(1);
  i64 curr = 1;
  _new[1] = 0;
  vis[1] = true;
  while (!q.empty()) {
    curr = q.front();
    q.pop();
    for (i64 el:g[curr]) {
      if (!vis[el]) {
        q.push(el);
        _new[el] = old[curr];
        vis[el] = true;
        if (flagesh[el]) _new[el] += old[el];
      }
    }
  }
}

void simulate1 (vector <i64>* g, i64 n, i64* old, i64* _new, bool* flagesh) {
  queue <i64> q;
  bool vis[n+1];
  memset(vis, false, sizeof(vis));
  q.push(1);
  i64 curr = 1;
  _new[1] = 0;
  vis[1] = true;
  while (!q.empty()) {
    curr = q.front();
    q.pop();
    for (i64 el:g[curr]) {
      if (!vis[el]) {
        q.push(el);
        _new[el] = old[curr];
        vis[el] = true;
        bool flag = true;
        for (i64 el2:g[el]) {
          if (!vis[el2]) {
            flag = false;
            break;
          }
        }
        if (flag) flagesh[el] = true;
        if (flag) _new[el] += old[el];
      }
    }
  }
}

int main () {
  i64 n, k, u, v;
  cin >> n >> k;

  if (n == 1) {
    i64 root = 0;
    cin >> root;
    char ch;
    while (k--) {
      cin >> ch;
      if (ch == '+') {
        i64 node, inc;
        cin >> node >> inc;
        root += inc;
      }
      else {
        i64 node;
        cin >> node;
        cout << root << endl;
      }
    }
    return 0;
  }

  bool flagesh[n+1];
  memset(flagesh, false, sizeof(flagesh));

  i64 old[n+1], _new[n+1];
  vector <i64> g[n+1];
  for (i64 i = 1; i < n; i++) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (i64 i = 1; i <= n; i++) {
    cin >> old[i];
  }

  for (i64 i = 0; i < k; i++) {
    memset(_new, 0, sizeof(_new));
    if (i == 0) simulate1(g, n, old, _new, flagesh);
    else simulate(g, n, old, _new, flagesh);
    char ch;
    cin >> ch;
    if (ch == '?') {
      i64 j;
      cin >> j;
      cout << _new[j] << endl;
    }
    else {
      i64 j, l;
      cin >> j >> l;
      _new[j] += l;
    }
    for (i64 i = 1; i <= n; i++) {
      old[i] = _new[i];
    }
  }
  // for(i64 el:_new)cout<<el<<" ";
  return 0;
}
