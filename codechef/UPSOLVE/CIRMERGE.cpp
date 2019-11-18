#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define bitch ios_base :: sync_with_stdio(false);\
  cin.tie(0);\
  cout.tie(0);
#define rep(i, s, n) for (int i = s; i < n; i++)
#define ms(x, v) memset(x, v, sizeof x);
#define watch(x) cout << (#x) << " is " << x << endl;
#define SIZE 501
const int INF = 1e18;
#define md 1000000007

int n, t;
inline int modinc (int x) { if (x >= n) return x - n; else return x;}
int dp[SIZE][SIZE], arr[SIZE], sum[SIZE][SIZE], ret;

/*
    * WTFFFF !!!
    * MOD % SE TLE AATA HAI
*/
int solve1 (int l, int r) {
  if (dp[l][r] != -1) return dp[l][r];
  if (l == r) return dp[l][r] = 0;
  if (modinc(l + 1) == r) return dp[l][r] = arr[l] + arr[r];
  int ret = LLONG_MAX;
  for (int i = l; i != r; i = modinc(i + 1))
  ret = min(ret, solve1(l, i) + solve1(modinc(i + 1), r) + sum[l][r]);
  return dp[l][r] = ret;
}

int32_t main () {
  bitch
  cin >> t;
  while (t--) {
    cin >> n;
    ms(dp, -1);
    rep (i, 0, n) cin >> arr[i];
    ret = LLONG_MAX;
    rep (i, 0, n) {
      sum[i][i] = arr[i];
      for (int j = modinc(i + 1); j != i; j = modinc(j + 1))
        sum[i][j] = sum[i][modinc(j + n - 1)] + arr[j];
    }
    rep (i, 0, n)
      ret = min(ret, solve1(i, modinc(i + n - 1)));
    cout << ret << endl;
  }
  return 0;
}
