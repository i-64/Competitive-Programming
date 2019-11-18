#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

i64 getmb (string str) {
  char greatest = 0;
   for (i64 i = 0; i < str.length(); i++) {
     if (greatest < str[i]) {
       greatest = str[i];
     }
   }
   if (greatest >= '0' && greatest <= '9') {
     return (greatest - '0' + 1);
   }
   else {
     return (greatest - 'A' + 11);
   }
}

void solve (i64 n) {
  i64 val;
  map <i64,i64> m;
  for (i64 i = 0; i < n; i++) {
    string str;
    i64 base;
    cin >> base >> str;

    if (base != -1) {
      try {
        val = stoll(str, 0, base);
      }
      catch (...) {
        val = 1e13;
      }
      if (val > 1e12) {
        continue;
      }
      else {
        m[val]++;
      }
      continue;
    }
    else {
      set <i64> s;
      i64 minbase = getmb(str);
      for (i64 b = minbase; b <= 36; b++) {
        try {
          val = stoll(str, 0, b);
        }
        catch (...) {
          val = 1e13;
        }
        s.insert(val);
      }
      for (i64 el:s) {
        if (el <= 1e12)
          m[el]++;
      }
      s.clear();
    }
  }

  for (auto p:m) {
    if (p.second == n){
      cout << p.first << endl;
      return ;
    }
  }
  cout << -1 << endl;
  return ;
}

int main () {
  i64 t;
  cin >> t;
  while (t--) {
    i64 n;
    cin >> n;
    solve (n);
  }
  return 0;
}
