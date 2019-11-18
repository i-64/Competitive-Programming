#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

void simulate (i64* arr, i64 n, i64 k) {
  for (i64 i = 0; i < k; i++) {
    arr[i % n] = arr[i % n] ^ arr[n - 1 - (i % n)];
  }
}

void solve (i64 n) {
  i64 arr[n], k;
  cin >> k;
  for (i64 i = 0; i < n; i++) cin >> arr[i];
  if (k / n % 3 == 0) {}
  else if (k / n % 3 == 1) {
    simulate(arr, n, n);
  }
  else {
    simulate(arr, n, n);
    simulate(arr, n, n);
  }

  if (k > n / 2 && n % 2 == 1) {
    arr[n / 2] = 0;
  }

  simulate(arr, n, k % n);
  // simulate(arr, n, k);
  for (i64 el:arr) cout << el << " ";
  cout << endl;
}

int main () {
  // freopen ("input.txt", "r", stdin);
  // freopen ("output2.txt", "w", stdout);
  i64 t;
  cin >> t;
  while (t--) {
    i64 n;
    cin >> n;
    solve(n);
  }
  return 0;
}
