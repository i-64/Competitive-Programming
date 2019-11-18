#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int temp;
    map <int, int> m;
    for (int i = 0; i < n; i++) {
      cin >> temp;
      m[temp]++;
    }
    bool flag = false;
    // sort(arr, arr+n);
    for (auto it = m.begin(); it != m.end(); it++) {
      if (it->f == 2048) {
        flag = true;
        break;
      }
      int c, d;
      if (it->s > 1) {
        c = (it->s)/2;
        d = it->s%2;
        it->s = d;
        m[it->f*2] += c;
      }
      // for(auto p:m)cout<<p.f<<"-"<<p.s<<" "; cout<<endl;
    }
    if (flag)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}

// 128 128 256 256 256
// 256 512
