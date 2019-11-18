#include <bits/stdc++.h>
using namespace std;
typedef long long i64;

i64 level[500010];

bool f(pair <i64,i64> &a, pair <i64,i64> &b) {
  return a.second > b.second;
}

void mylevels (vector<i64> graph[], i64 n, i64 x) {
  bool vis[n+1];
  memset(vis, false, sizeof(vis));
  queue <i64> q;
  i64 curr = x;
  q.push(curr);
  i64 lvl[n+1];
  vis[curr] = true;
  while (!q.empty()) {
    curr = q.front();
    q.pop();
    for (auto child:graph[x]) {
      if (!vis[curr]) {
        q.push(child);
        lvl[child] = lvl[curr] + 1;
        vis[child] = true;
      }
    }
  }
  for (int el:lvl)cout<<el<<" ";
  cout << endl;
  return ;
}

vector <pair<i64,i64>>* pri64Levels(vector<i64> graph[], i64 V, i64 x){
  bool vis[V+1];
  vector <pair<i64,i64>>* arr = new vector<pair<i64,i64>>();
  queue<i64> que;
  que.push(x);
  level[x] = 0;
  vis[x] = true;
  while (!que.empty()) {
    x = que.front();
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
  return arr;
}

int main () {
  i64 n, k, u, v;
  cin >> n >> k;

  // = = = SINGLE NODE IN TREE = = =
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

  // = = = MORE THAN ONE NODES = = =

  // DECLARATIONS
  i64 mytree[n+1];
  bool isleaf[n+1];
  vector <i64> g[n+1];
  i64 pi[n+1];
  vector <pair<i64,i64>> pairs;

  // INPUT TREE
  for (i64 i = 1; i < n; i++) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
    pairs.push_back(make_pair(u, v));
  }

  mylevels(g, n, 1);

  // GET LEVELS OF NODES AND SORT
  vector <pair<i64,i64>> levels = *pri64Levels(g, n, 1);
  sort(levels.begin(), levels.end(), f);

  for(auto p:levels)cout<<p.first<<" "<<p.second<<endl;

  // GET PARENTS
  for(auto p:pairs) {
    // if(p.first == 8 || p.second == 8)cout<<p.first<<" "<<p.second<<" "<<level[p.first]<<" "<<level[p.second];
    if (level[p.first] < level[p.second])
      pi[p.second] = p.first;
    else
      pi[p.first] = p.second;
  }

  // INPUT INITIAL VALUES
  for (i64 i = 1; i <= n; i++) {
    cin >> mytree[i];
  }

  // FIND LEAF NODES
  memset(isleaf, true, sizeof(isleaf));
  isleaf[1] = false;
  for (i64 i = 2; i <= n; i++) {cout<<pi[i]<<" ";
    // isleaf[pi[i]] = false;
  }

  // SIMULATE FOR TIME T = 0 -> K-1
  /*for (i64 t = 0; t < k; t++) {

    // REPRODUCTION EVERY SECOND
    for (i64 i = 0; i < n-1; i++) {
      i64 curr_node = levels[i].first;
      if (isleaf[curr_node])
        mytree[curr_node] += mytree[pi[curr_node]];
      else
        mytree[curr_node] = mytree[pi[curr_node]];
    }
    mytree[1] = 0;

    // PROCESS QUERY
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
  }*/
  return 0;
}

/*

20 83
1 15
12 1
16 13
6 2
17 13
4 9
3 10
19 11
10 20
11 10
9 5
17 4
7 2
6 14
18 2
3 12
8 12
1 9
15 2
25 58 92 8 55 53 77 59 20 71 36 61 19 6 51 81 47 16 85 42
+ 18 11
? 9
? 1
+ 4 17
? 10
+ 10 11
? 5
? 3
+ 5 4
? 8
+ 19 15
+ 10 12
+ 4 5
+ 4 14
? 11
? 4
? 16
+ 14 18
? 17
? 8
? 16
? 4
+ 3 3
+ 12 7
? 19
? 5
+ 2 18
+ 15 18
+ 7 20
? 13
? 8
? 15
+ 12 4
+ 1 18
? 7
? 12
? 1
? 7
+ 18 7
? 10
? 12
+ 7 18
? 16
+ 4 5
? 5
+ 5 9
? 12
? 1
+ 7 5
+ 7 5
? 7
+ 19 8
? 9
+ 4 11
+ 5 11
? 7
+ 19 20
+ 13 6
? 10
+ 10 15
? 10
? 1
? 2
? 3
? 4
? 5
? 6
? 7
? 8
? 9
? 10
? 11
? 12
? 13
? 14
? 15
? 16
? 17
? 18
? 19
? 20
? 1
? 2

*/
