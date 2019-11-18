#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define watch(x) cout << (#x) << " is " << x << endl;

class node {
public:
  int val;
  node () {
    val = 0;
  }
  node (int v) {
    val = v;
  }
};

vector <int> tree[100000];
int vis[100000];

int getdist (node* nodes, int v, int dist) { //cout << v << " ";
  if (nodes[v].val == 1){ /*cout<<dist<<" ";*/return dist;}
  vis[v] = 1;
  int ret = INT_MAX;
  for (int el : tree[v]) {
    if (nodes[el].val == 1) return dist+1;
    if (!vis[el]) {
      int curr = getdist(nodes, el, dist+1);
      // cout << curr << " ";
      ret = min(ret, curr);
    }
  }
  return ret;
}

int32_t main () {
  ios_base :: sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  // cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;
    // for (int i = 0; i < n; i++) {tree[i].clear();}
    node nodes[n];
    nodes[0].val = 1;
    for (int i = 1; i < n-1; i++) {
      nodes[i].val = 0;
    }
    n--;
    int u, v, m = n;
    // vector <int> tree[n];
    while (m--) {
      cin >> u >> v;
      tree[u-1].push_back(v-1);
      tree[v-1].push_back(u-1);
    }
    // for (int i = 0; i < n+1; i++) {cout << i << " => ";for (int el : tree[i]) cout << el << " ";cout << endl;}
    while (q--) {
      cin >> u >> v;
      if (u == 0) {
        // cout << v << " ";
        // cout << nodes[0].val << endl;
        memset(vis, 0, sizeof vis);
        cout << getdist(nodes, v-1, 0) << endl;
      }
      else {
        nodes[v-1].val = 1;
      }
    }
  }
  return 0;
}
