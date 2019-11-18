#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

i64 level[500010];

bool f(pair <i64,i64> &a, pair <i64,i64> &b) {
  return a.second > b.second;
}

vector <pair<i64,i64>>* pri64Levels(vector<i64> graph[], i64 V, i64 x){
  // i64 level[V];
  bool vis[V];
  vector <pair<i64,i64>>* arr = new vector<pair<i64,i64>>();
  queue<i64> que;
  que.push(x);
  level[x] = 0;
  vis[x] = true;
  while (!que.empty()) {
    // for(i64 el:que)cout<<el<<" ";cout<<endl;
    x = que.front();
    // cout<<x<<endl;
    que.pop();
    for (i64 i = 0; i < graph[x].size(); i++) {
      i64 b = graph[x][i];
      if (!vis[b]) {
        que.push(b);
        level[b] = level[x] + 1;
        vis[b] = true;
      }
    }
  }
  for (i64 i = 1; i <= V; i++)
    arr->push_back(make_pair(i, level[i]));
    // cout << " " << i << "   -->   " << level[i] << endl;
  return arr;
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
  }

  i64 mytree[n+1];
  bool isleaf[n+1];
  vector <i64> g[n+1];
  i64 pi[n+1];
  vector <pair<i64,i64>> pairs;
  for (i64 i = 1; i < n; i++) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
    pairs.push_back(make_pair(u, v));
  }
  vector <pair<i64,i64>> levels = *pri64Levels(g, n, 1);
  sort(levels.begin(), levels.end(), f);
  // for(auto p:levels)cout<<p.first<<" "<<p.second<<endl;
  for(auto p:pairs) {//cout<<p.first<<"("<<level[p.first]<<") "<<p.second<<"("<<level[p.second]<<")"<<endl;
    if (level[p.first] < level[p.second])
      pi[p.second] = p.first;
    else
      pi[p.first] = p.second;
  }
  // for(i64 el:pi)cout<<el<<endl;
  for (i64 i = 1; i <= n; i++) {
    cin >> mytree[i];
  }
  memset(isleaf, true, sizeof(isleaf));
  isleaf[1] = false;
  for (i64 i = 2; i <= n; i++) {
    isleaf[pi[i]] = false;
  }

  for (i64 t = 0; t < k; t++) {
    for (i64 i = 0; i < n-1; i++) {//cout<<levels[i].first<<" "<<isleaf[levels[i].first]<<" "<<pi[levels[i].first]<<endl;
      i64 curr_node = levels[i].first;
      // cout<<curr_node<<" ";
      if (isleaf[curr_node]) {
        mytree[curr_node] += mytree[pi[curr_node]];
      }
      else {
        mytree[curr_node] = mytree[pi[curr_node]];
      }
    }
    mytree[1] = 0;

    char ch;
    cin >> ch;
    if (ch == '+') {
      i64 node, inc;
      cin >> node >> inc;
      mytree[node] += inc;
    }
    else {
      i64 node;
      cin >> node;
      cout << mytree[node] << endl;
    }
    // for(i64 i=1;i<=n;i++)cout<<mytree[i]<<" ";cout<<endl;
  }

  // cout<<mytree[6];
  // for(i64 el:mytree)cout << el<<endl;
  return 0;
}
