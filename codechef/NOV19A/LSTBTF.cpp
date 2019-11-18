#include <bits/stdc++.h>
using namespace std;

int getsum (int n) {
  int ret = 0, d;
  while (n > 0) {
    d = n % 10;
    if (d == 0) return -1;
    ret = ret + d * d;
    n = n / 10;
  }
  return ret;
}

vector <int> precalc () {
  vector <int> ret;
  for (int i = 1; i < 10000000; i++) {
    int sq;
    if ((sq = getsum(i)) != -1) {
      double sqt = sqrt(sq);
      if (floor(sqt) == ceil(sqt)) {
        ret.push_back(i);
      }
    }
  }
  return ret;
}

int main () {
  int t, n;
  cin >> t;
  vector <int> arr = precalc();
  cout << arr.size() << endl;
  int i = 0;
  for (int el : arr) {
    if (el > pow(10, i)) {
      i++;
      cout << el << endl;
    }
  }
  while (t--) {
    cin >> n;
    cout << *(lower_bound(arr.begin(), arr.end(), n)+1) << endl;
  }
  return 0;
}
