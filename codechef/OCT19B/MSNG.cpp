#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

i64 getdig (char ch) {
  if (ch >= '0' && ch <= '9')
    return i64(ch - '0');
  else
    return ch - 'A' + 10;
}

i64 getval (string num, i64 base) {
  i64 ans = 0, mul = 1;
  for (i64 i = num.length() - 1; i >= 0; i--) {
    ans = ans + mul*getdig(num[i]);
    mul = mul * base;
    if (ans > 1e12)
      return -1;
  }
  return ans;
  /*try {
    ans = stoll(num, 0, base);
    if (ans > 1e12)
      return -1;
    return ans;
  }
  catch (...) {
    return -1;
  }*/
}

i64 getminbase (string str) {
  char mx = 0;
  for (i64 i = 0; i < str.length(); i++) {
    if (mx < str[i]) {
      mx = str[i];
    }
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
  if (mx ==  'O' )return 25;
  if (mx ==  'P' )return 26;
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
  // return 2;
  assert(false);
}

int main () {
  i64 t;
  cin >> t;

  while (t--) {
    i64 n, cnt = 0, ans = 1e13, temp;
    cin >> n;
    unordered_map <i64, i64> m;

    while (n--) {
      cnt++;
      i64 base;
      string num;
      cin >> base >> num;

      i64 oldres = -2;
      if (base == -1) {
        for (i64 i = 2; i <= 36; i++) {
          i64 temp = getval(num, i);
          if (temp == oldres) break;
          if (temp != -1) m[temp]++;
          else break;
          oldres = temp;
        }
      }
      else {
        i64 temp = getval(num, base);
        m[temp]++;
      }
    }

    for (pair <i64,i64> p: m) {
      if (p.second == cnt && p.first != -1)
        ans = min(p.first, ans);
    }

    if (ans == 1e13) cout << "-1" << endl;
    else cout << ans << endl;
    m.clear();
  }
  return 0;
}

/* all -1 consistent

-1 11000001
-1 21011
-1 3001
-1 1233
-1 521
-1 364
-1 301
-1 234
-1 193
-1 166
-1 141
-1 11B
-1 DB
-1 CD
-1 C1
*/


/* base given consistent

-1 11000001
-1 21011
-1 3001
-1 1233
-1 521
-1 364
-1 301
-1 234
10 193
-1 166
-1 141
-1 11B
-1 DB
-1 CD
-1 C1
*/

/* base given, inconsistent given base

-1 11000001
-1 21011
-1 3001
-1 1233
-1 521
-1 364
-1 301
-1 234
10 193
-1 166
-1 141
-1 11B
14 DC
-1 CD
16 C1
*/

/* base given, inconsistent unknown base

-1 11000001
-1 21011
-1 3001
-1 1233
-1 521
-1 364
-1 301
-1 234
10 193
-1 166
-1 141
13 11B
-1 DC
-1 CD
16 C1
*/

/* fail

1
20
-1 1
-1 1
-1 1
-1 1
-1 1
-1 1
-1 1
-1 1
-1 1
-1 1
-1 1
-1 1
-1 1
-1 1
-1 1
-1 1
-1 1
-1 1
-1 1
-1 1
*/
