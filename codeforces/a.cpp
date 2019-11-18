// elevator or stairs - codeforces
#include <bits/stdc++.h>
using namespace std;

cosnt int INF = 1e9;

int main () {
  int n, c;
  cin >> n >> c;
  int s[n], e[n];
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int i = 0; i < n; i++) cin >> e[i];

  int dp[n][2] = {INF};

  dp[0][0] = 0;
  dp[0][1] = 0;

  for (int i = 0; i < n-1; i++) {
    dp[i+1][0] = min(dp[i+1][0], );
  }

  return 0;
}
