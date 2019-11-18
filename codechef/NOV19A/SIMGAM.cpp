#include <bits/stdc++.h>
using namespace std;
using i64 = long long int;

void solve1 () {
  i64 n, temp, cnt = 0;
  bool turn = true;
  cin >> n;
  vector <i64> arr[n];
  for (i64 i = 0; i < n; i++) {
    i64 rn;
    cin >> rn;
    while (rn--) {
      cin >> temp;
      arr[i].push_back(temp);
      // cnt++;
    }
  }
  // cnt = ceil(cnt/2.0);

  i64 chef = 0;
  vector <int> v;
  for (int i = 0; i < n; i++) {
    int s = arr[i].size();
    // chef += accumulate(arr[i].begin(), arr[i].begin() + (s/2 - 1), 0);
    for (int j = 0; j < s/2; j++) {
      chef += arr[i][j];
      // cout << arr[i][j] << " ";
    }
    if (turn && (s % 2 == 1)) {
      chef += arr[i][s/2];
    }
    if (s % 2 == 1)
      turn = !turn;
    // cout << chef << endl;
  }

  cout << chef << endl;
}

void solve3 () {
  i64 n, temp;
  cin >> n;
  vector <i64> arr[n];
  for (i64 i = 0; i < n; i++) {
    i64 rn;
    cin >> rn;
    while (rn--) {
      cin >> temp;
      arr[i].push_back(temp);
    }
  }

  i64 chef = 0;
  for (i64 j = 0; j < n; j++) {
    for (i64 i = 0; i < arr[j].size()/2; i++)
      chef += arr[j][i];
    if (arr[0].size() % 2 == 1)
      chef += arr[0][arr[0].size()/2];
  }

  cout << chef << endl;
}

void solve () {
  i64 n, temp, cnt = 0;
  cin >> n;
  deque <i64> arr[n];
  for (i64 i = 0; i < n; i++) {
    i64 rn;
    cin >> rn;
    while (rn--) {
      cnt++;
      cin >> temp;
      arr[i].push_back(temp);
    }
  }

  int turn = 0;
  int chef = 0;
  int pos;
  for (int i = 0; i < cnt; i++) {
    turn = !turn;
    if (turn) {
      int mx = -1;
      for (int j = 0; j < n; j++) {
        if (arr[j].size() != 0 && mx < arr[j][0]) {
          mx = arr[j].front();
          pos = j;
        }
      }
      arr[pos].pop_front();
      chef += mx;
    }
    else {
      int mx = -1;
      for (int j = 0; j < n; j++) {
        if (arr[j].size() != 0 && mx < arr[j][0]) {
          mx = arr[j].back();
          pos = j;
        }
      }
      arr[pos].pop_back();
    }
  }
  cout << chef << endl;
}

int main () {
  i64 t;
  cin >> t;
  while (t--)
    solve1();
  return 0;
}

/*
1
5
5 2 9 7 6 4
5 3 2 6 5 5
5 9 8 7 4 2
5 3 1 5 4 9
5 7 5 8 6 4
*/
