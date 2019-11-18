#include <bits/stdc++.h>
using namespace std;


void dfs(int node, int parent, int ht[], int vis[], vector<int> tree[]){
    ht[node] = 1 + ht[parent];
    vis[node] = 1;
    for (auto it : tree[node]) {
        if (!vis[it])
            dfs(it, node, ht, vis, tree);
    }
}

int printLevelswithMaximumNodes(int N, int vis[], int ht[]){
    int mark[N + 1];
    memset(mark, 0, sizeof mark);
    int maxLevel = 0;
    for (int i = 1; i <= N; i++) {
        if (vis[i])
            mark[ht[i]]++;
        maxLevel = max(ht[i], maxLevel);
    }
    int maxi = 0;
    for (int i = 1; i <= maxLevel; i++) {
        maxi = max(mark[i], maxi);
    }
    for (int i = 1; i <= maxLevel; i++) {
        if (mark[i] == maxi)
            return i;
    }
}

int main () {
  int n;
  cin >> n;
  vector <int> tree[n+1];
  for (int i = 0; i < n-1; i++) {
    int u, v;
    cin >> u >> v;
    // if (u < v)
      tree[u].push_back(v);
      tree[v].push_back(u);
/*
      insertEdges(u, v, tree);
    else
      insertEdges(v, u, tree);*/
  }
  int ht[n + 1];
  int vis[n + 1] = { 0 };
  ht[0] = 0;
  dfs(1, 0, ht, vis, tree);
  cout << printLevelswithMaximumNodes(n, vis, ht) << endl;
  return 0;
}
