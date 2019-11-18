#include <bits/stdc++.h>
using namespace std;
typedef long long i64;

// TIME
#ifndef ONLINE_JUDGE
  #if defined (__clang__)
    void begin(void);
    void end(void);
    #pragma startup begin
    #pragma exit    end
    time_t mytm = time(NULL);
    void begin() {ctime(&mytm);}
    void end() {time_t t=time(NULL); ctime(&t);cout<<mytm-t<<endl;}
  #endif
#endif

#define fast ios_base :: sync_with_stdio(false);/
  cin.tie(0);/
  cout.tie(0);
#define watch(x)  cout << (#x) << " is " << x << endl
#define pb  push_back
#define mp  make_pair
#define f   first
#define s   second
#define md  1000000007

#define int i64
#define double long double
#define endl '\n'
#define remove erase

// int pq = p * modinv(q, md) % md;
inline int modinv(int a, int m) { int m1 = m, y = 0, x = 1; if (m == 1) return 0; while (a > 1) { int q = a / m; int t = m; m = a % m, a = t; t = y; y = x - q * y; x = t;} if (x < 0) x += m1; return x;}
inline void red(int &a, int &b) { int div = __gcd(a, b); a /= div; b /= div;}
inline int binpow(int a, int b) { int res = 1; while (b > 0) { if (b & 1) res *= a; a = a * a; b >>= 1;} return res;}

class Point {public: int x, y; Point (int a, int b) { x = a; y = b;}};

void solve() {

  // for array input
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];

  // begin writing code from here
}

int32_t main() {
  fast

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
