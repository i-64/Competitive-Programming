#include <bits/stdc++.h>
using namespace std;

unordered_set <int> s;
map <int, int> m;

vector<int>* facts2 (int n) {
  vector <int>* ret = new vector <int> ();
  ret->clear();
    for (int i = 1; i <= sqrt(n); i++)
        if (n % i == 0) {
            if (n/i == i){
              /*s.insert(i);*/ret->push_back(i);}
            else{
              /*s.insert(i);s.insert(n/i);*/ret->push_back(i);ret->push_back(n/i);}
        }
    // for (int el: *ret)cout<<el<<" ";cout<<endl;
    return ret;
}


int main () {
  // precalc();
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  // check

  // int manya;
  // cin >> manya;
  // factorize(manya);

  // ends here

  int t;
  cin >> t;
  while (t--) {
    s.clear();
    m.clear();
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    // int cnt = 0;
    int ans = 0;

    for (int i = n; i >= 0; i--) {
      // auto res = s.find(arr[i]);
      auto ret = *facts2(arr[i]);
      // if (res != s.end()) {
      for(int el: ret) {
        if (s.find(el) != s.end()) m[el]++;
      }
      s.insert(arr[i]);
      // }
    }

    for (auto p:m) //cout << p.first<<" "<<p.second<<endl;
      ans = max(ans, p.second);
    cout << ans << endl;
  }
  return 0;
}
