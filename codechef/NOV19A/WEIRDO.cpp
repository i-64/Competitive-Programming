#include <bits/stdc++.h>
using namespace std;

bool check (string str) {
  int vowels = 0, consonants = 0;
  for (char ch : str) {
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' ||ch == 'u') {
      vowels++;
    }
    else {
      consonants++;
    }
  }
  if (vowels <= consonants)
    return true;
  else
    return false;
}

bool alice (string str) {
  for (int i = 0; i < str.length(); i++) {
    for (int j = i + 1; j < str.length(); j++) {
      string s(str.begin()+i, str.begin()+j);
      cout<<s<<endl;
      if (check(s) == false)
        return false;
    }
  }
  return true;
}

void solve () {
  int n;
  cin >> n;
  unordered_map <char,int> total;
  unordered_set <int> s[26];
  string str;
  string arr[n], brr[n];
  int l = 0, r = 0;
  for (int i = 0; i < n; i++) {
    cin >> str;
    if (alice(str))
      arr[l++].copy(str);
    else
      brr[r++] = str;
  }

  for (int i = 0; i < n; i++) {
    cout << arr[i] << endl;
    for (char ch : arr[i]) {cout << "hello" << endl;
      total[ch]++;
      s[ch-'a'].insert(i);
    }
  }
  double sca = 1, scb = 1;
  for (int i = 0; i < 26; i++) {
    if(s[i].size()) {
      sca *= s[i].size()/((double)pow(total[i+'a'],l));}
  }

  cout<<sca<<endl;
}

int main () {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}

// 1100405402461
