#include <bits/stdc++.h>
using namespace std;
// #define int long long
// #define double long double
#define flash ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
#define watch(x) cout << (#x) << " is " << setprecision(10) << fixed << x << endl;
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
int rn, gn, bn;
Point s, r[SIZE], g[SIZE], b[SIZE];
double rg[SIZE][SIZE];
inline double dist (int a, int b, int x, int y) { return abs(sqrt(((a - x) * (a - x)) + ((b - y) * (b - y))));}
void getdistances () { for (int i = 0; i < rn; i++) for (int j = 0; j < gn; j++) rg[i][j] = dist(r[i].x, r[i].y, g[j].x, g[j].y);}
double solve () {
  getdistances();
  int posi, posj;
  double min_red_to_green = DBL_MAX;
  for (int i = 0; i < rn; i++) {
    for (int j = 0; j < gn; j++) {
      if (rg[i][j] < min_red_to_green) {
        posi = i;
        posj = j;
        min_red_to_green = rg[i][j];
      }
    }
  }
  double source_to_curr_red = dist(s.x, s.y, r[posi].x, r[posi].y);
  double source_to_curr_green = dist(s.x, s.y, g[posj].x, g[posj].y);
  double curr_red_to_blue = DBL_MAX, curr_green_to_blue = DBL_MAX;
  for (int i = 0; i < bn; i++) {
    curr_red_to_blue = min(dist(r[posi].x, r[posi].y, b[i].x, b[i].y), curr_red_to_blue);
    curr_green_to_blue = min(dist(g[posj].x, g[posj].y, b[i].x, b[i].y), curr_green_to_blue);
  }

  // return
  double one = source_to_curr_red + curr_green_to_blue;
  double two = source_to_curr_green + curr_red_to_blue;
  double ret = min(one, two) + min_red_to_green;
  return ret;
}
int32_t main () {
  flash
  int t;
  cin >> t;
  while (t--) {
    cin >> s.x >> s.y >> rn >> gn >> bn;
    for (int i = 0; i < rn; i++) cin >> r[i].x >> r[i].y;
    for (int i = 0; i < gn; i++) cin >> g[i].x >> g[i].y;
    for (int i = 0; i < bn; i++) cin >> b[i].x >> b[i].y;
    cout << setprecision(10) << fixed << solve() << endl;
  }
  return 0;
}
