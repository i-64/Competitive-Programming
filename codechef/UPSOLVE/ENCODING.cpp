#include <bits/stdc++.h>
#define md 1000000007;
using namespace std;
#define pb push_back
// using i64 = long long int;
#define int long long
#define double long double

i64 p[100001], ip[100001];

int mul (int a, int b) { return ((a * b) % mod);}
int sub (int a, int b) { return ((a - b) % mod);}
int add (int a, int b) { return ((a + b) % mod);}
int mul (int a, int b, int c) { return mul(mul(a, b), c);}

i64 modinv (int n) {
  int m = mod - 2;
  int ret = 1;
  while (m) {
    if (b % 2) {
      ans = mul(ret, n);
    }
    a = mul(a, a);
    b /= 2;
  }
  return ret;
}

int main () {

  i64 t, n1, n2, i, j, k, ans, tmp1, tmp2;
  string s1, s2;

  // precalc
  p[0] = 1;
  ip[0] = 1;

  for (int i = 1; i < 100001; i++) {
    p[i] = (p[i - 1] * 10) % md;
    ip[i] = modinv(p[i]);
  }

  // execution
  cin >> t;
  while (t--) {
    cin >> n1 >> s1 >> n2 >> s2;

  }

  return 0;
}
