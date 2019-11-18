#include <bits/stdc++.h>
using namespace std;

int main () {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    int arr[20];
    int k = 0;
    // long long ret = 0;
    while (n > 0) {
      arr[k++] = n % 10;
      n = n / 10;
    }
    reverse(arr, arr+k);
    int ret[k];
    for (int i = 0; i < k-1; i++) {
      ret[i] = arr[i] ^ arr[i+1];
    }
    ret[k-1] = arr[k-1] ^ arr[0];
    for (int el : ret) {
      cout << el;
    }
    cout << endl;
  }
  return 0;
}
