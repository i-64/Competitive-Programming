#include <bits/stdc++.h>
using namespace std;

int mcp (int* arr, int n) {
  int dp[n][n];
  memset(s, 0, sizeof s);
  memset(dp, 0, sizeof dp);
  for (int i = 1; i < n; i++)  dp[i][i] = 0;
  for (int len = 2; len < n; len++) {
    for (int i = 1; i < n - len + 1; i++) {
      int j = i + len - 1;
      dp[i][j] = INT_MAX;
      for (int k = i; k < j; k++) {
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + arr[i] + arr[i - 1]);
        // int cost = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
      }
    }
  }
  for (int i = 0; i < n; i++) { for (int j = 0; j < n; j++) printf("%d\t", dp[i][j]);printf("\n");}
  return dp[1][n - 1];
}

int32_t main () {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("%d\n", mcp(arr, n));
  }
  return 0;
}
