#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define watch(x) cout << (#x) << " is " << x << endl;

int32_t main () {
  ios_base :: sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string str;
    cin >> str;
    if (n == 1 && str[0] == 'a' || str[0] == 'e' || str[0] == 'i' || str[0] == 'o' || str[0] == 'u')
      {cout << 1 << endl;continue;}
    else if (n == 1) {
      cout << 0 << endl;continue;
    }
    int curr = 0, mx = 0;char ch;
    for (int i = 1; i < n; i++) {//cin>>ch;
      if ((str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') && str[i] != str[i-1]) {
        curr++;
      }
      else {
        mx = max(curr, mx);
        curr = 0;
        if (str[i] == str[i-1]) curr = 1;
      }
      // watch(curr)
      // watch(mx)
    }
    cout << max(mx, curr) << endl;
  }
  return 0;
}
