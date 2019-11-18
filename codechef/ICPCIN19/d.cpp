#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

int main () {
  ios_base :: sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string str;
    int n, k;
    cin >> n >> k >> str;
    string arr[k];
    vector <int> ms[20];
    vector <int> ins[n];
    for (int i = 0; i < k; i++) {
      cin >> arr[i];
      for (char ch:arr[i]) {
        ms[ch-'a'].push_back(i);
      }
    }
    for (auto el:ms[str[0]-'a']) {
      ins[0].push_back(el);
    }
    int ret = 0;
    int pos[n], l = 0;
    memset(pos, 0, sizeof(pos));
    for (int i = 1; i < n; i++) {
      int setnum = str[i] - 'a';
      set_intersection(ms[setnum].begin(), ms[setnum].end(), ins[i-1].begin(), ins[i-1].end(), inserter(ins[i], ins[i].begin()));
      if (ins[i].size() == 0) {
        pos[i] = 1;
        ret++;
        for (auto el:ms[setnum]) {
          ins[i].push_back(el);
        }
      }
    }
    // for (auto el:pos) cout<<el<<" ";cout<<endl;
    int retans[n], pen = *ins[n-1].begin();
    for (int i = n-1; i >= 0; i--) {
      if (pos[i+1] == 1) {
        pen = *ins[i].begin();
      }
      else {}
      retans[i] = pen;
    }
    for (int i = 0; i < n; i++) {
      cout << retans[i]+1 << " ";
    }
    cout << endl;
  }
  return 0;
}
