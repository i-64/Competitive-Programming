#include <bits/stdc++.h>
using namespace std;
using i64 = long long int;

const int INF = LLONG_MAX;
vector<vector<pair<int, int>>> adj;

void dijkstra(int s, vector<int> & d, vector<int> & p) {
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);

    d[s] = 0;
    set<pair<int, int>> q;
    q.insert({0, s});
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                p[to] = v;
                q.insert({d[to], to});
            }
        }
    }
}

i64 rn, gn, bn, x, y;
i64 r[5001][2], g[5001][2], b[5001][2], drg[5000][5000], dgb[5000][5000];

inline long double d (i64 x1, i64 y1, i64 x2, i64 y2) {
  i64 d1 = x1 - x2;
  i64 d2 = y1 - y2;
  return sqrt((d1*d1) + (d2*d2));
}

int solve () {
  for (int i = 0; i < rn; i++) {
    for (int j = 0; j < gn; j++) {
      drg[i][j] = d(r[i][0], r[i][1], g[j][0], g[j][1]);
    }
  }
  for (int i = 0; i < gn; i++) {
    for (int j = 0; j < bn; j++) {
      dgb[i][j] = d(g[i][0], g[i][1], b[j][0], b[j][1]);
    }
  }
  for (int i = 0; i < rn; i++) {
    dsr[i] = d(x, y, r[i][0], r[i][1]);
  }
  for (int i = 0; i < gn; i++) {
    dsr[i] = d(x, y, g[i][0], g[i][1]);
  }

}

int main () {
  i64 t;
  cin >> t;
  while (t--) {
    cin >> x >> y;
    cin >> rn >> gn >> bn;
    for (i64 i = 0; i < rn; i++) cin >> r[i][0] >> r[i][1];
    for (i64 i = 0; i < gn; i++) cin >> g[i][0] >> g[i][1];
    for (i64 i = 0; i < bn; i++) cin >> b[i][0] >> b[i][1];
    cout << setprecision(10) << fixed << solve() << endl;
  }
  return 0;
}
