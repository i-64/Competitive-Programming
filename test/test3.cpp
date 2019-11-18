#include <bits/stdc++.h>
using namespace std;

bool test (string s, string t) {
  int n1 = s.length(), n2 = t.length(), i = 0, j = 0;
  while (i < n1 && j < n2) {
    cout << i << endl;
    if (s[i] == s[j]) {
      i++;
      j++;
    }
    else {
      j++;
    }
  }
  if (i == n1)
    return true;
  else
    return false;
}

int main () {
  string s = "axc", t = "ahbgdc";
  cout << test(s, t) << endl;
  return 0;
}
