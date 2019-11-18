#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define double long double


int32_t main () {
  int t;
  cin >> t;
  while (t--) {
    int n;
    bool flag = true, bf = false;
    cin >> n;
    int arr[n], brr[n], diff[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) {
      cin >> brr[i];
    }
    for (int i = 0; i < n; i++) {
      diff[i] = brr[i] - arr[i];
      if (diff[i] < 0) {
        bf = true;break;
      }
    }
    for (int i = 0; i < n; i++) cout << diff[i] << " ";cout << endl;
    int i;
    if (bf == true) {cout << "NO1" << endl;continue;}
    for (i = 0; i < n; i++) {
      if (diff[i] != 0)
        continue;
      else break;
    }
    if (i != n-1 || i != n)
    for (i++; i < n; i++) {
      if (diff[i] == diff[i+1]) continue;
      else {
        if (diff[i+1] == 0) continue;
        else {cout << "fuck" << diff[i] << diff[i+1] << endl;flag = false;}
      }
    }
    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;
    // cout << ans << endl;
  }
  return 0;
}
