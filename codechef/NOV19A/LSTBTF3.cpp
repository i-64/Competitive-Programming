#include <bits/stdc++.h>
using namespace std;

int getsum (int* arr, int n) {
  int ret = 0;
  for (int i = 0; i < 10; i++) {
    ret += arr[i] * (i + 1) * (i + 1);
  }
  return ret;
}

void print (int* arr) {
  for (int i = 0; i < 10; i++) {
    if (arr[i])
    cout << string(arr[i], '0' + (i + 1));
  }
  cout << endl;
}

void solve () {
  int n;
  cin >> n;
  int arr[10];
  memset(arr, 0, sizeof arr);
  int i = 0, k = 1;
  arr[0] = n;
  while (true) {
    for (int i = 0; i < 10; i++) {
      arr[i] += k;
      d = sqrt(getsum(arr));
      if (floor(d) == ceil(d)) {
        print (arr);
        break;
      }
      arr[i] = 1;//later
    }
  }
}

int main () {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

/*

11111
11112
11113
11114
...
11122
11123
11124


*/
