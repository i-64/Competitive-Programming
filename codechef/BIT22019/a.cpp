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
  int t;
  cin >> t;
  while (t--) {
    int n, temp, ret = 0;
    cin >> n;
    // int arr[n];
    for (int i = 0; i < n; i++) {
      cin >> temp;
      if (temp > 0)
        ret += temp;
    }
    cout << ret << endl;

  }
  return 0;
}
