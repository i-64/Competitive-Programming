#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define watch(x) cout << (#x) << " is " << x << endl;

int32_t main () {
  ios_base :: sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  // cin >> t;
  while (t--) {
    int n, m, wn, bn;
    cin >> n >> m >> wn >> bn;
    int arr[n][m];
    memset(arr, 0, sizeof arr);
    int u, v;
    while (wn--) {
      cin >> u >> v;
      arr[u-1][v-1] = 1;
    }
    while (bn--) {
      cin >> u >> v;
      arr[u-1][v-1] = 2;
    }
    int i, j;
    int brr[n][m], cell[n][m];
    memset(brr, 0, sizeof brr);
    memset(cell, 0, sizeof cell);
    for (i = 0; i < n; i++) {
      int strength = 2;
      for (j = 0; j < m; j++) {
        strength -= arr[i][j];
        if (strength <= 0)
          break;
      }
      if (j != m)
        brr[i][j] = -1;
      else
        brr[i][m-1] = -1;
    }
    for (i = 0; i < n; i++) {
      int val = 1;bool start = false;
      for (j = m-1; j >= 0; j--) {
        if (brr[i][j] == -1) {
          start = true;
          val = 0;
        }
        if (start)
          val++;
        cell[i][j] = val;
        if (!start)
          val++;
        if (arr[i][j] == 2 || arr[i][j] == 1) {
          cell[i][j] = 0;
        }
      }
    }
    int sum = 0;
    // for (i = 0; i < n; i++) { for (j = 0; j < m; j++) cout << arr[i][j] << " ";cout << endl;}cout<<endl;
    // for (i = 0; i < n; i++) { for (j = 0; j < m; j++) cout << brr[i][j] << " ";cout << endl;}cout<<endl;
    // for (i = 0; i < n; i++) { for (j = 0; j < m; j++) cout << cell[i][j] << " ";cout << endl;}
    for (i = 0; i < n; i++) { for (j = 0; j < m; j++) sum += cell[i][j];}
    cout << sum << endl;
  }
  return 0;
}
