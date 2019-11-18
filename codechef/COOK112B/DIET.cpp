#include <bits/stdc++.h>
using namespace std;

int main () {
  int t;
  cin >> t;
  while (t--) {
    int n, k, sum = 0, pos = 0;
    bool flag = true;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      sum += arr[i];
      sum -= k;
      if (flag && sum < 0) {
        flag = false;
        pos = i+1;
      }
    }
    if (flag) cout << "YES" << endl;
    else {
      cout << "NO " << pos << endl;
    }
  }
  return 0;
}

