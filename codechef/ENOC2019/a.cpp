#include <bits/stdc++.h>
using namespace std;

const long long int m = 1000000007;

int main () {
  int t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long num = n / k;
    long long ans = (num * (num + 1)) % m;
    ans = ans % m;
    ans = (ans * k) % m;
    ans = (ans + n) % m;
    cout << ans << endl;
  }
  return 0;
}
