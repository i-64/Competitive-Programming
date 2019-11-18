#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    string str;
    cin >> str;
    int n = str.length();
    bool flag = true;
    int cnt = 0, i = 0, curr, last = 0;
    char ch;
    for (; i < n && str[i] == '.'; i++);
    if (i != n) last = str[i++] - '0';
    for (;i < n; i++) {
      ch = str[i];
      if (ch == '.') cnt++;
      else {
        curr = ch - '0';
        if (curr + last > cnt) {
          flag = false;
          break;
        }
        last = ch;
        cnt = 0;
      }
    }
    if (flag)
      cout << "safe" << endl;
    else
      cout << "unsafe" << endl;
  }
  return 0;
}

//it's grind season
