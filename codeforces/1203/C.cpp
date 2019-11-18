// me-no soln
// editorial-bruteforce
// me-how could i not think of it

#include <bits/stdc++.h>
using namespace std;
#define i_64 long long

int main() {
  i_64 n;
  cin >> n;
  i_64 arr[n];
  i_64 gcd = 0;
  for (i_64 i = 0; i < n; i++) {
    cin >> arr[i];
    gcd = __gcd(gcd, arr[i]);
  }

  i_64 cnt = 0;
  for (i_64 i = 1; i*i <= gcd; i++) {
    if (gcd%i == 0) {
      cnt++;
      if (i != gcd/i)
        cnt++;
    }
  }

  cout << cnt << endl;
  return 0;
}
