#include <bits/stdc++.h>
using namespace std;
using i64 = long long int;
i64 cnt = 0;
i64 rn, gn, bn, x, y;
i64 r[5001][2], g[5001][2], b[5001][2];

inline long double d (i64 x1, i64 y1, i64 x2, i64 y2) {
  i64 d1 = x1 - x2;
  i64 d2 = y1 - y2;
  return sqrt((d1*d1) + (d2*d2));
}

long double solve (i64 a, i64 c, long double dist, bool red, bool blue, bool green) { cnt++;
  if (blue) {
    return dist;
  }
  long double mn = DBL_MAX;
  if (!red) {
    for (i64 i = 0; i < rn; i++)
      mn = min(mn, solve(r[i][0], r[i][1], dist + d(a,  c, r[i][0], r[i][1]), true, blue, green));
  }
  if (!green) {
    for (i64 i = 0; i < gn; i++)
      mn = min(mn, solve(g[i][0], g[i][1], dist + d(a,  c, g[i][0], g[i][1]), red, blue, true));
  }
  if (red && green) {
    for (i64 i = 0; i < bn; i++)
    mn = min(mn, solve(b[i][0], b[i][1], dist + d(a,  c, b[i][0], b[i][1]), red, true, green));
  }
  return mn;
}

int main () {
  i64 t;
  cin >> t;
  while (t--) {
    cin >> x >> y;
    cin >> rn >> gn >> bn;
    for (i64 i = 0; i < rn; i++) cin >> r[i][0] >> r[i][1];
    for (i64 i = 0; i < gn; i++) cin >> g[i][0] >> g[i][1];
    for (i64 i = 0; i < bn; i++) cin >> b[i][0] >> b[i][1];
    cout << setprecision(10) << fixed << solve(x, y, 0.0, false, false, false) << endl;
    cout << cnt << endl;
    cnt = 0;
  }
  return 0;
}

/*

100
110
010


rgb
rbg
grb
gbr
brg
bgr


*/

/*

AIR
hill, a*, heur, 8puzz, goal, chatbot

DA


HPC
mat, vec, m_v, bub, merge, binary, dfs


*/
