#include <bits/stdc++.h>
using namespace std;

int shiftcomp (vector <vector<int>>& arr, vector <vector<int>>& brr, int r, int c) {
  int ret = 0, n = arr.size(), m = arr[0].size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (((i + r) < n) && ((j + c) < m) && ((i + r) >= 0) && ((j + c) >= 0)) {
        if (arr[i][j] != brr[i+r][j+c]) ret++;
      }
      else {
        if (arr[i][j] != 0) ret++;
      }
    }
  }
  // cout << ret << endl;
  return ret;
}

int main () {
  int t;
  cin >> t;
  while (t--) {
    int n, m, ans = INT_MAX;
    cin >> n >> m;
    vector <vector<int>> arr(n, vector<int>(m));
    vector <vector<int>> brr(n, vector<int>(m));
    // int arr[n][m], brr[n][m];
    char ch;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> ch;
        arr[i][j] = ch - '0';
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> ch;
        brr[i][j] = ch - '0';
      }
    }
    // for (int i = 0; i < n; i++) {
    //   for (int j = 0; j < m; j++) {
    //     cout << arr[i][j] << " ";
    //   }cout << endl;
    // }
    for (int r = 0; r < n; r++) {
      for (int c = 0; c < m; c++) {
        ans = min(ans, shiftcomp(arr, brr, r, c));
        ans = min(ans, shiftcomp(arr, brr, -r, c));
        ans = min(ans, shiftcomp(arr, brr, r, -c));
        ans = min(ans, shiftcomp(arr, brr, -r, -c));
      }
      if (ans == 0) break;
    }
    cout << ans << endl;
  }
  return 0;
}

