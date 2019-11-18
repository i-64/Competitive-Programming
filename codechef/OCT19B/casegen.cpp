#include <bits/stdc++.h>
using namespace std;

int r(int l, int r){
  return l+rand()%(l-r+1);
}

int main () {
  freopen("input.txt", "w", stdout);
  int t = 3;
  cout << t << endl;
  while (t--) {
    // cout << "100 " << r(1, 1000) << endl;
    int h = 300;
    while (h--) {
      cout << r(1, 1000) << " ";
    }
    // cout << r(1, 50) << endl;
    cout << endl;
  }
  return 0;
}
