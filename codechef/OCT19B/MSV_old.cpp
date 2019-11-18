#include <bits/stdc++.h>
using namespace std;

int primefs[10];

void precalc () {
    primefs[1] = 1;
    for (int i = 2; i < 1000000; i++) primefs[i] = i;
    for (int i = 4; i < 1000000; i = i + 2) primefs[i] = 2;
    for (int i=3; i * i < 1000000; i++) if (primefs[i] == i) for (int j = i * i; j < 1000000; j = j + i) if (primefs[j] == j) primefs[j] = i;
}

unordered_set <int> s;

void factorize (int x) {
    while (x != 1) {
        // ret.push_back(primefs[x]);
        s.insert(primefs[x]);
        cout<<primefs[x]<<endl;
        x /= primefs[x];
    }
}

vector<int>* facts2 (int n) {
  vector <int>* ret = new vector <int> ();
    for (int i = 1; i <= sqrt(n); i++)
        if (n % i == 0) {
            if (n/i == i){
              s.insert(i);ret->push_back(i);}
            else{
              s.insert(i);s.insert(n/i);ret->push_back(i);ret->push_back(n/i);}
        }
    return ret;
}

map <int, int> m;

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
      auto res = s.find(arr[i]);
      // cout<<i<<" test"<<endl;
      auto ret = *facts2(arr[i]);
      if (res != s.end()) {
        for(int el: ret) m[el]++;
      }
    }

    // for (int  i = 0; i < n; i++) {
    //   cnt = 0;
    //   for (int j = 0; j < i; j++) {
    //     if (arr[j] % arr[i] == 0)
    //       cnt++;
    //   }
    //   ans = max(ans, cnt);
    // }
    for (auto p:m)
    //cout<<p.first<<" "<<p.second<<endl;
    ans = max(ans, p.second);
    cout << ans << endl;
  }
  return 0;
}
