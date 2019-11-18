#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

i64 getminbase (string str) {
  char mx = 0;
  for (i64 i = 0; i < str.length(); i++) {
    mx = max(str[i], mx);
  }
  if (mx ==  '0' )return 2;
  if (mx ==  '1' )return 2;
  if (mx ==  '2' )return 3;
  if (mx ==  '3' )return 4;
  if (mx ==  '4' )return 5;
  if (mx ==  '5' )return 6;
  if (mx ==  '6' )return 7;
  if (mx ==  '7' )return 8;
  if (mx ==  '8' )return 9;
  if (mx ==  '9' )return 10;
  if (mx ==  'A' )return 11;
  if (mx ==  'B' )return 12;
  if (mx ==  'C' )return 13;
  if (mx ==  'D' )return 14;
  if (mx ==  'E' )return 15;
  if (mx ==  'F' )return 16;
  if (mx ==  'G' )return 17;
  if (mx ==  'H' )return 18;
  if (mx ==  'I' )return 19;
  if (mx ==  'J' )return 20;
  if (mx ==  'K' )return 21;
  if (mx ==  'L' )return 22;
  if (mx ==  'M' )return 23;
  if (mx ==  'N' )return 24;
  if (mx ==  'P' )return 26;
  if (mx ==  'O' )return 25;
  if (mx ==  'Q' )return 27;
  if (mx ==  'R' )return 28;
  if (mx ==  'S' )return 29;
  if (mx ==  'T' )return 30;
  if (mx ==  'U' )return 31;
  if (mx ==  'V' )return 32;
  if (mx ==  'W' )return 33;
  if (mx ==  'X' )return 34;
  if (mx ==  'Y' )return 35;
  if (mx ==  'Z' )return 36;
  if (mx ==  'a' )return 11;
  if (mx ==  'b' )return 12;
  if (mx ==  'c' )return 13;
  if (mx ==  'd' )return 14;
  if (mx ==  'e' )return 15;
  if (mx ==  'f' )return 16;
  if (mx ==  'g' )return 17;
  if (mx ==  'h' )return 18;
  if (mx ==  'i' )return 19;
  if (mx ==  'j' )return 20;
  if (mx ==  'k' )return 21;
  if (mx ==  'l' )return 22;
  if (mx ==  'm' )return 23;
  if (mx ==  'n' )return 24;
  if (mx ==  'p' )return 26;
  if (mx ==  'o' )return 25;
  if (mx ==  'q' )return 27;
  if (mx ==  'r' )return 28;
  if (mx ==  's' )return 29;
  if (mx ==  't' )return 30;
  if (mx ==  'u' )return 31;
  if (mx ==  'v' )return 32;
  if (mx ==  'w' )return 33;
  if (mx ==  'x' )return 34;
  if (mx ==  'y' )return 35;
  if (mx ==  'z' )return 36;
  return 2;
  // assert(false);
}

int main () {
  i64 t;
  cin >> t;
  while (t--) {
    i64 n, cnt = 0, value = -1, temp, valuepred = -1;
    bool flag = true;
    cin >> n;
    map <i64, i64> m;
    while (n--) {
      i64 base;
      string num;
      cin >> base >> num;
      if (base == -1) {
        cnt++;
        for (i64 i = getminbase(num); i <= 36; i++) {
          try {
            temp = stoll(num, 0, i);
            m[temp]++;
          } catch (...) {
            continue;
          }
        }
      }
      else {
        try {
          if (value == -1)
            value = stoll(num, 0, base);
          else
            if (value != stoll(num, 0, base))
          flag = false;
        } catch (...) {
          continue;
        }
      }
    }
    for (auto p:m) {
      if (p.second == cnt) {
        valuepred = p.first;
        break;
      }
    }
    // cout << value << " " << valuepred << " " << flag << endl;
    m.clear();
    if (valuepred == -1) {
      cout << "-1" << endl;
      continue;
    }
    if (flag == false) {
      cout << "-1" << endl;
      continue;
    }
    else {
      if(value>1000000000000 || valuepred>1000000000000) {
        cout<<"-1"<<endl;
        continue;
      }
      if (value == -1)
        cout << valuepred << endl;
      else if (value == valuepred)
        cout << value << endl;
      else
        cout << "-1" << endl;
      continue;
    }
  }
  return 0;
}

// -1 11000001
// -1 21011
// -1 3001
// -1 1233
// -1 521
// -1 364
// -1 301
// -1 234
// -1 193
// -1 166
// -1 141
// -1 11B
// -1 DB
// -1 CD
// -1 C1
