#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
#define watch(x) cout<<#x<<" is "<<x<<endl

int main () {
  i64 t;
  cin >> t;
  while (t--) {
    i64 n, m, q, x, y, j = 0, k = 0;
    cin >> n >> m >> q;
    bool rows[n],cols[m];
    memset(rows, false, sizeof(rows));
    memset(cols, false, sizeof(cols));
    while (q--) {
      cin >> x >> y;
      rows[x-1] = !rows[x-1];
      cols[y-1] = !cols[y-1];
    }
    for (bool el:rows) if (el) j++;
    for (bool el:cols) if (el) k++;
    i64 ans = m*j + n*k - 2*j*k;
    // watch(x);
    // watch(y);
    // watch(j);
    // watch(k);
    cout << ans << endl;
  }
  return 0;
}
