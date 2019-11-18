#include <bits/stdc++.h>
using i64 = long long;
using namespace std;
#define int i64

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

int rn, gn, bn, x, y;
Point r[10];

inline int dist (Point& a, Point& b) {
  return abs(sqrt((a.x - b.x) * (a.x - b.x)) + sqrt((a.y - b.y) * (a.y - b.y)));
}

int solve () {
  for (int i = 0; i < rn; i++) {
    for (int j = 0; j < gn; j++) {
      
    }
  }
}

int32_t main () {
  int t;
  cin >> t;
  while (t--) {
    cin >> x >> y >> rn >> gn >> bn;
    for (int i = 0; i < rn; i++) cin >> r[i].x >> r[i].y;
    for (int i = 0; i < gn; i++) cin >> g[i].x >> g[i].y;
    for (int i = 0; i < bn; i++) cin >> b[i].x >> b[i].y;
    cout << solve () << endl;
  }
  return 0;
}
