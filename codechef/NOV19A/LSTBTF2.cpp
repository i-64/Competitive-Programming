#include <bits/stdc++.h>
using namespace std;

int getsum (int* arr, int n) {
  int sum = 0;
  for (int i = 0; i < n; i++)
    sum += arr[i] * arr[i];
  return sum;
}

void print (int* arr, int n) {
  for (int i = n-1; i >= 0; i--) {
    cout << arr[i];
  }
  cout << endl;
}

void solve () {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    arr[i] = 1;
  }
  int i = 0;
  string str;
  while (true) {
    double s = sqrt(getsum(arr, n));
    if (floor(s) == ceil(s)) {
      print(arr, n);
      return;
    }
    else {
      bool flag = false;
      while (arr[i] == 9) {
        arr[i] = 1;
        i = (i + 1) % n;
        flag = true;
      }
      arr[i]++;
      if (flag) i = 0;
    }
  }
}

int main () {
  ios_base :: sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
