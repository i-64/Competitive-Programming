#include <bits/stdc++.h>
// using int = long long;
using namespace std;
// #define int long long
#define endl '\n'
// #define double long double
class Point {
public:
  int x, y;
  Point () {
    x = y = 0;
  }
  Point (int x, int y) {
    this->x = x;
    this->y = y;
  }
};
#define SIZE 5000
#define pr(x) cout << (#x) << " is " << setprecision(10) << fixed << x << endl;

int rn, gn, bn, x, y;
Point r[10], g[10], b[10], s;
double rg[10][10];

double d (int x1, int y1, int x2, int y2) {
  int d1 = x1 - x2;
  int d2 = y1 - y2;
  return sqrt((d1*d1) + (d2*d2));
}

double dist (Point& a, Point& b) {
  return abs(sqrt((a.x - b.x) * (a.x - b.x)) + sqrt((a.y - b.y) * (a.y - b.y)));
}

void getdistances () {
  for (int i = 0; i < rn; i++) {
    for (int j = 0; j < gn; j++) {
      rg[i][j] = d(r[i].x, r[i].y, g[j].x, g[j].y);
    }
  }
}

double solve () {
  getdistances();
  double ret = DBL_MAX, mnsr = DBL_MAX, d1 = DBL_MAX, d2 = DBL_MAX, mnrb = DBL_MAX, mngb = DBL_MAX;
  int posi, posj;
  for (int i = 0; i < rn; i++) {
    for (int j = 0; j < gn; j++) {
      mnsr = min(rg[i][j], mnsr);
      if (mnsr == rg[i][j]) {
        posi = i;
        posj = j;
      }
    }
  }
  pr(posi);
  pr(posj);
  d1 = d(s.x, s.y, r[posi].x, r[posi].y);
  d2 = d(s.x, s.y, g[posj].x, g[posj].y);
  for (int i = 0; i < bn; i++)
    mnrb = min(d(r[posi].x, r[posi].y, b[i].x, b[i].y), mnrb);
  for (int i = 0; i < gn; i++)
    mngb = min(d(g[posj].x, g[posj].y, b[i].x, b[i].y), mngb);
  d1 += mnrb;
  d2 += mngb;
  return (min(d1, d2) + mnsr);
}

int32_t main () {
  int t;
  cin >> t;
  while (t--) {
    cin >> x >> y >> rn >> gn >> bn;
    for (int i = 0; i < rn; i++) cin >> r[i].x >> r[i].y;
    for (int i = 0; i < gn; i++) cin >> g[i].x >> g[i].y;
    for (int i = 0; i < bn; i++) cin >> b[i].x >> b[i].y;
    cout << setprecision(10) << fixed << solve () << endl;
  }
  return 0;
}
