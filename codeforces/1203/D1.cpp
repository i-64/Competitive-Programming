//didn't understand

#include <bits/stdc++.h>
using namespace std;

int main() {
  string str1, str2;
  cin >> str1 >> str2;
  int l1 = str1.size(), l2 = str2.size(), ans = 0;

  for (int i = 0; i < l1; i++) {
    for (int j = i; j < l1; j++) {
      int pos = 0;
      for (int k = 0; k < l1; k++) {
        cout<<i<<" "<<j<<" "<<k<<" - ";
        if (i <= k && k <= j) continue;
        if (k < l2 && str2[pos] == str2[k]) pos++;
      }if (pos == l2) ans = max(ans, j-i+1);cout<<endl;
    }
    cout<<"---"<<endl;
  }

  cout << ans << endl;
  return 0;
}
