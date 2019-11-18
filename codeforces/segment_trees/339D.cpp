#include <bits/stdc++.h>
using namespace std;

int main () {
  int n;
  int arr[pow(2, n + 1)];
  for (int i = pow(2, n); i < pow(2, n + 1); i++) {
    cin >> arr[i];
    bool flag = true;
    for (int j = i / 2; j > 0; j /= 2, flag = !flag) {
      arr[j] = flag ? arr[pow(2, j)] | arr[pow(2, j) + 1] : arr[pow(2, j)] ^ arr[pow(2, j) + 1];
    }
  }
  return 0;
}
